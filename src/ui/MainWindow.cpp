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
#include "ui/models/LoadPatternsModel.hpp"
#include "ui/wizards/NewProjectWizard.hpp"

// libfemp includes
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

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>()) {
	ui->setupUi(this);

	// set the MDI area widget as the window's central widget
	m_mdiArea = new QMdiArea();
	setCentralWidget(m_mdiArea);  // this main window has a Multiple Document Interface
	m_windowMapper = new QSignalMapper(this);

	// create actions and connect signals to slots
	this->createActions();
	this->createDockWidgets();

	// set the user interface
	setUserInterfaceAsClosed();
	m_load_pattern_repository = std::make_shared<gui::persistence::LoadPatternRepository>(m_document.getProject().getDomainModel());
}

MainWindow::~MainWindow() = default;

void MainWindow::setSelection(Selection) {}

void MainWindow::clearSelection() {}

void MainWindow::newProject() {
	qInfo() << "MainWindow::newProject()";

	// tweak the UI
	setUserInterfaceAsClosed();

	// free everything
	m_document.clear();

	// The NewProjectWizard dialog will fill up a given document object through
	// the steps
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

void MainWindow::importProjectFromJsonFile(QString file_name) {
	std::fstream file;
	file.open(file_name.toStdString(), std::fstream::in);

	// TODO react to failed file open

	fem::Model& model = m_document.getProject().getModel();
	model.clear();
	auto parser = fem::ModelImporterFactory::makeFemJsonParser();
	parser->parse(file, model);

	switch (parser->error.code) {
		case Parser::Error::ERR_OK:
			// setup the user interface
			m_document.setProjectType(Document::TYPE_SOLID3D);	// nasty hack due to poor design
			setUserInterfaceAsOpened();
			break;

		default:
			qCritical() << __FILE__ << ":" << __LINE__;
			qCritical() << QString("Error: %1").arg(QString::fromStdString(parser->error.message));

			QMessageBox::critical(this, tr("Error"), parser->error.message.c_str());
			m_document.clear();
			break;
	}

	m_document.setFileName(file_name);

	OutputElementStatisticsVisitor visit;
	m_document.getProject().accept(visit);
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
	this->setUserInterfaceAsClosed();
	this->m_document.clear();
	this->m_selectionManager.clearSelection();

	// prepare the file
	QStringList sl = dialog.selectedFiles();
	QString file_name = sl.at(0);

	importProjectFromJsonFile(file_name);
}

void MainWindow::reopenProject() {
	qInfo() << "MainWindow::reopenProject()";

	if (m_document.isFileNameNotSet()) {
		QMessageBox::critical(this, tr("Error"), tr("This document hasn't been saved to a file"));
		return;
	}

	// clear the document
	setUserInterfaceAsClosed();
	this->m_selectionManager.clearSelection();

	std::string file_name(m_document.getFileName().toUtf8());
	importProjectFromJsonFile(QString::fromStdString(file_name));
}

static void saveDocument(Document& doc, std::string file_name) {
	gui::application::SaveDocumentCommand command(doc.getProject().getModel(), file_name);
	command.execute();

	doc.setDirty(false);
}

void MainWindow::saveProject() {
	qInfo() << "MainWindow::saveProject()";

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
		ui->actionReopen->setEnabled(true);
	}

	saveDocument(m_document, m_document.getFileName().toStdString());
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
	m_document.setFileName(file_name);
	saveDocument(m_document, file_name.toStdString());
}

