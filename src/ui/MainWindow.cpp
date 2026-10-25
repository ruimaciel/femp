#include "MainWindow.hpp"

#include "ui/ui_MainWindow.h"

// application includes
#include <application/commands/DumpFemEquationCommand.hpp>
#include <application/commands/SaveDocumentCommand.hpp>

// gui includes
#include "DefaultProgressIndicator.hpp"
#include "FempApplication.hpp"
#include "ProjectVisitor/MoveNodesVisitor.hpp"
#include "ProjectVisitor/OutputElementStatisticsVisitor.hpp"
#include "ProjectVisitor/OutputResultsInNodesCSVVisitor.hpp"
#include "ProjectVisitor/SetDomainLoadsVisitor.hpp"
#include "ProjectVisitor/SetNodeRestraintsVisitor.hpp"
#include "ui/AnalysisResultsWindow.hpp"
#include "ui/MatrixWindow.hpp"
#include "ui/MdiWindow.hpp"
#include "ui/ModelWindow.hpp"
#include "ui/PostprocessingWindow.hpp"
#include "ui/TensorFieldWindow.hpp"
#include "ui/dialogs/AnalysisDialog.hpp"
#include "ui/dialogs/AnalysisProgressDialog.hpp"
#include "ui/dialogs/AnalysisSummaryDialog.hpp"
#include "ui/dialogs/DomainLoadsDialog.hpp"
#include "ui/dialogs/MaterialsEditorDialog.hpp"
#include "ui/dialogs/MoveNodesDialog.hpp"
#include "ui/dialogs/NodeActionsDialog.hpp"
#include "ui/dialogs/NodeRestrainsDialog.hpp"
#include "ui/dialogs/QuadratureRulesOptionsDialog.hpp"
#include "ui/dialogs/SelectionDialog.hpp"
#include "ui/dock_widgets/CommandLineDockWidget.hpp"
#include "ui/models/LoadPatternsModel.hpp"
#include "ui/wizards/NewProjectWizard.hpp"

// libfemp includes
#include <AppState.hpp>
#include <libfemp/Analysis.hpp>
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/LinearAnalysis.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/NodeRestrictions.hpp>
#include <libfemp/io/import/ModelImporterFactory.hpp>
#include <libfemp/solvers/CGSolver.hpp>
#include <libfemp/solvers/CholeskySolver.hpp>
#include <persistence/LoadPatternRepository.hpp>

// Qt includes
#include <QAction>
#include <QDebug>
#include <QFileDialog>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QProgressDialog>
#include <QSignalMapper>
#include <QString>
#include <QTextStream>
#include <QTime>
#include <QTranslator>

// std includes
#include <stdlib.h>

#include <fstream>
#include <string>
#include <thread>

