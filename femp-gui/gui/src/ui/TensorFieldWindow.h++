#ifndef FEMP_TENSORFIELDWINDOW_HPP
#define FEMP_TENSORFIELDWINDOW_HPP

// gui includes
#include "BaseWindow.h++"
#include "MdiWindow.h++"
#include "SelectionManager.h++"
#include "WindowWithResults.h++"
#include "WindowWithScaling.h++"
#include <options/Options.h++>
#include <Project.h++>

// viewer includes
#include "../viewer/TensorFieldViewport.h++"

// libfemp includes
#include <libfemp/AnalysisResult.h++>
#include <libfemp/ElementResults/ResultsRanges.h++>

// Qt includes
#include <QComboBox>
#include <QToolBar>
#include <QWidget>

/**
 * MDI window designed to represent a tensor field of a given analysis result
 */
class TensorFieldWindow : public MdiWindow, public WindowWithResults, public BaseWindow {
	Q_OBJECT

	protected:
	TensorFieldViewport* m_viewportTensorField;

	QToolBar* m_toolBarToggleMenuBarVisibility;

	QAction* m_actionVisibleNegativePrincipalStresses;
	QAction* m_actionVisiblePositivePrincipalStresses;

	QToolBar* m_tensorFieldVisualization;
	QComboBox* m_comboBoxAnalysis;

	fem::AnalysisResult* m_result;	// pointer to the current analysis result,
									// which will point to a reference

	// gradient values
	fem::ResultsRanges<double> m_resultsRanges;	 // used to set values for representation

	public:
	TensorFieldWindow(fem::Project& project, fem::AnalysisResult& result, ViewportColors& colors, QWidget* parent = nullptr);

	public Q_SLOTS:
	void setDisplacementsScale(double scale);

	void toggleMenuBarVisibility(bool);
	void setNegativePrincipalStressesVisibility(const bool state);
	void setPositivePrincipalStressesVisibility(const bool state);

	void setAnalysisResult(fem::AnalysisResult& result);

	/**
	 * Calls ResultsRangeDialog and sets m_results_ranges accordingly
	 */
	void setResultsRanges();

	Q_SIGNALS:
	/**
	 * Emits a signal to dump the results from a given set of project objets
	 */
	void dumpResultsFromSelection(fem::AnalysisResult* result);

	protected:
	void connectSignalsToSlots() override;

	void createToolBars(fem::Project&);

	void setGradientValuesRange(const fem::AnalysisResult& result);
};

#endif
