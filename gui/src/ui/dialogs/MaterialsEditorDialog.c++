#include "MaterialsEditorDialog.h++"

#include <QTreeWidget>
#include <vector>

MaterialsEditorDialog::MaterialsEditorDialog(fem::Model & model, QWidget* parent)
    : QDialog(parent), model(model)
{
    setupUi(this);

    // set signals and slots
    connect(listWidgetMaterials, SIGNAL(itemSelectionChanged()), this, SLOT(resetSelectionUI()));

    // fill the materials
    loadMaterials();
}

MaterialsEditorDialog::~MaterialsEditorDialog()
{
}

void MaterialsEditorDialog::loadMaterials()
{
    auto material_list = model.getMaterialList();
    for (size_t i = 0; i < material_list.size(); i++) {
        this->listWidgetMaterials->insertItem(int(i), QString::fromStdString(material_list[i].label));
    }
}

void MaterialsEditorDialog::resetSelectionUI()
{
    if (listWidgetMaterials->selectedItems().empty()) {
        this->pushButtonEdit->setDisabled(true);
        this->pushButtonEditCopy->setDisabled(true);
        this->pushButtonDelete->setDisabled(true);
    } else {
        this->pushButtonEdit->setEnabled(true);
        this->pushButtonEditCopy->setEnabled(true);
        this->pushButtonDelete->setEnabled(true);
    }
}
