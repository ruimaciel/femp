#include "MainWindow.h++"
#include <QAction>
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QProgressDialog>
#include <QString>
#include <QTextStream>
#include <QTime>
#include <QTranslator>

#include <fstream>
#include <stdlib.h> // getenv()
#include <string>
#include <thread>

#include <QDebug>

#include "FempApplication.h++"

#include "ui/models/LoadPatternsModel.h++"

#include "ui/dialogs/AnalysisDialog.h++"
#include "ui/dialogs/AnalysisProgressDialog.h++"
#include "ui/dialogs/AnalysisSummaryDialog.h++"
#include "ui/dialogs/DomainLoadsDialog.h++"
#include "ui/dialogs/MaterialsEditorDialog.h++"
#include "ui/dialogs/MoveNodesDialog.h++"
#include "ui/dialogs/NodeActionsDialog.h++"
#include "ui/dialogs/NodeRestrainsDialog.h++"
#include "ui/dialogs/QuadratureRulesOptionsDialog.h++"
#include "ui/dialogs/SelectionDialog.h++"
#include "ui/wizards/NewProjectWizard.h++"

#include "ui/AnalysisResultsWindow.h++"
#include "ui/MatrixWindow.h++"
#include "ui/MdiWindow.h++"
#include "ui/ModelWindow.h++"
#include "ui/PostprocessingWindow.h++"
#include "ui/TensorFieldWindow.h++"

#include "DefaultProgressIndicator.h++"

#include <libfemp/Analysis.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/LinearAnalysis.h++>
#include <libfemp/Model.h++>
#include <libfemp/NodeRestrictions.h++>
#include <libfemp/io/export/JsonExporter.h++>
#include <libfemp/io/import/ModelImporterFactory.h++>
#include <libfemp/solvers/CGSolver.h++>
#include <libfemp/solvers/CholeskySolver.h++>
#include <persistence/LoadPatternRepository.h++>

#include "ProjectVisitor/MoveNodesVisitor.h++"
#include "ProjectVisitor/OutputElementStatisticsVisitor.h++"
#include "ProjectVisitor/OutputResultsInNodesCSVVisitor.h++"
#include "ProjectVisitor/OutputResultsInNodesVisitor.h++"
#include "ProjectVisitor/SetDomainLoadsVisitor.h++"
#include "ProjectVisitor/SetNodeRestraintsVisitor.h++"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // set the MDI area widget as the window's central widget
    m_mdiArea = new QMdiArea;
    setCentralWidget(m_mdiArea); // this main window has a Multiple Document Interface
    m_windowMapper = new QSignalMapper(this);

    // initialize the member attributes
    this->m_hasUnsavedChanges = false;

    // create actions and connect signals to slots
    this->createActions();
    this->createDockWidgets();

    // set the user interface
    setUserInterfaceAsClosed();
}

void MainWindow::newProject()
{
    // tweak the UI
    setUserInterfaceAsClosed();

    // free everything
    m_document.clear();

    /*
    The NewProjectWizard dialog will fill up a given document object through the steps
    */
    NewProjectWizard np(m_document, this);
    switch (np.exec()) {
    case QDialog::Accepted:
        setUserInterfaceAsOpened();
        break;

    default:
        m_document.clear();
        break;
    }
}

void MainWindow::openProject()
{
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
    this->setUserInterfaceAsClosed();
    this->m_document.clear();
    this->m_selectionManager.clearSelection();

    // prepare the file
    QStringList sl = dialog.selectedFiles();

    QString file_name = sl.at(0);

    std::string my_file_name(sl.at(0).toUtf8());
    std::fstream file;

    file.open(my_file_name, std::fstream::in);
    if (!file) {
        QMessageBox::critical(this, tr("Error"), tr("There was an error opening the file"));
        return;
    }

    fem::Model& model = m_document.getProject().getModel();
    auto parser = fem::ModelImporterFactory::makeFemJsonParser();
    parser->parse(file, model);

    switch (parser->error.code) {
    case Parser::Error::ERR_OK:
        // setup the user interface
        m_document.setProjectType(Document::TYPE_SOLID3D); // nasty hack due to poor design
        this->setUserInterfaceAsOpened();
        break;

    default:
        qCritical() << __FILE__ << ":" << __LINE__;
        qCritical() << QString("Error: %1").arg(QString::fromStdString(parser->error.message));

        QMessageBox::critical(this, tr("Error"), parser->error.message.c_str());
        m_document.clear();
        break;
    }

    m_document.setFileName(file_name);

    OutputElementStatisticsVisitor visit(m_selectionManager.getSelection());
    m_document.getProject().accept(visit);

    file.close();
}