namespace femp::ui {

struct MainWindow::Private {
  fem::LinearAnalysis<double> analysis;
  CommandLineDockWidget *commandLineDockWidget = nullptr;
  QMdiArea *mdiArea = nullptr;
  femp::Document document;
  femp::SelectionManager selectionManager;
  ::ViewportColors colors;
  femp::DocumentState renderedDocumentState =
      femp::DocumentState::DocumentStateUnknown;
  QSignalMapper *windowMapper = nullptr;
  femp::application::ILoadPatternRepositoryPtr loadPatternRepository;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>()),
      d(std::make_unique<Private>()) {
  ui->setupUi(this);

  // set the MDI area widget as the window's central widget
  d->mdiArea = new QMdiArea();
  setCentralWidget(d->mdiArea);
  d->windowMapper = new QSignalMapper(this);

  // create actions and connect signals to slots
  this->createActions();
  this->createDockWidgets();

  // set the user interface
  setUserInterfaceAsClosed();
  d->loadPatternRepository =
      std::make_shared<femp::persistence::LoadPatternRepository>(
          d->document.getProject().getDomainModel());
}

MainWindow::~MainWindow() = default;

void MainWindow::onAppStateChanged(femp::AppState state) {
  switch (state.lifeCycleState) {
  case femp::ApplicationLifeCycleState::AppStateStart:
    qInfo() << "Application state changed to: Starting";
    this->show();
    break;
  case femp::ApplicationLifeCycleState::AppStateActive:
    qInfo() << "Application state changed to: Active";
    break;
  case femp::ApplicationLifeCycleState::AppStateInactive:
    qInfo() << "Application state changed to: Inactive";
    break;
  default:
    qWarning() << "Application state changed to: Unknown";
    break;
  }

  if (state.documentState == d->renderedDocumentState) {
    return;
  }

  d->renderedDocumentState = state.documentState;
  switch (state.documentState) {
  case femp::DocumentState::DocumentStateOpen:
    setUserInterfaceAsOpened();
    break;
  case femp::DocumentState::DocumentStateClosed:
    setUserInterfaceAsClosed();
    break;
  default:
    qWarning() << "Document state is unknown";
    break;
  }
}

void MainWindow::setSelection(::Selection) {}

void MainWindow::clearSelection() {}

void MainWindow::newProject() {
  qInfo() << "MainWindow::newProject()";

  // free everything
  d->document.clear();
  emit documentClosed();

  // The NewProjectWizard dialog will fill up a given document object through
  // the steps
  NewProjectWizard np(d->document, this);
  switch (np.exec()) {
  case QDialog::Accepted:
    emit documentOpened();
    break;

  default:
    d->document.clear();
    emit documentClosed();
    break;
  }
}

void MainWindow::importProjectFromJsonFile(QString file_name) {
  std::fstream file;
  file.open(file_name.toStdString(), std::fstream::in);

  // TODO react to failed file open

  fem::Model &model = d->document.getProject().getModel();
  model.clear();
  auto parser = fem::ModelImporterFactory::makeFemJsonParser();
  parser->parse(file, model);

  switch (parser->error.code) {
  case Parser::Error::ERR_OK:
    d->document.setProjectType(
        femp::Document::TYPE_SOLID3D); // nasty hack due to poor design
    d->document.setFileName(file_name);
    emit documentOpened();
    break;

  default:
    qCritical() << __FILE__ << ":" << __LINE__;
    qCritical() << QString("Error: %1")
                       .arg(QString::fromStdString(parser->error.message));

    QMessageBox::critical(this, tr("Error"), parser->error.message.c_str());
    d->document.clear();
    emit documentClosed();
    break;
  }

  femp::OutputElementStatisticsVisitor visit;
  d->document.getProject().accept(visit);
}

void MainWindow::openProject() {
  qInfo() << "MainWindow::openProject()";

  // get the last dir where a project was opened
  QFileDialog dialog(this);

  QDir file_dialog_directory = Options::getInstance().getProjectOpenDirectory();
  dialog.setDirectory(file_dialog_directory);

  // setup the file dialog
  dialog.setFileMode(QFileDialog::ExistingFile);
  dialog.setNameFilter(tr("FEM project (*.fem.json)"));
  if (dialog.exec() == QDialog::Rejected) {
    // user cancelled, no file was loaded
    return;
  }

  file_dialog_directory = dialog.directory();
  Options::getInstance().setProjectOpenDirectory(file_dialog_directory);

  // clear the document
  d->document.clear();
  d->selectionManager.clearSelection();
  emit documentClosed();

  // prepare the file
  QStringList sl = dialog.selectedFiles();
  QString file_name = sl.at(0);

  importProjectFromJsonFile(file_name);
}

void MainWindow::reopenProject() {
  qInfo() << "MainWindow::reopenProject()";

  if (d->document.isFileNameNotSet()) {
    QMessageBox::critical(this, tr("Error"),
                          tr("This document hasn't been saved to a file"));
    return;
  }

  // clear the document
  d->selectionManager.clearSelection();
  emit documentClosed();

  std::string file_name(d->document.getFileName().toUtf8());
  importProjectFromJsonFile(QString::fromStdString(file_name));
}

static void saveDocument(femp::Document &doc, std::string file_name) {
  femp::application::SaveDocumentCommand command(doc.getProject().getModel(),
                                                file_name);
  command.execute();

  doc.setDirty(false);
}

void MainWindow::saveProject() {
  qInfo() << "MainWindow::saveProject()";

  if (d->document.isFileNameNotSet()) {
    QFileDialog dialog(this);
    QDir file_dialog_directory =
        Options::getInstance().getProjectOpenDirectory();
    dialog.setDirectory(file_dialog_directory);

    // setup the file dialog
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("FEM project (*.fem.json)"));
    dialog.setDefaultSuffix("fem.json");
    if (dialog.exec() == QDialog::Rejected) {
      // user cancelled
      return;
    }

    QStringList sl;
    sl = dialog.selectedFiles();
    QString file_name = sl.at(0);

    // check if file already exists
    QFile file;
    file.setFileName(file_name);

    if (file.exists()) {
      QMessageBox msgBox;
      msgBox.setText(tr("File already exists"));
      msgBox.setInformativeText(tr("Do you want to overwrite it?"));
      msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
      msgBox.setDefaultButton(QMessageBox::No);
      if (msgBox.exec() == QMessageBox::No) {
        return;
      }
    }

    // set a new file name for this file
    d->document.setFileName(file_name);

    this->setWindowTitle("Femp - " + file_name);
    ui->actionReopen->setEnabled(true);
  }

