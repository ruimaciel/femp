#include "MainWindow.h++"
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>

#include <string>
#include <fstream>
#include <iostream>	// for cout. remove after tests
#include <string>
#include <stdlib.h>	// getenv()

#include "NewProjectWizard.h++"
#include "fem_msh.h++"
#include "parsers/json.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	mdiArea = new QMdiArea;
	setCentralWidget(mdiArea);	// this main window has a Multiple Document Interface
	//mdiArea->setViewMode(QMdiArea::TabbedView);

	// Load global options from the options files
	this->loadOptions();

	// initialize the member attributes
	this->hasUnsavedChanges = false;

	// set up the dock widgets
	/*
	commandLineDockWidget = new CommandLineDockWidget(this);
	this->addDockWidget(static_cast<Qt::DockWidgetArea>(8), commandLineDockWidget);
	*/

	// create actions and connect signals to slots
	this->createActions();
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
	Now the "new project" wizard will create a new project directory.
	Then it will call loadProject() to load the newly created project.
	*/
	NewProjectWizard np(this);
	connect(&np,SIGNAL(newProject(Document::Type)), this, SLOT(startNewProject(Document::Type)));
	np.exec();
}


void MainWindow::openProject()
{
	std::string last_path, tmp;

	// get the last dir where a project was opened 
	if(options.getOption("project.open.last",tmp))
	{
		last_path = tmp;
	}
	else
	{
		last_path = getenv("HOME");
	}
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
	sl = dialog.selectedFiles();
	document.file_name = new QString;
	*document.file_name = sl.at(0);

	// check if file exists
	QFile file;
	file.setFileName(*document.file_name);
	if(!file.exists())
	{
		QMessageBox::critical(this, tr("File not found"), tr("File was not found"));
		return;
	}

	//file exists, now open it and parse it
	if(file.open(QIODevice::ReadOnly|QIODevice::Text) == false)
	{
		QMessageBox::critical(this, tr("Error"), tr("There was an error opening the file"));
		return;
	}

	json_t *root = NULL;
	FILE *f = fdopen(file.handle(), "r");
	switch(json_stream_parse(f,&root) )
	{
		case JSON_OK:
			// all went well
			break;

		default:
			//TODO implement better error handling
			QMessageBox::critical(this, tr("Error"), tr("There was an error parsing the project file"));
			return;
			break;
	}
	#define PTEST(TEST) {if(!(TEST)){QMessageBox::critical(this, tr("Error"), tr("There was an error parsing the project file")); qWarning("PERROR line %d: " #TEST, __LINE__); return;} }
	#define PMOVE(TO)	{ PTEST(TO != NULL); cursor = TO; }

	// document in memory, now let the importing begin
	json_t *cursor = root;
	PTEST(cursor->child != NULL);

	cursor = cursor->child;
	PTEST(cursor->type == JSON_STRING);
	PTEST( QString::compare(cursor->text,"fem") == 0);
	//TODO finish this

	// move to the materials field
	PMOVE(cursor->next);	// pointing to root->materials
	PTEST( QString::compare(cursor->text,"materials") == 0);
	//TODO finish this

	// move to the nodes field
	PMOVE(cursor->next);	// pointing to root->nodes
	PTEST( QString::compare(cursor->text,"nodes") == 0);
	PMOVE(cursor->child);
	PTEST(cursor->type == JSON_ARRAY);
	if(cursor->child != NULL) // testing root->"nodes"->array for children
	{	// has child nodes
		QString temp;
		size_t n = 0;
		double p[3] = {0,0,0};
		json_t *ac;
		// iterate through the child nodes of "nodes":[]
		for(cursor = cursor->child; cursor->next != NULL; cursor = cursor->next)
		{
			ac = cursor;
			PTEST(ac->type == JSON_ARRAY);
			PTEST(ac->child != NULL);
			ac = ac->child;
			PTEST(ac->type == JSON_NUMBER);
			temp = ac->text;
			n = temp.toLongLong();	// get the node index

			PTEST(ac->next != NULL);
			ac = ac->next;	// move cursor to the coordinates array
			PTEST(ac->type == JSON_ARRAY);
			PTEST(ac->child != NULL);
			ac = ac->child;
			PTEST(ac->type == JSON_NUMBER);	// point to the first coordinate
			temp = ac->text;
			p[0] = temp.toDouble();	// get point.x()
			
			PTEST(ac->next != NULL);	// there must be a 2nd array element
			ac = ac->next;
			PTEST(ac->type == JSON_NUMBER);	// point to the first coordinate
			temp = ac->text;
			p[1] = temp.toDouble();	// get point.x()
			
			PTEST(ac->next != NULL);	// there must be a 2nd array element
			ac = ac->next;
			PTEST(ac->type == JSON_NUMBER);	// point to the first coordinate
			temp = ac->text;
			p[2] = temp.toDouble();	// get point.x()
			PTEST(ac->next == NULL);
			
			// having the values, let's add the node to the node list
			document.model.setNode(n, p[0], p[1], p[2]);
		}
	}
	else
	{
		// root->nodes doesn't have child nodes: empty array
	}

	//TODO finish this
	cursor = cursor->parent;	// move to root->"nodes"->array
	cursor = cursor->parent;	// move to root->"nodes"

	// move to the elements field
	PMOVE(cursor->next);	// pointing to root->"elements"
	PTEST( QString::compare(cursor->text,"elements") == 0);
	PMOVE( cursor->child );	// pointing to root->"elements"->array
	PTEST( cursor->type == JSON_ARRAY);
	if(cursor->child != NULL)
	{	// elements present in this document
		size_t nn;	// number of nodes which will be expected for each type
		json_t *ec = NULL;
		fem::Element::Type type = fem::Element::FE_INVALID;

		for(json_t *c = cursor->child; c != NULL; c = c->next)
		{
			PTEST(c->type == JSON_OBJECT);
			PTEST(c->child != NULL);
			ec = c->child;	// pointing to root->"elements"->array->object->"type"
			PTEST(ec->type == JSON_STRING);
			PTEST(QString::compare(ec->text,"type") == 0);
			PTEST(ec->child->type == JSON_STRING);	// value of label "type" must be a string
			
			// identify this type and act accordingly
			switch(type = fem::Element::extractType(ec->child->text) )
			{
				case fem::Element::FE_LINE2:
					nn = 2;
					break;

				case fem::Element::FE_TRIANGLE3:
					nn = 3;
					break;

				case fem::Element::FE_QUADRANGLE4:
					nn = 4;
					break;

				case fem::Element::FE_TETRAHEDRON4:
					nn = 4;	// expect 4 nodes in the "nodes" array
					break;

				case fem::Element::FE_HEXAHEDRON8:
					nn = 8;
					break;

				case fem::Element::FE_PRISM6:
					nn = 6;
					break;

				case fem::Element::FE_PYRAMID5:
					nn = 5;
					break;

				case fem::Element::FE_LINE3:
					nn = 3;
					break;

				case fem::Element::FE_TRIANGLE6:
					nn = 6;
					break;

				case fem::Element::FE_QUADRANGLE9:
					nn = 9;
					break;

				case fem::Element::FE_TETRAHEDRON10:
					nn = 10;
					break;

				case fem::Element::FE_HEXAHEDRON27:
					nn = 27;
					break;

				case fem::Element::FE_PRISM18:
					nn = 18;
					break;

				case fem::Element::FE_PYRAMID14:
					nn = 14;
					break;

				case fem::Element::FE_QUADRANGLE8:
					nn = 8;
					break;

				case fem::Element::FE_HEXAHEDRON20:
					nn = 20;
					break;

				case fem::Element::FE_PRISM15:
					nn = 15;
					break;

				case fem::Element::FE_PYRAMID13:
					nn = 13;
					break;

				case fem::Element::FE_ITRIANGLE9:
					nn = 9;
					break;

				case fem::Element::FE_TRIANGLE10:
					nn = 10;
					break;

				case fem::Element::FE_ITRIANGLE12:
					nn = 12;
					break;

				case fem::Element::FE_TRIANGLE15:
					nn = 15;
					break;

				case fem::Element::FE_ITRIANGLE15:
					nn = 15;
					break;

				case fem::Element::FE_TRIANGLE21:
					nn = 21;
					break;

				case fem::Element::FE_EDGE4:
					nn = 4;
					break;

				case fem::Element::FE_EDGE5:
					nn = 5;
					break;

				case fem::Element::FE_EDGE6:
					nn = 6;
					break;

				case fem::Element::FE_TETRAHEDRON20:
					nn = 20;
					break;

				case fem::Element::FE_TETRAHEDRON35:
					nn = 35;
					break;

				case fem::Element::FE_TETRAHEDRON56:
					nn = 56;
					break;

				case fem::Element::FE_INVALID:
				default:
					qWarning("invalid element");
					continue;
					break;

			}
			// extract nodes
			PTEST(ec->next != NULL);
			ec = ec->next;
			PTEST(ec->type == JSON_STRING);
			PTEST(QString::compare(ec->text,"nodes") == 0);
			PTEST(ec->child != NULL);
			ec = ec->child;	// pointing to root->"elements"->array->object->"nodes"->array
			PTEST(ec->type == JSON_ARRAY);
			PTEST(ec->child != NULL);	// node array must be populated

			std::vector<size_t> tn;	// the temporary node vector
			QString temp;	// the temporary string, to convert numbers
			unsigned int i;
			for(ec = ec->child, i = 0; ec != NULL; ec = ec->next, i++)	// pointing to root->"elements"->array->objects->"nodes"->array->number
			{
				PTEST(ec->type == JSON_NUMBER);
				temp = ec->text;
				tn.push_back(temp.toLongLong());
			}
			PTEST(tn.size() == nn);	// evaluate if the document had as many nodes as those which were expected

			// get this element's material
			if(ec->next != NULL)
			{	
				/*
				// there is still another field
				ec = ec->next;	// pointing to root->"elements"->array->object->"material"
				PTEST(ec->type == JSON_STRING);	// which must be a label
				PTEST(QString::compare(ec->text,"material") == 0);
				PTEST(ec->child != NULL);
				PTEST(ec->child->type == JSON_NUMBER);	// material must be a number
				temp = ec->child->text;
				document.model.setDefaultMaterial(temp.toLongLong());	// sets the material
				*/
			}
			// now let's add the element
			document.model.pushElement(type,tn); 
		}
		//TODO finish this
	}
	cursor = cursor->parent;	// move to root->"elements"

	// move to the node restrictions field
	PMOVE(cursor->next);	// pointing to root->node restrictions
	PTEST( QString::compare(cursor->text,"node restrictions") == 0);
	//TODO finish this

	// move to the load patterns field
	PMOVE(cursor->next);	// pointing to root->load patterns
	PTEST( QString::compare(cursor->text,"load patterns") == 0);
	//TODO finish this

	// move to the combinations field
	PMOVE(cursor->next);	// pointing to root->combinations
	PTEST( QString::compare(cursor->text,"combinations") == 0);
	//TODO finish this

	

	#undef PTEST
	// tweak the UI
	setUserInterfaceAsOpened();
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
}


void MainWindow::loadOptions()
{
	std::ifstream is;
	std::string path;

	// Set default options
	options.setDefault();
	/*TODO Set default options */

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

	
void MainWindow::startNewProject(Document::Type type)
{
	// set the document settings 
	document.clear();
	document.setProjectType(type);

	// set the UI
	setUserInterfaceAsOpened();
	hasUnsavedChanges = false;
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

	// open all relevant MDI windows
	glWidget = new GLWidget(this);
	glWidget->setModel(&document.model);
	mdiArea->addSubWindow(glWidget);
	glWidget->show();
	// enable the "close"
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

	// close all MDI windows
	//TODO define a better way to close the MDI window
	glWidget->hide();
	delete glWidget, glWidget = NULL;
	
}