void MainWindow::reopenProject()
{
    if (m_document.isFileNameNotSet()) {
        QMessageBox::critical(this, tr("Error"), tr("This document hasn't been saved to a file"));
        return;
    }

    // clear the document
    setUserInterfaceAsClosed();
    fem::Model& femp_model = this->m_document.getProject().getModel();
    femp_model.clear();
    this->m_selectionManager.clearSelection();

    std::string my_file_name(m_document.getFileName().toUtf8());
    std::fstream file;

    file.open(my_file_name, std::fstream::in);
    if (!file) {
        QMessageBox::critical(this, tr("Error"), tr("There was an error opening the file"));
        m_document.clear();
        return;
    }

    // import the model by parsing the Fem.Json document
    auto parser = fem::ModelImporterFactory::makeFemJsonParser();
    parser->parse(file, femp_model);

    switch (parser->error.code) {
    case Parser::Error::ERR_OK:
        setUserInterfaceAsOpened();
        break;

    default:
        qCritical() << __FILE__ << ":" << __LINE__;
        qCritical() << QString("Error: %1").arg(QString::fromStdString(parser->error.message));

        QMessageBox::critical(this, tr("Error"), parser->error.message.c_str());
        m_document.clear();
        break;
    }

    file.close();
}

void MainWindow::saveProject()
{
    if (m_document.isFileNameNotSet()) {
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

        // set a new file name for this file
        m_document.setFileName(file_name);

        this->setWindowTitle("Femp - " + file_name);
        ui.actionReopen->setEnabled(true);
    }

    saveDocument(m_document, m_document.getFileName().toStdString());
}

void MainWindow::saveProjectAs()
{
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
    m_document.setFileName(file_name);
    saveDocument(m_document, file_name.toStdString());
}

