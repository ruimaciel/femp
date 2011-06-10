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

#include <thread>
#include <string>
#include <fstream>
#include <iostream>	// for cout. remove after tests
#include <string>
#include <stdlib.h>	// getenv()

#include "Logs.h++"	// declare the global message loggers

#include "NewProjectWizard.h++"
#include "NodeRestrainsDialog.h++"
#include "NodeActionsDialog.h++"
#include "DisplayOptionsDialog.h++"
#include "ui/MaterialsEditorDialog.h++"
#include "ui/QuadratureRulesOptionsDialog.h++"
#include "ui/AnalysisProgressDialog.h++"
#include "ui/AnalysisDialog.h++"
#include "ui/MdiWindow.h++"
#include "ui/ModelWindow.h++"
#include "ui/ResultWindow.h++"

#include "fem_msh.h++"
#include "parsers/json.h"

#include "fem/NodeRestrictions.h++"

#include "DefaultProgressIndicator.h++"
#include "fem/Analysis.h++"
#include "fem/LinearAnalysis.h++"
#include "fem/AnalysisResult.h++"
#include "fem/solvers/CholeskySolver.h++"
#include "fem/solvers/CGSolver.h++"




MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	// set the MDI area widget as the window's central widget
	mdiArea = new QMdiArea;
	setCentralWidget(mdiArea);	// this main window has a Multiple Document Interface

	// Load global options from the options files
	this->loadOptions();

	// initialize the member attributes
	this->hasUnsavedChanges = false;

	// initialize the Docks
	commandLineDockWidget = new CommandLineDockWidget(this);
	connect(this, SIGNAL(setMessage(QString)), commandLineDockWidget, SLOT(getMessage(QString)));
	connect(this, SIGNAL(setWarning(QString)), commandLineDockWidget, SLOT(getWarning(QString)));
	connect(this, SIGNAL(setError(QString)), commandLineDockWidget, SLOT(getError(QString)));

	// set the MainWindow connections
	connect(&mylog,	SIGNAL(newMessage(QString)),	commandLineDockWidget, SLOT(getMessage(QString)));

	// create actions and connect signals to slots
	this->createActions();
	this->createToolBars();

	// set the user interface
	setUserInterfaceAsClosed();

}


