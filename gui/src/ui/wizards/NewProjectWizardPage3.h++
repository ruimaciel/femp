#ifndef NEWPROJECTWIZARDPAGE3_HPP
#define NEWPROJECTWIZARDPAGE3_HPP

#include "ui/ui_NewProjectWizardPage3.h"

#include <QWizardPage>

#include "Document.h++"

#include <libfemp/parsers/MshParser.h++>

/**
New Project Wizard section on how to load a mesh from a file
**/
class NewProjectWizardPage3
    : public QWizardPage,
      public Ui::NewProjectWizardPage3 {
    Q_OBJECT

private:
    bool m_successfulImport;
    MshParser m_parser;

    Document& m_document; // must point to a valid instance or it crashes

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
