#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QComboBox>

#include "ui/ui_MainWindow.h"

#include "CommandLineDockWidget.h++"
#include "ProgramOptions.h++"
#include "viewer/ViewportColors.h++"

#include "viewer/ModelViewport.h++"

#include "Document.h++"

#include "fem/LinearAnalysis.h++"
#include "fem/AnalysisResult.h++"



class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow (QWidget *parent = 0);

protected:
	Ui::MainWindow 	ui;
	//ModelViewport *viewport;	// opengl viewport

	fem::LinearAnalysis<double> analysis;
	fem::AnalysisResult<double> analysis_result;

	CommandLineDockWidget *commandLineDockWidget;

	QMdiArea	* mdiArea;

	// the toolbars
	QToolBar *visibilityToolBar;
	QToolBar *viewportToolBar;
	QToolBar *actionsToolBar;

	QComboBox *comboActionsLoadPattern;	// a combo box that is inserted in the Actions toolbar to select the load pattern

	ProgramOptions 	options;	// the global program options
	bool 	hasUnsavedChanges;	// true if the document has unsaved changes

	Document document;	// the FEM document

	ViewportColors colors;	// the elements' viewport colors

	QAction *actionViewportXY;	// places the camera displaying the XY plane
	QAction *actionViewportYZ;	// places the camera displaying the XY plane
	QAction *actionViewportXZ;	// places the camera displaying the XZ plane
	QAction *actionViewportIso;	// places the camera on an isometric view angle



public Q_SLOTS:
	/* starts off a brand new FEM project */
	void newProject();	// launches the New Project wizard 
	void openProject();
	void reopenProject();	// if the current model has been saved to a file then this routine reloads the document
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
	void editQuadratureRules();

	/**
	Sets DisplayOption's options refering to the element visualization
	**/
	void setElementDisplay();
	void setNodeForcesDisplay();

	/**
	runs the analysis on the current model
	**/
	void runAnalysis();

	/**
	Dumps the FEM equation (K matrix, d and f vectors) to a file following the Matlab format
	**/
	void dumpFemEquation();

	// set current ModelViewport
	void showModel();
	void showDisplacements();

	/**
	Logging slots
	**/
	void getMessage(QString);
	void getWarning(QString);
	void getError(QString);

	// set the viewport in the current MDI window
	void setViewportXY();
	void setViewportYZ();
	void setViewportXZ();
	void setViewportIso();

	// set MDI subwindow configuration
	void setTiledWindows();
	void setCascadeWindows();
	void createNewViewportWindow();

	// updates the UI according to the currently active MDI subwindow
	void updateUiFromActiveMdiSubWindow(QMdiSubWindow *);

Q_SIGNALS:
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
