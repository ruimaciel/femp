#include "MaterialsEditorDialog.h++"

#include <QTreeWidget>
#include <vector>



MaterialsEditorDialog::MaterialsEditorDialog(fem::Model *model, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	this->model = model;


	// set signals and slots
	connect(listWidgetMaterials, SIGNAL(itemSelectionChanged() ), this, SLOT(resetSelectionUI()));

	// fill the materials
	loadMaterials();
}


MaterialsEditorDialog::~MaterialsEditorDialog()
{
}


void MaterialsEditorDialog::loadMaterials()
{
	for(size_t i = 0; i < model->material_list.size(); i++)
	{
		this->listWidgetMaterials->insertItem(i, model->material_list[i].label);
	}
}


void MaterialsEditorDialog::resetSelectionUI()
{
	if(listWidgetMaterials->selectedItems().empty())
	{
		this->pushButtonEdit->setDisabled(true);
		this->pushButtonEditCopy->setDisabled(true);
		this->pushButtonDelete->setDisabled(true);
	}
	else
	{
		this->pushButtonEdit->setEnabled(true);
		this->pushButtonEditCopy->setEnabled(true);
		this->pushButtonDelete->setEnabled(true);
	}
}
