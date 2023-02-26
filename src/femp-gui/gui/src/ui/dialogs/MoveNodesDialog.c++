#include "MoveNodesDialog.h++"

#include "ui_MoveNodesDialog.h"

MoveNodesDialog::MoveNodesDialog(QWidget* parent) : QDialog(parent), m_ui(std::make_unique<Ui::MoveNodesDialog>()) {
	m_ui->setupUi(this);
}

MoveNodesDialog::~MoveNodesDialog() = default;

fem::Point3D MoveNodesDialog::getTranslation() {
	fem::Point3D translation;

	translation.x(m_ui->doubleSpinBoxX->value());
	translation.y(m_ui->doubleSpinBoxY->value());
	translation.z(m_ui->doubleSpinBoxZ->value());

	return translation;
}
