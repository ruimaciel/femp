#include "DomainLoadsDialog.h++"

DomainLoadsDialog::DomainLoadsDialog(LoadPatternsModel &model, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	this->comboBoxLoadPattern->setModel(&model);
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


