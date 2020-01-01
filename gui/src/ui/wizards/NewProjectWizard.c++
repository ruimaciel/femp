#include "NewProjectWizard.h++"

#include <QDir>
#include <QMessageBox>

NewProjectWizard::NewProjectWizard(Document& doc, QWidget* parent)
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
    m_page2 = new NewProjectWizardPage2;
    addPage(m_page2);

    m_page3 = new NewProjectWizardPage3(doc.getProject());
    addPage(m_page3);

    //TODO crude hack
    doc.setProjectType(Document::TYPE_SOLID3D);
}

void NewProjectWizard::accept()
{
    //TODO emit type depending on the result
    Q_EMIT newProject(Document::TYPE_SOLID3D);

    QDialog::accept();
}
