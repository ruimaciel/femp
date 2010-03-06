#include "MainWindow.h++"
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QTranslator>
#include <QToolBar>

#include <string>
#include <fstream>
#include <iostream>	// for cout. remove after tests
#include <string>
#include <stdlib.h>	// getenv()

#include "NewProjectWizard.h++"
#include "NodeRestrainsDialog.h++"
#include "NodeActionsDialog.h++"
#include "DisplayOptionsDialog.h++"

#include "fem_msh.h++"
#include "parsers/json.h"

#include "fem/NodeRestrictions.h++"
#include "fem/Analysis.h++"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	mdiArea = new QMdiArea;
	setCentralWidget(mdiArea);	// this main window has a Multiple Document Interface
	//mdiArea->setViewMode(QMdiArea::TabbedView);
	window_gl_viewport = NULL;	// no windows on startup

	// Load global options from the options files
	this->loadOptions();

	// initialize the member attributes
	this->hasUnsavedChanges = false;

	// set up the dock widgets
	/*
	commandLineDockWidget = new CommandLineDockWidget(this);
	this->addDockWidget(static_cast<Qt::DockWidgetArea>(8), commandLineDockWidget);
	*/

	// initialize the toolbars
	visibilityToolBar = NULL;
	viewportToolBar = NULL;

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
	if(options.getOption("project.new.default_directory",tmp, ""))
	{
		default_path += "/" + tmp;
	}

	/*
	Now the "new project" wizard will create a new project directory.
	Then it will call loadProject() to load the newly created project.
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
	QStringList sl;

	// setup the file dialog
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilter(tr("FEM project (*.fem.json)"));
	if(dialog.exec() == QDialog::Rejected)
	{
		// user cancelled, no file was loaded
		return;
	}
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


void MainWindow::saveProject()
{
	//TODO finish this
	if(document.file_name == NULL)
	{
		QFileDialog dialog(this);
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
				qWarning("rejected");
				delete document.file_name;
				document.file_name = NULL;
				return;
			}
				qWarning("accepted");
		}

		// set a new file name for this file
		
	}
	document.save();
	hasUnsavedChanges = false;
}


void MainWindow::saveProjectAs()
{
	qWarning("MainWindow::saveProjectAs() not yet implemented");
	//TODO finish this

	QFileDialog dialog(this);
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

	//TODO finish this
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
	 connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(newProject()));
	 connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openProject()));
	 connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(saveProject()));
	 connect(ui.actionSaveAs, SIGNAL(triggered()), this, SLOT(saveProjectAs()));
	 connect(ui.actionClose, SIGNAL(triggered()), this, SLOT(closeProject()));
	 connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(quit()));
	 connect(ui.actionImportMesh, SIGNAL(triggered()), this, SLOT(importMesh()));
	 connect(ui.actionTogglePerspective, SIGNAL(triggered()), this, SIGNAL(togglePerspective()));
	 connect(ui.actionNodeRestraints, SIGNAL(triggered()), this, SLOT(setNodeRestraints()));
	 connect(ui.actionNodeActions, SIGNAL(triggered()), this, SLOT(setNodeActions()));
	 connect(ui.actionRun, SIGNAL(triggered()), this, SLOT(runAnalysis()));
	 connect(ui.actionViewActions, SIGNAL(triggered()), this, SLOT(setDisplayOptions()));
	 connect(ui.actionDisplayNodes, SIGNAL(triggered()), this, SLOT(setElementDisplay()));
	 connect(ui.actionDisplaySurfaces, SIGNAL(triggered()), this, SLOT(setElementDisplay()));
	 connect(ui.actionDisplayWireframe, SIGNAL(triggered()), this, SLOT(setElementDisplay()));
}


void MainWindow::createToolBars()
{
	visibilityToolBar = addToolBar(tr("Visibility"));
	visibilityToolBar->addAction(ui.actionDisplayNodes);
	visibilityToolBar->addAction(ui.actionDisplaySurfaces);
	visibilityToolBar->addAction(ui.actionDisplayWireframe);
	//TODO add actions
}


void MainWindow::destroyToolBars()
{
	removeToolBar(visibilityToolBar);
}


void MainWindow::loadOptions()
{
	std::ifstream is;
	std::string path;
	std::vector<double> default_color;

	// Set default options
	options.setDefault();
	options.setOption("viewport.nodes.radius",10.0f);	// sets the default node radius
	default_color.reserve(3);
	default_color[0] = 0, default_color[1] = 0.8f, default_color[2] = 0.8f;
	options.setOption("viewport.nodes.color",default_color);
	default_color[0] = 0, default_color[1] = 0, default_color[2] = 0;
	options.setOption("viewport.wireframe.color",default_color);
	default_color[0] = 0, default_color[1] = 0, default_color[2] = 1;
	options.setOption("viewport.elements.tetrahedron4.color",default_color);
	options.setOption("viewport.elements.tetrahedron10.color",default_color);
	options.setOption("viewport.elements.hexahedron8.color",default_color);
	options.setOption("viewport.elements.hexahedron27.color",default_color);

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
	
	// set color options
	{
	std::vector<double> temp;
	if(options.getOption("viewport.nodes.color",temp, std::vector<double>())) 
	{ 
		if(temp.size() == 3) 
		{ 
			colors.node[0] = temp[0]; 
			colors.node[1] = temp[1]; 
			colors.node[2] = temp[2]; 
		} 
	} 

	if(options.getOption("viewport.wireframe.color",temp, std::vector<double>())) 
	{ 
		if(temp.size() == 3) 
		{ 
			colors.wireframe[0] = temp[0]; 
			colors.wireframe[1] = temp[1]; 
			colors.wireframe[2] = temp[2]; 
		} 
	} 


	// set up a helper function
	#define SET_ELEMENT_COLOR(ELEMENT) { \
	if(options.getOption("viewport.elements."#ELEMENT".color",temp, std::vector<double>())) \
	{ \
		if(temp.size() == 3) \
		{ \
			colors.ELEMENT[0] = temp[0]; \
			colors.ELEMENT[1] = temp[1]; \
			colors.ELEMENT[2] = temp[2]; \
		} \
	} }

	// let's set the element colors
	SET_ELEMENT_COLOR(tetrahedron4);
	SET_ELEMENT_COLOR(tetrahedron10);
	SET_ELEMENT_COLOR(hexahedron8);
	SET_ELEMENT_COLOR(hexahedron27);

	#undef SET_ELEMENT_COLOR
	}
}


/*
Imports a mesh from a mesh document 
*/
void MainWindow::importMesh()
{
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
			//TODO include file name
			qWarning("unable to open file %s",qPrintable(mesh_file.fileName()));
			QMessageBox msgBox(this);
			msgBox.setIcon(QMessageBox::Warning);
			msgBox.setWindowTitle("Error");
			msgBox.setText("Unable to open file "+mesh_file.fileName() );
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
			return;
		}

		// TODO import mesh from a Gmsh file
		FILE *f = fdopen(mesh_file.handle(), "r");
		fem_model_import_msh(f,document.model);
		mesh_file.close();
	}
	// now this document has unsaved changes
	hasUnsavedChanges = true;
}

	
void MainWindow::setNodeRestraints()
{
	NodeRestrainsDialog nd;
	if(nd.exec() == QDialog::Accepted)
	{
		fem::NodeRestrictions nr;
		int r = nd.getRestraints();
		for(std::map<size_t,bool>::iterator it = document.selected_nodes.begin(); it != document.selected_nodes.end(); it++)
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
				document.model.node_restrictions_list[it->first] = nr;
			}
		}
	}
}


