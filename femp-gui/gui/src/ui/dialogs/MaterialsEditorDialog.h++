#ifndef MATERIALS_EDITOR_DIALOG_HPP
#define MATERIALS_EDITOR_DIALOG_HPP

#include "ui_MaterialsEditorDialog.h"
#include <QDialog>

#include <libfemp/Model.h++>

class MaterialsEditorDialog
    : public QDialog,
      private Ui::MaterialsEditorDialog {
    Q_OBJECT

private:
    fem::Model& model;

public:
    explicit MaterialsEditorDialog(fem::Model& model, QWidget* parent = nullptr);
    ~MaterialsEditorDialog();

public slots:
    void loadMaterials();

private slots:

    /**
     * Resets the UI according to the selection state
     */
    void resetSelectionUI();
};

#endif
