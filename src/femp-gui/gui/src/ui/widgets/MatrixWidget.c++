#include "MatrixWidget.h++"

#include <libfemp/Model.h++>
#include <libfemp/Node.h++>

MatrixWidget::MatrixWidget(fem::Project& project, QWidget* parent) : QWidget(parent) {
	setupUi(this);

	MatrixModel* m_model = new MatrixModel(project, parent);
	this->tableView->setModel(m_model);
}
