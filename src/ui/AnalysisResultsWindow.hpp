#ifndef FEMP_UI_ANALYSISRESULTSWINDOW_HPP
#define FEMP_UI_ANALYSISRESULTSWINDOW_HPP

// ui includes
#include <ui/widgets/AnalysisResultsWidget.hpp>

// gui includes
#include <Project.hpp>

#include "BaseWindow.hpp"

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
  AnalysisResultsWidget *m_analysisResultsWidget;
  femp::Project const *m_project;

public:
  AnalysisResultsWindow(femp::Project &project, QWidget *parent = nullptr);
};

#endif
