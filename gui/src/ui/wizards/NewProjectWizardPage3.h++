#ifndef NEWPROJECTWIZARDPAGE3_HPP
#define NEWPROJECTWIZARDPAGE3_HPP

#include "ui/ui_NewProjectWizardPage3.h"

#include <QWizardPage>

#include "Document.h++"

/**
New Project Wizard section on how to load a mesh from a file
**/
class NewProjectWizardPage3
    : public QWizardPage,
      public Ui::NewProjectWizardPage3
{
    Q_OBJECT

private:
    bool m_successfulImport;

    Document& m_document;

public:
    NewProjectWizardPage3(Document& document);

    bool validatePage();
    bool isComplete() const;

private:
    bool validMeshFile();
    void loadMaterialsCombo();

private slots:
    void loadMeshFile();
    void getFileFromDialog(void);
    void addNewMaterial(void);
};

#endif
