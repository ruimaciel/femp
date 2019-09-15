#include "MatrixWidget.h++"

#include <libfemp/Model.h++>
#include <libfemp/Node.h++>

MatrixWidget::MatrixWidget(fem::Project& project, QWidget* parent)
    : QWidget(parent)
{
    setupUi(this);

    m_model = new MatrixModel(project, parent);
    this->tableView->setModel(m_model);
    m_project = &project;
    m_result = &project.result[0];
}
