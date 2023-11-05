#ifndef FEMP_UI_ANALYSIS_RESULTS_WIDGET_HPP
#define FEMP_UI_ANALYSIS_RESULTS_WIDGET_HPP

#include <ui/models/AnalysisResultsModel.hpp>

// include gui
#include <Project.hpp>

// include libfemp
#include <libfemp/AnalysisResult.hpp>

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
	Ui::AnalysisResultsWidget* m_ui;
};

#endif