void MainWindow::closeProject() {
	qInfo() << "MainWindow::closeProject()";

	if (m_document.isDirty()) {
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
				return;	 // exit and do nothing
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

void MainWindow::quit() {
	qInfo() << "MainWindow::quit()";

	if (m_document.isDirty()) {
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
				return;	 // exit and do nothing
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
	connect(ui->actionReopen, &QAction::triggered, this, &MainWindow::reopenProject);
	connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveProject);
	connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::saveProjectAs);
	connect(ui->actionClose, &QAction::triggered, this, &MainWindow::closeProject);
	connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::quit);
	connect(ui->actionNodeRestraints, &QAction::triggered, this, &MainWindow::setNodeRestraints);
	connect(ui->actionNodeActions, &QAction::triggered, this, &MainWindow::setNodeActions);
	connect(ui->actionDomainLoads, &QAction::triggered, this, &MainWindow::setDomainLoads);
	connect(ui->actionMoveNodes, &QAction::triggered, this, &MainWindow::moveSelectedNodes);

	connect(ui->actionRun, &QAction::triggered, this, &MainWindow::runAnalysis);
	connect(ui->actionDump_FEM_equation, &QAction::triggered, this, &MainWindow::dumpFemEquation);
	connect(ui->actionAnalysisSummary, &QAction::triggered, this, &MainWindow::showAnalysisSummary);

	connect(ui->actionEditMaterials, &QAction::triggered, this, &MainWindow::editMaterials);

	connect(ui->actionWindowTile, &QAction::triggered, this, &MainWindow::setTiledWindows);
	connect(ui->actionWindowCascade, &QAction::triggered, this, &MainWindow::setCascadeWindows);

	// MDI window creation
	connect(ui->actionNewModelWindow, &QAction::triggered, this, &MainWindow::createNewModelWindow);
	connect(ui->actionNewPostprocessingWindow, &QAction::triggered, this, &MainWindow::createNewPostprocessingWindow);
	connect(ui->actionNewTensorFieldWindow, &QAction::triggered, this, &MainWindow::createNewTensorFieldWindow);
	connect(ui->actionNewAnalysisResultsWindow, &QAction::triggered, this, &MainWindow::createNewAnalysisResultsWindow);
	connect(ui->actionNewFemEquationWindow, &QAction::triggered, this, &MainWindow::createNewFemEquationWindow);

	connect(ui->actionViewSelection, &QAction::triggered, this, &MainWindow::showSelection);
	connect(ui->actionViewAll, &QAction::triggered, this, &MainWindow::showAll);

	connect(ui->actionQuadrature_rules, &QAction::triggered, this, &MainWindow::editQuadratureRules);
	connect(ui->actionSelection, &QAction::triggered, this, &MainWindow::editSelection);
	connect(ui->actionResults_from_selection, &QAction::triggered, this, &MainWindow::dumpResultsFromSelection);

	connect(ui->menuWindowOpened, &QMenu::aboutToShow, this, &MainWindow::updateWindowMenu);
}

void MainWindow::createDockWidgets() {
	// initialize the Docks
	m_commandLineDockWidget = new CommandLineDockWidget(this);

	// set the MainWindow connections
	connect(this, &MainWindow::informationMessageSent, m_commandLineDockWidget, &CommandLineDockWidget::getMessage);
	connect(this, &MainWindow::warningMessageSent, m_commandLineDockWidget, &CommandLineDockWidget::getWarning);
	connect(this, &MainWindow::errorMessageSent, m_commandLineDockWidget, &CommandLineDockWidget::getError);

	// add selection dock widget
	this->addDockWidget(Qt::RightDockWidgetArea, m_commandLineDockWidget);
}

void MainWindow::setNodeRestraints() {
	qInfo() << "MainWindow::setNodeRestraints()";

	assert(m_mdiArea != nullptr);

	NodeRestrainsDialog nd;
	if (nd.exec() != QDialog::Accepted) {
		return;
	}

	SetNodeRestraintsVisitor visitor(m_selectionManager.getSelection().getNodeReferences(), nd.getRestrictions());

	// set the restraints in the model
	m_document.getProject().accept(visitor);
}

void MainWindow::setNodeActions() {
	qInfo() << "MainWindow::setNodeActions()";

	LoadPatternsModel load_patterns_model(m_load_pattern_repository, this);

	NodeActionsDialog na(load_patterns_model, this);
	if (na.exec() != QDialog::Accepted) {
		return;
	}

	Selection const selection = m_selectionManager.getSelection();

	// shortcut just to reduce code clutter
	fem::Model& femp_model = m_document.getProject().getModel();
	auto load_pattern_index = na.getLoadPattern();
	fem::LoadPattern& load_pattern = femp_model.load_pattern_list[load_pattern_index];

	// assign nodal loads
	for (fem::node_ref_t const& node : selection.getNodeReferences()) {
		load_pattern.addNodalLoad(node, na.getForce());
	}
}

void MainWindow::setDomainLoads() {
	qInfo() << "MainWindow::setDomainLoads()";

	LoadPatternsModel model(m_load_pattern_repository, this);

	DomainLoadsDialog dialog(model, this);

	// call the dialog box
	if (dialog.exec() != QDialog::Accepted) {
		return;
	}

	fem::Model& femp_model = m_document.getProject().getModel();
	auto load_pattern_index = dialog.getLoadPattern();
	SetDomainLoadsVisitor visitor(m_selectionManager.getSelection().getElementReferences(), femp_model.load_pattern_list[load_pattern_index],
								  dialog.getForce());

	m_document.getProject().accept(visitor);

	m_document.setDirty();
}

