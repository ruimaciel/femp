#ifndef ANALYSIS_RESULTS_WIDGET_H
#define ANALYSIS_RESULTS_WIDGET_H

#include <ui/models/AnalysisResultsModel.h++>

// include gui
#include <Project.h++>

// include libfemp
#include <libfemp/AnalysisResult.h++>

// include Qt
#include <QSortFilterProxyModel>
#include <QWidget>

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
	AnalysisResultsWidget(fem::Project& project, QWidget* parent = nullptr);

	private Q_SLOTS:
	// Calls the TableFilterDialog and sets the table according to the user input
	void setFilterOptions();

	private:
 	Ui::AnalysisResultsWidget *m_ui;
};

#endif