void MainWindow::setNodeActions()
{
	qWarning("dude");
	NodeActionsDialog na(document.model, this);
	if(na.exec() == QDialog::Accepted)
	{
		for(std::map<size_t,bool>::iterator it = document.selected_nodes.begin(); it != document.selected_nodes.end(); it++)
		{
		if(it->second == true)
		{
			document.model.load_pattern_list[na.getLoadPattern()].addNodalLoad(it->first, na.getForce());
			document.model.load_pattern_list[na.getLoadPattern()].addNodalDisplacement(it->first, na.getDisplacement());
		}
		}
	}
}


void MainWindow::setDisplayOptions()
{
	DisplayOptionsDialog da(document.model, this);
	if(da.exec() == QDialog::Accepted)
	{
		// set the LoadPattern pointer
		size_t n = da.getLoadPatternIndex();
		glWidget->display_options.load_pattern = &document.model.load_pattern_list[n];

		// set the other visualization options
		glWidget->display_options.nodal_forces = da.renderNodalForces();
		glWidget->display_options.surface_forces = da.renderSurfaceForces();
		glWidget->display_options.domain_forces = da.renderDomainForces();
		glWidget->display_options.nodal_displacements = da.renderNodalDisplacements();
	}
}


void MainWindow::setElementDisplay()
{
	if(glWidget != NULL)
	{
		glWidget->display_options.nodes 	= this->ui.actionDisplayNodes->isChecked()?1:0;
		glWidget->display_options.surfaces	= this->ui.actionDisplaySurfaces->isChecked()?1:0;
		glWidget->display_options.wireframe	= this->ui.actionDisplayWireframe->isChecked()?1:0;
	}
}