void MainWindow::moveSelectedNodes() {
	qInfo() << "MainWindow::moveSelectedNodes()";

	MoveNodesDialog nd(this);
	if (nd.exec() != QDialog::Accepted) {
		return;
	}

	// get list of node restraints from active window
	Selection selection = m_selectionManager.getSelection();
	MoveNodesVisitor visitor(selection.getNodeReferences(), nd.getTranslation());

	m_document.getProject().accept(visitor);

	m_document.setDirty();
}

void MainWindow::editMaterials() {
	qInfo() << "MainWindow::editMaterials()";

	fem::Model& femp_model = m_document.getProject().getModel();
	MaterialsEditorDialog dialog(femp_model, this);
	dialog.exec();
}

void MainWindow::editQuadratureRules() {
	qInfo() << "MainWindow::editQuadratureRules()";

	QuadratureRulesOptionsDialog dialog(m_analysis, this);
	dialog.exec();
}

void MainWindow::editSelection() {
	qInfo() << "MainWindow::editSelection()";

	SelectionDialog dialog(m_document.getProject().getDomainModel(), m_selectionManager, this);
	dialog.exec();

	// signal that a selection changed
	Selection selection = m_selectionManager.getSelection();
	emit selectionChanged(selection);
}

void MainWindow::runAnalysis() {
	qInfo() << "MainWindow::runAnalysis()";

	using namespace std;

	fem::Model& femp_model = this->m_document.getProject().getModel();

	// check if ther is a load pattern
	if (femp_model.getLoadPatternList().empty()) {
		QMessageBox::critical(this, "No load patterns", "This model doesn't have any load patterns to run");
		return;
	}

	fem::Solver<double>* solver = nullptr;

	// run the AnalysisDialog to get the solver
	AnalysisDialog analysis_dialog(m_load_pattern_repository, this);
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

	// TODO finish this
	fem::AnalysisResult analysis_result;
	fem::LoadPattern lp = femp_model.load_pattern_list[analysis_dialog.loadPattern()];
	m_analysis.set(femp_model, lp, analysis_result, progress, solver);

	auto analysis = [&]() { m_analysis.run(femp_model, lp, analysis_result, progress); };

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

	if (!m_analysis.succeeded()) {
		QMessageBox::critical(this, "No analysis", "There isn't a equation to dump");
		return;
	}

	m_document.getProject().pushAnalysisResult(analysis_result);

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

	auto& femp_result = m_document.getProject().getAnalysisResults();

	if (femp_result.empty()) {
		QMessageBox::information(this, "No analysis", "There isn't a equation to dump");
		return;
	}

	using namespace std;

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

	gui::application::DumpFemEquationCommand command(femp_result.back(), file_name);
	command.execute();
}

void MainWindow::showAnalysisSummary() {
	qInfo() << "MainWindow::showAnalysisSummary()";

	// crude hack
	AnalysisSummaryDialog dialog(m_document.getProject().getAnalysisResults().back(), this);
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
	fem::AnalysisResult& femp_result = this->m_document.getProject().getAnalysisResults().back();  // nasty hack

	OutputResultsInNodesCSVVisitor visitor(m_selectionManager.getSelection().getNodeReferences(), &femp_result, out);

	m_document.getProject().accept(visitor);

	file.close();
}

void MainWindow::showSelection() {
	qInfo() << "MainWindow::showSelection()";
	QMdiSubWindow* mdi_window = m_mdiArea->currentSubWindow();
	if (mdi_window == nullptr) {
		qCritical() << "MainWindow::showSelection(): mdi_window is null";
		return;
	}

	MdiWindow* window = static_cast<MdiWindow*>(mdi_window->widget());
	if (window != nullptr) {
		qCritical() << "MainWindow::showSelection(): indow is null";
		return;
	}

	Selection selection = m_selectionManager.getSelection();
	window->showSelection(selection);
}