void MainWindow::newProject()
{
	// initialize a new project
	std::string default_path, tmp;

	default_path = getenv("HOME");
	if(options.getOption("project.new.default_directory",tmp))
	{
		default_path += "/" + tmp;
	}

	/*
	The NewProjectWizard dialog will fill up a given document object through the steps
	*/
	NewProjectWizard np(&document, this);
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


void MainWindow::openProject()
{
	std::string last_path, tmp;

	// get the last dir where a project was opened 
	QFileDialog dialog(this);
	dialog.setDirectory(file_dialog_last_directory);
	
	QStringList sl;

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

	// prepare the file
	sl = dialog.selectedFiles();
	document.file_name = new QString;
	*document.file_name = sl.at(0);

	// load the file and check for errors
	switch( document.load() )
	{
		case Document::ERR_OK:
			// tweak the UI
			setUserInterfaceAsOpened();
			return;
			break;

		case Document::ERR_FILE_NOT_FOUND:
			QMessageBox::critical(this, tr("Error"), tr("File not found"));
			break;

		case Document::ERR_FILE_OPEN:
			QMessageBox::critical(this, tr("Error"), tr("There was an error opening the file"));
			break;

		case Document::ERR_INVALID_FILE:
			QMessageBox::critical(this, tr("Error"), tr("Invalid file"));
			break;

		case Document::ERR_PARSER_ERROR:
			QMessageBox::critical(this, tr("Error"), tr("Malformed file"));
			break;

		default:
			QMessageBox::critical(this, tr("Error"), tr("A misterious error occurred"));
			break;
	}

	// clean up the mess
	document.clear();
}


void MainWindow::reopenProject()
{
	if(document.file_name != NULL)
	{
		// clear the document
		setUserInterfaceAsClosed();
		this->document.project.model.clear();

		// load the file and check for errors
		switch( document.load() )
		{
			case Document::ERR_OK:
				// tweak the UI
				setUserInterfaceAsOpened();
				hasUnsavedChanges = false;
				return;
				break;

			case Document::ERR_FILE_NOT_FOUND:
				QMessageBox::critical(this, tr("Error"), tr("File not found"));
				break;

			case Document::ERR_FILE_OPEN:
				QMessageBox::critical(this, tr("Error"), tr("There was an error opening the file"));
				break;

			case Document::ERR_INVALID_FILE:
				QMessageBox::critical(this, tr("Error"), tr("Invalid file"));
				break;

			case Document::ERR_PARSER_ERROR:
				QMessageBox::critical(this, tr("Error"), tr("Malformed file"));
				break;

			default:
				QMessageBox::critical(this, tr("Error"), tr("A misterious error occurred"));
				break;
		}

		// clean up the mess
		document.clear();
	}
	else
	{
		QMessageBox::critical(this, tr("Error"), tr("This document hasn't been saved to a file"));
	}
}

void MainWindow::saveProject()
{
	mylog.setPrefix("MainWindow::saveProject()");
	
	if(document.file_name == NULL)
	{
		QFileDialog dialog(this);
		dialog.setDirectory(file_dialog_last_directory);
		QStringList sl;

		// setup the file dialog
		dialog.setFileMode(QFileDialog::AnyFile);
		dialog.setNameFilter(tr("FEM project (*.fem.json)"));
		dialog.setDefaultSuffix("fem.json");
		if(dialog.exec() == QDialog::Rejected)
		{
			// user cancelled 
			return;
		}

		file_dialog_last_directory = dialog.directory();

		sl = dialog.selectedFiles();
		document.file_name = new QString;
		*document.file_name = sl.at(0);
		// check if file already exists
		QFile file;
		file.setFileName(*document.file_name);
		if(file.exists())
		{
			QMessageBox msgBox;
			msgBox.setText(tr("File already exists") );
			msgBox.setInformativeText(tr("Do you want to overwrite it?") );
			msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
			msgBox.setDefaultButton(QMessageBox::No);
			if(msgBox.exec() == QMessageBox::No)
			{
				mylog.message("rejected");
				delete document.file_name;
				document.file_name = NULL;
				return;
			}
				mylog.message("accepted");
		}

		// set a new file name for this file
		
		this->setWindowTitle("Femp - " + *document.file_name);
		ui.actionReopen->setEnabled(true);
	}
	document.save();
	hasUnsavedChanges = false;

	mylog.clearPrefix();
}


void MainWindow::saveProjectAs()
{
	mylog.message("MainWindow::saveProjectAs() not yet implemented");

	QFileDialog dialog(this);
	QStringList sl;

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

	file_dialog_last_directory = dialog.directory();

	sl = dialog.selectedFiles();
	document.file_name = new QString;
	*document.file_name = sl.at(0);

	// tweak the UI
	document.save();
	hasUnsavedChanges = false;
}


void MainWindow::closeProject()
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
}


void MainWindow::quit()
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


void MainWindow::createActions()
{
	// connect the actions
	connect(ui.actionNew,	SIGNAL(triggered()), this,	SLOT(newProject()));
	connect(ui.actionOpen,	SIGNAL(triggered()), this,	SLOT(openProject()));
	connect(ui.actionReopen,	SIGNAL(triggered()), this,	SLOT(reopenProject()));
	connect(ui.actionSave,	SIGNAL(triggered()), this,	SLOT(saveProject()));
	connect(ui.actionSaveAs,	SIGNAL(triggered()), this,	SLOT(saveProjectAs()));
	connect(ui.actionClose,	SIGNAL(triggered()), this,	SLOT(closeProject()));
	connect(ui.actionQuit,	SIGNAL(triggered()), this,	SLOT(quit()));
	connect(ui.actionImportMesh,	SIGNAL(triggered()), this,	SLOT(importMesh()));
	connect(ui.actionNodeRestraints,	SIGNAL(triggered()), this,	SLOT(setNodeRestraints()));
	connect(ui.actionNodeActions,	SIGNAL(triggered()), this,	SLOT(setNodeActions()));
	connect(ui.actionRun,	SIGNAL(triggered()), this,	SLOT(runAnalysis()));
	connect(ui.actionDump_FEM_equation,	SIGNAL(triggered()),	this,	SLOT(dumpFemEquation()));

	connect(ui.actionViewActions,	SIGNAL(triggered()), this,	SLOT(setDisplayOptions()));
	connect(ui.actionEditMaterials,	SIGNAL(triggered()),	this,	SLOT(editMaterials()));
	connect(ui.actionDisplayNodes,	SIGNAL(triggered()), this,	SLOT(setElementDisplay()));
	connect(ui.actionDisplaySurfaces,	SIGNAL(triggered()), this,	SLOT(setElementDisplay()));

	connect(ui.actionWindowTile,	SIGNAL(triggered()), this,	SLOT(setTiledWindows()));
	connect(ui.actionWindowCascade,	SIGNAL(triggered()), this,	SLOT(setCascadeWindows()));
	connect(ui.actionNewViewportWindow,	SIGNAL(triggered()), this,	SLOT(createNewViewportWindow()));

	connect(ui.actionShowNodalForces,	SIGNAL(triggered()),	this,	SLOT(setNodeForcesDisplay()));

	connect(ui.actionViewModel,	SIGNAL(triggered()),	this,	SLOT(showModel()));
	connect(ui.actionViewDisplacements,	SIGNAL(triggered()),	this,	SLOT(showDisplacements()));

	connect(ui.actionQuadrature_rules,	SIGNAL(triggered()),	this,	SLOT(editQuadratureRules()) );
}