void MainWindow::runAnalysis()
{
	//TODO finish this
	fem::Analysis analysis;

	//TODO for testing purposes only. remove
	// document.model.run(document.model.load_pattern_list[0]);	// nasty hack to test the code
	analysis.run(document.model, document.model.load_pattern_list[0]);
}


void MainWindow::setUserInterfaceAsOpened()	
{
	//TODO finish this
	// set the menus
	ui.menuProject->setEnabled(true);
	ui.menuView->setEnabled(true);
	ui.menuWindow->setEnabled(true);
	ui.actionSave->setEnabled(true);
	ui.actionSaveAs->setEnabled(true);
	ui.actionClose->setEnabled(true);
	ui.actionNodeRestraints->setEnabled(true);
	ui.actionNodeActions->setEnabled(true);
	ui.actionDisplayNodes->setChecked(true);
	ui.actionDisplaySurfaces->setChecked(true);
	ui.actionDisplayWireframe->setChecked(true);

	// open all relevant MDI windows
	glWidget = new GLWidget(this);
	glWidget->setDocument(&document);
	glWidget->setColors(&colors);
	double radius;
	options.getOption("viewport.nodes.radius",radius,20);
	glWidget->setNodeRadiusScale(radius);
	glWidget->setFocusPolicy(Qt::StrongFocus);
	glWidget->display_options.setDefaultOptions();
	connect(this,SIGNAL(togglePerspective()), glWidget, SLOT(togglePerspective()));
	
	window_gl_viewport = new QMdiSubWindow(mdiArea);
	window_gl_viewport->setWidget(glWidget);
	window_gl_viewport->setAttribute(Qt::WA_DeleteOnClose);
	window_gl_viewport->setWindowTitle(tr("model viewport"));
	window_gl_viewport->showMaximized();
	//mdiArea->addSubWindow(window_gl_viewport);
	// enable the "close"

	// set toolbars
	createToolBars();
}


void MainWindow::setUserInterfaceAsClosed()	
{
	//TODO finish this
	// set the menus
	ui.menuProject->setDisabled(true);
	ui.menuView->setDisabled(true);
	ui.menuWindow->setDisabled(true);
	ui.actionSave->setDisabled(true);
	ui.actionSaveAs->setDisabled(true);
	ui.actionClose->setDisabled(true);
	ui.actionNodeRestraints->setDisabled(true);
	ui.actionNodeActions->setDisabled(true);

	// close all MDI windows
	if(window_gl_viewport != NULL)
	{
		//TODO free glWidget?
		mdiArea->removeSubWindow(window_gl_viewport);
		delete window_gl_viewport; 
		window_gl_viewport = NULL;
	}
	mdiArea->closeAllSubWindows();

	// handle the toolbars
	destroyToolBars();
}

