#include "MatrixWidget.hpp"

#include <libfemp/Model.hpp>
#include <libfemp/Node.hpp>

MatrixWidget::MatrixWidget(fem::Project& project, QWidget* parent) : QWidget(parent) {
	setupUi(this);

	MatrixModel* m_model = new MatrixModel(project, parent);
	this->tableView->setModel(m_model);
}
