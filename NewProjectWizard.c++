#include "NewProjectWizard.h++"

#include <QDir>
#include <QMessageBox>

#include "ui/NewProjectWizardPage1.h++"
#include "ui/NewProjectWizardPage2.h++"
#include "ui/NewProjectWizardPageLast.h++"

NewProjectWizard::NewProjectWizard(QWidget *parent, QString basedir)
	: QWizard(parent)
{
	// sets the pages that will be displayed by the wizard
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
	QDir location;
	QFile file;
	location = field("location").toString();
	Document document;	// temporary document

	//TODO create a brand new project
	qWarning("location: %s", qPrintable(location.absolutePath()));

	file.setFileName(location.filePath(field("projectName").toString()));

	// sets the project dir
	document.setFileName(file.fileName() + ".fem.json");

	// initialize the values
	//TODO set values
	document.setProjectType(Document::TYPE_SOLID3D);

	// Save the empty project files
	switch(document.save())
	{
		case Document::ERR_NONE:
			break;
		default:
			QMessageBox msgBox;
			msgBox.setText("Some error occurred while saving the project file");
			msgBox.exec();
			break;
	}

	QDialog::accept();
}

