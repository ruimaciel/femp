#ifndef FEMP_UI_MAINWINDOW_HPP
#define FEMP_UI_MAINWINDOW_HPP

#include <selection/Selection.hpp>

#include <QMainWindow>
#include <QString>

#include <memory>

class CommandLineDockWidget;
class ViewportColors;

#include <SelectionManager.hpp>

namespace femp {
class AppState;
class Document;
} // namespace femp

namespace Ui {
class MainWindow;
}

namespace femp::ui {

/**
 * The application's main window
 **/
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

signals:
  void selectionChanged(::Selection);
  void selectionCleared();

  void documentOpened();
  void documentClosed();

  void informationMessageSent(QString);
  void warningMessageSent(QString);
  void errorMessageSent(QString);

public slots:
  /**
   * handles the application state change event
   * @brief onAppStateChanged
   * @param state
   */
  void onAppStateChanged(femp::AppState state);

  /**
   * @brief setSelection
   */
  void setSelection(::Selection); // sets the selection
  void clearSelection();          // clears the selection

  /**
   * Starts off a brand new FEM project
   */
  void newProject();
  void openProject();

  void importProjectFromJsonFile(QString file_name);

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
  struct Private;
  std::unique_ptr<Private> d;

  void createActions();
  void createToolBars();
  void createDockWidgets();
  void destroyToolBars();

  // sets the user interface state
  void setUserInterfaceAsOpened();
  void setUserInterfaceAsClosed();
  void setUserInterfacePostAnalysis();

protected:
  ::ViewportColors &getViewportColors();

protected:
  std::unique_ptr<Ui::MainWindow> ui;
};

} // namespace femp::ui

#endif
