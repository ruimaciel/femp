#include "NewProjectWizardPage1.h++"

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <sys/stat.h>

NewProjectWizardPage1::NewProjectWizardPage1(QWidget* parent, QString basedir)
    : QWizardPage(parent)
{
    setupUi(this);
    //TODO test if this directory is valid
    m_baseDir = basedir;
    this->lineEditLocation->setText(basedir);

    // connect signals and slots
    connect(this->pushButtonFileDialog, SIGNAL(clicked()), this, SLOT(setNewLocation()));

    // register fields
    registerField("location", lineEditLocation);
    registerField("projectName*", lineEditProjectName);
}

bool NewProjectWizardPage1::validatePage()
{
    QDir path;
    QFile file;

    //TODO finish this
    if (lineEditLocation->text().isEmpty())
        return false;
    path = lineEditLocation->text();
    if (!path.exists()) {
        QMessageBox msgBox;
        msgBox.setText("Error accessing location");
        msgBox.setInformativeText("Please select a new location for your project");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        return false;
    }

    // test the new project name
    if (lineEditProjectName->text().isEmpty()) {
        return false;
    }
    file.setFileName(path.filePath(lineEditProjectName->text()));
    if (file.exists()) // tests the intended new project directory
    {
        // project name directory already exists
        QMessageBox msgBox;
        msgBox.setText(tr("File already exists"));
        msgBox.setInformativeText(tr("Do you want to use it anyway?"));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        msgBox.setIcon(QMessageBox::Information);
        switch (msgBox.exec()) {
        case QMessageBox::Yes:
            return true;
            break;

        case QMessageBox::No:
            return false;
            break;
        }
    } else {
        // intended project file doesn't exist
    }

    return true;
}

void NewProjectWizardPage1::setNewLocation()
{
    QDir newLocation;
    newLocation = QFileDialog::getExistingDirectory(this, tr("Open Directory"), m_baseDir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    /*
    // This apparently doesn't work
    QDir newLocation;
    QFileDialog fd(this, tr("Select base directory"), base_dir);
    // fd.setFileMode(QFileDialog::Directory);
    fd.setOptions(QFileDialog::ShowDirsOnly);
    fd.setViewMode(QFileDialog::List);
    fd.exec();
    */

    if (newLocation.exists())
        this->lineEditLocation->setText(newLocation.path());
    else
        this->lineEditLocation->setText(m_baseDir);
}