  saveDocument(d->document, d->document.getFileName().toStdString());
}

void MainWindow::saveProjectAs() {
  qInfo() << "MainWindow::saveProjectAs()";

  QFileDialog dialog(this);

  QDir file_dialog_directory = Options::getInstance().getProjectOpenDirectory();
  dialog.setDirectory(file_dialog_directory);

  // setup the file dialog
  dialog.setFileMode(QFileDialog::AnyFile);
  dialog.setNameFilter(tr("FEM project (*.fem.json)"));
  dialog.setDefaultSuffix("fem.json");
  if (dialog.exec() == QDialog::Rejected) {
    // user cancelled
    return;
  }

  QStringList sl;
  sl = dialog.selectedFiles();

  QString file_name = sl.at(0);

  // check if file already exists
  QFile file;
  file.setFileName(file_name);
  if (file.exists()) {
    QMessageBox msgBox;
    msgBox.setText(tr("File already exists"));
    msgBox.setInformativeText(tr("Do you want to overwrite it?"));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if (msgBox.exec() == QMessageBox::No) {
      return;
    }
  }

  this->setWindowTitle("Femp - " + file_name);

  // tweak the UI
  d->document.setFileName(file_name);
  saveDocument(d->document, file_name.toStdString());
}

void MainWindow::closeProject() {
  qInfo() << "MainWindow::closeProject()";

  if (d->document.isDirty()) {
    // ask the user if he wants to save the changes
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard |
                              QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    switch (msgBox.exec()) {
    case QMessageBox::Save:
      this->saveProject();
      break;

    case QMessageBox::Discard:
      // move on
      break;

    case QMessageBox::Cancel:
      return; // exit and do nothing
      break;

    default:
      // this part should never be reached
      break;
    }
  }

  // free everything
  d->document.clear();
  d->selectionManager.clearSelection();
  emit documentClosed();
}

void MainWindow::quit() {
  qInfo() << "MainWindow::quit()";

  if (d->document.isDirty()) {
    // ask the user if he wants to save the changes
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard |
                              QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    switch (msgBox.exec()) {
    case QMessageBox::Save:
      this->saveProject();
      break;

    case QMessageBox::Discard:
      // move on
      break;

    case QMessageBox::Cancel:
      return; // exit and do nothing
      break;

    default:
      // this part should never be reached
      break;
    }
  }

  // proceed to quit
  this->close();
}

