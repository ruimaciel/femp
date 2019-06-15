#ifndef NEW_PROJECT_WIZAR_HPP
#define NEW_PROJECT_WIZAR_HPP

#include <QString>
#include <QWidget>
#include <QWizard>

//#include "ui/NewProjectWizardPage1.h++"
#include "ui/wizards/NewProjectWizardPage2.h++"
#include "ui/wizards/NewProjectWizardPage3.h++"
#include "ui/wizards/NewProjectWizardPageLast.h++"

#include "Document.h++"

class NewProjectWizard : public QWizard {
    Q_OBJECT

public:
    NewProjectWizard(Document& doc, QWidget* parent = nullptr);

private:
    // NewProjectWizardPage1 *page1;
    NewProjectWizardPage2* m_page2; // Select project type
    NewProjectWizardPage3* m_page3; // Import mesh
    NewProjectWizardPageLast* m_pageLast;

Q_SIGNALS:
    void newProject(Document::Type type);

public Q_SLOTS:
    void accept();
};

#endif
