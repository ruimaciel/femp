#ifndef FEMP_UI_POSTPROCESSINGWINDOW_HPP
#define FEMP_UI_POSTPROCESSINGWINDOW_HPP

// gui includes
#include <options/Options.hpp>

#include "../Project.hpp"
#include "BaseWindow.hpp"
#include "MdiWindow.hpp"
#include "WindowWithPostprocessing.hpp"
#include "WindowWithResults.hpp"
#include "WindowWithScaling.hpp"

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/ElementResults/ResultsRanges.hpp>

// Qt includes
#include <QWidget>

#include <SelectionManager.hpp>

namespace femp {
class SelectionManager;
}

class QComboBox;
class QToolBar;

/**
 * MDI window designed to represent the model
 */
namespace femp::ui {

class PostprocessingWindow : public femp::ui::MdiWindow,
                             public WindowWithResults,
                             public femp::ui::WindowWithPostprocessing,
                             public WindowWithScaling,
                             public femp::ui::BaseWindow {
  Q_OBJECT

protected:
  enum AnalysisType {
    A_DISPLACEMENT = 0,
    A_STRAIN_11,
    A_STRAIN_22,
    A_STRAIN_33,
    A_STRAIN_12,
    A_STRAIN_13,
    A_STRAIN_23,
    A_FEMP_VIEWER_11,
    A_FEMP_VIEWER_22,
    A_FEMP_VIEWER_33,
    A_FEMP_VIEWER_12,
    A_FEMP_VIEWER_13,
    A_FEMP_VIEWER_23,
    A_VON_MISES
  };

  QToolBar *m_toolBarToggleMenuBarVisibility;
  QComboBox *m_comboBoxAnalysis;

  fem::AnalysisResult *m_result; // pointer to the current analysis result,
                                 // which will point to a reference

  // gradient values
  fem::ResultsRanges<double>
      m_resultsRanges; // used to set values for representation

public:
  PostprocessingWindow(femp::Project &project, fem::AnalysisResult &result,
                       ::ViewportColors &colors, ::QWidget *parent = nullptr);

public Q_SLOTS:
  void setDisplacementsScale(double scale);

  // sets the postprocessing state according
  void setPostprocessingState(int state);
  void toggleMenuBarVisibility(bool);

  void setAnalysisResult(fem::AnalysisResult &result);

  /**
   * Calls ResultsRangeDialog and sets m_results_ranges accordingly
   */
  void setResultsRanges();

Q_SIGNALS:
  /**
   * Emits a signal to dump the results from a given set of project objets
   */
  void dumpResultsFromSelection(fem::AnalysisResult *result);

protected:
  void connectSignalsToSlots() override;

  void createToolBars(femp::Project &);

  void setGradientValuesRange(const fem::AnalysisResult &result);
};

} // namespace femp::ui

#endif
