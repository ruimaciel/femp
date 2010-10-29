#include "MainWindow.h++"
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QTime>
#include <QTranslator>
#include <QToolBar>
#include <QString>

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

#include "fem_msh.h++"
#include "parsers/json.h"

#include "fem/NodeRestrictions.h++"

#include "fem/Analysis.h++"
#include "fem/LinearAnalysis.h++"

#include "viewer/ModelViewport.h++"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	// set the MDI area widget as the window's central widget
	mdiArea = new QMdiArea;
	setCentralWidget(mdiArea);	// this main window has a Multiple Document Interface
	//mdiArea->setViewMode(QMdiArea::TabbedView);

	// Load global options from the options files
	this->loadOptions();

	// initialize the member attributes
	this->hasUnsavedChanges = false;


	// initialize the toolbars
	visibilityToolBar	= NULL;
	viewportToolBar	= NULL;
	actionsToolBar	= NULL;
	comboActionsLoadPattern	= NULL;

	// initialize the Docks
	commandLineDockWidget = new CommandLineDockWidget(this);
	connect(this, SIGNAL(setMessage(QString)), commandLineDockWidget, SLOT(getMessage(QString)));
	connect(this, SIGNAL(setWarning(QString)), commandLineDockWidget, SLOT(getWarning(QString)));
	connect(this, SIGNAL(setError(QString)), commandLineDockWidget, SLOT(getError(QString)));

	// set the MainWindow connections
	connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(updateUiFromActiveMdiSubWindow(QMdiSubWindow*)));
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
	if(options.getOption("project.new.default_directory",tmp, ""))
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
	mylog.setPrefix("MainWindow::saveProject()");
	
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
				mylog.message("rejected");
				delete document.file_name;
				document.file_name = NULL;
				return;
			}
				mylog.message("accepted");
		}

		// set a new file name for this file
		
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
	// create actions
	actionViewportXY = new QAction("XY", this);
	actionViewportYZ = new QAction("YZ", this);
	actionViewportXZ = new QAction("XZ", this);
	actionViewportIso = new QAction("iso", this);

	// connect the actions
	connect(actionViewportXY,	SIGNAL(triggered()),	this,	SLOT(setViewportXY()));
	connect(actionViewportYZ,	SIGNAL(triggered()),	this,	SLOT(setViewportYZ()));
	connect(actionViewportXZ,	SIGNAL(triggered()),	this,	SLOT(setViewportXZ()));
	connect(actionViewportIso,	SIGNAL(triggered()),	this,	SLOT(setViewportIso()));
	connect(ui.actionNew, 	SIGNAL(triggered()), this, SLOT(newProject()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openProject()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(saveProject()));
	connect(ui.actionSaveAs, SIGNAL(triggered()), this, SLOT(saveProjectAs()));
	connect(ui.actionClose, SIGNAL(triggered()), this, SLOT(closeProject()));
	connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(quit()));
	connect(ui.actionImportMesh, SIGNAL(triggered()), this, SLOT(importMesh()));
	connect(ui.actionNodeRestraints, SIGNAL(triggered()), this, SLOT(setNodeRestraints()));
	connect(ui.actionNodeActions, SIGNAL(triggered()), this, SLOT(setNodeActions()));
	connect(ui.actionRun, SIGNAL(triggered()), this, SLOT(runAnalysis()));
	connect(ui.actionViewActions, SIGNAL(triggered()), this, SLOT(setDisplayOptions()));
	connect(ui.actionEditMaterials, SIGNAL(triggered()),	this,	SLOT(editMaterials()));
	connect(ui.actionDisplayNodes, SIGNAL(triggered()), this, SLOT(setElementDisplay()));
	connect(ui.actionDisplaySurfaces, SIGNAL(triggered()), this, SLOT(setElementDisplay()));
	connect(ui.actionDisplayWireframe, SIGNAL(triggered()), this, SLOT(setElementDisplay()));

	connect(ui.actionWindowTile, SIGNAL(triggered()), this, SLOT(setTiledWindows()));
	connect(ui.actionWindowCascade, SIGNAL(triggered()), this, SLOT(setCascadeWindows()));

	connect(ui.actionShowNodalForces,	SIGNAL(triggered()),	this,	SLOT(setNodeForcesDisplay()));
}


