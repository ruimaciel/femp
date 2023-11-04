#ifndef NEWPROJECTWIZARDPAGE3_HPP
#define NEWPROJECTWIZARDPAGE3_HPP

#include <Project.hpp>
#include <QWizardPage>

#include "ui/ui_NewProjectWizardPage3.h"

/**
New Project Wizard section on how to load a mesh from a file
**/
class NewProjectWizardPage3 : public QWizardPage, public Ui::NewProjectWizardPage3 {
	Q_OBJECT

	private:
	bool m_successfulImport;

	public:
	NewProjectWizardPage3(fem::Project& project);

	bool validatePage();
	bool isComplete() const;

	private:
	bool validMeshFile();
	void loadMaterialsCombo();

	private slots:
	void loadMeshFile();
	void getFileFromDialog(void);
	void addNewMaterial(void);

	private:
	fem::Project& m_project;
};

#endif
