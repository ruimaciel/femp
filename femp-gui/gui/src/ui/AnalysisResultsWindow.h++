#ifndef FEMP_ANALYSIS_RESULTS_WINDOW_H
#define FEMP_ANALYSIS_RESULTS_WINDOW_H

#include <Project.h++>
#include <QComboBox>
#include <QMdiSubWindow>
#include <QToolBar>
#include <QWidget>
#include <ui/widgets/AnalysisResultsWidget.h++>

#include "BaseWindow.h++"

/**
MDI window designed to represent a model's results
**/
class AnalysisResultsWindow : public QMdiSubWindow, public BaseWindow {
	Q_OBJECT

	protected:
	AnalysisResultsWidget* m_analysisResultsWidget;
	fem::Project const* m_project;

	public:
	AnalysisResultsWindow(fem::Project& project, QWidget* parent = nullptr);
};

#endif
