#include "MainWindow.h++"
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QTime>
#include <QTranslator>
#include <QString>
#include <QTextStream>
#include <QProgressDialog>

#include <thread>
#include <string>
#include <fstream>
#include <iostream>	// for cout. remove after tests
#include <stdlib.h>	// getenv()

#include "FempApplication.h++"

#include "ui/LoadPatternsModel.h++"

#include "ui/wizards/NewProjectWizard.h++"
#include "ui/dialogs/NodeRestrainsDialog.h++"
#include "ui/dialogs/NodeActionsDialog.h++"
#include "ui/dialogs/DisplayOptionsDialog.h++"
#include "ui/dialogs/DomainLoadsDialog.h++"
#include "ui/dialogs/MaterialsEditorDialog.h++"
#include "ui/dialogs/QuadratureRulesOptionsDialog.h++"
#include "ui/dialogs/SelectionDialog.h++"
#include "ui/dialogs/AnalysisProgressDialog.h++"
#include "ui/dialogs/AnalysisDialog.h++"
#include "ui/dialogs/MoveNodesDialog.h++"
#include "ui/dialogs/AnalysisSummaryDialog.h++"

#include "ui/MdiWindow.h++"
#include "ui/ModelWindow.h++"
#include "ui/PostprocessingWindow.h++"
#include "ui/TensorFieldWindow.h++"
#include "ui/AnalysisResultsWindow.h++"
#include "ui/MatrixWindow.h++"


#include "DefaultProgressIndicator.h++"

#include <libfemp/NodeRestrictions.h++>
#include <libfemp/Analysis.h++>
#include <libfemp/LinearAnalysis.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/solvers/CholeskySolver.h++>
#include <libfemp/solvers/CGSolver.h++>
#include <libfemp/parsers/FemJsonParser.h++>
#include <libfemp/parsers/MshParser.h++>
#include <libfemp/parsers/json.h>
#include <libfemp/parsers/fem_msh.h++>
#include <libfemp/export/JsonExporter.h++>

#include "ProjectVisitor/OutputResultsInNodesVisitor.h++"
#include "ProjectVisitor/OutputResultsInNodesCSVVisitor.h++"
#include "ProjectVisitor/SetNodeRestraintsVisitor.h++"
#include "ProjectVisitor/SetDomainLoadsVisitor.h++"
#include "ProjectVisitor/MoveNodesVisitor.h++"
#include "ProjectVisitor/OutputElementStatisticsVisitor.h++"

#include "FempSettings.h++"




MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// set the MDI area widget as the window's central widget
	m_mdiArea = new QMdiArea;
	setCentralWidget(m_mdiArea);	// this main window has a Multiple Document Interface
	m_windowMapper = new QSignalMapper(this);

	// Load global options from the options files
	this->loadOptions();

	// initialize the member attributes
	this->m_hasUnsavedChanges = false;

	// create actions and connect signals to slots
	this->createActions();
	this->createDockWidgets();

	// set the user interface
	setUserInterfaceAsClosed();
}


void
MainWindow::newProject()
{
	// tweak the UI
	setUserInterfaceAsClosed();

	// free everything
	m_document.clear();

	/*
	The NewProjectWizard dialog will fill up a given document object through the steps
	*/
	NewProjectWizard np(m_document, this);
	switch(np.exec())
	{
	case QDialog::Accepted:
		setUserInterfaceAsOpened();
		break;

	default:
		m_document.clear();
		break;
	}
}


