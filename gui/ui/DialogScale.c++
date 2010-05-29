#include "DialogScale.h++"


DialogScale::DialogScale(float scale, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	// set the current scale
	this->doubleSpinBox->setValue(scale);
}


DialogScale::~DialogScale()
{
}


double DialogScale::scale()
{
	return this->doubleSpinBox->value();
}