void MainWindow::createActions() {
  // connect the actions
  connect(ui->actionNew, &QAction::triggered, this, &MainWindow::newProject);
  connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openProject);
  connect(ui->actionReopen, &QAction::triggered, this,
          &MainWindow::reopenProject);
  connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveProject);
  connect(ui->actionSaveAs, &QAction::triggered, this,
          &MainWindow::saveProjectAs);
  connect(ui->actionClose, &QAction::triggered, this,
          &MainWindow::closeProject);
  connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::quit);
  connect(ui->actionNodeRestraints, &QAction::triggered, this,
          &MainWindow::setNodeRestraints);
  connect(ui->actionNodeActions, &QAction::triggered, this,
          &MainWindow::setNodeActions);
  connect(ui->actionDomainLoads, &QAction::triggered, this,
          &MainWindow::setDomainLoads);
  connect(ui->actionMoveNodes, &QAction::triggered, this,
          &MainWindow::moveSelectedNodes);

  connect(ui->actionRun, &QAction::triggered, this, &MainWindow::runAnalysis);
  connect(ui->actionDump_FEM_equation, &QAction::triggered, this,
          &MainWindow::dumpFemEquation);
  connect(ui->actionAnalysisSummary, &QAction::triggered, this,
          &MainWindow::showAnalysisSummary);

  connect(ui->actionEditMaterials, &QAction::triggered, this,
          &MainWindow::editMaterials);

  connect(ui->actionWindowTile, &QAction::triggered, this,
          &MainWindow::setTiledWindows);
  connect(ui->actionWindowCascade, &QAction::triggered, this,
          &MainWindow::setCascadeWindows);

  // MDI window creation
  connect(ui->actionNewModelWindow, &QAction::triggered, this,
          &MainWindow::createNewModelWindow);
  connect(ui->actionNewPostprocessingWindow, &QAction::triggered, this,
          &MainWindow::createNewPostprocessingWindow);
  connect(ui->actionNewTensorFieldWindow, &QAction::triggered, this,
          &MainWindow::createNewTensorFieldWindow);
  connect(ui->actionNewAnalysisResultsWindow, &QAction::triggered, this,
          &MainWindow::createNewAnalysisResultsWindow);
  connect(ui->actionNewFemEquationWindow, &QAction::triggered, this,
          &MainWindow::createNewFemEquationWindow);

  connect(ui->actionViewSelection, &QAction::triggered, this,
          &MainWindow::showSelection);
  connect(ui->actionViewAll, &QAction::triggered, this, &MainWindow::showAll);

  connect(ui->actionQuadrature_rules, &QAction::triggered, this,
          &MainWindow::editQuadratureRules);
  connect(ui->actionSelection, &QAction::triggered, this,
          &MainWindow::editSelection);
  connect(ui->actionResults_from_selection, &QAction::triggered, this,
          &MainWindow::dumpResultsFromSelection);

  connect(ui->menuWindowOpened, &QMenu::aboutToShow, this,
          &MainWindow::updateWindowMenu);
}

void MainWindow::createDockWidgets() {
  // initialize the Docks
  d->commandLineDockWidget = new CommandLineDockWidget(this);

  // set the MainWindow connections
  connect(this, &MainWindow::informationMessageSent, d->commandLineDockWidget,
          &CommandLineDockWidget::getMessage);
  connect(this, &MainWindow::warningMessageSent, d->commandLineDockWidget,
          &CommandLineDockWidget::getWarning);
  connect(this, &MainWindow::errorMessageSent, d->commandLineDockWidget,
          &CommandLineDockWidget::getError);

  // add selection dock widget
  this->addDockWidget(Qt::RightDockWidgetArea, d->commandLineDockWidget);
}

void MainWindow::setNodeRestraints() {
  qInfo() << "MainWindow::setNodeRestraints()";

  assert(d->mdiArea != nullptr);

  NodeRestrainsDialog nd;
  if (nd.exec() != QDialog::Accepted) {
    return;
  }

  femp::SetNodeRestraintsVisitor visitor(
      d->selectionManager.getSelection().getNodeReferences(),
      nd.getRestrictions());

  // set the restraints in the model
  d->document.getProject().accept(visitor);
}

void MainWindow::setNodeActions() {
  qInfo() << "MainWindow::setNodeActions()";

  LoadPatternsModel load_patterns_model(d->loadPatternRepository, this);

  NodeActionsDialog na(load_patterns_model, this);
  if (na.exec() != QDialog::Accepted) {
    return;
  }

  ::Selection const selection = d->selectionManager.getSelection();

  // shortcut just to reduce code clutter
  fem::Model &femp_model = d->document.getProject().getModel();
  auto load_pattern_index = na.getLoadPattern();
  fem::LoadPattern &load_pattern =
      femp_model.load_pattern_list[load_pattern_index];

  // assign nodal loads
  for (fem::node_ref_t const &node : selection.getNodeReferences()) {
    load_pattern.addNodalLoad(node, na.getForce());
  }
}

void MainWindow::setDomainLoads() {
  qInfo() << "MainWindow::setDomainLoads()";

  LoadPatternsModel model(d->loadPatternRepository, this);

  DomainLoadsDialog dialog(model, this);

  // call the dialog box
  if (dialog.exec() != QDialog::Accepted) {
    return;
  }

  fem::Model &femp_model = d->document.getProject().getModel();
  auto load_pattern_index = dialog.getLoadPattern();
  femp::SetDomainLoadsVisitor visitor(
      d->selectionManager.getSelection().getElementReferences(),
      femp_model.load_pattern_list[load_pattern_index], dialog.getForce());

  d->document.getProject().accept(visitor);

  d->document.setDirty();
}

