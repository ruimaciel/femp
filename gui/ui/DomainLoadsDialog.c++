#include "DomainLoadsDialog.h++"

DomainLoadsDialog::DomainLoadsDialog(fem::Model &model, QWidget *parent)
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


DomainLoadsDialog::~DomainLoadsDialog()
{
}


size_t
DomainLoadsDialog::getLoadPattern()
{
	//TODO must get some sort of sanity check
	return this->comboBoxLoadPattern->currentIndex();
}


fem::point
DomainLoadsDialog::getForce()
{
	fem::point p;
	p.data[0] = this->doubleSpinBoxFx->value();
	p.data[1] = this->doubleSpinBoxFy->value();
	p.data[2] = this->doubleSpinBoxFz->value();
	return p;
}


