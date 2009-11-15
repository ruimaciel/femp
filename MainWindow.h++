#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "ui/ui_MainWindow.h"

#include "CommandLineDockWidget.h++"
#include "ProgramOptions.h++"

#include "Document.h++"



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

	Document document;	// the FEM document

public Q_SLOTS:
	/* starts off a brand new FEM project */
	void newProject();	// launches the New Project wizard 
	void openProject();
	void saveProject();
	void saveProjectAs();
	void closeProject();
	void quit();

private Q_SLOTS:
	void startProject(QString, Document::Type);	// called by the New Project wizard dialog to finish

private:
	void createActions();	// creates the actions and connects them
	void loadOptions();	// loads global options from the options files

};


#endif