void MainWindow::showAll() {
	qInfo() << "MainWindow::showAll()";

	QMdiSubWindow* mdi_window = m_mdiArea->currentSubWindow();
	if (mdi_window == nullptr) {
		qCritical() << "MainWindow::showAll(): mdi_window is null";
		return;
	}

	MdiWindow* window = static_cast<MdiWindow*>(mdi_window->widget());
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

void MainWindow::setTiledWindows() {
	m_mdiArea->tileSubWindows();
}

void MainWindow::setCascadeWindows() {
	m_mdiArea->cascadeSubWindows();
}

void MainWindow::createNewViewportWindow() {
	this->createNewModelWindow();
}

void MainWindow::createNewModelWindow() {
	qInfo() << "MainWindow::createNewModelWindow()";

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

void MainWindow::createNewPostprocessingWindow() {
	qInfo() << "MainWindow::createNewPostprocessingWindow()";
	auto& femp_result = m_document.getProject().getAnalysisResults();
	if (femp_result.empty()) {
		qCritical() << "MainWindow::createNewPostprocessingWindow(): tried to set "
					   "a postprocessing window although no results are available";
		return;
	}

	PostprocessingWindow* window = new PostprocessingWindow(m_document.getProject(), femp_result.back(), getViewportColors(), this);

	// create the model's MDI window
	QMdiSubWindow* mdi_window = new QMdiSubWindow(m_mdiArea);
	mdi_window->setWidget(window);
	mdi_window->setAttribute(Qt::WA_DeleteOnClose);
	mdi_window->setWindowTitle(tr("Postprocessing"));
	mdi_window->showMaximized();
}

void MainWindow::createNewTensorFieldWindow() {
	qInfo() << "MainWindow::createNewTensorFieldWindow()";
	if (m_document.getProject().getAnalysisResults().empty()) {
		qCritical() << "MainWindow::createNewTensorFieldWindow(): tried to set a "
					   "postprocessing window although no results are available";
		return;
	}

	TensorFieldWindow* window = new TensorFieldWindow(m_document.getProject(), m_document.getProject().getAnalysisResults().back(), getViewportColors(), this);

	// create the model's MDI window
	QMdiSubWindow* mdi_window = new QMdiSubWindow(m_mdiArea);

	mdi_window->setWidget(window);
	mdi_window->setAttribute(Qt::WA_DeleteOnClose);
	mdi_window->setWindowTitle(tr("Tensor field"));
	mdi_window->showMaximized();
}

void MainWindow::createNewAnalysisResultsWindow() {
	qInfo() << "MainWindow::createNewAnalysisResultsWindow()";
	if (m_document.getProject().getAnalysisResults().empty()) {
		qCritical() << __FILE__ << ":" << __LINE__;
		qCritical() << "MainWindow::createNewAnalysisResultWindow(): tried to set "
					   "a results window although there is no result available";
		return;
	}

	AnalysisResultsWindow* mdi_window = new AnalysisResultsWindow(m_document.getProject(), m_mdiArea);
	mdi_window->showMaximized();
}

void MainWindow::createNewFemEquationWindow() {
	qInfo() << "MainWindow::createNewFemEquationWindow()";
	if (m_document.getProject().getAnalysisResults().empty()) {
		qCritical() << "MainWindow::createNewFemEquationWindow(): tried to set a "
					   "results window although there is no result available";
		return;
	}

	MatrixWindow* mdi_window = new MatrixWindow(m_document.getProject(), m_mdiArea);
	mdi_window->showMaximized();
}

void MainWindow::updateWindowMenu() {
	qInfo() << "MainWindow::updateWindowMenu()";

	QList<QMdiSubWindow*> subWindowList = m_mdiArea->subWindowList();

	// empties the menu
	ui->menuWindowOpened->clear();

	// fills the menu
	QAction* action;
	// for(QList<QMdiSubWindow *>::const_iterator subwindow =
	// subWindowList.begin(); subwindow != subWindowList.end(); subwindow++)
	for (int n = 0; n < subWindowList.size(); n++) {
		// get current MDI window label
		BaseWindow* base = dynamic_cast<BaseWindow*>(subWindowList[n]->widget());
		{
			// TODO fix problem with menu windows
			qCritical() << "MainWindow::updateWindowMenu(): nullptr result";
			continue;
		}

		// set the action name
		action = new QAction(base->label(), this);
		action->setData(n);
		ui->menuWindowOpened->addAction(action);

		// map
		m_windowMapper->setMapping(action, n);
		connect(action, &QAction::triggered, m_windowMapper, QOverload<>::of(&QSignalMapper::map));
		connect(m_windowMapper, &QSignalMapper::mappedInt, this, &MainWindow::activateSubWindowByIndex);
	}
}

void MainWindow::activateSubWindowByIndex(int index) {
	QList<QMdiSubWindow*> subWindowList = m_mdiArea->subWindowList();
	this->m_mdiArea->setActiveSubWindow(subWindowList[index]);
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
	this->addDockWidget(static_cast<Qt::DockWidgetArea>(9), m_commandLineDockWidget);

	// set the window name
	if (m_document.isFileNameNotSet())
		this->setWindowTitle("Femp - [unnamed.fem.json]");
	else
		this->setWindowTitle("Femp - " + m_document.getFileName());
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
	m_mdiArea->closeAllSubWindows();

	// handle the docks
	this->removeDockWidget(m_commandLineDockWidget);
	m_commandLineDockWidget->clear();

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

ViewportColors& MainWindow::getViewportColors() {
	return m_colors;
}
