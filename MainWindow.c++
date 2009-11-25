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


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	mdiArea = new QMdiArea;
	setCentralWidget(mdiArea);	// this main window has a Multiple Document Interface

	glWidget = new GLWidget(this);
	glWidget->setModel(&document.model);
	
	mdiArea->addSubWindow(glWidget);

// temp 
/*
        document.model.setNode(0, 0.0f, 0.0f, 0.0f);
        document.model.setNode(1,-0.5f,-0.5f,-1.0f);
        document.model.setNode(2, 0.5f,-0.5f,-1.0f);
        document.model.setNode(3, 0.5f, 0.5f,-1.0f);
        document.model.setNode(4,-0.5f, 0.5f,-1.0f);
        document.model.setNode(5,-0.5f,-0.5f, 1.0f);
        document.model.setNode(6, 0.5f,-0.5f, 1.0f);
        document.model.setNode(7, 0.5f, 0.5f, 1.0f);
        document.model.setNode(8,-0.5f, 0.5f, 1.0f);
*/
// temp ^

	// Load global options from the options files
	this->loadOptions();

	// initialize the member attributes
	this->hasUnsavedChanges = false;

	// set up the dock widgets
	// commandLineDockWidget = new CommandLineDockWidget(this);
	// this->addDockWidget(static_cast<Qt::DockWidgetArea>(8), commandLineDockWidget);

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
	NewProjectWizard np(this,default_path.c_str());
	if(np.exec() == 1)
	{
		// the new dialog wizard ended with a successfull project
		setUserInterfaceAsOpened();
	}
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

        QDir location;
	// location = QFileDialog::getExistingDirectory(this, tr("Open project directory"), last_path.c_str(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	QDir newLocation;
	QFileDialog fd(this, tr("Open project directory"), last_path.c_str());
	fd.setFileMode(QFileDialog::Directory);
	fd.setOption(QFileDialog::ShowDirsOnly, true);
	fd.setViewMode(QFileDialog::List);
	fd.exec();

	// tweak the UI
	setUserInterfaceAsOpened();
}


void MainWindow::saveProject()
{
	//TODO finish this
	document.save();
}


void MainWindow::saveProjectAs()
{
	qWarning("MainWindow::saveProjectAs() not yet implemented");
	//TODO finish this
	// tweak the UI
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

	//TODO finish this
	// tweak the UI
	ui.actionClose->setEnabled(false);
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


/*
void MainWindow::startProject(QString path, Document::Type type)
{
	document.initialize(type, path.toStdString());

	// set UI
	//TODO finish this
}
*/

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
}


