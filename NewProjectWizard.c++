#include "NewProjectWizard.h++"

#include "ui/NewProjectWizardPage1.h++"
#include "ui/NewProjectWizardPage2.h++"
#include "ui/NewProjectWizardPageLast.h++"

NewProjectWizard::NewProjectWizard(QWidget *parent, QString basedir)
	: QWizard(parent)
{
	page1 = new NewProjectWizardPage1(this,basedir);
	addPage(page1);
	addPage(new NewProjectWizardPage2);
	addPage(new NewProjectWizardPageLast);
}


NewProjectWizard::~NewProjectWizard()
{
}