void MainWindow::closeProject()
{
    if (this->m_hasUnsavedChanges) {
        // ask the user if he wants to save the changes
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
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

    // tweak the UI
    setUserInterfaceAsClosed();

    // free everything
    m_document.clear();
    this->m_selectionManager.clearSelection();
}

void MainWindow::quit()
{
    if (this->m_hasUnsavedChanges) {
        // ask the user if he wants to save the changes
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
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

void MainWindow::createActions()
{
    // connect the actions
    connect(ui.actionNew, &QAction::triggered, this, &MainWindow::newProject);
    connect(ui.actionOpen, &QAction::triggered, this, &MainWindow::openProject);
    connect(ui.actionReopen, &QAction::triggered, this, &MainWindow::reopenProject);
    connect(ui.actionSave, &QAction::triggered, this, &MainWindow::saveProject);
    connect(ui.actionSaveAs, &QAction::triggered, this, &MainWindow::saveProjectAs);
    connect(ui.actionClose, &QAction::triggered, this, &MainWindow::closeProject);
    connect(ui.actionQuit, &QAction::triggered, this, &MainWindow::quit);
    connect(ui.actionNodeRestraints, &QAction::triggered, this, &MainWindow::setNodeRestraints);
    connect(ui.actionNodeActions, &QAction::triggered, this, &MainWindow::setNodeActions);
    connect(ui.actionDomainLoads, &QAction::triggered, this, &MainWindow::setDomainLoads);
    connect(ui.actionMoveNodes, &QAction::triggered, this, &MainWindow::moveSelectedNodes);

    connect(ui.actionRun, &QAction::triggered, this, &MainWindow::runAnalysis);
    connect(ui.actionDump_FEM_equation, &QAction::triggered, this, &MainWindow::dumpFemEquation);
    connect(ui.actionAnalysisSummary, &QAction::triggered, this, &MainWindow::showAnalysisSummary);

    connect(ui.actionEditMaterials, &QAction::triggered, this, &MainWindow::editMaterials);

    connect(ui.actionWindowTile, &QAction::triggered, this, &MainWindow::setTiledWindows);
    connect(ui.actionWindowCascade, &QAction::triggered, this, &MainWindow::setCascadeWindows);

    // MDI window creation
    connect(ui.actionNewModelWindow, &QAction::triggered, this, &MainWindow::createNewModelWindow);
    connect(ui.actionNewPostprocessingWindow, &QAction::triggered, this, &MainWindow::createNewPostprocessingWindow);
    connect(ui.actionNewTensorFieldWindow, &QAction::triggered, this, &MainWindow::createNewTensorFieldWindow);
    connect(ui.actionNewAnalysisResultsWindow, &QAction::triggered, this, &MainWindow::createNewAnalysisResultsWindow);
    connect(ui.actionNewFemEquationWindow, &QAction::triggered, this, &MainWindow::createNewFemEquationWindow);

    connect(ui.actionViewSelection, &QAction::triggered, this, &MainWindow::showSelection);
    connect(ui.actionViewAll, &QAction::triggered, this, &MainWindow::showAll);

    connect(ui.actionQuadrature_rules, &QAction::triggered, this, &MainWindow::editQuadratureRules);
    connect(ui.actionSelection, &QAction::triggered, this, &MainWindow::editSelection);
    connect(ui.actionResults_from_selection, &QAction::triggered, this, &MainWindow::dumpResultsFromSelection);

    connect(ui.menuWindowOpened, &QMenu::aboutToShow, this, &MainWindow::updateWindowMenu);
}

void MainWindow::createDockWidgets()
{
    // initialize the Docks
    m_commandLineDockWidget = new CommandLineDockWidget(this);

    // set the MainWindow connections
    connect(this, &MainWindow::setMessage, m_commandLineDockWidget, &CommandLineDockWidget::getMessage);
    connect(this, &MainWindow::setWarning, m_commandLineDockWidget, &CommandLineDockWidget::getWarning);
    connect(this, &MainWindow::setError, m_commandLineDockWidget, &CommandLineDockWidget::getError);

    // add selection dock widget
    this->addDockWidget(Qt::RightDockWidgetArea, m_commandLineDockWidget);
}

void MainWindow::setNodeRestraints()
{
    assert(m_mdiArea != nullptr);

    NodeRestrainsDialog nd;
    if (nd.exec() == QDialog::Accepted) {
        // get list of node restraints from active window
        Selection selection = m_selectionManager.getSelection();
        SetNodeRestraintsVisitor visitor(selection, nd.getRestrictions());

        // set the restraints in the model
        m_document.getProject().accept(visitor);
    }
}

void MainWindow::setNodeActions()
{
    fem::Model& femp_model = m_document.getProject().getModel();
    LoadPatternsModel load_patterns_model(femp_model.getLoadPatternList(), this);

    NodeActionsDialog na(load_patterns_model, this);

    if (na.exec() != QDialog::Accepted) {
        return;
    }

    Selection const selection = m_selectionManager.getSelection();

    // shortcut just to reduce code clutter
    fem::LoadPattern& load_pattern = femp_model.load_pattern_list[na.getLoadPattern()];

    // assign nodal loads
    for (fem::node_ref_t const& node : selection.getNodeReferences()) {
        load_pattern.addNodalLoad(node, na.getForce());
    }
}

void MainWindow::setDomainLoads()
{
    fem::Model& femp_model = m_document.getProject().getModel();

    LoadPatternsModel model(femp_model.getLoadPatternList(), this);

    DomainLoadsDialog dialog(model, this);

    // call the dialog box
    if (dialog.exec() != QDialog::Accepted) {
        return;
    }

    Selection const selection = m_selectionManager.getSelection();

    SetDomainLoadsVisitor visitor(selection, femp_model.load_pattern_list[dialog.getLoadPattern()], dialog.getForce());

    m_document.getProject().accept(visitor);

    m_document.setUnsaved();
}

void MainWindow::moveSelectedNodes()
{
    assert(m_mdiArea != nullptr);

    MoveNodesDialog nd(this);
    if (nd.exec() != QDialog::Accepted) {
        return;
    }

    // get list of node restraints from active window
    Selection selection = m_selectionManager.getSelection();
    MoveNodesVisitor visitor(selection, nd.getTranslation());

    m_document.getProject().accept(visitor);

    m_document.setUnsaved();
}

void MainWindow::editMaterials()
{
    fem::Model& femp_model = m_document.getProject().getModel();
    MaterialsEditorDialog dialog(femp_model, this);
    dialog.exec();
}

void MainWindow::editQuadratureRules()
{
    QuadratureRulesOptionsDialog dialog(m_analysis, this);
    dialog.exec();
}

void MainWindow::editSelection()
{
    SelectionDialog dialog(m_document.getProject().getDomainModel(), m_selectionManager, this);
    dialog.exec();
}

void MainWindow::runAnalysis()
{
    using namespace std;

    fem::Model& femp_model = this->m_document.getProject().getModel();

    // check if ther is a load pattern
    if (femp_model.getLoadPatternList().empty()) {
        QMessageBox::critical(this, "No load patterns", "This model doesn't have any load patterns to run");
        return;
    }

    fem::Solver<double>* solver = nullptr;

    // run the AnalysisDialog to get the solver
    gui::application::ILoadPatternRepositoryPtr load_pattern_repository = std::make_shared<gui::persistence::LoadPatternRepository>(m_document.getProject().getDomainModel());

    AnalysisDialog analysis_dialog(load_pattern_repository, this);
    switch (analysis_dialog.exec()) {
    case QDialog::Accepted:
        solver = analysis_dialog.solver();
        if (analysis_dialog.loadPattern() == -1) {
            QMessageBox::critical(this, "No load patterns", "This model doesn't have any load patterns to run");
            return;
        }
        break;

    default:
        return;
        break;
    }

    // runs the analysis
    DefaultProgressIndicator progress;
    AnalysisProgressDialog dialog(this);

    // connect the dialog with the progress indicator
    connect(&progress, &DefaultProgressIndicator::beginSection, &dialog, &AnalysisProgressDialog::beginSection);
    connect(&progress, &DefaultProgressIndicator::endSection, &dialog, &AnalysisProgressDialog::endSection);
    connect(&progress, &DefaultProgressIndicator::setProgress, &dialog, &AnalysisProgressDialog::setProgress);
    connect(&progress, &DefaultProgressIndicator::setMessage, &dialog, &AnalysisProgressDialog::setMessage);
    connect(&progress, &DefaultProgressIndicator::setError, &dialog, &AnalysisProgressDialog::setError);
    connect(&progress, &DefaultProgressIndicator::finish, &dialog, &AnalysisProgressDialog::finish);

    //TODO finish this
    fem::AnalysisResult analysis_result;
    fem::LoadPattern lp = femp_model.load_pattern_list[analysis_dialog.loadPattern()];
    m_analysis.set(femp_model, lp, analysis_result, progress, solver);

    auto analysis = [&]() {
        m_analysis.run(femp_model, lp, analysis_result, progress);
    };

    std::thread t(analysis);

    switch (dialog.exec()) {
    case QDialog::Accepted:
        //TODO implement a way to abort the analysis thread if the abort button is pressed
        break;

    default:
        break;
    }
    t.join();

    if (m_analysis.succeeded()) {
        m_document.getProject().pushAnalysisResult(analysis_result);

        // set the UI
        this->setUserInterfacePostAnalysis();
        this->createNewPostprocessingWindow();
    } else {
        QMessageBox::critical(this, "No analysis", "There isn't a equation to dump");
    }

    delete solver;
}

void MainWindow::dumpFemEquation()
{
    auto& femp_result = m_document.getProject().getAnalysisResults();

    if (femp_result.empty()) {
        QMessageBox::information(this, "No analysis", "There isn't a equation to dump");
        return;
    }

    using namespace std;

    //TODO pick file name
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
            m_document.clearFileName();
            return;
        }
    }

    // set a new file name for this file

    file.open(QFile::WriteOnly);
    QTextStream out(&file);
    out.setRealNumberNotation(QTextStream::ScientificNotation);
    out.setRealNumberPrecision(16);

    out << "# Created by lalib\n";
    out << "# name: K\n";
    out << "# type: matrix\n";
    out << "# rows: " << femp_result.back().equation.K.rows() << "\n";
    out << "# columns: " << femp_result.back().equation.K.columns() << "\n";

    for (size_t j = 0; j < femp_result.back().equation.K.columns(); j++) {
        for (size_t i = 0; i < femp_result.back().equation.K.rows(); i++) {
            out << " " << femp_result.back().equation.K.value(i, j);
        }
        out << "\n";
    }
    out << endl;

    out << "# Created by lalib\n";
    out << "# name: f\n";
    out << "# type: matrix\n";
    out << "# rows: " << femp_result.back().equation.size() << "\n";
    out << "# columns: 1\n";

    for (size_t i = 0; i < femp_result.back().equation.size(); i++) {
        out << " " << femp_result.back().equation.f.value(i) << "\n";
    }
    out << endl;

    out << "# Created by lalib\n";
    out << "# name: d\n";
    out << "# type: matrix\n";
    out << "# rows: " << femp_result.back().equation.d.size() << "\n";
    out << "# columns: 1\n";

    for (size_t i = 0; i < femp_result.back().equation.d.size(); i++) {
        out << " " << femp_result.back().equation.d.value(i) << "\n";
    }

    out << endl;
    file.close();
}

void MainWindow::showAnalysisSummary()
{
    // crude hack
    AnalysisSummaryDialog dialog(m_document.getProject().getAnalysisResults().back(), this);
    dialog.exec();
}

void MainWindow::dumpResultsFromSelection()
{
    QString file_name;
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
        file_name = sl.at(0);

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
    //dump the text to a text file
    fem::AnalysisResult& femp_result = this->m_document.getProject().getAnalysisResults().back(); // nasty hack

    Selection selection = m_selectionManager.getSelection();

    OutputResultsInNodesCSVVisitor visitor(selection, &femp_result, out);

    m_document.getProject().accept(visitor);

    file.close();
}

void MainWindow::showSelection()
{
    Selection selection = m_selectionManager.getSelection();

    QMdiSubWindow* mdi_window = m_mdiArea->currentSubWindow();
    if (mdi_window != nullptr) {
        MdiWindow* window = static_cast<MdiWindow*>(mdi_window->widget());
        if (window != nullptr) {
            window->showSelection(selection);
        }
    }
}

void MainWindow::showAll()
{
    QMdiSubWindow* mdi_window = m_mdiArea->currentSubWindow();
    if (mdi_window != nullptr) {
        MdiWindow* window = static_cast<MdiWindow*>(mdi_window->widget());
        if (window != nullptr) {
            window->showAll();
        }
    }
}

void MainWindow::getMessage(QString message)
{
    emit setMessage(message);
}

void MainWindow::getWarning(QString message)
{
    emit setMessage(message);
}

void MainWindow::getError(QString message)
{
    emit setMessage(message);
}

void MainWindow::setTiledWindows()
{
    m_mdiArea->tileSubWindows();
}

void MainWindow::setCascadeWindows()
{
    m_mdiArea->cascadeSubWindows();
}

void MainWindow::createNewViewportWindow()
{
    this->createNewModelWindow();
}

void MainWindow::createNewModelWindow()
{
    ModelWindow* window = new ModelWindow(m_document.getProject(), getViewportColors(), this);

    // create the model's MDI window
    QMdiSubWindow* mdi_window = new QMdiSubWindow(m_mdiArea);

    mdi_window->setWidget(window);
    mdi_window->setAttribute(Qt::WA_DeleteOnClose);
    mdi_window->setWindowTitle(tr("Model"));
    mdi_window->showMaximized();

    connect(window, &ModelWindow::selectionChanged, &m_selectionManager, &SelectionManager::setSelection);
    connect(window, &ModelWindow::selectionCleared, &m_selectionManager, &SelectionManager::clearSelection);

    connect(&m_selectionManager, &SelectionManager::selectionChanged, window, &ModelWindow::setSelection);
    connect(&m_selectionManager, &SelectionManager::selectionCleared, window, &ModelWindow::clearSelection);
}

void MainWindow::createNewPostprocessingWindow()
{
    auto& femp_result = m_document.getProject().getAnalysisResults();
    if (femp_result.empty()) {
        qCritical() << __FILE__ << ":" << __LINE__;
        qCritical() << "MainWindow::createNewPostprocessingWindow(): tried to set a postprocessing window although no results are available";
    } else {
        PostprocessingWindow* window = new PostprocessingWindow(m_document.getProject(), femp_result.back(), getViewportColors(), this);

        // create the model's MDI window
        QMdiSubWindow* mdi_window = new QMdiSubWindow(m_mdiArea);
        mdi_window->setWidget(window);
        mdi_window->setAttribute(Qt::WA_DeleteOnClose);
        mdi_window->setWindowTitle(tr("Postprocessing"));
        mdi_window->showMaximized();
    }
}

void MainWindow::createNewTensorFieldWindow()
{
    if (m_document.getProject().getAnalysisResults().empty()) {
        qCritical() << __FILE__ << ":" << __LINE__;
        qCritical() << "MainWindow::createNewPostprocessingWindow(): tried to set a postprocessing window although no results are available";
    } else {
        TensorFieldWindow* window = new TensorFieldWindow(m_document.getProject(), m_document.getProject().getAnalysisResults().back(), getViewportColors(), this);

        // create the model's MDI window
        QMdiSubWindow* mdi_window = new QMdiSubWindow(m_mdiArea);

        mdi_window->setWidget(window);
        mdi_window->setAttribute(Qt::WA_DeleteOnClose);
        mdi_window->setWindowTitle(tr("Tensor field"));
        mdi_window->showMaximized();
    }
}

void MainWindow::createNewAnalysisResultsWindow()
{
    qCritical() << __FILE__ << ":" << __LINE__;
    qCritical() << "MainWindow::createNewAnalysisResultsWindow()";
    if (m_document.getProject().getAnalysisResults().empty()) {
        qCritical() << __FILE__ << ":" << __LINE__;
        qCritical() << "MainWindow::createNewAnalysisResultWindow(): tried to set a results window although there is no result available";
        return;
    }

    AnalysisResultsWindow* mdi_window = new AnalysisResultsWindow(m_document.getProject(), m_mdiArea);
    mdi_window->showMaximized();
}

void MainWindow::createNewFemEquationWindow()
{
    qCritical() << __FILE__ << ":" << __LINE__;
    qCritical() << "MainWindow::createNewFemEquationWindow()";
    if (m_document.getProject().getAnalysisResults().empty()) {
        qCritical() << "MainWindow::createNewFemEquationWindow(): tried to set a results window although there is no result available";
        return;
    }

    MatrixWindow* mdi_window = new MatrixWindow(m_document.getProject(), m_mdiArea);
    mdi_window->showMaximized();
}

void MainWindow::updateWindowMenu()
{
    qWarning("MainWindow::updateWindowMenu()");

    QList<QMdiSubWindow*> subWindowList = m_mdiArea->subWindowList();

    // empties the menu
    ui.menuWindowOpened->clear();

    // fills the menu
    QAction* action;
    //for(QList<QMdiSubWindow *>::const_iterator subwindow = subWindowList.begin(); subwindow != subWindowList.end(); subwindow++)
    for (int n = 0; n < subWindowList.size(); n++) {
        // get current MDI window label
        BaseWindow* base = dynamic_cast<BaseWindow*>(subWindowList[n]->widget());
        {
            //TODO fix problem with menu windows
            qCritical() << "MainWindow::updateWindowMenu(): nullptr result";
            continue;
        }

        // set the action name
        action = new QAction(base->label(), this);
        action->setData(n);
        ui.menuWindowOpened->addAction(action);

        // map
        m_windowMapper->setMapping(action, n);
        connect(action, SIGNAL(triggered()), m_windowMapper, SLOT(map()));
        connect(m_windowMapper, SIGNAL(mapped(int)), this, SLOT(activateSubWindowByIndex(int)));
    }
}

void MainWindow::activateSubWindowByIndex(int index)
{
    QList<QMdiSubWindow*> subWindowList = m_mdiArea->subWindowList();
    this->m_mdiArea->setActiveSubWindow(subWindowList[index]);
}

void MainWindow::setUserInterfaceAsOpened()
{
    // set the menus
    ui.menuProject->setEnabled(true);
    ui.menuView->setEnabled(true);
    ui.menuWindow->setEnabled(true);
    ui.actionReopen->setEnabled(true);
    ui.actionSave->setEnabled(true);
    ui.actionSaveAs->setEnabled(true);
    ui.actionClose->setEnabled(true);
    ui.actionNodeRestraints->setEnabled(true);
    ui.actionNodeActions->setEnabled(true);
    ui.actionDomainLoads->setEnabled(true);
    ui.actionMoveNodes->setEnabled(true);
    ui.actionEditMaterials->setEnabled(true);
    ui.actionQuadrature_rules->setEnabled(true);
    ui.actionSelection->setEnabled(true);

    ui.actionDisplayNodes->setChecked(true);
    ui.actionDisplaySurfaces->setChecked(true);

    this->createNewViewportWindow();

    // set the docks
    this->addDockWidget(static_cast<Qt::DockWidgetArea>(9), m_commandLineDockWidget);

    // set the window name
    if (m_document.isFileNameNotSet())
        this->setWindowTitle("Femp - [unnamed.fem.json]");
    else
        this->setWindowTitle("Femp - " + m_document.getFileName());
}

void MainWindow::setUserInterfaceAsClosed()
{
    // set the menus
    ui.menuProject->setDisabled(true);
    ui.menuView->setDisabled(true);
    ui.menuWindow->setDisabled(true);
    ui.menuDump->setDisabled(true);

    ui.actionReopen->setDisabled(true);
    ui.actionSave->setDisabled(true);
    ui.actionSaveAs->setDisabled(true);
    ui.actionClose->setDisabled(true);
    ui.actionNodeRestraints->setDisabled(true);
    ui.actionNodeActions->setDisabled(true);
    ui.actionDomainLoads->setDisabled(true);
    ui.actionMoveNodes->setDisabled(true);
    ui.actionEditMaterials->setDisabled(true);
    ui.actionQuadrature_rules->setDisabled(true);
    ui.actionSelection->setDisabled(true);
    ui.actionDump_FEM_equation->setDisabled(true);
    ui.actionResults_from_selection->setDisabled(true);

    ui.actionNewPostprocessingWindow->setDisabled(true);
    ui.actionNewTensorFieldWindow->setDisabled(true);
    ui.actionNewAnalysisResultsWindow->setDisabled(true);
    ui.actionNewFemEquationWindow->setDisabled(true);
    ui.actionAnalysisSummary->setDisabled(true);

    // close all MDI windows
    m_mdiArea->closeAllSubWindows();

    // handle the docks
    this->removeDockWidget(m_commandLineDockWidget);
    m_commandLineDockWidget->clear();

    // set the window name
    this->setWindowTitle("Femp");
}

void MainWindow::setUserInterfacePostAnalysis()
{
    ui.menuDump->setEnabled(true);
    ui.actionDump_FEM_equation->setEnabled(true);
    ui.actionResults_from_selection->setEnabled(true);
    ui.actionNewPostprocessingWindow->setEnabled(true);
    ui.actionNewTensorFieldWindow->setEnabled(true);
    ui.actionNewAnalysisResultsWindow->setEnabled(true);
    ui.actionNewFemEquationWindow->setEnabled(true);
    ui.actionAnalysisSummary->setEnabled(true);
}

ViewportColors& MainWindow::getViewportColors()
{
    return m_colors;
}

void MainWindow::saveDocument(Document& doc, std::string file_name)
{
    // check if if the given file_name exists
    std::ofstream out;
    out.open(file_name, std::ios::out | std::ios::trunc);

    JsonExporter exporter;
    exporter.output(out, doc.getProject().getModel());

    // cleanup and exit
    // TODO see KDE/ext4 row on proper unix file_name writing
    out.flush();
    out.close();

    doc.setUnsaved(false);
    m_hasUnsavedChanges = false;
}
