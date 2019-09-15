#ifndef NEW_MATERIAL_DIALOG_HPP
#define NEW_MATERIAL_DIALOG_HPP

#include "ui/ui_NewMaterialDialog.h"
#include <QDialog>
#include <libfemp/Model.h++> // for the materials list

class NewMaterialDialog
    : public QDialog,
      private Ui::NewMaterialDialog {
    Q_OBJECT

private:
    fem::Model& m_model; // a pointer to a fem::Model object

public:
    explicit NewMaterialDialog(fem::Model& model, QWidget* parent = nullptr);

private:
    /**
     * Checks if a given string matches a material label already added to the list
     */
    bool isDuplicate(QString name);

private slots:
    void checkMaterialName(); // checks for duplicates
    void addNewMaterial(); // adds a new material to the list from the data added to the forms
};

#endif