void MainWindow::moveSelectedNodes() {
  qInfo() << "MainWindow::moveSelectedNodes()";

  MoveNodesDialog nd(this);
  if (nd.exec() != QDialog::Accepted) {
    return;
  }

  // get list of node restraints from active window
  ::Selection selection = d->selectionManager.getSelection();
  femp::MoveNodesVisitor visitor(selection.getNodeReferences(), nd.getTranslation());

  d->document.getProject().accept(visitor);

  d->document.setDirty();
}

void MainWindow::editMaterials() {
  qInfo() << "MainWindow::editMaterials()";

  fem::Model &femp_model = d->document.getProject().getModel();
  MaterialsEditorDialog dialog(femp_model, this);
  dialog.exec();
}

void MainWindow::editQuadratureRules() {
  qInfo() << "MainWindow::editQuadratureRules()";

  QuadratureRulesOptionsDialog dialog(d->analysis, this);
  dialog.exec();
}

void MainWindow::editSelection() {
  qInfo() << "MainWindow::editSelection()";

  SelectionDialog dialog(d->document.getProject().getDomainModel(),
                         d->selectionManager, this);
  dialog.exec();

  // signal that a selection changed
  ::Selection selection = d->selectionManager.getSelection();
  emit selectionChanged(selection);
}

void MainWindow::runAnalysis() {
  qInfo() << "MainWindow::runAnalysis()";

  fem::Model &femp_model = d->document.getProject().getModel();

  // check if ther is a load pattern
  if (femp_model.getLoadPatternList().empty()) {
    QMessageBox::critical(this, "No load patterns",
                          "This model doesn't have any load patterns to run");
    return;
  }

  fem::Solver<double> *solver = nullptr;

  // run the AnalysisDialog to get the solver
  AnalysisDialog analysis_dialog(d->loadPatternRepository, this);
  switch (analysis_dialog.exec()) {
  case QDialog::Accepted:
    solver = analysis_dialog.solver();
    if (analysis_dialog.loadPattern() == -1) {
      QMessageBox::critical(this, "No load patterns",
                            "This model doesn't have any load patterns to run");
      return;
    }
    break;

  default:
    return;
    break;
  }

  // runs the analysis
  femp::DefaultProgressIndicator progress;
  AnalysisProgressDialog dialog(this);

  // connect the dialog with the progress indicator
  connect(&progress, &femp::DefaultProgressIndicator::beginSection, &dialog,
          &AnalysisProgressDialog::beginSection);
  connect(&progress, &femp::DefaultProgressIndicator::endSection, &dialog,
          &AnalysisProgressDialog::endSection);
  connect(&progress, &femp::DefaultProgressIndicator::setProgress, &dialog,
          &AnalysisProgressDialog::setProgress);
  connect(&progress, &femp::DefaultProgressIndicator::setMessage, &dialog,
          &AnalysisProgressDialog::setMessage);
  connect(&progress, &femp::DefaultProgressIndicator::setError, &dialog,
          &AnalysisProgressDialog::setError);
  connect(&progress, &femp::DefaultProgressIndicator::finish, &dialog,
          &AnalysisProgressDialog::finish);

  // TODO finish this
  fem::AnalysisResult analysis_result;
  fem::LoadPattern lp =
      femp_model.load_pattern_list[analysis_dialog.loadPattern()];
  d->analysis.set(femp_model, lp, analysis_result, progress, solver);

  auto analysis = [&]() {
    d->analysis.run(femp_model, lp, analysis_result, progress);
  };

  std::thread t(analysis);

  switch (dialog.exec()) {
  case QDialog::Accepted:
    // TODO implement a way to abort the analysis thread if the abort button
    // is pressed
    break;

  default:
    break;
  }
  t.join();

  if (!d->analysis.succeeded()) {
    QMessageBox::critical(this, "No analysis",
                          "There isn't a equation to dump");
    return;
  }

  d->document.getProject().pushAnalysisResult(analysis_result);

  delete solver;

  onAnalysisFinished();
}

void MainWindow::onAnalysisFinished() {
  // set the UI
  this->setUserInterfacePostAnalysis();
  this->createNewPostprocessingWindow();
}

