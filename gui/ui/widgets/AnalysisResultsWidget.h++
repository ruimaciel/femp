#ifndef ANALYSIS_RESULTS_WIDGET_H
#define ANALYSIS_RESULTS_WIDGET_H

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include <QWidget>
#include <QSortFilterProxyModel>

#include <Project.h++>
#include <libfemp/AnalysisResult.h++>

#include "ui_AnalysisResultsWidget.h"
#include <ui/AnalysisResultsModel.h++>


/**
Widget used in MDI windows to display the results of a given analysis
**/
class AnalysisResultsWidget
	:public QWidget, private Ui::AnalysisResultsWidget
{
	Q_OBJECT

protected:
	fem::Project const &m_project;
	fem::AnalysisResult const *m_result;
	AnalysisResultsModel *m_model;

	// proxy model to provide a way to filter stuff from the results
	QSortFilterProxyModel m_proxy_model;

public:
	AnalysisResultsWidget(fem::Project &project, QWidget *parent = nullptr);

	/**
	Sets which project to represent
	**/
	void setProjectResults(fem::AnalysisResult const &result);

private:
	// adds load pattern names to the combo box
	void fillComboBox(fem::Model const &);

private Q_SLOTS:
	// Calls the TableFilterDialog and sets the table according to the user input
	void setFilterOptions();
};

#endif
