#include "DisplayOptionsDialog.h++"

DisplayOptionsDialog::DisplayOptionsDialog(fem::Model &model, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	// fill the combo box with the available load pattern
	for(std::vector<fem::LoadPattern>::iterator i = model.load_pattern_list.begin(); i != model.load_pattern_list.end(); i++)
	{
		this->comboBoxLoadPattern->addItem(QString::fromStdString(i->label));
	}

}


DisplayOptionsDialog::~DisplayOptionsDialog()
{
}


size_t DisplayOptionsDialog::getLoadPatternIndex()
{
	return this->comboBoxLoadPattern->currentIndex();
}


bool DisplayOptionsDialog::renderNodalForces()
{
	return(this->checkBoxNodalForces->isChecked());
}


bool DisplayOptionsDialog::renderSurfaceForces()
{
	return(this->checkBoxSurfaceForces->isChecked());
}


bool DisplayOptionsDialog::renderDomainForces()
{
	return(this->checkBoxDomainForces->isChecked());
}


bool DisplayOptionsDialog::renderNodalDisplacements()
{
	return(this->checkBoxNodalDisplacements->isChecked());
}