void MainWindow::createToolBars()
{
	// build the visibility toolbar
	visibilityToolBar = addToolBar(tr("Visibility"));
	visibilityToolBar->addAction(ui.actionDisplayNodes);
	visibilityToolBar->addAction(ui.actionDisplaySurfaces);
	visibilityToolBar->addAction(ui.actionDisplayWireframe);

	// build the viewport toolbar
	viewportToolBar = addToolBar(tr("Viewport"));
	viewportToolBar->addAction(actionViewportXY);
	viewportToolBar->addAction(actionViewportYZ);
	viewportToolBar->addAction(actionViewportXZ);
	viewportToolBar->addAction(actionViewportIso);

	// build the actions toolbar
	//TODO finish this
	actionsToolBar = addToolBar(tr("Display actions"));

	comboActionsLoadPattern = new QComboBox;
	// fill the combo box with load patterns
	if(document.model.load_pattern_list.empty())
	{
		comboActionsLoadPattern->addItem(tr("no load cases"));
		comboActionsLoadPattern->setDisabled(true);
	}
	else
	{
		// fill the combo box with all the load patterns which were already defined
		for(std::vector<fem::LoadPattern>::iterator i = document.model.load_pattern_list.begin(); i != document.model.load_pattern_list.end(); i++)
		{
			comboActionsLoadPattern->addItem(QString::fromStdString(i->label));
		}
	}
	// add the rest of the toolbar buttons
	actionsToolBar->addWidget(comboActionsLoadPattern);
	actionsToolBar->addAction(ui.actionShowNodalDisplacements);
	actionsToolBar->addAction(ui.actionShowNodalForces);
	actionsToolBar->addAction(ui.actionShowSurfaceForces);
	actionsToolBar->addAction(ui.actionShowDomainForces);
}


void MainWindow::destroyToolBars()
{
	//deletes all toolbars
	if(visibilityToolBar)
	{
		removeToolBar(visibilityToolBar); 
		delete visibilityToolBar;
		visibilityToolBar = NULL;
	}
	if(viewportToolBar)
	{
		removeToolBar(viewportToolBar); 
		delete viewportToolBar;
		viewportToolBar = NULL;
	}
	if(actionsToolBar)
	{
		//TODO delete the load pattern combo box?
		removeToolBar(actionsToolBar); 
		delete actionsToolBar;
		actionsToolBar = NULL;
	}
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

		//TODO add code for the force arrows custom color code
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
		fem_model_import_msh(f,document.model);
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
				document.model.node_restrictions_list[it->first] = nr;
			}
		}
	}
}


void MainWindow::setNodeActions()
{
	mylog.setPrefix("MainWindow::setNodeActions()");

	NodeActionsDialog na(document.model, this);
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
	 */
}


void MainWindow::editMaterials()
{
	//TODO finish this
	MaterialsEditorDialog dialog(&document.model, this);
	dialog.exec();
}


void MainWindow::setElementDisplay()
{
	mylog.setPrefix("MainWindow::setElementDisplay()");
	//TODO make this rely on the active window
	if(mdiArea->activeSubWindow() != NULL)
	{
		// mdiArea has an active subwindow
		MdiWindowProperties *mwp = dynamic_cast<MdiWindowProperties *>(mdiArea->activeSubWindow()->widget());

		if(mwp == NULL)
		{
			mylog.message("no can do");
			return;
		}

		// set the new viewport according to the MDI subwindow's widget type
		switch(mwp->window_type)
		{
			case MdiWindowProperties::MWP_Model:
				{
					mylog.message("MWP_Model");
					ModelViewport *w = static_cast<ModelViewport *>(mwp);

					// set the position
					w->display_options.nodes 	= this->ui.actionDisplayNodes->isChecked()?1:0;
					w->display_options.surfaces	= this->ui.actionDisplaySurfaces->isChecked()?1:0;
					w->display_options.wireframe	= this->ui.actionDisplayWireframe->isChecked()?1:0;
				}
				break;

			default:
				mylog.message("void MainWindow::setElementDisplay(): unsupported case");
				break;
		}
	}

	mylog.clearPrefix();
}


void MainWindow::setNodeForcesDisplay()
{
	//TODO make this rely on the active window
	if(mdiArea->activeSubWindow() != NULL)
	{
		// mdiArea has an active subwindow
		MdiWindowProperties *mwp = dynamic_cast<MdiWindowProperties *>(mdiArea->activeSubWindow()->widget());

		if(mwp == NULL)
		{
			mylog.message("MainWindow::setNodeForcesDisplay(): no can do");
			return;
		}

		// set the new viewport according to the MDI subwindow's widget type
		switch(mwp->window_type)
		{
			case MdiWindowProperties::MWP_Model:
				{
					ModelViewport *w = static_cast<ModelViewport *>(mwp);

					// set the position
					w->display_options.nodal_forces 	= this->ui.actionShowNodalForces->isChecked()?1:0;
				}
				break;

			default:
				mylog.message("void MainWindow::setNodeForcesDisplay(): unsupported case");
				break;
		}
	}
}


