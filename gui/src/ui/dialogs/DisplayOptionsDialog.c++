#include "DisplayOptionsDialog.h++"

DisplayOptionsDialog::DisplayOptionsDialog(fem::Model &model, QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    // fill the combo box with the available load pattern
    for(auto load_pattern: model.getLoadPatternList() )
    {
        QString label = QString::fromStdString(load_pattern.getLabel());
        this->comboBoxLoadPattern->addItem(label);
    }

}


size_t
DisplayOptionsDialog::getLoadPatternIndex()
{
    return this->comboBoxLoadPattern->currentIndex();
}


bool
DisplayOptionsDialog::renderNodalForces()
{
    return(this->checkBoxNodalForces->isChecked());
}


bool
DisplayOptionsDialog::renderSurfaceForces()
{
    return(this->checkBoxSurfaceForces->isChecked());
}


bool
DisplayOptionsDialog::renderDomainForces()
{
    return(this->checkBoxDomainForces->isChecked());
}


bool
DisplayOptionsDialog::renderNodalDisplacements()
{
    return(this->checkBoxNodalDisplacements->isChecked());
}


