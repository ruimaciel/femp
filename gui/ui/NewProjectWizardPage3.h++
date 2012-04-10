#ifndef NEWPROJECTWIZARDPAGE3_HPP
#define NEWPROJECTWIZARDPAGE3_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include "ui/ui_NewProjectWizardPage3.h"

#include <QWizardPage>

#include "parsers/MshParser.h++"
#include "Document.h++"


/**
New Project Wizard section on how to load a mesh from a file
**/
class NewProjectWizardPage3
	: public QWizardPage, public Ui::NewProjectWizardPage3
{
	Q_OBJECT

	private:
		bool successful_import;
		MshParser parser;

	public:
		Document *document;	// must point to a valid instance or it crashes

	public:
		NewProjectWizardPage3(Document *document);
		~NewProjectWizardPage3();

		bool validatePage();
		bool isComplete() const;

	private:
		bool validMeshFile();
		void loadMaterialsCombo();

	private slots:
		void loadMeshFile();
		void getFileFromDialog(void);
		void addNewMaterial(void);
};


#endif

