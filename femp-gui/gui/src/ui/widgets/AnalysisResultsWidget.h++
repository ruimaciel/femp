#ifndef ANALYSIS_RESULTS_WIDGET_H
#define ANALYSIS_RESULTS_WIDGET_H

#include <Project.h++>
#include <QSortFilterProxyModel>
#include <QWidget>
#include <libfemp/AnalysisResult.h++>
#include <ui/models/AnalysisResultsModel.h++>

#include "ui_AnalysisResultsWidget.h"

/**
 * Widget used in MDI windows to display the results of a given analysis
 */
class AnalysisResultsWidget : public QWidget, private Ui::AnalysisResultsWidget {
	Q_OBJECT

   protected:
	// proxy model to provide a way to filter stuff from the results
	QSortFilterProxyModel m_proxy_model;

   public:
	AnalysisResultsWidget(fem::Project& project, QWidget* parent = nullptr);

   private Q_SLOTS:
	// Calls the TableFilterDialog and sets the table according to the user input
	void setFilterOptions();
};

#endif
