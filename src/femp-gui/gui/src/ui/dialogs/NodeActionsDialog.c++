#include "NodeActionsDialog.h++"

#include "LoadPatternDialog.h++"
#include "ui/ui_NodeActionsDialog.h"

// Qt includes
#include <QAbstractItemView>

NodeActionsDialog::NodeActionsDialog(LoadPatternsModel& model, QWidget* parent) : QDialog(parent), m_ui(std::unique_ptr<Ui::NodeActionsDialog>()) {
	m_ui->setupUi(this);

	m_ui->comboBoxLoadPattern->setModel(&model);
}

NodeActionsDialog::~NodeActionsDialog() = default;

size_t NodeActionsDialog::getLoadPattern() {
	// TODO must get some sort of sanity check
	return m_ui->comboBoxLoadPattern->currentIndex();
}

fem::Point3D NodeActionsDialog::getForce() {
	fem::Point3D p;
	p.data[0] = m_ui->doubleSpinBoxFx->value();
	p.data[1] = m_ui->doubleSpinBoxFy->value();
	p.data[2] = m_ui->doubleSpinBoxFz->value();
	return p;
}

fem::Point3D NodeActionsDialog::getDisplacement() {
	fem::Point3D p;
	p.data[0] = m_ui->doubleSpinBoxDx->value();
	p.data[1] = m_ui->doubleSpinBoxDy->value();
	p.data[2] = m_ui->doubleSpinBoxDz->value();
	return p;
}

void NodeActionsDialog::loadPatternCreated(size_t, fem::LoadPattern const&) {
	m_ui->comboBoxLoadPattern->view()->reset();
}
