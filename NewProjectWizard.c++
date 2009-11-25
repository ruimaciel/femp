#include "NewProjectWizard.h++"

#include <QDir>
#include <QMessageBox>

#include "ui/NewProjectWizardPage1.h++"
#include "ui/NewProjectWizardPage2.h++"
#include "ui/NewProjectWizardPageLast.h++"

NewProjectWizard::NewProjectWizard(QWidget *parent)
	: QWizard(parent)
{
	// sets the pages that will be displayed by the wizard
	/*
	page1 = new NewProjectWizardPage1(this,basedir);
	addPage(page1);
	*/
	//TODO rename ProjectWizardPage2 class
	page2 = new NewProjectWizardPage2;
	addPage(page2);
	/*
	pageLast = new NewProjectWizardPageLast;
	addPage(pageLast);
	*/
}


NewProjectWizard::~NewProjectWizard()
{
}


void NewProjectWizard::accept()
{
	//TODO emit type depending on the result
	Q_EMIT newProject(Document::TYPE_SOLID3D);

	QDialog::accept();
}

