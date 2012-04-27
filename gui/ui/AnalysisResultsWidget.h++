#ifndef ANALYSIS_RESULTS_WIDGET_H
#define ANALYSIS_RESULTS_WIDGET_H

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QWidget>

#include "ui_AnalysisResultsWidget.h"
#include "AnalysisResultsModel.h++"
#include "../fem/Project.h++"
#include "../fem/AnalysisResult.h++"


/**
Widget used in MDI windows to display the results of a given analysis
**/
class AnalysisResultsWidget
	:public QWidget, private Ui::AnalysisResultsWidget
{
	Q_OBJECT
protected:
	fem::Project const *m_project;
	fem::AnalysisResult<double> const *m_result;
	AnalysisResultsModel *m_model;

public:
	AnalysisResultsWidget(fem::Project &project, QWidget *parent = nullptr);

	/**
	Sets which project to represent
	**/
	void setProjectResults(fem::AnalysisResult<double> const &result);

private:
	// adds load pattern names to the combo box
	void fillComboBox(fem::Model const &);
};

#endif
