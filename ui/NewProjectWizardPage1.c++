#include "NewProjectWizardPage1.h++"

NewProjectWizardPage1::NewProjectWizardPage1(QWidget *parent, QString basedir)
	: QWizardPage(parent)
{
	setupUi(this);
	this->lineEditLocation->setText(basedir);
}

NewProjectWizardPage1::~NewProjectWizardPage1()
{
}