void MainWindow::createToolBars()
{
	// build the actions toolbar
	//TODO finish this
}


void MainWindow::destroyToolBars()
{
	//deletes all toolbars
}


void MainWindow::loadOptions()
{
	using namespace std;

	std::ifstream is;
	std::string path;
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
	path = "/etc/femp/options.opt";
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
		}
	}
	else
	{
		file_dialog_last_directory = QDir::home();
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

		if(options.getOption("viewport.wireframe.color",temp) )
		{ 
			if(temp.size() == 3) 
			{ 
				colors.wireframe[0] = temp[0]; 
				colors.wireframe[1] = temp[1]; 
				colors.wireframe[2] = temp[2]; 
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


/*
   Imports a mesh from a mesh document 
 */
void MainWindow::importMesh()
{
	mylog.setPrefix("MainWindow::importMesh()");

	QStringList files;
	QFile mesh_file;
	QFileDialog dialog(this);

	// setup the file dialog
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilter(tr("Mesh files (*.msh)"));
	//TODO import options from ProgramOptions

	if(dialog.exec())
	{
		// import file
		files = dialog.selectedFiles();
		mesh_file.setFileName(files[0]);
		if(!mesh_file.open(QIODevice::ReadOnly | QIODevice::Text) )
		{	// failed to open file
			//TODO implement variadic method to emulate printf()
			//mylog.message("unable to open file %s" + qPrintable(mesh_file.fileName()));
			mylog.message("unable to open file");

			QMessageBox msgBox(this);
			msgBox.setIcon(QMessageBox::Warning);
			msgBox.setWindowTitle("Error");
			msgBox.setText("Unable to open file "+mesh_file.fileName() );
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
			return;
		}

		// import mesh from a Gmsh file
		FILE *f = fdopen(mesh_file.handle(), "r");
		fem_model_import_msh(f,document.project.model);
		mesh_file.close();

		//TODO implement way to add document type from the dialog box
		document.setProjectType( Document::TYPE_SOLID3D);
	}
	// now this document has unsaved changes
	hasUnsavedChanges = true;
	
	mylog.clearPrefix();
}


void MainWindow::setNodeRestraints()
{
	assert(mdiArea != NULL);

	// check if active window supports node restraints
	//TODO implement this

	NodeRestrainsDialog nd;
	if(nd.exec() == QDialog::Accepted)
	{
		// get list of node restraints from active window
		fem::NodeRestrictions nr;
		int r = nd.getRestraints();
		for(std::map<size_t,bool>::iterator it = document.model_selection.nodes.begin(); it != document.model_selection.nodes.end(); it++)
		{
			if(it->second == true)
			{
				nr.reset();
				if(r & NodeRestrainsDialog::RX)
					nr.setdx();
				if(r & NodeRestrainsDialog::RY)
					nr.setdy();
				if(r & NodeRestrainsDialog::RZ)
					nr.setdz();
				document.project.model.node_restrictions_list[it->first] = nr;
			}
		}
	}
}


void MainWindow::setNodeActions()
{
	mylog.setPrefix("MainWindow::setNodeActions()");

	NodeActionsDialog na(document.project.model, this);
	if(na.exec() == QDialog::Accepted)
	{
		for(std::map<size_t,bool>::iterator it = document.model_selection.nodes.begin(); it != document.model_selection.nodes.end(); it++)
		{
			if(it->second == true)
			{
				document.model.load_pattern_list[na.getLoadPattern()].addNodalLoad(it->first, na.getForce());
				document.model.load_pattern_list[na.getLoadPattern()].addNodalDisplacement(it->first, na.getDisplacement());
			}
		}
	}

	mylog.clearPrefix();
}


void MainWindow::setDisplayOptions()
{
	//TODO make this generic
	/*
	   DisplayOptionsDialog da(document.project.model, this);
	   if(da.exec() == QDialog::Accepted)
	   {
	// set the LoadPattern pointer
	size_t n = da.getLoadPatternIndex();
	glWidget->display_options.load_pattern = &document.project.model.load_pattern_list[n];

	// set the other visualization options
	glWidget->display_options.nodal_forces = da.renderNodalForces();
	glWidget->display_options.surface_forces = da.renderSurfaceForces();
	glWidget->display_options.domain_forces = da.renderDomainForces();
	glWidget->display_options.nodal_displacements = da.renderNodalDisplacements();
	}
	 */
}


void MainWindow::editMaterials()
{
	//TODO finish this
	MaterialsEditorDialog dialog(&document.project.model, this);
	dialog.exec();
}


void MainWindow::editQuadratureRules()
{
	QuadratureRulesOptionsDialog dialog(analysis, this);
	dialog.exec();
}


void MainWindow::setElementDisplay()
{
}


void MainWindow::setNodeForcesDisplay()
{
}


void MainWindow::runAnalysis()
{
	mylog.setPrefix("MainWindow::runAnalysis()");

	using namespace std;

	// check if ther is a load pattern
	if( this->document.project.model.load_pattern_list.empty() ) 
	{
		QMessageBox::critical(this, "No load patterns", "This model doesn't have any load patterns to run");
		return;
	}

	fem::Solver<double> * solver = NULL;

	// run the AnalysisDialog to get the solver
	AnalysisDialog analysis_dialog(document.project.model, this);
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
	QString message;
	fem::AnalysisResult<double> analysis_result;
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
	analysis.set(document.project.model, document.project.model.load_pattern_list[analysis_dialog.loadPattern()], analysis_result, progress, solver);

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

	document.project.pushAnalysisResult(analysis_result);

	//TODO set the UI

	QMdiSubWindow *displacements_window;

	displacements_window = mdiArea->activeSubWindow();
	if(displacements_window == NULL)
	{
		// no window is currently active
		ModelViewport *viewport;	// opengl viewport
		viewport = new ModelViewport(document.project, this);
		viewport->setColors(colors);

		// create the model's MDI window
		displacements_window = new QMdiSubWindow(mdiArea);
		displacements_window->setWidget(viewport);
		displacements_window->setAttribute(Qt::WA_DeleteOnClose);
		displacements_window->showMaximized();

		mdiArea->setActiveSubWindow(displacements_window);
	}
	
	this->showDisplacements();

        ui.actionDump_FEM_equation->setEnabled(true);

	delete solver;


	mylog.clearPrefix();
}


void MainWindow::dumpFemEquation()
{
	if( document.project.result.empty() )
	{
		QMessageBox::information(this, "No analysis", "There isn't a equation to dump");
	}
	else
	{
		using namespace std;

		//TODO pick file name
		QFileDialog dialog(this);
		QStringList sl;
		QString file_name;

		// setup the file dialog
		dialog.setFileMode(QFileDialog::AnyFile);
		dialog.setNameFilter(tr("Octave file (*.oct)"));
		dialog.setDefaultSuffix("oct");
		if(dialog.exec() == QDialog::Rejected)
		{
			// user cancelled 
			return;
		}
		sl = dialog.selectedFiles();
		file_name = sl.at(0);

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
				mylog.message("rejected");
				delete document.file_name;
				document.file_name = NULL;
				return;
			}
			mylog.message("accepted");
		}

		// set a new file name for this file

		file.open(QFile::WriteOnly);
		QTextStream     out(&file);
		out.setRealNumberNotation(QTextStream::ScientificNotation);
		out.setRealNumberPrecision(16);
		// */
		/*
		   ofstream out(file.fileName().toStdString () );
		   out << "test" << endl;
		 */


		out << "# Created by lalib\n";
		out << "# name: K\n";
		out << "# type: matrix\n";
		out << "# rows: " << document.project.result.back().K.rows() << "\n";
		out << "# columns: " << document.project.result.back().K.columns() << "\n";

		for(size_t j = 0; j < document.project.result.back().K.columns(); j++)
		{
			for(size_t i = 0; i < document.project.result.back().K.rows(); i++)
			{
				out << " " << document.project.result.back().K.value(i,j);
			}
			out << "\n";
		}
		out << endl;
		// */
		/*
		   out << "# Created by lalib\n";
		   out << "# name: K\n";
		   out << "# type: sparse matrix\n";
		   out << "# nnz: " << document.project.result.back().K.data.data.size() << "\n";
		   out << "# rows: " << document.project.result.back().K.rows() << "\n";
		   out << "# columns: " << document.project.result.back().K.columns() << "\n";

		   for( std::map< size_t, double>::iterator i = document.project.result.back().K.data.data.begin(); i != document.project.result.back().K.data.data.end(); i++)
		   {
		   out << i->first/document.project.result.back().K.columns() << " " << i->first%document.project.result.back().K.columns() << " " << i->second << "\n";
		   }
		   out << endl;
		// */

		//lalib::dump_octave(out, "f", document.project.result.back().f);
		out << "# Created by lalib\n";
		out << "# name: f\n";
		out << "# type: matrix\n";
		out << "# rows: " << document.project.result.back().f.size() << "\n";
		out << "# columns: 1\n";
		for(size_t i = 0; i < document.project.result.back().f.size(); i++)
		{
			out << " " << document.project.result.back().f.value(i) << "\n";
		}
		out << endl;
		//*/

		//lalib::dump_octave(out, "d", document.project.result.back().d);

		out << "# Created by lalib\n";
		out << "# name: d\n";
		out << "# type: matrix\n";
		out << "# rows: " << document.project.result.back().d.size() << "\n";
		out << "# columns: 1\n";
		for(size_t i = 0; i < document.project.result.back().d.size(); i++)
		{
			out << " " << document.project.result.back().d.value(i) << "\n";
		}
		out << endl;
		//*/
		//out.close();
		file.close();
	}
}


void MainWindow::showModel()
{
	//TODO finish this
	QMdiSubWindow *window;

	window = mdiArea->activeSubWindow();
	if(window != NULL)
	{
		window->setWindowTitle("Model");

		ModelWindow *model_window = new ModelWindow(document.project, colors, this);
		window->setWidget(model_window);
	}
	else
	{
		this->createNewViewportWindow();
	}
}


void MainWindow::showDisplacements()
{
	QMdiSubWindow *window;

	window = mdiArea->activeSubWindow();
	if(window != NULL)
	{
		window->setWindowTitle("Displacements");

		//TODO rename ResultWindow to DisplacementsWindow
		ResultWindow *viewport = new ResultWindow(document.project, colors, this);
		window->setWidget(viewport);
	}
	else
	{
		qWarning("MainWindow::showDisplacements(): no active subwindow");
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
	mdiArea->tileSubWindows();
}


void MainWindow::setCascadeWindows()
{
	mdiArea->cascadeSubWindows();
}


void MainWindow:: createNewViewportWindow()
{
	ModelWindow *window;	// opengl viewport
	window = new ModelWindow(document.project, colors, this);

	// create the model's MDI window
	QMdiSubWindow	* window_gl_viewport;	// the model's opengl viewport

	window_gl_viewport = new QMdiSubWindow(mdiArea);
	window_gl_viewport->setWidget(window);
	window_gl_viewport->setAttribute(Qt::WA_DeleteOnClose);
	window_gl_viewport->setWindowTitle(tr("model viewport"));
	window_gl_viewport->showMaximized();
}


void MainWindow::setUserInterfaceAsOpened()
{
	mylog.setPrefix("MainWindow::setUserInterfaceAsOpened()");

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
	ui.actionEditMaterials->setEnabled(true);
	ui.actionQuadrature_rules->setEnabled(true);

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

	mylog.clearPrefix();
}


void MainWindow::setUserInterfaceAsClosed()	
{
	// set the menus
	ui.menuProject->setDisabled(true);
	ui.menuView->setDisabled(true);
	ui.menuWindow->setDisabled(true);
	ui.actionReopen->setDisabled(true);
	ui.actionSave->setDisabled(true);
	ui.actionSaveAs->setDisabled(true);
	ui.actionClose->setDisabled(true);
	ui.actionNodeRestraints->setDisabled(true);
	ui.actionNodeActions->setDisabled(true);
	ui.actionEditMaterials->setDisabled(true);
	ui.actionQuadrature_rules->setDisabled(true);
        ui.actionDump_FEM_equation->setDisabled(true);

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

