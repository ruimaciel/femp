#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QMainWindow>
#include <QComboBox>
#include <QDir>
#include <QSignalMapper>

#include <libfemp/LinearAnalysis.h++>
#include <libfemp/AnalysisResult.h++>

#include "ui/ui_MainWindow.h"

#include "ui/dock_widgets/CommandLineDockWidget.h++"
#include "ui/dock_widgets/SelectionDockWidget.h++"

#include "ProgramOptions.h++"
#include <gui/options/Options.h++>

#include "ui/ModelWindow.h++"

#include "viewer/ModelViewport.h++"

#include "Document.h++"
#include "SelectionManager.h++"



class MainWindow
		: public QMainWindow,
		public sigc::trackable
{
	Q_OBJECT

public:
	explicit MainWindow (QWidget *parent = 0);

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
	void setDomainLoads();
	void moveSelectedNodes();

	void editMaterials();
	void editQuadratureRules();

	/**
	Calls the dialog which is used to fine tune the object selection list
	**/
	void editSelection();

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

protected:
	ViewportColors &getViewportColors();

protected:
	Ui::MainWindow 	ui;

	fem::LinearAnalysis<double> m_analysis;

	CommandLineDockWidget *m_commandLineDockWidget;
	SelectionDockWidget *m_selectionDockWidget;

	QMdiArea	* m_mdiArea;

	ProgramOptions 	m_options;	// the global program options
	bool 	m_hasUnsavedChanges;	// true if the document has unsaved changes

	Document m_document;	// the FEM document
	SelectionManager m_selectionManager;	// object which handles object selection

	ViewportColors m_colors;	// the elements' viewport colors

	QDir m_resultsDumpDialogLastDirectory;
	QSignalMapper	*m_windowMapper;	// used to map menu clicks to window activation


};


#endif
