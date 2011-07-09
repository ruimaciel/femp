#include "NewProjectWizard.h++"

#include <QDir>
#include <QMessageBox>


NewProjectWizard::NewProjectWizard(Document &doc, QWidget *parent)
	: QWizard(parent)
{
	// clear the model, start with a clean slate
	doc.clear();

	// sets the pages that will be displayed by the wizard
	/*
	page1 = new NewProjectWizardPage1(this,basedir);
	addPage(page1);
	*/

	//TODO rename ProjectWizardPage2 class
	page2 = new NewProjectWizardPage2;
	addPage(page2);

	page3 = new NewProjectWizardPage3(&doc);
	page3->document = &doc;
	addPage(page3);

	/*
	pageLast = new NewProjectWizardPageLast;
	addPage(pageLast);
	*/

	//TODO crude hack
	doc.setProjectType(Document::TYPE_SOLID3D);
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

