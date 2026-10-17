#ifndef FEMP_UI_ANALYSIS_RESULTS_WIDGET_HPP
#define FEMP_UI_ANALYSIS_RESULTS_WIDGET_HPP

// include Qt
#include <QSortFilterProxyModel>
#include <QWidget>

#include <memory>

namespace fem {
class Project;
}

namespace Ui {
class AnalysisResultsWidget;
}

/**
 * Widget used in MDI windows to display the results of a given analysis
 */
class AnalysisResultsWidget : public QWidget {
  Q_OBJECT

protected:
  // proxy model to provide a way to filter stuff from the results
  QSortFilterProxyModel m_proxy_model;

public:
  AnalysisResultsWidget(fem::Project &project, QWidget *parent = nullptr);
  ~AnalysisResultsWidget() override;

private Q_SLOTS:
  // Calls the TableFilterDialog and sets the table according to the user input
  void setFilterOptions();

private:
  struct Private;
  std::unique_ptr<Private> m_private;
};

#endif
