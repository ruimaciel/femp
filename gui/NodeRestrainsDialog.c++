#include "NodeRestrainsDialog.h++"


NodeRestrainsDialog::NodeRestrainsDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


NodeRestrainsDialog::~NodeRestrainsDialog()
{
}


int NodeRestrainsDialog::getRestraints()
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