void MainWindow::dumpFemEquation() {
  qInfo() << "MainWindow::dumpEquation()";

  auto &femp_result = d->document.getProject().getAnalysisResults();

  if (femp_result.empty()) {
    QMessageBox::information(this, "No analysis",
                             "There isn't a equation to dump");
    return;
  }

  QFileDialog dialog(this);

  // setup the file dialog
  dialog.setFileMode(QFileDialog::AnyFile);
  dialog.setNameFilter(tr("Octave file (*.oct)"));
  dialog.setDefaultSuffix("oct");
  if (dialog.exec() == QDialog::Rejected) {
    // user cancelled
    return;
  }

  QStringList sl = dialog.selectedFiles();
  QString file_name = sl.at(0);

  femp::application::DumpFemEquationCommand command(femp_result.back(),
                                                   file_name);
  command.execute();
}

void MainWindow::showAnalysisSummary() {
  qInfo() << "MainWindow::showAnalysisSummary()";

  // crude hack
  AnalysisSummaryDialog dialog(
      d->document.getProject().getAnalysisResults().back(), this);
  dialog.exec();
}

void MainWindow::dumpResultsFromSelection() {
  qInfo() << "MainWindow::dumpResultsFromSelection()";

  QFile file;

  // opens the file
  {
    QFileDialog dialog(this);
    dialog.setDirectory(Options::getInstance().getDumpResultsDirectory());
    QStringList sl;

    // setup the file dialog
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setNameFilter(tr("text file (*.txt)"));
    dialog.setDefaultSuffix("txt");
    if (dialog.exec() == QDialog::Rejected) {
      // user cancelled
      return;
    }

    // get the last directory used to dump results
    Options::getInstance().setDumpResultsDirectory(dialog.directory());

    sl = dialog.selectedFiles();
    QString file_name = sl.at(0);

    // check if file already exists
    file.setFileName(file_name);
    if (file.exists()) {
      QMessageBox msgBox;
      msgBox.setText(tr("File already exists"));
      msgBox.setInformativeText(tr("Do you want to overwrite it?"));
      msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
      msgBox.setDefaultButton(QMessageBox::No);
      if (msgBox.exec() == QMessageBox::No) {
        return;
      }
    }
  }

  // prepare the file for dumping
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QMessageBox::critical(this, tr("femp"), tr("Failed to open file"));
    return;
  }

  QTextStream out(&file);
  // dump the text to a text file
  fem::AnalysisResult &femp_result =
      d->document.getProject().getAnalysisResults().back(); // nasty hack

  femp::OutputResultsInNodesCSVVisitor visitor(
      d->selectionManager.getSelection().getNodeReferences(), &femp_result,
      out);

  d->document.getProject().accept(visitor);

  file.close();
}

void MainWindow::showSelection() {
  qInfo() << "MainWindow::showSelection()";
  QMdiSubWindow *mdi_window = d->mdiArea->currentSubWindow();
  if (mdi_window == nullptr) {
    qCritical() << "MainWindow::showSelection(): mdi_window is null";
    return;
  }

  MdiWindow *window = static_cast<MdiWindow *>(mdi_window->widget());
  if (window != nullptr) {
    qCritical() << "MainWindow::showSelection(): indow is null";
    return;
  }

  ::Selection selection = d->selectionManager.getSelection();
  window->showSelection(selection);
}

void MainWindow::showAll() {
  qInfo() << "MainWindow::showAll()";

  QMdiSubWindow *mdi_window = d->mdiArea->currentSubWindow();
  if (mdi_window == nullptr) {
    qCritical() << "MainWindow::showAll(): mdi_window is null";
    return;
  }

  MdiWindow *window = static_cast<MdiWindow *>(mdi_window->widget());
  if (window == nullptr) {
    qCritical() << "MainWindow::showAll(): window is null";
    return;
  }

  window->showAll();
}

void MainWindow::getMessage(QString message) {
  emit informationMessageSent(message);
}

void MainWindow::getWarning(QString message) {
  emit informationMessageSent(message);
}

void MainWindow::getError(QString message) {
  emit informationMessageSent(message);
}

void MainWindow::setTiledWindows() { d->mdiArea->tileSubWindows(); }

void MainWindow::setCascadeWindows() { d->mdiArea->cascadeSubWindows(); }

void MainWindow::createNewViewportWindow() { this->createNewModelWindow(); }

