#include "DomainLoadsDialog.hpp"

#include "LoadPatternDialog.hpp"
#include "ui_DomainLoadsDialog.h"

DomainLoadsDialog::DomainLoadsDialog(LoadPatternsModel& model, QWidget* parent) : QDialog(parent), m_ui(std::make_unique<Ui::DomainLoadsDialog>()) {
	m_ui->setupUi(this);

	m_ui->comboBoxLoadPattern->setModel(&model);
}

DomainLoadsDialog::~DomainLoadsDialog() = default;

size_t DomainLoadsDialog::getLoadPattern() {
	// TODO must get some sort of sanity check
	return m_ui->comboBoxLoadPattern->currentIndex();
}

fem::Point3D DomainLoadsDialog::getForce() {
	fem::Point3D p;
	p.data[0] = m_ui->doubleSpinBoxFx->value();
	p.data[1] = m_ui->doubleSpinBoxFy->value();
	p.data[2] = m_ui->doubleSpinBoxFz->value();
	return p;
}
