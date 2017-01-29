#include "NodeRestrainsDialog.h++"


NodeRestrainsDialog::NodeRestrainsDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


NodeRestrainsDialog::~NodeRestrainsDialog()
{
}


int 
NodeRestrainsDialog::getRestraints()
{
	int r = NONE;
	if(checkBoxX->isChecked())
		r |= RX;
	if(checkBoxY->isChecked())
		r |= RY;
	if(checkBoxZ->isChecked())
		r |= RZ;

	return r;
}


fem::NodeRestrictions 
NodeRestrainsDialog::getRestrictions() const
{
	fem::NodeRestrictions restrictions;

	if(checkBoxX->isChecked()) restrictions.setdx();
	if(checkBoxY->isChecked()) restrictions.setdy();
	if(checkBoxZ->isChecked()) restrictions.setdz();

	return restrictions;
}

