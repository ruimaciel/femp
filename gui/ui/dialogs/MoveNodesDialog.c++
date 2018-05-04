#include "MoveNodesDialog.h++"

MoveNodesDialog::MoveNodesDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


MoveNodesDialog::~MoveNodesDialog()
{
}


fem::Point
MoveNodesDialog::getTranslation()
{
	fem::Point translation;

	translation.x(doubleSpinBoxX->value());
	translation.y(doubleSpinBoxY->value());
	translation.z(doubleSpinBoxZ->value());

	return translation;
}