void
MainWindow::openProject()
{
	// get the last dir where a project was opened
	QFileDialog dialog(this);

	QDir file_dialog_directory = FempSettings::getInstance().getProjectOpenDirectory();
	dialog.setDirectory(file_dialog_directory);

	// setup the file dialog
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilter(tr("FEM project (*.fem.json)"));
	if(dialog.exec() == QDialog::Rejected)
	{
		// user cancelled, no file was loaded
		return;
	}

	file_dialog_directory = dialog.directory();
	FempSettings::getInstance().setProjectOpenDirectory(file_dialog_directory);


	// clear the document
	this->setUserInterfaceAsClosed();
	this->m_document.clear();
	this->m_selectionManager.clearSelection();

	// prepare the file
	QStringList sl = dialog.selectedFiles();

	QString file_name = sl.at(0);

	std::string my_file_name( sl.at(0).toUtf8() );
	std::fstream file;

	file.open(my_file_name, std::fstream::in);
	if(!file)
	{
		QMessageBox::critical(this, tr("Error"), tr("There was an error opening the file"));
		return;
	}

	FemJsonParser parser;
	fem::Model &model = m_document.getProject().getModel();
	parser.parse(file, model);

	switch(parser.error.code)
	{
	case FemJsonParser::Error::ERR_OK:
		// setup the user interface
		m_document.setProjectType( Document::TYPE_SOLID3D);	// nasty hack due to poor design
		this->setUserInterfaceAsOpened();
		break;

	default:
		std::cerr << __FILE__ << ":" << __LINE__ ;
		std::cerr << "Error: " << parser.error.message << std::endl;
		QMessageBox::critical(this, tr("Error"), parser.error.message.c_str());
		m_document.clear();
		break;
	}

	m_document.setFileName(file_name);

	OutputElementStatisticsVisitor visit(m_selectionManager.getSelection());
	m_document.getProject().accept(visit);

	file.close();
}


void
MainWindow::reopenProject()
{
	if(m_document.file_name != nullptr)
	{
		// clear the document
		setUserInterfaceAsClosed();
		fem::Model &femp_model = this->m_document.getProject().getModel();
		femp_model.clear();
		this->m_selectionManager.clearSelection();

		std::string my_file_name( m_document.file_name->toUtf8() );
		std::fstream file;

		file.open(my_file_name, std::fstream::in);
		if(!file)
		{
			QMessageBox::critical(this, tr("Error"), tr("There was an error opening the file"));
			m_document.clear();
			return;
		}

		FemJsonParser parser;
		parser.parse(file, femp_model);

		switch(parser.error.code)
		{
		case FemJsonParser::Error::ERR_OK:
			setUserInterfaceAsOpened();
			break;

		default:
			std::cerr << __FILE__ << ":" << __LINE__ ;
			std::cerr << "Error: " << parser.error.message << std::endl;
			QMessageBox::critical(this, tr("Error"), parser.error.message.c_str());
			m_document.clear();
			break;
		}


		file.close();
	}
	else
	{
		QMessageBox::critical(this, tr("Error"), tr("This document hasn't been saved to a file"));
	}
}


void
MainWindow::saveProject()
{
	if(m_document.file_name == nullptr)
	{
		QFileDialog dialog(this);
		QDir file_dialog_directory = FempSettings::getInstance().getProjectOpenDirectory();
		dialog.setDirectory(file_dialog_directory);

		// setup the file dialog
		dialog.setFileMode(QFileDialog::AnyFile);
		dialog.setNameFilter(tr("FEM project (*.fem.json)"));
		dialog.setDefaultSuffix("fem.json");
		if(dialog.exec() == QDialog::Rejected)
		{
			// user cancelled
			return;
		}

		QStringList sl;
		sl = dialog.selectedFiles();
		QString file_name = sl.at(0);

		// check if file already exists
		QFile file;
		file.setFileName(file_name);

		if(file.exists())
		{
			QMessageBox msgBox;
			msgBox.setText(tr("File already exists") );
			msgBox.setInformativeText(tr("Do you want to overwrite it?") );
			msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
			msgBox.setDefaultButton(QMessageBox::No);
			if(msgBox.exec() == QMessageBox::No)
			{
				return;
			}
		}

		// set a new file name for this file
		m_document.setFileName(file_name);

		this->setWindowTitle("Femp - " + file_name );
		ui.actionReopen->setEnabled(true);
	}

	saveDocument(m_document, (*m_document.file_name).toStdString());
}


void
MainWindow::saveProjectAs()
{
	QFileDialog dialog(this);

	QDir file_dialog_directory = FempSettings::getInstance().getProjectOpenDirectory();
	dialog.setDirectory(file_dialog_directory);

	// setup the file dialog
	dialog.setFileMode(QFileDialog::AnyFile);
	dialog.setNameFilter(tr("FEM project (*.fem.json)"));
	dialog.setDefaultSuffix("fem.json");
	if(dialog.exec() == QDialog::Rejected)
	{
		// user cancelled
		return;
	}

	QStringList sl;
	sl = dialog.selectedFiles();

	QString file_name = sl.at(0);

	// check if file already exists
	QFile file;
	file.setFileName(file_name);
	if(file.exists())
	{
		QMessageBox msgBox;
		msgBox.setText(tr("File already exists") );
		msgBox.setInformativeText(tr("Do you want to overwrite it?") );
		msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		msgBox.setDefaultButton(QMessageBox::No);
		if(msgBox.exec() == QMessageBox::No)
		{
			return;
		}
	}

	this->setWindowTitle("Femp - " + file_name);

	// tweak the UI
	m_document.setFileName(file_name);
	saveDocument(m_document, file_name.toStdString());
}


