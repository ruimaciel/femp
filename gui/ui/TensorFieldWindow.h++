#ifndef TENSOR_FIELD__WINDOW_HPP
#define TENSOR_FIELD__WINDOW_HPP

#include "BaseWindow.h++"
#include "MdiWindow.h++"
#include "WindowWithResults.h++"
#include "WindowWithScaling.h++"

#include <QWidget>
#include <QToolBar>
#include <QComboBox>

#include "../fem/Project.h++"
#include "../fem/AnalysisResult.h++"
#include "../fem/ElementResults/ResultsRanges.h++"
#include "../viewer/ViewportColors.h++"
#include "../viewer/TensorFieldViewport.h++"

#include "Selection.h++"
#include "SelectionManager.h++"


/**
MDI window designed to represent a tensor field of a given analysis result
**/
class TensorFieldWindow 
	: virtual public MdiWindow, virtual public WindowWithResults, public BaseWindow
{
	Q_OBJECT

protected:
	TensorFieldViewport *m_tensor_field_viewport;

	QToolBar *toggleMenuBarVisibilityToolBar;	

	QAction *actionVisibleNegativePrincipalStresses;
	QAction *actionVisiblePositivePrincipalStresses;

	QToolBar *m_tensor_field_visualization;	
	QComboBox *analysisComboBox;

	fem::AnalysisResult<double> *m_result;	// pointer to the current analysis result, which will point to a reference

	//gradient values
	fem::ResultsRanges<double> m_results_ranges;	// used to set values for representation

public:
	TensorFieldWindow (fem::Project &project, fem::AnalysisResult<double> &result, ViewportColors &colors, QWidget *parent = 0);


public Q_SLOTS:
	void setDisplacementsScale(double scale);

	void toggleMenuBarVisibility(bool);
	void setNegativePrincipalStressesVisibility(const bool state);
	void setPositivePrincipalStressesVisibility(const bool state);

	void setAnalysisResult(fem::AnalysisResult<double> &result);

	/**
	Calls ResultsRangeDialog and sets m_results_ranges accordingly
	**/
	void setResultsRanges();

Q_SIGNALS:
	/**
	emits a signal to dump the results from a given set of project objets
	**/
	void dumpResultsFromSelection(fem::AnalysisResult<double> *result);
	
protected:
	void connectSignalsToSlots();

	void createToolBars(fem::Project &);

	void setGradientValuesRange(const fem::AnalysisResult<double> &result);


};	

#endif
