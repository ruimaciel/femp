#include "MainWindow.h++"
#include <QAction>

#include <string>
#include <fstream>
#include <iostream>	// for cout. remove after tests

#include <stdlib.h>	// getenv()


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	// Load options
	this->loadOptions();


	commandLineDockWidget = new CommandLineDockWidget(this);
	this->addDockWidget(static_cast<Qt::DockWidgetArea>(8), commandLineDockWidget);

	// connect signals and slots
	 connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(newProject()));

}


void MainWindow::newProject()
{
	// initialize a new project

	// tweak the UI
	ui.actionClose->setEnabled(true);
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

