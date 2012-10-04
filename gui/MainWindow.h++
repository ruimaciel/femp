#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QMainWindow>
#include <QComboBox>
#include <QDir>
#include <QSignalMapper>

#include "ui/ui_MainWindow.h"

#include "CommandLineDockWidget.h++"
#include "SelectionDockWidget.h++"

#include "ProgramOptions.h++"
#include "viewer/ViewportColors.h++"

#include "ui/ModelWindow.h++"

#include "viewer/ModelViewport.h++"

#include "Document.h++"
#include "SelectionManager.h++"

#include "fem/LinearAnalysis.h++"
#include "fem/AnalysisResult.h++"



class MainWindow 
	: public QMainWindow,
	public sigc::trackable
{
	Q_OBJECT

public:
	MainWindow (QWidget *parent = 0);

protected:
	Ui::MainWindow 	ui;

	fem::LinearAnalysis<double> analysis;

	CommandLineDockWidget *commandLineDockWidget;
	SelectionDockWidget *selectionDockWidget;

	QMdiArea	* mdiArea;

	ProgramOptions 	options;	// the global program options
	bool 	hasUnsavedChanges;	// true if the document has unsaved changes

	Document document;	// the FEM document
	SelectionManager m_selection_manager;	// object which handles object selection

	ViewportColors colors;	// the elements' viewport colors

	QDir file_dialog_last_directory;
	QSignalMapper	*m_window_mapper;	// used to map menu clicks to window activation


public Q_SLOTS:
	/* starts off a brand new FEM project */
	void newProject();	// launches the New Project wizard 
	void openProject();
	void reopenProject();	// if the current model has been saved to a file then this routine reloads the document
	void saveProject();
	void saveProjectAs();
	void closeProject();
	void quit();

	/**
	Calls the "set node restraints" dialog and, from it's output, sets them
	**/
	void setNodeRestraints();
	void setNodeActions();
	void moveSelectedNodes();

	void setDisplayOptions();
	void editMaterials();
	void editQuadratureRules();

	/**
	Calls the dialog which is used to fine tune the object selection list
	**/
	void editSelection();

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

	/**
	Displays a summary of the last analysis
	**/
	void showAnalysisSummary();
	
	/**
	Dumps the results from the objects which are currently selected
	@param	result	the result which will be dumped
	**/
	void dumpResultsFromSelection(fem::AnalysisResult<double> *result);

	/**
	Dumps the results taken from the last analysis from the objects which are currently selected
	**/
	void dumpResultsFromSelection();

	/**
	Logging slots
	**/
	void getMessage(QString);
	void getWarning(QString);
	void getError(QString);

	/**
	Sets the current MdiViewport to show only the selected objects
	**/
	void showSelection();
	void showAll();

	// set MDI subwindow configuration
	void setTiledWindows();
	void setCascadeWindows();
	void createNewViewportWindow();
	void createNewModelWindow();
	void createNewPostprocessingWindow();
	void createNewTensorFieldWindow();
	void createNewAnalysisResultsWindow();
	void createNewFemEquationWindow();
	void updateWindowMenu();

	// set all signal and slots connections
	void setSignalsAndSlotsConnections(ModelWindow *window);
	void activateSubWindowByIndex(int);

Q_SIGNALS:
	void setMessage(QString);
	void setWarning(QString);
	void setError(QString);

private:
	void createActions();	// creates the actions and connects them
	void createToolBars();
	void createDockWidgets();
	void destroyToolBars();
	void loadOptions();	// loads global options from the options files

	// sets the user interface state
	void setUserInterfaceAsOpened();	// sets the user interface in it's "opened document" state
	void setUserInterfaceAsClosed();	// sets the user interface in it's "closed document" state
	void setUserInterfacePostAnalysis();	// sets the user interface in it's "analysis performed" state

};


#endif
