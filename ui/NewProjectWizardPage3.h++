#ifndef NEWPROJECTWIZARDPAGE3_HPP
#define NEWPROJECTWIZARDPAGE3_HPP

#include "ui/ui_NewProjectWizardPage3.h"

#include <QWizardPage>

#include "Document.h++"


class NewProjectWizardPage3: public QWizardPage, public Ui_NewProjectWizardPage3
{
	Q_OBJECT

	private:
		bool successful_import;

	public:
		Document *document;	// must point to a valid instance or it crashes

	public:
		NewProjectWizardPage3();
		~NewProjectWizardPage3();

		bool validatePage();
		bool isComplete() const;

	private:
		bool validMeshFile();

	private slots:
		void loadMeshFile();
		void getFileFromDialog(void);
};


#endif

