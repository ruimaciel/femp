#ifndef ANALYSIS_RESULTS_WIDGET_H
#define ANALYSIS_RESULTS_WIDGET_H

#include <QSortFilterProxyModel>
#include <QWidget>

#include <Project.h++>
#include <libfemp/AnalysisResult.h++>

#include "ui_AnalysisResultsWidget.h"
#include <ui/models/AnalysisResultsModel.h++>

/**
 * Widget used in MDI windows to display the results of a given analysis
 */
class AnalysisResultsWidget
    : public QWidget,
      private Ui::AnalysisResultsWidget {
    Q_OBJECT

protected:
    fem::Project const& m_project;
    AnalysisResultsModel* m_model;

    // proxy model to provide a way to filter stuff from the results
    QSortFilterProxyModel m_proxy_model;

public:
    AnalysisResultsWidget(fem::Project& project, QWidget* parent = nullptr);

private Q_SLOTS:
    // Calls the TableFilterDialog and sets the table according to the user input
    void setFilterOptions();
};

#endif