void MainWindow::createNewModelWindow() {
  qInfo() << "MainWindow::createNewModelWindow()";

  ModelWindow *window =
      new ModelWindow(d->document.getProject(), getViewportColors(), this);

  // create the model's MDI window
  QMdiSubWindow *mdi_window = new QMdiSubWindow(d->mdiArea);

  mdi_window->setWidget(window);
  mdi_window->setAttribute(Qt::WA_DeleteOnClose);
  mdi_window->setWindowTitle(tr("Model"));
  mdi_window->showMaximized();

  connect(window, &ModelWindow::selectionChanged, &d->selectionManager,
          &femp::SelectionManager::setSelection);
  connect(window, &ModelWindow::selectionCleared, &d->selectionManager,
          &femp::SelectionManager::clearSelection);

  connect(&d->selectionManager, &femp::SelectionManager::selectionChanged, window,
          &ModelWindow::setSelection);
  connect(&d->selectionManager, &femp::SelectionManager::selectionCleared, window,
          &ModelWindow::clearSelection);
}

void MainWindow::createNewPostprocessingWindow() {
  qInfo() << "MainWindow::createNewPostprocessingWindow()";
  auto &femp_result = d->document.getProject().getAnalysisResults();
  if (femp_result.empty()) {
    qCritical() << "MainWindow::createNewPostprocessingWindow(): tried to set "
                   "a postprocessing window although no results are available";
    return;
  }

  femp::ui::PostprocessingWindow *window = new femp::ui::PostprocessingWindow(
      d->document.getProject(), femp_result.back(), getViewportColors(), this);

  // create the model's MDI window
  QMdiSubWindow *mdi_window = new QMdiSubWindow(d->mdiArea);
  mdi_window->setWidget(window);
  mdi_window->setAttribute(Qt::WA_DeleteOnClose);
  mdi_window->setWindowTitle(tr("Postprocessing"));
  mdi_window->showMaximized();
}

void MainWindow::createNewTensorFieldWindow() {
  qInfo() << "MainWindow::createNewTensorFieldWindow()";
  if (d->document.getProject().getAnalysisResults().empty()) {
    qCritical() << "MainWindow::createNewTensorFieldWindow(): tried to set a "
                   "postprocessing window although no results are available";
    return;
  }

  femp::ui::TensorFieldWindow *window = new femp::ui::TensorFieldWindow(
      d->document.getProject(),
      d->document.getProject().getAnalysisResults().back(), getViewportColors(),
      this);

  // create the model's MDI window
  QMdiSubWindow *mdi_window = new QMdiSubWindow(d->mdiArea);

  mdi_window->setWidget(window);
  mdi_window->setAttribute(Qt::WA_DeleteOnClose);
  mdi_window->setWindowTitle(tr("Tensor field"));
  mdi_window->showMaximized();
}

void MainWindow::createNewAnalysisResultsWindow() {
  qInfo() << "MainWindow::createNewAnalysisResultsWindow()";
  if (d->document.getProject().getAnalysisResults().empty()) {
    qCritical() << __FILE__ << ":" << __LINE__;
    qCritical() << "MainWindow::createNewAnalysisResultWindow(): tried to set "
                   "a results window although there is no result available";
    return;
  }

  AnalysisResultsWindow *mdi_window =
      new AnalysisResultsWindow(d->document.getProject(), d->mdiArea);
  mdi_window->showMaximized();
}

void MainWindow::createNewFemEquationWindow() {
  qInfo() << "MainWindow::createNewFemEquationWindow()";
  if (d->document.getProject().getAnalysisResults().empty()) {
    qCritical() << "MainWindow::createNewFemEquationWindow(): tried to set a "
                   "results window although there is no result available";
    return;
  }

  femp::ui::MatrixWindow *mdi_window = new femp::ui::MatrixWindow(
      d->document.getProject(), d->mdiArea);
  mdi_window->showMaximized();
}

