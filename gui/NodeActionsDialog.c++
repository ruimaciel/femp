#include "NodeActionsDialog.h++"

NodeActionsDialog::NodeActionsDialog(fem::Model &model, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	// setup the LoadPattern vector
	if(model.load_pattern_list.empty())
	{
		fem::LoadPattern lp;
		lp.label = "Default";
		model.load_pattern_list.push_back(lp);
	}
	
	// fill the load pattern combo box
	for(size_t i = 0; i < model.load_pattern_list.size(); i++)
	{
		this->comboBoxLoadPattern->insertItem(i, QString::fromStdString(model.load_pattern_list[i].label));
	}
}


NodeActionsDialog::~NodeActionsDialog()
{
}


size_t NodeActionsDialog::getLoadPattern()
{
	//TODO must get some sort of sanity check
	return this->comboBoxLoadPattern->currentIndex();
}


fem::point NodeActionsDialog::getForce()
{
	fem::point p;
	p.data[0] = this->doubleSpinBoxFx->value();
	p.data[1] = this->doubleSpinBoxFy->value();
	p.data[2] = this->doubleSpinBoxFz->value();
	return p;
}


fem::point NodeActionsDialog::getDisplacement()
{
	fem::point p;
	p.data[0] = this->doubleSpinBoxDx->value();
	p.data[1] = this->doubleSpinBoxDy->value();
	p.data[2] = this->doubleSpinBoxDz->value();
	return p;
}

