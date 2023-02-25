#include "DomainLoadsDialog.h++"

#include "LoadPatternDialog.h++"

DomainLoadsDialog::DomainLoadsDialog(LoadPatternsModel& model, QWidget* parent) : QDialog(parent) {
	setupUi(this);

	this->comboBoxLoadPattern->setModel(&model);
}

size_t DomainLoadsDialog::getLoadPattern() {
	// TODO must get some sort of sanity check
	return this->comboBoxLoadPattern->currentIndex();
}

fem::Point3D DomainLoadsDialog::getForce() {
	fem::Point3D p;
	p.data[0] = this->doubleSpinBoxFx->value();
	p.data[1] = this->doubleSpinBoxFy->value();
	p.data[2] = this->doubleSpinBoxFz->value();
	return p;
}
