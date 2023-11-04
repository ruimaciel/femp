#include "NodeRestrainsDialog.hpp"

#include "ui/ui_NodeRestrainDialog.h"

NodeRestrainsDialog::NodeRestrainsDialog(QWidget* parent) : QDialog(parent), m_ui(std::make_unique<Ui::NodeRestrainDialog>()) {
	m_ui->setupUi(this);
}

NodeRestrainsDialog::~NodeRestrainsDialog() = default;

int NodeRestrainsDialog::getRestraints() {
	int r = NONE;
	if (m_ui->checkBoxX->isChecked()) r |= RX;
	if (m_ui->checkBoxY->isChecked()) r |= RY;
	if (m_ui->checkBoxZ->isChecked()) r |= RZ;

	return r;
}

fem::NodeRestrictions NodeRestrainsDialog::getRestrictions() const {
	fem::NodeRestrictions restrictions;

	if (m_ui->checkBoxX->isChecked()) restrictions.setdx();
	if (m_ui->checkBoxY->isChecked()) restrictions.setdy();
	if (m_ui->checkBoxZ->isChecked()) restrictions.setdz();

	return restrictions;
}
