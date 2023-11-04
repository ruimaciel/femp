#include "MaterialsEditorDialog.hpp"

#include "ui_MaterialsEditorDialog.h"

// std includes
#include <vector>

MaterialsEditorDialog::MaterialsEditorDialog(fem::Model& model, QWidget* parent)
	: QDialog(parent), model(model), m_ui(std::make_unique<Ui::MaterialsEditorDialog>()) {
	m_ui->setupUi(this);

	// set signals and slots
	connect(m_ui->listWidgetMaterials, SIGNAL(itemSelectionChanged()), this, SLOT(resetSelectionUI()));

	// fill the materials
	loadMaterials();
}

MaterialsEditorDialog::~MaterialsEditorDialog() {}

void MaterialsEditorDialog::loadMaterials() {
	auto material_list = model.getMaterialList();
	for (size_t i = 0; i < material_list.size(); i++) {
		m_ui->listWidgetMaterials->insertItem(int(i), QString::fromStdString(material_list[i].getLabel()));
	}
}

void MaterialsEditorDialog::resetSelectionUI() {
	if (m_ui->listWidgetMaterials->selectedItems().empty()) {
		m_ui->pushButtonEdit->setDisabled(true);
		m_ui->pushButtonEditCopy->setDisabled(true);
		m_ui->pushButtonDelete->setDisabled(true);
	} else {
		m_ui->pushButtonEdit->setEnabled(true);
		m_ui->pushButtonEditCopy->setEnabled(true);
		m_ui->pushButtonDelete->setEnabled(true);
	}
}
