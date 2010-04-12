#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "ui/ui_MainWindow.h"

#include "CommandLineDockWidget.h++"
#include "ProgramOptions.h++"
#include "glwidget.h++"

#include "Document.h++"



class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow (QWidget *parent = 0);

private:
	Ui::MainWindow 	ui;
	CommandLineDockWidget *commandLineDockWidget;

	QMdiArea	* mdiArea;
	QMdiSubWindow	* window_gl_viewport;	// the model's opengl viewport
	GLWidget 	* glWidget;	//TODO this pointer isn't necessary. consider removing it

	// the toolbars
	QToolBar *visibilityToolBar;
	QToolBar *viewportToolBar;

	ProgramOptions 	options;	// the global program options
	bool 	hasUnsavedChanges;	// true if the document has unsaved changes

	Document document;	// the FEM document
	ViewportColors colors;	// the elements' viewport colors


public Q_SLOTS:
	/* starts off a brand new FEM project */
	void newProject();	// launches the New Project wizard 
	void openProject();
	void saveProject();
	void saveProjectAs();
	void closeProject();
	void quit();
	void importMesh();

	/**
	Calls the "set node restraints" dialog and, from it's output, sets them
	**/
	void setNodeRestraints();
	void setNodeActions();
	void setDisplayOptions();
	void editMaterials();

	/**
	Sets DisplayOption's options refering to the element visualization
	**/
	void setElementDisplay();

	/**
	runs the analysis on the current model
	**/
	void runAnalysis();

	/**
	Logging slots
	**/
	void getMessage(QString);
	void getWarning(QString);
	void getError(QString);

Q_SIGNALS:
	void togglePerspective();	// toggles between orthographic and projection

	void setMessage(QString);
	void setWarning(QString);
	void setError(QString);

private:
	void createActions();	// creates the actions and connects them
	void createToolBars();
	void destroyToolBars();
	void loadOptions();	// loads global options from the options files
	void setUserInterfaceAsOpened();	// sets the user interface in it's "opened document" state
	void setUserInterfaceAsClosed();	// sets the user interface in it's "closed document" state
};


#endif
