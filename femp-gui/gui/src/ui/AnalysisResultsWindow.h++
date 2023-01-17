#ifndef FEMP_ANALYSISRESULTSWINDOW_H
#define FEMP_ANALYSISRESULTSWINDOW_H

// ui includes
#include <ui/widgets/AnalysisResultsWidget.h++>

// gui includes
#include "BaseWindow.h++"
#include <Project.h++>

// Qt includes
#include <QComboBox>
#include <QMdiSubWindow>
#include <QToolBar>
#include <QWidget>


/**
 * MDI window designed to represent a model's results
 */
class AnalysisResultsWindow : public QMdiSubWindow, public BaseWindow {
	Q_OBJECT

	protected:
	AnalysisResultsWidget* m_analysisResultsWidget;
	fem::Project const* m_project;

	public:
	AnalysisResultsWindow(fem::Project& project, QWidget* parent = nullptr);
};

#endif
