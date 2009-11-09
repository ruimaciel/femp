#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "ui/ui_MainWindow.h"

#include "CommandLineDockWidget.h++"
#include "ProgramOptions.h++"



class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow (QWidget *parent = 0);

private:
	Ui::MainWindow ui;
	CommandLineDockWidget *commandLineDockWidget;
	ProgramOptions options;	// the global program options
	bool hasUnsavedChanges;	// true if the document has unsaved changes

private Q_SLOTS:
	/* starts off a brand new FEM project */
	void newProject();
	void openProject();
	void saveProject();
	void saveProjectAs();
	void closeProject();
	void quit();

private:
	void createActions();	// creates the actions and connects them
	void loadOptions();	// loads global options from the options files

};


#endif
