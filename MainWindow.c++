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

	// Load global options from the options files
	this->loadOptions();

	// initialize the member attributes
	this->hasUnsavedChanges = false;

	// set up the dock widgets
	commandLineDockWidget = new CommandLineDockWidget(this);
	this->addDockWidget(static_cast<Qt::DockWidgetArea>(8), commandLineDockWidget);

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
	np.exec();
	
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


void MainWindow::createActions()
{
	 connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(newProject()));
	 connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openProject()));
	 connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(saveProject()));
	 connect(ui.actionSaveAs, SIGNAL(triggered()), this, SLOT(saveProjectAs()));
	 connect(ui.actionClose, SIGNAL(triggered()), this, SLOT(closeProject()));
	 connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(quit()));
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