void
MainWindow::closeProject()
{
	if(this->m_hasUnsavedChanges)
	{
		// ask the user if he wants to save the changes
		QMessageBox msgBox;
		msgBox.setText("The document has been modified.");
		msgBox.setInformativeText("Do you want to save your changes?");
		msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Save);
		switch(msgBox.exec())
		{
		case QMessageBox::Save:
			this->saveProject();
			break;

		case QMessageBox::Discard:
			// move on
			break;

		case QMessageBox::Cancel:
			return;	// exit and do nothing
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


void
MainWindow::quit()
{
	if(this->m_hasUnsavedChanges)
	{
		// ask the user if he wants to save the changes
		QMessageBox msgBox;
		msgBox.setText("The document has been modified.");
		msgBox.setInformativeText("Do you want to save your changes?");
		msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Save);
		switch(msgBox.exec())
		{
		case QMessageBox::Save:
			this->saveProject();
			break;

		case QMessageBox::Discard:
			// move on
			break;

		case QMessageBox::Cancel:
			return;	// exit and do nothing
			break;

		default:
			// this part should never be reached
			break;
		}
	}

	// proceed to quit
	this->close();
}


void
MainWindow::createActions()
{
	// connect the actions
	connect(ui.actionNew,						&QAction::triggered,	this,	&MainWindow::newProject);
	connect(ui.actionOpen,						&QAction::triggered,	this,	&MainWindow::openProject);
	connect(ui.actionReopen,					&QAction::triggered,	this,	&MainWindow::reopenProject);
	connect(ui.actionSave,						&QAction::triggered,	this,	&MainWindow::saveProject);
	connect(ui.actionSaveAs,					&QAction::triggered,	this,	&MainWindow::saveProjectAs);
	connect(ui.actionClose,						&QAction::triggered,	this,	&MainWindow::closeProject);
	connect(ui.actionQuit,						&QAction::triggered,	this,	&MainWindow::quit);
	connect(ui.actionNodeRestraints,			&QAction::triggered,	this,	&MainWindow::setNodeRestraints);
	connect(ui.actionNodeActions,				&QAction::triggered,	this,	&MainWindow::setNodeActions);
	connect(ui.actionDomainLoads,				&QAction::triggered,	this,	&MainWindow::setDomainLoads);
	connect(ui.actionMoveNodes,					&QAction::triggered,	this,	&MainWindow::moveSelectedNodes);

	connect(ui.actionRun,						&QAction::triggered,	this,	&MainWindow::runAnalysis);
	connect(ui.actionDump_FEM_equation,			&QAction::triggered,	this,	&MainWindow::dumpFemEquation);
	connect(ui.actionAnalysisSummary,			&QAction::triggered,	this,	&MainWindow::showAnalysisSummary);

	connect(ui.actionEditMaterials,				&QAction::triggered,	this,	&MainWindow::editMaterials);

	connect(ui.actionWindowTile,				&QAction::triggered,	this,	&MainWindow::setTiledWindows);
	connect(ui.actionWindowCascade,				&QAction::triggered,	this,	&MainWindow::setCascadeWindows);

	// MDI window creation
	connect(ui.actionNewModelWindow,			&QAction::triggered,	this,	&MainWindow::createNewModelWindow);
	connect(ui.actionNewPostprocessingWindow,	&QAction::triggered,	this,	&MainWindow::createNewPostprocessingWindow);
	connect(ui.actionNewTensorFieldWindow,		&QAction::triggered,	this,	&MainWindow::createNewTensorFieldWindow);
	connect(ui.actionNewAnalysisResultsWindow,	&QAction::triggered,	this,	&MainWindow::createNewAnalysisResultsWindow);
	connect(ui.actionNewFemEquationWindow,		&QAction::triggered,	this,	&MainWindow::createNewFemEquationWindow);

	connect(ui.actionViewSelection,				&QAction::triggered,	this,	&MainWindow::showSelection);
	connect(ui.actionViewAll,					&QAction::triggered,	this,	&MainWindow::showAll);

	connect(ui.actionQuadrature_rules,			&QAction::triggered,	this,	&MainWindow::editQuadratureRules);
	connect(ui.actionSelection,					&QAction::triggered,	this,	&MainWindow::editSelection);
	connect(ui.actionResults_from_selection,	&QAction::triggered,	this,	&MainWindow::dumpResultsFromSelection);

	connect(ui.menuWindowOpened,	&QMenu::aboutToShow,	this,	&MainWindow::updateWindowMenu);
}


void
MainWindow::createDockWidgets()
{
	// initialize the Docks
	m_commandLineDockWidget = new CommandLineDockWidget(this);

	// set the MainWindow connections
	connect(this, &MainWindow::setMessage,	m_commandLineDockWidget, &CommandLineDockWidget::getMessage);
	connect(this, &MainWindow::setWarning,	m_commandLineDockWidget, &CommandLineDockWidget::getWarning);
	connect(this, &MainWindow::setError, 	m_commandLineDockWidget, &CommandLineDockWidget::getError);

	// add selection dock widget
	this->addDockWidget(Qt::RightDockWidgetArea, m_commandLineDockWidget);
}


void
MainWindow::loadOptions()
{
	using namespace std;

	std::vector<float> default_color;

	// Set default options
	m_options.setDefault();

	m_colors = FempSettings::getInstance().getViewportColors();

	//TODO Set default options

	// Set system options
	m_options.setSystem();
	std::string path = "/etc/femp/options.opt";

	std::ifstream is;
	is.open(path.c_str(), std::ifstream::in);
	if(is.is_open())
	{
		m_options.importFile(is);
		is.close();
	}

	// Set local options
	m_options.setLocal();
	path = getenv("HOME");
	path += "/.femp/options.opt";
	is.open(path.c_str(), std::ifstream::in);
	if(is.is_open())
	{
		m_options.importFile(is);
		is.close();
	}

		// set quadrature rules options for the stiffness matrix
	{
		int temp = 0;

		if(m_options.wasSet("analysis.quadrature.stiffness.tetrahedron4") )
		{
			if(m_options.getOption("analysis.quadrature.stiffness.tetrahedron4",temp) )
			{
				if( (temp >0) & (temp <= 5) )
					this->m_analysis.tetra4.stiffness_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.stiffness.tetrahedron10") )
		{
			if(m_options.getOption("analysis.quadrature.stiffness.tetrahedron10",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.tetra10.stiffness_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.stiffness.hexahedron8") )
		{
			if(m_options.getOption("analysis.quadrature.stiffness.hexahedron8",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.hexa8.stiffness_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.stiffness.hexahedron20") )
		{
			if(m_options.getOption("analysis.quadrature.stiffness.hexahedron20",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.hexa20.stiffness_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.stiffness.hexahedron27") )
		{
			if(m_options.getOption("analysis.quadrature.stiffness.hexahedron27",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.hexa27.stiffness_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.stiffness.prism6") )
		{
			if(m_options.getOption("analysis.quadrature.stiffness.prism6",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.prism6.stiffness_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.stiffness.prism15") )
		{
			if(m_options.getOption("analysis.quadrature.stiffness.prism15",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.prism15.stiffness_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.stiffness.prism18") )
		{
			if(m_options.getOption("analysis.quadrature.stiffness.prism18",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.prism18.stiffness_degree = temp;
			}
		}
	}

	// set quadrature rules options for the domain loads
	{
		int temp = 0;

		if(m_options.wasSet("analysis.quadrature.domain.triangle3") )
		{
			if(m_options.getOption("analysis.quadrature.domain.triangle3",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.tri3.domain_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.domain.triangle6") )
		{
			if(m_options.getOption("analysis.quadrature.domain.triangle6",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.tri6.domain_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.domain.quadrangle4") )
		{
			if(m_options.getOption("analysis.quadrature.domain.quadrangle4",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.quad4.domain_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.domain.quadrangle8") )
		{
			if(m_options.getOption("analysis.quadrature.domain.quadrangle8",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.quad8.domain_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.domain.quadrangle9") )
		{
			if(m_options.getOption("analysis.quadrature.domain.quadrangle9",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.quad9.domain_degree = temp;
			}
		}

		if(m_options.wasSet("analysis.quadrature.domain.tetrahedron4") )
		{
			if(m_options.getOption("analysis.quadrature.domain.tetrahedron4",temp) )
			{
				if( (temp >0) & (temp <= 5) )
					this->m_analysis.tetra4.domain_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.domain.tetrahedron10") )
		{
			if(m_options.getOption("analysis.quadrature.domain.tetrahedron10",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.tetra10.domain_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.domain.hexahedron8") )
		{
			if(m_options.getOption("analysis.quadrature.domain.hexahedron8",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.hexa8.domain_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.domain.hexahedron20") )
		{
			if(m_options.getOption("analysis.quadrature.domain.hexahedron20",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.hexa20.domain_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.domain.hexahedron27") )
		{
			if(m_options.getOption("analysis.quadrature.domain.hexahedron27",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.hexa27.domain_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.domain.prism6") )
		{
			if(m_options.getOption("analysis.quadrature.domain.prism6",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.prism6.domain_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.domain.prism15") )
		{
			if(m_options.getOption("analysis.quadrature.domain.prism15",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.prism15.domain_degree = temp;
			}
		}
		if(m_options.wasSet("analysis.quadrature.domain.prism18") )
		{
			if(m_options.getOption("analysis.quadrature.domain.prism18",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->m_analysis.prism18.domain_degree = temp;
			}
		}
	}
}


void
MainWindow::setNodeRestraints()
{
	assert(m_mdiArea != nullptr);

	NodeRestrainsDialog nd;
	if(nd.exec() == QDialog::Accepted)
	{
		// get list of node restraints from active window
		Selection selection = m_selectionManager.getSelection();
		SetNodeRestraintsVisitor visitor(selection, nd.getRestrictions());

		// set the restraints in the model
		m_document.getProject().accept(visitor);
	}
}


void
MainWindow::setNodeActions()
{
	fem::Model &femp_model = m_document.getProject().getModel();
	LoadPatternsModel load_patterns_model(femp_model, this);

	NodeActionsDialog na(load_patterns_model, this);

	if(na.exec() == QDialog::Accepted)
	{
		Selection const selection = m_selectionManager.getSelection();

		fem::Point3D force = na.getForce();
		//fem::Point displacement = na.getDisplacement(); // doesn't support node displacements

		if(force != fem::Point3D(0,0,0))
		{
			// shortcut just to reduce code clutter
			fem::LoadPattern &load_pattern = femp_model.load_pattern_list[ na.getLoadPattern() ];

			// assign nodal loads
			for(fem::node_ref_t const &node: selection.getNodeReferences())
			{
				load_pattern.addNodalLoad(node, force);
			}
		}
	}
}


void
MainWindow::setDomainLoads()
{
	fem::Model &femp_model = m_document.getProject().getModel();

	LoadPatternsModel model(femp_model, this);

	DomainLoadsDialog dialog(model, this);

	// call the dialog box
	if(dialog.exec() == QDialog::Accepted)
	{
		Selection const selection = m_selectionManager.getSelection();

		SetDomainLoadsVisitor visitor(selection,  femp_model.load_pattern_list[ dialog.getLoadPattern() ], dialog.getForce() );

		m_document.getProject().accept(visitor);

		m_document.setUnsaved();
	}
}


void
MainWindow::moveSelectedNodes()
{
	assert(m_mdiArea != nullptr);

	MoveNodesDialog nd(this);
	if(nd.exec() == QDialog::Accepted)
	{
		// get list of node restraints from active window
		Selection selection = m_selectionManager.getSelection();
		MoveNodesVisitor visitor(selection, nd.getTranslation());

		m_document.getProject().accept(visitor);

		m_document.setUnsaved();
	}
}


void
MainWindow::editMaterials()
{
	fem::Model & femp_model = m_document.getProject().getModel();
	MaterialsEditorDialog dialog(&femp_model, this);
	dialog.exec();
}


void
MainWindow::editQuadratureRules()
{
	QuadratureRulesOptionsDialog dialog(m_analysis, this);
	dialog.exec();
}


void
MainWindow::editSelection()
{
	SelectionDialog dialog(m_document.getProject(), m_selectionManager, this);
	dialog.exec();
}


void
MainWindow::runAnalysis()
{
	using namespace std;

	fem::Model &femp_model = this->m_document.getProject().getModel();

	// check if ther is a load pattern
	if( femp_model.getLoadPatternList().empty() )
	{
		QMessageBox::critical(this, "No load patterns", "This model doesn't have any load patterns to run");
		return;
	}

	fem::Solver<double> * solver = nullptr;

	// run the AnalysisDialog to get the solver
	AnalysisDialog analysis_dialog(femp_model, this);
	switch(analysis_dialog.exec())
	{
	case QDialog::Accepted:
		solver = analysis_dialog.solver();
		if( analysis_dialog.loadPattern() == -1)
		{
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
	connect(&progress,	&DefaultProgressIndicator::beginSection,	&dialog,	&AnalysisProgressDialog::beginSection);
	connect(&progress,	&DefaultProgressIndicator::endSection,		&dialog,	&AnalysisProgressDialog::endSection);
	connect(&progress,	&DefaultProgressIndicator::setProgress,		&dialog,	&AnalysisProgressDialog::setProgress);
	connect(&progress,	&DefaultProgressIndicator::setMessage,		&dialog,	&AnalysisProgressDialog::setMessage);
	connect(&progress,	&DefaultProgressIndicator::setError,		&dialog,	&AnalysisProgressDialog::setError);
	connect(&progress,	&DefaultProgressIndicator::finish,			&dialog,	&AnalysisProgressDialog::finish);

	//TODO finish this
	fem::AnalysisResult analysis_result;
	m_analysis.set(femp_model, femp_model.load_pattern_list[analysis_dialog.loadPattern()], analysis_result, progress, solver);

	std::thread t(m_analysis);

	switch(dialog.exec())
	{
	case QDialog::Accepted:
		//TODO implement a way to abort the analysis thread if the abort button is pressed
		break;

	default:
		break;
	}
	t.join();

	if(m_analysis.succeeded())
	{
		m_document.getProject().pushAnalysisResult(analysis_result);

		// set the UI
		this->setUserInterfacePostAnalysis();
		this->createNewPostprocessingWindow();
	}
	else
	{
		QMessageBox::critical(this, "No analysis", "There isn't a equation to dump");
	}

	delete solver;
}


void
MainWindow::dumpFemEquation()
{
	auto & femp_result = m_document.getProject().result;

	if( femp_result.empty() )
	{
		QMessageBox::information(this, "No analysis", "There isn't a equation to dump");
	}
	else
	{
		using namespace std;

		//TODO pick file name
		QFileDialog dialog(this);

		// setup the file dialog
		dialog.setFileMode(QFileDialog::AnyFile);
		dialog.setNameFilter(tr("Octave file (*.oct)"));
		dialog.setDefaultSuffix("oct");
		if(dialog.exec() == QDialog::Rejected)
		{
			// user cancelled
			return;
		}

		QStringList sl = dialog.selectedFiles();
		QString file_name = sl.at(0);

		// check if file already exists
		QFile file;
		file.setFileName(file_name);
		if(file.exists())
		{
			QMessageBox msgBox;
			msgBox.setText(tr("File already exists") );
			msgBox.setInformativeText(tr("Do you want to overwrite it?") );
			msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
			msgBox.setDefaultButton(QMessageBox::No);
			if(msgBox.exec() == QMessageBox::No)
			{
				delete m_document.file_name;
				m_document.file_name = nullptr;
				return;
			}
		}

		// set a new file name for this file

		file.open(QFile::WriteOnly);
		QTextStream     out(&file);
		out.setRealNumberNotation(QTextStream::ScientificNotation);
		out.setRealNumberPrecision(16);

		out << "# Created by lalib\n";
		out << "# name: K\n";
		out << "# type: matrix\n";
		out << "# rows: " << femp_result.back().K.rows() << "\n";
		out << "# columns: " << femp_result.back().K.columns() << "\n";

		for(size_t j = 0; j < femp_result.back().K.columns(); j++)
		{
			for(size_t i = 0; i < femp_result.back().K.rows(); i++)
			{
				out << " " << femp_result.back().K.value(i,j);
			}
			out << "\n";
		}
		out << endl;
		// */
		out << "# Created by lalib\n";
		out << "# name: f\n";
		out << "# type: matrix\n";
		out << "# rows: " << femp_result.back().f.size() << "\n";
		out << "# columns: 1\n";
		for(size_t i = 0; i < femp_result.back().f.size(); i++)
		{
			out << " " << femp_result.back().f.value(i) << "\n";
		}
		out << endl;

		//lalib::dump_octave(out, "d", document.getProject().result.back().d);

		out << "# Created by lalib\n";
		out << "# name: d\n";
		out << "# type: matrix\n";
		out << "# rows: " << femp_result.back().d.size() << "\n";
		out << "# columns: 1\n";
		for(size_t i = 0; i < femp_result.back().d.size(); i++)
		{
			out << " " << femp_result.back().d.value(i) << "\n";
		}
		out << endl;
		//out.close();
		file.close();
	}
}


void
MainWindow::showAnalysisSummary()
{
	// crude hack
	AnalysisSummaryDialog dialog(m_document.getProject().result.back() , this);
	dialog.exec();
}


void
MainWindow::dumpResultsFromSelection()
{
	QString file_name;
	QFile file;

	// opens the file
	{
		QFileDialog dialog(this);
		dialog.setDirectory(FempSettings::getInstance().getDumpResultsDirectory());
		QStringList sl;

		// setup the file dialog
		dialog.setFileMode(QFileDialog::AnyFile);
		dialog.setAcceptMode(QFileDialog::AcceptSave);
		dialog.setNameFilter(tr("text file (*.txt)"));
		dialog.setDefaultSuffix("txt");
		if(dialog.exec() == QDialog::Rejected)
		{
			// user cancelled
			return;
		}

		// get the last directory used to dump results
		FempSettings::getInstance().setDumpResultsDirectory(dialog.directory());

		sl = dialog.selectedFiles();
		file_name = sl.at(0);

		// check if file already exists
		file.setFileName(file_name);
		if(file.exists())
		{
			QMessageBox msgBox;
			msgBox.setText(tr("File already exists") );
			msgBox.setInformativeText(tr("Do you want to overwrite it?") );
			msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
			msgBox.setDefaultButton(QMessageBox::No);
			if(msgBox.exec() == QMessageBox::No)
			{
				return;
			}
		}
	}

	// prepare the file for dumping
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QMessageBox::critical(this, tr("femp"), tr("Failed to open file"));
		return;
	}

	QTextStream     out(&file);
	//dump the text to a text file
	fem::AnalysisResult & femp_result = this->m_document.getProject().result.back();	// nasty hack

	Selection selection = m_selectionManager.getSelection();

	OutputResultsInNodesCSVVisitor visitor(selection, &femp_result, out);

	m_document.getProject().accept(visitor);

	file.close();
}


void
MainWindow::showSelection()
{
	Selection selection = m_selectionManager.getSelection();

	QMdiSubWindow *mdi_window = m_mdiArea->currentSubWindow();
	if(mdi_window != nullptr)
	{
		MdiWindow *window = static_cast<MdiWindow*>(mdi_window->widget() );
		if(window != nullptr)
		{
			window->showSelection(selection);
		}
	}

}


void
MainWindow::showAll()
{
	QMdiSubWindow *mdi_window = m_mdiArea->currentSubWindow();
	if(mdi_window != nullptr)
	{
		MdiWindow *window = static_cast<MdiWindow*>(mdi_window->widget() );
		if(window != nullptr)
		{
			window->showAll();
		}
	}
}


void
MainWindow::getMessage(QString message)
{
	emit setMessage(message);
}


void
MainWindow::getWarning(QString message)
{
	emit setMessage(message);
}


void
MainWindow::getError(QString message)
{
	emit setMessage(message);
}


void
MainWindow::setTiledWindows()
{
	m_mdiArea->tileSubWindows();
}


void
MainWindow::setCascadeWindows()
{
	m_mdiArea->cascadeSubWindows();
}


void
MainWindow::createNewViewportWindow()
{
	this->createNewModelWindow();
}


void
MainWindow::createNewModelWindow()
{
	ModelWindow *window = new ModelWindow(m_document.getProject(), getViewportColors(), this);

	// create the model's MDI window
	QMdiSubWindow	* mdi_window = new QMdiSubWindow(m_mdiArea);

	mdi_window->setWidget(window);
	mdi_window->setAttribute(Qt::WA_DeleteOnClose);
	mdi_window->setWindowTitle(tr("Model"));
	mdi_window->showMaximized();
	window->connectToSelectionManager(this->m_selectionManager);
}


void
MainWindow::createNewPostprocessingWindow()
{
	auto &femp_result = m_document.getProject().result;
	if(femp_result.empty())
	{
		std::cerr << __FILE__ << ":" << __LINE__ ;
		std::cerr << "MainWindow::createNewPostprocessingWindow(): tried to set a postprocessing window although no results are available" << std::endl;
	}
	else
	{
		PostprocessingWindow *window = new PostprocessingWindow(m_document.getProject(), femp_result.back(), getViewportColors(), this);

		// create the model's MDI window
		QMdiSubWindow	* mdi_window = new QMdiSubWindow(m_mdiArea);
		mdi_window->setWidget(window);
		mdi_window->setAttribute(Qt::WA_DeleteOnClose);
		mdi_window->setWindowTitle(tr("Postprocessing"));
		mdi_window->showMaximized();
		window->connectToSelectionManager(this->m_selectionManager);
	}
}


void
MainWindow::createNewTensorFieldWindow()
{
	if(m_document.getProject().result.empty())
	{
		std::cerr << __FILE__ << ":" << __LINE__ ;
		std::cerr << "MainWindow::createNewPostprocessingWindow(): tried to set a postprocessing window although no results are available" << std::endl;
	}
	else
	{
		TensorFieldWindow *window = new TensorFieldWindow(m_document.getProject(), m_document.getProject().result.back(), getViewportColors(), this);

		// create the model's MDI window
		QMdiSubWindow	* mdi_window = new QMdiSubWindow(m_mdiArea);

		mdi_window->setWidget(window);
		mdi_window->setAttribute(Qt::WA_DeleteOnClose);
		mdi_window->setWindowTitle(tr("Tensor field"));
		mdi_window->showMaximized();
		window->connectToSelectionManager(this->m_selectionManager);
	}
}


void
MainWindow::createNewAnalysisResultsWindow()
{
	std::cerr << __FILE__ << ":" << __LINE__ ;
	std::cerr << "MainWindow::createNewAnalysisResultsWindow()" << std::endl;
	if(m_document.getProject().result.empty())
	{
		std::cerr << __FILE__ << ":" << __LINE__ ;
		std::cerr << "MainWindow::createNewAnalysisResultWindow(): tried to set a results window although there is no result available" << std::endl;
		return;
	}

	AnalysisResultsWindow *mdi_window = new AnalysisResultsWindow(m_document.getProject(), m_mdiArea);
	mdi_window->showMaximized();
}


void
MainWindow::createNewFemEquationWindow()
{
	std::cerr << __FILE__ << ":" << __LINE__ ;
	std::cerr << "MainWindow::createNewFemEquationWindow()" << std::endl;
	if(m_document.getProject().result.empty())
	{
		std::cerr << "MainWindow::createNewFemEquationWindow(): tried to set a results window although there is no result available" << std::endl;
		return;
	}

	MatrixWindow *mdi_window = new MatrixWindow(m_document.getProject(), m_mdiArea);
	mdi_window->showMaximized();
}


void
MainWindow::updateWindowMenu()
{
	qWarning("MainWindow::updateWindowMenu()");

	QList<QMdiSubWindow *> 	subWindowList = m_mdiArea->subWindowList();

	// empties the menu
	ui.menuWindowOpened->clear();

	// fills the menu
	QAction *action;
	//for(QList<QMdiSubWindow *>::const_iterator subwindow = subWindowList.begin(); subwindow != subWindowList.end(); subwindow++)
	for(int n = 0; n < subWindowList.size(); n++)
	{
		// get current MDI window label
		BaseWindow *base = dynamic_cast<BaseWindow*>(subWindowList[n]->widget());
		{
			//TODO fix problem with menu windows
			std::cerr << "MainWindow::updateWindowMenu(): nullptr result" << std::endl;
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


void
MainWindow::activateSubWindowByIndex(int index)
{
	QList<QMdiSubWindow *> 	subWindowList = m_mdiArea->subWindowList();
	this->m_mdiArea->setActiveSubWindow(subWindowList[index]);
}


void
MainWindow::setUserInterfaceAsOpened()
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
	if(m_document.file_name == nullptr)
		this->setWindowTitle("Femp - [unnamed.fem.json]");
	else
		this->setWindowTitle("Femp - " + *m_document.file_name);
}


void
MainWindow::setUserInterfaceAsClosed()
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


void
MainWindow::setUserInterfacePostAnalysis()
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

ViewportColors & MainWindow::getViewportColors()
{
	return m_colors;
}


void
MainWindow::saveDocument(Document &doc, std::string file_name)
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

