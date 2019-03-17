#include "SelectionDialog.h++"

#include <QtWidgets/QVBoxLayout>


SelectionDialog::SelectionDialog (fem::Project &project, SelectionManager &selection_manager, QWidget *parent)
	: QDialog(parent)
{
	this->m_selection_widget = new SelectionWidget(project, selection_manager, this);
	//TODO handle error if memory allocation fails

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(m_selection_widget);
	this->setLayout(layout);

	this->show();
}


