#ifndef NEWPROJECTWIZARDPAGE1_HPP
#define NEWPROJECTWIZARDPAGE1_HPP

#include "ui/ui_NewProjectWizardPage1.h"

#include <QString>
#include <QWizardPage>

class NewProjectWizardPage1
    : public QWizardPage
    , public Ui::NewProjectWizardPage1
{
    Q_OBJECT

public:
    NewProjectWizardPage1(QWidget* parent = nullptr, QString basedir = QString());

    bool validatePage();

private:
    QString m_baseDir;

private Q_SLOTS:
    void setNewLocation();
};

#endif
