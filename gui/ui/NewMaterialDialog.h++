#ifndef NEW_MATERIAL_DIALOG_HPP
#define NEW_MATERIAL_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDialog>
#include "ui/ui_NewMaterialDialog.h"

#include "fem/Model.h++"	// for the materials list


class NewMaterialDialog
	: public QDialog, private Ui::NewMaterialDialog
{
	Q_OBJECT

	private:
		fem::Model *model;	// a pointer to a fem::Model object

	public:
		NewMaterialDialog(fem::Model *model, QWidget *parent = NULL);
		~NewMaterialDialog();


	private:
		// checks if a given string matches a material label already added to the list
		bool isDuplicate(QString name);

	private slots:
		void checkMaterialName();	// checks for duplicates
		void addNewMaterial();	// adds a new material to the list from the data added to the forms
};

#endif