void MainWindow::runAnalysis()
{
	mylog.setPrefix("MainWindow::runAnalysis()");

	using namespace std;

	//emit setMessage("Model analysis: started");
	mylog.message("Model analysis: started");

	QString message;
	QTime time;

	time.start();	// to get the run time

	//TODO finish this
	//TODO consider options for integration points
	fem::LinearAnalysis<double> analysis;

	//TODO for testing purposes only. remove

	analysis.run(document.model, document.model.load_pattern_list[0]);

	message.sprintf("Model analysis: finished after %d ms", time.elapsed());
	//TODO implement variadic function
	mylog.message(message);


	//TODO implement displacements viewport
	mylog.message("displacements widget wasn't implemented yet");

	/*
	// create subwindows
	GLDisplacementsWidget *glDisplacementsWidget;
	std::map<size_t, fem::Node> dm = analysis.displacements_map();	//TODO pass the displacements_map to the ProcessedModel object

	glDisplacementsWidget = new GLDisplacementsWidget(&document, &document.processed_model.back(), this);
	glDisplacementsWidget->setColors(&colors);

	double radius;
	options.getOption("viewport.nodes.radius",radius,20);
	glDisplacementsWidget->setNodeRadiusScale(radius);
	glDisplacementsWidget->setFocusPolicy(Qt::StrongFocus);
	glDisplacementsWidget->display_options.setDefaultOptions();

	// create new MDI window for the displacements widget
	QMdiSubWindow *subWindow;
	subWindow = new QMdiSubWindow(mdiArea);
	subWindow->setWidget(glDisplacementsWidget);
	subWindow->setAttribute(Qt::WA_DeleteOnClose);
	subWindow->setWindowTitle("Displacements");

	glDisplacementsWidget->show();

	*/

	mylog.clearPrefix();
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


void MainWindow::setViewportXY()
{
	//TODO check if current MDI window supports this feature
	if(mdiArea->activeSubWindow() != NULL)
	{
		// mdiArea has an active subwindow
		MdiWindowProperties *mwp = dynamic_cast<MdiWindowProperties *>(mdiArea->activeSubWindow()->widget());

		if(mwp == NULL)
		{
			mylog.message("no can do");
			return;
		}

		// set the new viewport according to the MDI subwindow's widget type
		switch(mwp->window_type)
		{
			case MdiWindowProperties::MWP_Model:
				{
					mylog.message("MWP_Model");
					ModelViewport *w = static_cast<ModelViewport *>(mwp);

					// set the position
					w->setXRotation(0);
					w->setYRotation(0);
					w->setZRotation(0);
				}
				break;

			default:
				mylog.message("void MainWindow::setViewportXY(): unsupported case");
				break;
		}
	}
}


void MainWindow::setViewportYZ()
{
	//TODO check if current MDI window supports this feature
	if(mdiArea->activeSubWindow() != NULL)
	{
		// mdiArea has an active subwindow
		MdiWindowProperties *mwp = dynamic_cast<MdiWindowProperties *>(mdiArea->activeSubWindow()->widget());

		if(mwp == NULL)
		{
			mylog.message("MainWindow::setViewportYZ(): casting to MdiWindowProperties has failed");
			return;
		}

		// set the new viewport according to the MDI subwindow's widget type
		switch(mwp->window_type)
		{
			case MdiWindowProperties::MWP_Model:
				{
					mylog.message("MWP_Model");
					ModelViewport *w = static_cast<ModelViewport *>(mwp);

					// set the position
					w->setXRotation(0);
					w->setYRotation(270);
					w->setZRotation(0);
				}
				break;

			default:
				mylog.message("void MainWindow::setViewportXY(): unsupported case");
				break;
		}
	}
}


void MainWindow::setViewportXZ()
{
	//TODO check if current MDI window supports this feature
	if(mdiArea->activeSubWindow() != NULL)
	{
		// mdiArea has an active subwindow
		MdiWindowProperties *mwp = dynamic_cast<MdiWindowProperties *>(mdiArea->activeSubWindow()->widget());

		if(mwp == NULL)
		{
			mylog.message("MainWindow::setViewportXZ(): casting to MdiWindowProperties has failed");
			return;
		}

		// set the new viewport according to the MDI subwindow's widget type
		switch(mwp->window_type)
		{
			case MdiWindowProperties::MWP_Model:
				{
					mylog.message("MWP_Model");
					ModelViewport *w = static_cast<ModelViewport *>(mwp);

					// set the view angle
					w->setXRotation(90);
					w->setYRotation(0);
					w->setZRotation(0);
				}
				break;

			default:
				mylog.message("void MainWindow::setViewportXZ(): unsupported case");
				break;
		}
	}
}


void MainWindow::setViewportIso()
{
	mylog.setPrefix("MainWindow::setViewportIso()");
	mylog.message("MainWindow::setViewportIso(): needs to be implemented");
	mylog.clearPrefix();
}


void MainWindow::setTiledWindows()
{
	mdiArea->tileSubWindows();
}


void MainWindow::setCascadeWindows()
{
	mdiArea->cascadeSubWindows();
}


void MainWindow::updateUiFromActiveMdiSubWindow(QMdiSubWindow *subwindow)
{
	mylog.setPrefix("MainWindow::updateUiFromActiveMdiSubWindow(QMdiSubWindow *subwindow)");

	//TODO finish this
	if(subwindow == NULL)
	{
		// there are no active windows in the workspace
		//TODO finish this
	}
	else
	{
		// update the UI accordingly
		MdiWindowProperties *mwp = dynamic_cast<MdiWindowProperties *>(subwindow->widget());

		if(mwp == NULL)
		{
			mylog.message("void MainWindow::updateUiFromActiveMdiSubWindow(QMdiSubWindow *subwindow): failed to access the window's MdiWindoProperties");
			return;
		}

		// set the new viewport according to the MDI subwindow's widget type
		switch(mwp->window_type)
		{
			case MdiWindowProperties::MWP_Model:
				{
					//mylog.message("MWP_Model");
					ModelViewport *w = static_cast<ModelViewport *>(mwp);

					// update the UI according to this window's options
					this->ui.actionDisplayNodes->setChecked(w->display_options.nodes);
					this->ui.actionDisplaySurfaces->setChecked(w->display_options.surfaces);
					this->ui.actionDisplayWireframe->setChecked(w->display_options.wireframe);

					// change combo box
					//TODO set the combo box to the current load pattern
					this->ui.actionShowNodalDisplacements->setChecked(w->display_options.nodal_displacements);
					this->ui.actionShowNodalForces->setChecked(w->display_options.nodal_forces);
					this->ui.actionShowSurfaceForces->setChecked(w->display_options.surface_forces);
					this->ui.actionShowDomainForces->setChecked(w->display_options.domain_forces);

					//TODO finish this
				}
				break;

			default:
				mylog.message("void MainWindow::updateUiFromActiveMdiSubWindow(QMdiSubWindow *subwindow): unsupported state");
				break;
		}
	}
	mylog.clearPrefix();
}


void MainWindow::setUserInterfaceAsOpened()
{
	mylog.setPrefix("MainWindow::setUserInterfaceAsOpened()");

	// set the menus
	ui.menuProject->setEnabled(true);
	ui.menuView->setEnabled(true);
	ui.menuWindow->setEnabled(true);
	ui.actionSave->setEnabled(true);
	ui.actionSaveAs->setEnabled(true);
	ui.actionClose->setEnabled(true);
	ui.actionNodeRestraints->setEnabled(true);
	ui.actionNodeActions->setEnabled(true);
	ui.actionEditMaterials->setEnabled(true);

	ui.actionDisplayNodes->setChecked(true);
	ui.actionDisplaySurfaces->setChecked(true);
	ui.actionDisplayWireframe->setChecked(true);

	// set the new viewport widget
	ModelViewport *viewport = new ModelViewport(&document.model, this);
	viewport->setColors(&colors);

	/*
	// open all relevant MDI windows
	GLModelWidget *glWidget = new GLModelWidget(&document, this);
	glWidget->setColors(&colors);
	double radius;
	options.getOption("viewport.nodes.radius",radius,20);
	glWidget->setNodeRadiusScale(radius);
	glWidget->setFocusPolicy(Qt::StrongFocus);
	glWidget->display_options.setDefaultOptions();
	*/

	// create the model's MDI window
	QMdiSubWindow	* window_gl_viewport;	// the model's opengl viewport

	window_gl_viewport = new QMdiSubWindow(mdiArea);
	window_gl_viewport->setWidget(viewport);
	window_gl_viewport->setAttribute(Qt::WA_DeleteOnClose);
	window_gl_viewport->setWindowTitle(tr("model viewport"));
	window_gl_viewport->showMaximized();

	// set toolbars
	createToolBars();

	// set the docks
	this->addDockWidget(static_cast<Qt::DockWidgetArea>(8), commandLineDockWidget);

	mylog.clearPrefix();
}


void MainWindow::setUserInterfaceAsClosed()	
{
	// set the menus
	ui.menuProject->setDisabled(true);
	ui.menuView->setDisabled(true);
	ui.menuWindow->setDisabled(true);
	ui.actionSave->setDisabled(true);
	ui.actionSaveAs->setDisabled(true);
	ui.actionClose->setDisabled(true);
	ui.actionNodeRestraints->setDisabled(true);
	ui.actionNodeActions->setDisabled(true);
	ui.actionEditMaterials->setDisabled(true);

	// close all MDI windows
	mdiArea->closeAllSubWindows();

	// handle the toolbars
	destroyToolBars();

	// handle the docks
	this->removeDockWidget(commandLineDockWidget);
	commandLineDockWidget->clear();
}

