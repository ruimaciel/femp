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


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	mdiArea = new QMdiArea;
	setCentralWidget(mdiArea);	// this main window has a Multiple Document Interface

	glWidget = new GLWidget(this);
	glWidget->setModel(&document.model);
	
	mdiArea->addSubWindow(glWidget);

// temp 
        document.model.setNode(0, 0.0f, 0.0f, 0.0f);
        document.model.setNode(1,-0.5f,-0.5f,-1.0f);
        document.model.setNode(2, 0.5f,-0.5f,-1.0f);
        document.model.setNode(3, 0.5f, 0.5f,-1.0f);
        document.model.setNode(4,-0.5f, 0.5f,-1.0f);
        document.model.setNode(5,-0.5f,-0.5f, 1.0f);
        document.model.setNode(6, 0.5f,-0.5f, 1.0f);
        document.model.setNode(7, 0.5f, 0.5f, 1.0f);
        document.model.setNode(8,-0.5f, 0.5f, 1.0f);
// temp ^

	// Load global options from the options files
	this->loadOptions();

	// initialize the member attributes
	this->hasUnsavedChanges = false;

	// set up the dock widgets
	// commandLineDockWidget = new CommandLineDockWidget(this);
	// this->addDockWidget(static_cast<Qt::DockWidgetArea>(8), commandLineDockWidget);

	glWidget = new GLWidget;
	//setCentralWidget(glWidget);

	// create actions and connect signals to slots
	this->createActions();
}


void MainWindow::newProject()
{
	std::string default_path, tmp;
	QString directory;

	// initialize a new project


	default_path = getenv("HOME");
	if(options.getOption("project.new.default_directory",tmp))
	{
		default_path += "/" + tmp;
	}
	NewProjectWizard np(this,default_path.c_str());
	connect(&np, SIGNAL(newProject(QString, Document::Type)), this, SLOT(startProject(QString, Document::Type)));
	np.exec();
	disconnect(&np,0,0,0);	// this signal is no more
	
	// Setup the document

	// tweak the UI
	ui.actionClose->setEnabled(true);
}


void MainWindow::openProject()
{
	qWarning("MainWindow::openProject() not yet implemented");
	// tweak the UI
	ui.actionClose->setEnabled(true);
}


void MainWindow::saveProject()
{
	qWarning("not yet implemented");
	// tweak the UI
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


void MainWindow::startProject(QString path, Document::Type type)
{
	document.initialize(type, path.toStdString());

	// set UI
	//TODO finish this
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
	QFileDialog dialog(this);
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilter(tr("Mesh files (*.msh)"));
	//TODO import options from ProgramOptions
	if(dialog.exec())
	{
		// import file
		files = dialog.selectedFiles();
	}
}


