#include "MatrixWindow.h++"


MatrixWindow::MatrixWindow(fem::Project &project, QWidget *parent)
	: QMdiSubWindow(parent), BaseWindow("Stiffness matrix")
{
	m_project = &project;
	m_matrix_widget = new MatrixWidget(project, parent);

	this->setAttribute(Qt::WA_DeleteOnClose);
	this->setWindowTitle(tr("Stiffness matrix"));
	this->setWidget(m_matrix_widget);
}


