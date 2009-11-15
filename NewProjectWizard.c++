#include "NewProjectWizard.h++"

#include "ui/NewProjectWizardPage1.h++"
#include "ui/NewProjectWizardPage2.h++"
#include "ui/NewProjectWizardPageLast.h++"

NewProjectWizard::NewProjectWizard(QWidget *parent, QString basedir)
	: QWizard(parent)
{
	page1 = new NewProjectWizardPage1(this,basedir);
	addPage(page1);
	page2 = new NewProjectWizardPage2;
	addPage(page2);
	pageLast = new NewProjectWizardPageLast;
	addPage(pageLast);
}


NewProjectWizard::~NewProjectWizard()
{
}


void NewProjectWizard::accept()
{
	QString location;
	// location = field("completelocation").toString();

	Document::Type type;
	//TODO find a way to pass the project type
	type = Document::TYPE_SOLID3D;

	Q_EMIT newProject(location, type);
	QDialog::accept();
}

