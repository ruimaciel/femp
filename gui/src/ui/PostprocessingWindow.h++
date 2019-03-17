#ifndef FEMP_POSTPROCESSING__WINDOW_HPP
#define FEMP_POSTPROCESSING__WINDOW_HPP

#include "BaseWindow.h++"
#include "MdiWindow.h++"
#include "WindowWithResults.h++"
#include "WindowWithPostprocessing.h++"
#include "WindowWithScaling.h++"

#include <QWidget>
#include <QToolBar>
#include <QComboBox>

#include "../Project.h++"
#include <libfemp/AnalysisResult.h++>
#include <libfemp/ElementResults/ResultsRanges.h++>

#include <options/Options.h++>

#include "Selection.h++"
#include "SelectionManager.h++"


/**
MDI window designed to represent the model
**/
class PostprocessingWindow
		: public MdiWindow
		, public WindowWithResults
		, public WindowWithPostprocessing
		, public WindowWithScaling
		, public BaseWindow
{
	Q_OBJECT

protected:
	enum AnalysisType {
		A_DISPLACEMENT = 0,
		A_STRAIN_11, A_STRAIN_22, A_STRAIN_33, A_STRAIN_12,A_STRAIN_13,A_STRAIN_23,
		A_STRESS_11, A_STRESS_22, A_STRESS_33, A_STRESS_12,A_STRESS_13,A_STRESS_23,
		A_VON_MISES
	};

	QToolBar *m_toolBarToggleMenuBarVisibility;
	QComboBox *m_comboBoxAnalysis;

	fem::AnalysisResult *m_result;	// pointer to the current analysis result, which will point to a reference

	//gradient values
	fem::ResultsRanges<double> m_resultsRanges;	// used to set values for representation

public:
	PostprocessingWindow (fem::Project &project, fem::AnalysisResult &result, ViewportColors &colors, QWidget *parent = nullptr);


public Q_SLOTS:
	void setDisplacementsScale(double scale);

	// sets the postprocessing state according
	void setPostprocessingState(int state);
	void toggleMenuBarVisibility(bool);

	void setAnalysisResult(fem::AnalysisResult &result);

	/**
	Calls ResultsRangeDialog and sets m_results_ranges accordingly
	**/
	void setResultsRanges();

Q_SIGNALS:
	/**
	emits a signal to dump the results from a given set of project objets
	**/
	void dumpResultsFromSelection(fem::AnalysisResult *result);

protected:
	void connectSignalsToSlots() override;

	void createToolBars(fem::Project &);

	void setGradientValuesRange(const fem::AnalysisResult &result);


};

#endif
