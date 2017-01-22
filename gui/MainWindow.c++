#include "MainWindow.h++"
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QTime>
#include <QTranslator>
#include <QToolBar>
#include <QString>
#include <QTextStream>
#include <QProgressDialog>

#include <thread>
#include <string>
#include <fstream>
#include <iostream>	// for cout. remove after tests
#include <string>
#include <stdlib.h>	// getenv()

#include "ui/LoadPatternsModel.h++"

#include "ui/NewProjectWizard.h++"
#include "NodeRestrainsDialog.h++"
#include "ui/NodeActionsDialog.h++"
#include "ui/DisplayOptionsDialog.h++"
#include "ui/DomainLoadsDialog.h++"
#include "ui/MaterialsEditorDialog.h++"
#include "ui/QuadratureRulesOptionsDialog.h++"
#include "ui/SelectionDialog.h++"
#include "ui/AnalysisProgressDialog.h++"
#include "ui/AnalysisDialog.h++"
#include "ui/MoveNodesDialog.h++"
#include "ui/AnalysisSummaryDialog.h++"

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

#include "ProjectVisitor/OutputResultsInNodesVisitor.h++"
#include "ProjectVisitor/OutputResultsInNodesCSVVisitor.h++"
#include "ProjectVisitor/SetNodeRestraintsVisitor.h++"
#include "ProjectVisitor/SetDomainLoadsVisitor.h++"
#include "ProjectVisitor/MoveNodesVisitor.h++"
#include "ProjectVisitor/OutputElementStatisticsVisitor.h++"




MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	// set the MDI area widget as the window's central widget
	mdiArea = new QMdiArea;
	setCentralWidget(mdiArea);	// this main window has a Multiple Document Interface
	m_window_mapper = new QSignalMapper(this);

	// Load global options from the options files
	this->loadOptions();

	// initialize the member attributes
	this->hasUnsavedChanges = false;

	// create actions and connect signals to slots
	this->createActions();
	this->createToolBars();
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
	document.clear();

	std::string default_path = getenv("HOME");
	std::string tmp;
	if(options.getOption("project.new.default_directory",tmp))
	{
		default_path += "/" + tmp;
	}

	/*
	The NewProjectWizard dialog will fill up a given document object through the steps
	*/
	NewProjectWizard np(document, this);
	switch(np.exec())
	{
		case QDialog::Accepted:
			setUserInterfaceAsOpened();
			break;

		default:
			document.clear();
			break;
	}
}


void 
MainWindow::openProject()
{
	// get the last dir where a project was opened 
	QFileDialog dialog(this);
	dialog.setDirectory(file_dialog_last_directory);
	
	// setup the file dialog
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilter(tr("FEM project (*.fem.json)"));
	if(dialog.exec() == QDialog::Rejected)
	{
		// user cancelled, no file was loaded
		return;
	}

	file_dialog_last_directory = dialog.directory();

	// clear the document
	this->setUserInterfaceAsClosed();
	this->document.clear();
	this->m_selection_manager.clearSelection();

	// prepare the file
	QStringList sl;
	sl = dialog.selectedFiles();

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
	parser.parse(file, document.getProject().model);

	switch(parser.error.code)
	{
		case FemJsonParser::Error::ERR_OK:
			// setup the user interface
			document.setProjectType( Document::TYPE_SOLID3D);	// nasty hack due to poor design
			this->setUserInterfaceAsOpened();
			break;

		default:
			std::cerr << __FILE__ << ":" << __LINE__ ;
			std::cerr << "Error: " << parser.error.message << std::endl;
			QMessageBox::critical(this, tr("Error"), parser.error.message.c_str());
			document.clear();
			break;
	}

	document.setFileName(file_name);

	OutputElementStatisticsVisitor visit(m_selection_manager.getSelection());
	document.getProject().accept(visit);

	file.close();
}


