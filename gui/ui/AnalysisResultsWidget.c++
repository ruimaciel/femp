#include "AnalysisResultsWidget.h++"

#include <iostream>

#include "../fem/Model.h++"
#include "../fem/Node.h++"


AnalysisResultsWidget::AnalysisResultsWidget(fem::Project &project, QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);

	m_model = new AnalysisResultsModel(project, parent);
	this->tableView->setModel(m_model);

	m_project = &project;

	setProjectResults(project.result[0]);	//CRUDE HACK
}


void 
AnalysisResultsWidget::setProjectResults(fem::AnalysisResult<double> const &results)
{
	m_result  = &results;
}


void 
AnalysisResultsWidget::fillComboBox(fem::Model const &)
{
	//TODO finish this
}

