#include "MatrixWidget.h++"

#include <iostream>

#include "../fem/Model.h++"
#include "../fem/Node.h++"


MatrixWidget::MatrixWidget(fem::Project &project, QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);

	m_model = new MatrixModel(project, parent);
	this->tableView->setModel(m_model);
	m_project = &project;
	m_result = &project.result[0];	//CRUDE HACK
}