void 
MainWindow::reopenProject()
{
	if(document.file_name != NULL)
	{
		// clear the document
		setUserInterfaceAsClosed();
		this->document.getProject().model.clear();
		this->m_selection_manager.clearSelection();

		std::string my_file_name( document.file_name->toUtf8() ); 
		std::fstream file;

		file.open(my_file_name, std::fstream::in);
		if(!file)
		{
			QMessageBox::critical(this, tr("Error"), tr("There was an error opening the file"));
			document.clear();
			return;
		}

		FemJsonParser parser;
		parser.parse(file, document.getProject().model);

		switch(parser.error.code)
		{
			case FemJsonParser::Error::ERR_OK:
				setUserInterfaceAsOpened();
				break;

			default:
				std::cerr << __FILE__ << ":" << __LINE__ ;
				std::cerr << "Error: " << parser.error.message << std::endl;
				QMessageBox::critical(this, tr("Error"), parser.error.message.c_str());
				document.clear();
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
	if(document.file_name == NULL)
	{
		QFileDialog dialog(this);
		dialog.setDirectory(file_dialog_last_directory);

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
		document.setFileName(file_name);
		
		this->setWindowTitle("Femp - " + file_name );
		ui.actionReopen->setEnabled(true);
	}
	document.save();
	hasUnsavedChanges = false;
}


void 
MainWindow::saveProjectAs()
{
	QFileDialog dialog(this);

	dialog.setDirectory(file_dialog_last_directory);

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
	document.setFileName(file_name);
	document.save();
	hasUnsavedChanges = false;
}


void 
MainWindow::closeProject()
{
	if(this->hasUnsavedChanges)
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
	document.clear();
	this->m_selection_manager.clearSelection();
}


void 
MainWindow::quit()
{
	if(this->hasUnsavedChanges)
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
	connect(ui.actionNew,	SIGNAL(triggered()), this,	SLOT(newProject()));
	connect(ui.actionOpen,	SIGNAL(triggered()), this,	SLOT(openProject()));
	connect(ui.actionReopen,	SIGNAL(triggered()), this,	SLOT(reopenProject()));
	connect(ui.actionSave,	SIGNAL(triggered()), this,	SLOT(saveProject()));
	connect(ui.actionSaveAs,	SIGNAL(triggered()), this,	SLOT(saveProjectAs()));
	connect(ui.actionClose,	SIGNAL(triggered()), this,	SLOT(closeProject()));
	connect(ui.actionQuit,	SIGNAL(triggered()), this,	SLOT(quit()));
	connect(ui.actionNodeRestraints,	SIGNAL(triggered()), this,	SLOT(setNodeRestraints()) );
	connect(ui.actionNodeActions,	SIGNAL(triggered()), this,	SLOT(setNodeActions()) );
	connect(ui.actionDomainLoads,	SIGNAL(triggered()), this,	SLOT(setDomainLoads()) );
	connect(ui.actionMoveNodes,	SIGNAL(triggered()), this,	SLOT(moveSelectedNodes()) );

	connect(ui.actionRun,	SIGNAL(triggered()), this,	SLOT(runAnalysis()));
	connect(ui.actionDump_FEM_equation,	SIGNAL(triggered()),	this,	SLOT(dumpFemEquation()));
	connect(ui.actionAnalysisSummary,	SIGNAL(triggered()),	this,	SLOT(showAnalysisSummary() ));

	connect(ui.actionViewActions,	SIGNAL(triggered()), this,	SLOT(setDisplayOptions()));
	connect(ui.actionEditMaterials,	SIGNAL(triggered()),	this,	SLOT(editMaterials()));
	connect(ui.actionDisplayNodes,	SIGNAL(triggered()), this,	SLOT(setElementDisplay()));
	connect(ui.actionDisplaySurfaces,	SIGNAL(triggered()), this,	SLOT(setElementDisplay()));

	connect(ui.actionWindowTile,	SIGNAL(triggered()), this,	SLOT(setTiledWindows()));
	connect(ui.actionWindowCascade,	SIGNAL(triggered()), this,	SLOT(setCascadeWindows()));

	connect(ui.actionShowNodalForces,	SIGNAL(triggered()),	this,	SLOT(setNodeForcesDisplay()));

	// MDI window creation 
	connect(ui.actionNewModelWindow,		SIGNAL(triggered()),	this,	SLOT(createNewModelWindow()));
	connect(ui.actionNewPostprocessingWindow,	SIGNAL(triggered()),	this,	SLOT(createNewPostprocessingWindow()));
	connect(ui.actionNewTensorFieldWindow,		SIGNAL(triggered()),	this,	SLOT(createNewTensorFieldWindow()));
	connect(ui.actionNewAnalysisResultsWindow,	SIGNAL(triggered()),	this,	SLOT(createNewAnalysisResultsWindow()));
	connect(ui.actionNewFemEquationWindow,		SIGNAL(triggered()),	this,	SLOT(createNewFemEquationWindow()));

	connect(ui.actionViewSelection,	SIGNAL(triggered()),	this,	SLOT(showSelection()));
	connect(ui.actionViewAll,	SIGNAL(triggered()),	this,	SLOT(showAll()));

	connect(ui.actionQuadrature_rules,	SIGNAL(triggered()),	this,	SLOT(editQuadratureRules()) );
	connect(ui.actionSelection,		SIGNAL(triggered()),	this,	SLOT(editSelection()) );
	connect(ui.actionResults_from_selection,		SIGNAL(triggered()),	this,	SLOT(dumpResultsFromSelection()) );

	connect(ui.menuWindowOpened,	SIGNAL(aboutToShow()),	this,	SLOT(updateWindowMenu()) );
}


void 
MainWindow::createToolBars()
{
	// build the actions toolbar
	//TODO finish this
}


void 
MainWindow::createDockWidgets()
{
	// initialize the Docks
	commandLineDockWidget = new CommandLineDockWidget(this);
	connect(this, SIGNAL(setMessage(QString)), commandLineDockWidget, SLOT(getMessage(QString)));
	connect(this, SIGNAL(setWarning(QString)), commandLineDockWidget, SLOT(getWarning(QString)));
	connect(this, SIGNAL(setError(QString)), commandLineDockWidget, SLOT(getError(QString)));

	// set the MainWindow connections

	this->addDockWidget(Qt::RightDockWidgetArea, commandLineDockWidget);

	//TODO add selection dock widget
}


void 
MainWindow::destroyToolBars()
{
	//deletes all toolbars
}


void 
MainWindow::loadOptions()
{
	using namespace std;

	std::vector<double> default_color;

	// Set default options
	options.setDefault();
	options.setOption("viewport.nodes.radius",10.0f);	// sets the default node radius
	default_color.reserve(3);

	default_color[0] = 0, default_color[1] = 0.8f, default_color[2] = 0.8f;
	options.setOption("viewport.nodes.color",default_color);

	default_color[0] = 0.5f, default_color[1] = 0.5f, default_color[2] = 0;
	options.setOption("viewport.wireframe.color",default_color);

	default_color[0] = 1, default_color[1] = 0, default_color[2] = 0;
	options.setOption("viewport.arrows.color",default_color);
	options.setOption("viewport.arrows.radius",10.0f);
	options.setOption("viewport.arrows.length",100.0f);

	//TODO Set default options

	// Set system options
	options.setSystem();
	std::string path = "/etc/femp/options.opt";

	std::ifstream is;
	is.open(path.c_str(), std::ifstream::in);
	if(is.is_open())
	{
		options.importFile(is);
		is.close();
	}

	// Set local options
	options.setLocal();
	path = getenv("HOME");
	path += "/.femp/options.opt";
	is.open(path.c_str(), std::ifstream::in);
	if(is.is_open())
	{
		options.importFile(is);
		is.close();
	}

	if(options.wasSet("project.open.default_directory"))
	{
		std::string default_path;
		options.getOption("project.open.default_directory",default_path);
		if( QFile::exists(QString::fromStdString(default_path)) )
		{
			//TODO this doesn't work
			file_dialog_last_directory.setPath(QString::fromStdString(default_path));
		}
		else
		{
			file_dialog_last_directory = QDir::home();
			QString path = file_dialog_last_directory.absolutePath();
		}
	}
	else
	{
		file_dialog_last_directory = QDir::home();
	}

	if(options.wasSet("project.results.dump.default_directory"))
	{
		std::string default_path;
		options.getOption("project.results.dump.default_directory",default_path);
		if( QFile::exists(QString::fromStdString(default_path)) )
		{
			results_dump_dialog_last_directory.setPath(QString::fromStdString(default_path));
		}
		else
		{
			results_dump_dialog_last_directory = QDir::home();
			QString path = results_dump_dialog_last_directory.absolutePath();
		}
	}
	else
	{
		results_dump_dialog_last_directory = file_dialog_last_directory;
	}

	// set color options
	{
		std::vector<double> temp;
		if(options.getOption("viewport.nodes.color",temp) )
		{ 
			if(temp.size() == 3) 
			{ 
				colors.node[0] = temp[0]; 
				colors.node[1] = temp[1]; 
				colors.node[2] = temp[2]; 
			} 
		} 

		if(options.getOption("viewport.background.color",temp) )
		{ 
			if(temp.size() == 3) 
			{ 
				colors.background[0] = temp[0]; 
				colors.background[1] = temp[1]; 
				colors.background[2] = temp[2]; 
			} 
		} 

		if(options.getOption("viewport.wireframe.color",temp) )
		{ 
			if(temp.size() == 3) 
			{ 
				colors.wireframe[0] = temp[0]; 
				colors.wireframe[1] = temp[1]; 
				colors.wireframe[2] = temp[2]; 
			} 
		} 

		if(options.getOption("viewport.fields.color.maximum_positive",temp) )
		{ 
			if(temp.size() == 3) 
			{ 
				colors.field_maximum_positive[0] = temp[0]; 
				colors.field_maximum_positive[1] = temp[1]; 
				colors.field_maximum_positive[2] = temp[2]; 
			} 
		} 

		if(options.getOption("viewport.fields.color.maximum_negative",temp) )
		{ 
			if(temp.size() == 3) 
			{ 
				colors.field_maximum_negative[0] = temp[0]; 
				colors.field_maximum_negative[1] = temp[1]; 
				colors.field_maximum_negative[2] = temp[2]; 
			} 
		} 

		if(options.getOption("viewport.fields.color.neutral",temp) )
		{ 
			if(temp.size() == 3) 
			{ 
				colors.field_neutral[0] = temp[0]; 
				colors.field_neutral[1] = temp[1]; 
				colors.field_neutral[2] = temp[2]; 
			} 
		} 
		//TODO add code for the force arrows custom color code
	}

	// set quadrature rules options for the stiffness matrix 
	{
		int temp = 0;

		if(options.wasSet("analysis.quadrature.stiffness.tetrahedron4") )
		{
			if(options.getOption("analysis.quadrature.stiffness.tetrahedron4",temp) )
			{
				if( (temp >0) & (temp <= 5) )
					this->analysis.tetra4.stiffness_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.stiffness.tetrahedron10") )
		{
			if(options.getOption("analysis.quadrature.stiffness.tetrahedron10",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.tetra10.stiffness_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.stiffness.hexahedron8") )
		{
			if(options.getOption("analysis.quadrature.stiffness.hexahedron8",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.hexa8.stiffness_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.stiffness.hexahedron20") )
		{
			if(options.getOption("analysis.quadrature.stiffness.hexahedron20",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.hexa20.stiffness_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.stiffness.hexahedron27") )
		{
			if(options.getOption("analysis.quadrature.stiffness.hexahedron27",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.hexa27.stiffness_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.stiffness.prism6") )
		{
			if(options.getOption("analysis.quadrature.stiffness.prism6",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.prism6.stiffness_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.stiffness.prism15") )
		{
			if(options.getOption("analysis.quadrature.stiffness.prism15",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.prism15.stiffness_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.stiffness.prism18") )
		{
			if(options.getOption("analysis.quadrature.stiffness.prism18",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.prism18.stiffness_degree = temp;
			}
		}
	}

	// set quadrature rules options for the domain loads
	{
		int temp = 0;

		if(options.wasSet("analysis.quadrature.domain.triangle3") )
		{
			if(options.getOption("analysis.quadrature.domain.triangle3",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.tri3.domain_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.domain.triangle6") )
		{
			if(options.getOption("analysis.quadrature.domain.triangle6",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.tri6.domain_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.domain.quadrangle4") )
		{
			if(options.getOption("analysis.quadrature.domain.quadrangle4",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.quad4.domain_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.domain.quadrangle8") )
		{
			if(options.getOption("analysis.quadrature.domain.quadrangle8",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.quad8.domain_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.domain.quadrangle9") )
		{
			if(options.getOption("analysis.quadrature.domain.quadrangle9",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.quad9.domain_degree = temp;
			}
		}

		if(options.wasSet("analysis.quadrature.domain.tetrahedron4") )
		{
			if(options.getOption("analysis.quadrature.domain.tetrahedron4",temp) )
			{
				if( (temp >0) & (temp <= 5) )
					this->analysis.tetra4.domain_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.domain.tetrahedron10") )
		{
			if(options.getOption("analysis.quadrature.domain.tetrahedron10",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.tetra10.domain_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.domain.hexahedron8") )
		{
			if(options.getOption("analysis.quadrature.domain.hexahedron8",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.hexa8.domain_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.domain.hexahedron20") )
		{
			if(options.getOption("analysis.quadrature.domain.hexahedron20",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.hexa20.domain_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.domain.hexahedron27") )
		{
			if(options.getOption("analysis.quadrature.domain.hexahedron27",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.hexa27.domain_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.domain.prism6") )
		{
			if(options.getOption("analysis.quadrature.domain.prism6",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.prism6.domain_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.domain.prism15") )
		{
			if(options.getOption("analysis.quadrature.domain.prism15",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.prism15.domain_degree = temp;
			}
		}
		if(options.wasSet("analysis.quadrature.domain.prism18") )
		{
			if(options.getOption("analysis.quadrature.domain.prism18",temp) )
			{
				if( (temp >0) & (temp <= 5) )	// maximum supported integration rule is 5
					this->analysis.prism18.domain_degree = temp;
			}
		}
	}
}


void 
MainWindow::setNodeRestraints()
{
	assert(mdiArea != NULL);

	NodeRestrainsDialog nd;
	if(nd.exec() == QDialog::Accepted)
	{
		// get list of node restraints from active window
		Selection selection = m_selection_manager.getSelection();
		SetNodeRestraintsVisitor visitor(selection, nd.getRestrictions());

		// set the restraints in the model
		document.getProject().accept(visitor);
	}
}


void 
MainWindow::setNodeActions()
{
	LoadPatternsModel model(document.getProject().model, this);

	NodeActionsDialog na(model, this);

	// Connect the sigc++ signals
	na.create_load_pattern.connect( sigc::mem_fun(document.getProject().model, &fem::Model::createEmptyLoadPattern));

	if(na.exec() == QDialog::Accepted)
	{
		Selection const selection = m_selection_manager.getSelection();

		fem::Point force = na.getForce();
		//fem::Point displacement = na.getDisplacement(); // doesn't support node displacements

		if(force != fem::Point(0,0,0))
		{
			// shortcut just to reduce code clutter
			fem::Model &model = document.getProject().model;
			fem::LoadPattern &load_pattern = model.load_pattern_list[ na.getLoadPattern() ];

			// assign nodal loads
			for(fem::node_ref_t const &node: selection.m_nodes_selected)
			{
				load_pattern.addNodalLoad(node, force);
			}
		}
	}
}


void 
MainWindow::setDomainLoads()
{
	fem::Model &femp_model = document.getProject().model;

	LoadPatternsModel model(femp_model, this);

	DomainLoadsDialog dialog(model, this);

	// Connect the sigc++ signals
	dialog.create_load_pattern.connect( sigc::mem_fun(femp_model, &fem::Model::createEmptyLoadPattern));

	/*
	From:
	https://developer.gnome.org/libsigc++-tutorial/stable/ch04.html#id455954
	myaliendetector.signal_detected.connect( sigc::hide<std::string>( sigc::ptr_fun(warn_people) ) );
	*/
	//document.getProject().model.load_pattern_created.connect(sigc::hide<size_t const, fem::LoadPattern const &>(dialog.loadPatternCreated() ) );


	// call the dialog box
	if(dialog.exec() == QDialog::Accepted)
	{
		Selection const selection = m_selection_manager.getSelection();

		SetDomainLoadsVisitor visitor(selection,  femp_model.load_pattern_list[ dialog.getLoadPattern() ], dialog.getForce() );

		document.getProject().accept(visitor);

		document.setUnsaved();
	}
}


void 
MainWindow::moveSelectedNodes()
{
	assert(mdiArea != NULL);

	MoveNodesDialog nd(this);
	if(nd.exec() == QDialog::Accepted)
	{
		// get list of node restraints from active window
		Selection selection = m_selection_manager.getSelection();
		MoveNodesVisitor visitor(selection, nd.getTranslation());

		document.getProject().accept(visitor);

		document.setUnsaved();
	}
}


void 
MainWindow::setDisplayOptions()
{
	//TODO make this generic
	/*
	   DisplayOptionsDialog da(document.getProject().model, this);
	   if(da.exec() == QDialog::Accepted)
	   {
	// set the LoadPattern pointer
	size_t n = da.getLoadPatternIndex();
	glWidget->display_options.load_pattern = &document.getProject().model.load_pattern_list[n];

	// set the other visualization options
	glWidget->display_options.nodal_forces = da.renderNodalForces();
	glWidget->display_options.surface_forces = da.renderSurfaceForces();
	glWidget->display_options.domain_forces = da.renderDomainForces();
	glWidget->display_options.nodal_displacements = da.renderNodalDisplacements();
	}
	 */
}


void 
MainWindow::editMaterials()
{
	MaterialsEditorDialog dialog(&document.getProject().model, this);
	dialog.exec();
}


void 
MainWindow::editQuadratureRules()
{
	QuadratureRulesOptionsDialog dialog(analysis, this);
	dialog.exec();
}


void 
MainWindow::editSelection()
{
	SelectionDialog dialog(document.getProject(), m_selection_manager, this);
	dialog.exec();
}


void 
MainWindow::setElementDisplay()
{
}


void 
MainWindow::setNodeForcesDisplay()
{
}


void 
MainWindow::runAnalysis()
{
	using namespace std;

	fem::Model &femp_model = this->document.getProject().model;

	// check if ther is a load pattern
	if( femp_model.load_pattern_list.empty() ) 
	{
		QMessageBox::critical(this, "No load patterns", "This model doesn't have any load patterns to run");
		return;
	}

	fem::Solver<double> * solver = NULL;

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
	connect(&progress,	SIGNAL(beginSection(std::string)),	&dialog,	SLOT(beginSection(std::string) ));
	connect(&progress,	SIGNAL(endSection()),	&dialog,	SLOT(endSection() ));
	connect(&progress,	SIGNAL(setProgress(size_t)),	&dialog,	SLOT(setProgress(size_t) ));
	connect(&progress,	SIGNAL(setMessage(std::string)),	&dialog,	SLOT(setMessage(std::string) ));
	connect(&progress,	SIGNAL(setError(std::string)),	&dialog,	SLOT(setError(std::string) ));
	connect(&progress,	SIGNAL(finish()),	&dialog,	SLOT(finish() ));

	//TODO finish this
	fem::AnalysisResult<double> analysis_result;
	analysis.set(femp_model, femp_model.load_pattern_list[analysis_dialog.loadPattern()], analysis_result, progress, solver);

	std::thread t(analysis);

	switch(dialog.exec())
	{
		case QDialog::Accepted:
			//TODO implement a way to abort the analysis thread if the abort button is pressed
			break;

		default:
			break;
	}
	t.join();

	if(analysis.succeeded())
	{
		document.getProject().pushAnalysisResult(analysis_result);

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
	auto & femp_result = document.getProject().result;

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
				delete document.file_name;
				document.file_name = NULL;
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
	AnalysisSummaryDialog dialog(document.getProject().result.back() , this);
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
		dialog.setDirectory(results_dump_dialog_last_directory);
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
		results_dump_dialog_last_directory = dialog.directory();

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
	fem::AnalysisResult<double> & femp_result = this->document.getProject().result.back();	// nasty hack

	Selection selection = m_selection_manager.getSelection();

	OutputResultsInNodesCSVVisitor visitor(selection, &femp_result, out);

	document.getProject().accept(visitor);

	file.close();
}


void 
MainWindow::showSelection()
{
	Selection selection = m_selection_manager.getSelection();
	
	QMdiSubWindow *mdi_window = mdiArea->currentSubWindow();
	if(mdi_window != NULL)
	{
		MdiWindow *window = static_cast<MdiWindow*>(mdi_window->widget() );
		if(window != NULL)
		{
			window->showSelection(selection);
		}
	}

}


void 
MainWindow::showAll()
{
	QMdiSubWindow *mdi_window = mdiArea->currentSubWindow();
	if(mdi_window != NULL)
	{
		MdiWindow *window = static_cast<MdiWindow*>(mdi_window->widget() );
		if(window != NULL)
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
	mdiArea->tileSubWindows();
}


void 
MainWindow::setCascadeWindows()
{
	mdiArea->cascadeSubWindows();
}


void 
MainWindow::createNewViewportWindow()
{
	this->createNewModelWindow();
}


void 
MainWindow::createNewModelWindow()
{
	ModelWindow *window;	// opengl viewport
	window = new ModelWindow(document.getProject(), colors, this);

	// create the model's MDI window
	QMdiSubWindow	* mdi_window = new QMdiSubWindow(mdiArea);
	mdi_window->setWidget(window);
	mdi_window->setAttribute(Qt::WA_DeleteOnClose);
	mdi_window->setWindowTitle(tr("Model"));
	mdi_window->showMaximized();
	window->connectToSelectionManager(this->m_selection_manager);

	// connect signals and slots
	setSignalsAndSlotsConnections(window);
}


void 
MainWindow::createNewPostprocessingWindow()
{
	auto &femp_result = document.getProject().result;
	if(femp_result.empty())
	{
		std::cerr << __FILE__ << ":" << __LINE__ ;
		std::cerr << "MainWindow::createNewPostprocessingWindow(): tried to set a postprocessing window although no results are available" << std::endl;
	}
	else
	{
		PostprocessingWindow *window;	// opengl viewport
		window = new PostprocessingWindow(document.getProject(), femp_result.back(), colors, this);

		// create the model's MDI window
		QMdiSubWindow	* mdi_window;	// the model's opengl viewport

		mdi_window = new QMdiSubWindow(mdiArea);
		mdi_window->setWidget(window);
		mdi_window->setAttribute(Qt::WA_DeleteOnClose);
		mdi_window->setWindowTitle(tr("Postprocessing"));
		mdi_window->showMaximized();
		window->connectToSelectionManager(this->m_selection_manager);
	}
}


void 
MainWindow::createNewTensorFieldWindow()
{
	if(document.getProject().result.empty())
	{
		std::cerr << __FILE__ << ":" << __LINE__ ;
		std::cerr << "MainWindow::createNewPostprocessingWindow(): tried to set a postprocessing window although no results are available" << std::endl;
	}
	else
	{
		TensorFieldWindow *window;	// MDI viewport
		window = new TensorFieldWindow(document.getProject(), document.getProject().result.back(), colors, this);

		// create the model's MDI window
		QMdiSubWindow	* mdi_window;

		mdi_window = new QMdiSubWindow(mdiArea);
		mdi_window->setWidget(window);
		mdi_window->setAttribute(Qt::WA_DeleteOnClose);
		mdi_window->setWindowTitle(tr("Tensor field"));
		mdi_window->showMaximized();
		window->connectToSelectionManager(this->m_selection_manager);
	}
}


void 
MainWindow::createNewAnalysisResultsWindow()
{
	std::cerr << __FILE__ << ":" << __LINE__ ;
	std::cerr << "MainWindow::createNewAnalysisResultsWindow()" << std::endl;
	if(document.getProject().result.empty())
	{
		std::cerr << __FILE__ << ":" << __LINE__ ;
		std::cerr << "MainWindow::createNewAnalysisResultWindow(): tried to set a results window although there is no result available" << std::endl;
		return;
	}

	AnalysisResultsWindow *mdi_window;
	mdi_window = new AnalysisResultsWindow(document.getProject(), mdiArea);
	mdi_window->showMaximized();
}


void 
MainWindow::createNewFemEquationWindow()
{
	std::cerr << __FILE__ << ":" << __LINE__ ;
	std::cerr << "MainWindow::createNewFemEquationWindow()" << std::endl;
	if(document.getProject().result.empty())
	{
		std::cerr << "MainWindow::createNewFemEquationWindow(): tried to set a results window although there is no result available" << std::endl;
		return;
	}

	MatrixWindow *mdi_window;
	mdi_window = new MatrixWindow(document.getProject(), mdiArea);
	mdi_window->showMaximized();
}


void 
MainWindow::updateWindowMenu()
{
	qWarning("MainWindow::updateWindowMenu()");

	QList<QMdiSubWindow *> 	subWindowList;
	subWindowList = mdiArea->subWindowList();

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
		m_window_mapper->setMapping(action, n);
		connect(action, SIGNAL(triggered()), m_window_mapper, SLOT(map()));
		connect(m_window_mapper, SIGNAL(mapped(int)), this, SLOT(activateSubWindowByIndex(int)));
	}
}


void 
MainWindow::activateSubWindowByIndex(int index)
{
	QList<QMdiSubWindow *> 	subWindowList;
	subWindowList = mdiArea->subWindowList();
	this->mdiArea->setActiveSubWindow(subWindowList[index]);
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

	// set toolbars
	createToolBars();

	// set the docks
	this->addDockWidget(static_cast<Qt::DockWidgetArea>(9), commandLineDockWidget);

	// set the window name
	if(document.file_name == NULL)
		this->setWindowTitle("Femp - [unnamed.fem.json]");
	else
		this->setWindowTitle("Femp - " + *document.file_name);
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
	mdiArea->closeAllSubWindows();

	// handle the toolbars
	destroyToolBars();

	// handle the docks
	this->removeDockWidget(commandLineDockWidget);
	commandLineDockWidget->clear();

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


void 
MainWindow::setSignalsAndSlotsConnections(ModelWindow *window)
{
	assert(window != NULL);
}


