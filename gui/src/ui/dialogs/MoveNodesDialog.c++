#include "MoveNodesDialog.h++"

MoveNodesDialog::MoveNodesDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
}


fem::Point3D
MoveNodesDialog::getTranslation()
{
    fem::Point3D translation;

    translation.x(doubleSpinBoxX->value());
    translation.y(doubleSpinBoxY->value());
    translation.z(doubleSpinBoxZ->value());

    return translation;
}