void MainWindow::updateWindowMenu() {
  qInfo() << "MainWindow::updateWindowMenu()";

  // empties the menu
  ui->menuWindowOpened->clear();

  // fills the menu
  QList<QMdiSubWindow *> subWindowList = d->mdiArea->subWindowList();
  for (int n = 0; n < subWindowList.size(); n++) {
    // get current MDI window label
    femp::ui::BaseWindow *base =
        dynamic_cast<femp::ui::BaseWindow *>(subWindowList[n]->widget());
    {
      // TODO fix problem with menu windows
      qCritical() << "MainWindow::updateWindowMenu(): nullptr result";
      continue;
    }

    // set the action name
    QAction *action = new QAction(base->label(), this);
    action->setData(n);
    ui->menuWindowOpened->addAction(action);

    // map
    d->windowMapper->setMapping(action, n);
    connect(action, &QAction::triggered, d->windowMapper,
            QOverload<>::of(&QSignalMapper::map));
    connect(d->windowMapper, &QSignalMapper::mappedInt, this,
            &MainWindow::activateSubWindowByIndex);
  }
}

void MainWindow::activateSubWindowByIndex(int index) {
  QList<QMdiSubWindow *> subWindowList = d->mdiArea->subWindowList();
  d->mdiArea->setActiveSubWindow(subWindowList[index]);
}

void MainWindow::setUserInterfaceAsOpened() {
  // set the menus
  ui->menuProject->setEnabled(true);
  ui->menuView->setEnabled(true);
  ui->menuWindow->setEnabled(true);
  ui->actionReopen->setEnabled(true);
  ui->actionSave->setEnabled(true);
  ui->actionSaveAs->setEnabled(true);
  ui->actionClose->setEnabled(true);
  ui->actionNodeRestraints->setEnabled(true);
  ui->actionNodeActions->setEnabled(true);
  ui->actionDomainLoads->setEnabled(true);
  ui->actionMoveNodes->setEnabled(true);
  ui->actionEditMaterials->setEnabled(true);
  ui->actionQuadrature_rules->setEnabled(true);
  ui->actionSelection->setEnabled(true);

  ui->actionDisplayNodes->setChecked(true);
  ui->actionDisplaySurfaces->setChecked(true);

  this->createNewViewportWindow();

  // set the docks
  this->addDockWidget(static_cast<Qt::DockWidgetArea>(9),
                      d->commandLineDockWidget);

  // set the window name
  if (d->document.isFileNameNotSet())
    this->setWindowTitle("Femp - [unnamed.fem.json]");
  else
    this->setWindowTitle("Femp - " + d->document.getFileName());
}

void MainWindow::setUserInterfaceAsClosed() {
  // set the menus
  ui->menuProject->setDisabled(true);
  ui->menuView->setDisabled(true);
  ui->menuWindow->setDisabled(true);
  ui->menuDump->setDisabled(true);

  ui->actionReopen->setDisabled(true);
  ui->actionSave->setDisabled(true);
  ui->actionSaveAs->setDisabled(true);
  ui->actionClose->setDisabled(true);
  ui->actionNodeRestraints->setDisabled(true);
  ui->actionNodeActions->setDisabled(true);
  ui->actionDomainLoads->setDisabled(true);
  ui->actionMoveNodes->setDisabled(true);
  ui->actionEditMaterials->setDisabled(true);
  ui->actionQuadrature_rules->setDisabled(true);
  ui->actionSelection->setDisabled(true);
  ui->actionDump_FEM_equation->setDisabled(true);
  ui->actionResults_from_selection->setDisabled(true);

  ui->actionNewPostprocessingWindow->setDisabled(true);
  ui->actionNewTensorFieldWindow->setDisabled(true);
  ui->actionNewAnalysisResultsWindow->setDisabled(true);
  ui->actionNewFemEquationWindow->setDisabled(true);
  ui->actionAnalysisSummary->setDisabled(true);

  // close all MDI windows
  d->mdiArea->closeAllSubWindows();

  // handle the docks
  this->removeDockWidget(d->commandLineDockWidget);
  d->commandLineDockWidget->clear();

  // set the window name
  this->setWindowTitle("Femp");
}

void MainWindow::setUserInterfacePostAnalysis() {
  ui->menuDump->setEnabled(true);
  ui->actionDump_FEM_equation->setEnabled(true);
  ui->actionResults_from_selection->setEnabled(true);
  ui->actionNewPostprocessingWindow->setEnabled(true);
  ui->actionNewTensorFieldWindow->setEnabled(true);
  ui->actionNewAnalysisResultsWindow->setEnabled(true);
  ui->actionNewFemEquationWindow->setEnabled(true);
  ui->actionAnalysisSummary->setEnabled(true);
}

::ViewportColors &MainWindow::getViewportColors() { return d->colors; }

} // namespace femp::ui
