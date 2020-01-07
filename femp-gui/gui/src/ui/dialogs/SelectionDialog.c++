#include "SelectionDialog.h++"

#include <QtWidgets/QVBoxLayout>

SelectionDialog::SelectionDialog(std::shared_ptr<gui::Model> model, SelectionManager& selection_manager, QWidget* parent)
    : QDialog(parent)
{
    this->m_selection_widget = new SelectionWidget(model, selection_manager, this);
    //TODO handle error if memory allocation fails

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_selection_widget);
    this->setLayout(layout);

    this->show();
}
