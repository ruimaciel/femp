#include "NewProjectWizardPage1.h++"

#include <sys/stat.h>
#include <QMessageBox>
#include <QFileDialog>

NewProjectWizardPage1::NewProjectWizardPage1(QWidget *parent, QString basedir)
	: QWizardPage(parent)
{
	setupUi(this);
	//TODO test if this directory is valid
	base_dir = basedir;
	this->lineEditLocation->setText(basedir);


	// connect signals and slots
	connect(this->pushButtonFileDialog,SIGNAL(clicked()), this, SLOT(setNewLocation()));

	// register fields
	registerField("location",lineEditLocation);
	registerField("projectName*",lineEditProjectName);
}

NewProjectWizardPage1::~NewProjectWizardPage1()
{
}


bool NewProjectWizardPage1::validatePage()
{
	struct stat buffer;	// buffer for stat()

	QString path;
	//TODO finish this 
	path = lineEditLocation->text();
	if(path.isEmpty() )
		return false;
	if(stat(path.toAscii(), &buffer) != 0)
	{
		QMessageBox msgBox;
		msgBox.setText("Error accessing location");
		msgBox.setInformativeText("Please select a new location for your project");
		msgBox.setIcon(QMessageBox::Information);
		msgBox.exec();
		return false;
	}
	if(lineEditProjectName->text().isEmpty())
	{
		//TODO "next" button needs to be disabled
		return false;
	}
	path = lineEditLocation->text();
	if(path.isEmpty() )
		return false;
	if(stat(path.toAscii(), &buffer) != 0)
	{
		QMessageBox msgBox;
		msgBox.setText("Error accessing location");
		msgBox.setInformativeText("Please select a new location for your project");
		msgBox.setIcon(QMessageBox::Information);
		msgBox.exec();
		return false;
	}

	path += lineEditProjectName->text();
	
	return true;
}


void NewProjectWizardPage1::setNewLocation()
{
	QString newLocation;
	newLocation = QFileDialog::getExistingDirectory(this, tr("Open Directory"), base_dir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	if(newLocation.isEmpty())
		this->lineEditLocation->setText(base_dir);
	else
		this->lineEditLocation->setText(newLocation);
}

