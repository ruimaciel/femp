#ifndef FEMP_MAINWINDOW_HPP
#define FEMP_MAINWINDOW_HPP

// ui includes
#include "ui/ModelWindow.h++"
#include "ui/dock_widgets/CommandLineDockWidget.h++"
#include "ui/ui_MainWindow.h"

// gui includes
#include "Document.h++"
#include "SelectionManager.h++"
#include <options/Options.h++>

// application includes
#include <application/interfaces/ILoadPatternRepository.h++>

// viewer includes
#include "viewer/ModelViewport.h++"

// libfemp includes
#include <libfemp/AnalysisResult.h++>
#include <libfemp/LinearAnalysis.h++>

// Qt includes
#include <QComboBox>
#include <QDir>
#include <QMainWindow>
#include <QSignalMapper>

/**
 * The application's main window
 **/
class MainWindow : public QMainWindow {
	Q_OBJECT

	public:
	explicit MainWindow(QWidget* parent = nullptr);

	signals:
	void selectionChanged(Selection);
	void selectionCleared();

	void informationMessageSent(QString);
	void warningMessageSent(QString);
	void errorMessageSent(QString);

	public slots:
	/**
	 * @brief setSelection
	 */
	void setSelection(Selection);  // sets the selection
	void clearSelection();		   // clears the selection

	/**
	 * Starts off a brand new FEM project
	 */
	void newProject();
	void openProject();

	/**
	 * If the current model has been saved to a file then this routine reloads the
	 * document
	 */
	void reopenProject();
	void saveProject();
	void saveProjectAs();
	void closeProject();
	void quit();

	/**
	 * Calls the "set node restraints" dialog and, from it's output, sets them
	 */
	void setNodeRestraints();
	void setNodeActions();
	void setDomainLoads();
	void moveSelectedNodes();

	void editMaterials();
	void editQuadratureRules();

	/**
	 * Calls the dialog which is used to fine tune the object selection list
	 */
	void editSelection();

	/**
	 * Runs the analysis on the current model
	 */
	void runAnalysis();

	void onAnalysisFinished();

	/**
	 * Dumps the FEM equation (K matrix, d and f vectors) to a file following the
	 * Matlab format
	 */
	void dumpFemEquation();

	/**
	 * Displays a summary of the last analysis
	 */
	void showAnalysisSummary();

	/**
	 * Dumps the results taken from the last analysis from the objects which are
	 * currently selected
	 */
	void dumpResultsFromSelection();

	/**
	 * Logging slots
	 */
	void getMessage(QString);
	void getWarning(QString);
	void getError(QString);

	/**
	 * Sets the current MdiViewport to show only the selected objects
	 */
	void showSelection();
	void showAll();

	/**
	 * set MDI subwindow configuration
	 */
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

	private:
	void createActions();
	void createToolBars();
	void createDockWidgets();
	void destroyToolBars();

	// sets the user interface state
	void setUserInterfaceAsOpened();
	void setUserInterfaceAsClosed();
	void setUserInterfacePostAnalysis();

	protected:
	ViewportColors& getViewportColors();

	void saveDocument(Document& doc, std::string filename);

	protected:
	Ui::MainWindow ui;

	fem::LinearAnalysis<double> m_analysis;

	CommandLineDockWidget* m_commandLineDockWidget;

	QMdiArea* m_mdiArea;

	Document m_document;				  // the FEM document
	SelectionManager m_selectionManager;  // object which handles object selection

	ViewportColors m_colors;  // the elements' viewport colors

	QSignalMapper* m_windowMapper;	// used to map menu clicks to window activation

	gui::application::ILoadPatternRepositoryPtr m_load_pattern_repository;
};

#endif
