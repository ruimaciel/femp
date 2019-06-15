#ifndef NEWPROJECTWIZARDPAGE1_HPP
#define NEWPROJECTWIZARDPAGE1_HPP

#include "ui/ui_NewProjectWizardPage1.h"
#include <sigc++/sigc++.h> // to side step a compiler error caused by a conflict with Qt and libsigc++

#include <QString>
#include <QWizardPage>

class NewProjectWizardPage1 : public QWizardPage, public Ui::NewProjectWizardPage1 {
    Q_OBJECT

public:
    NewProjectWizardPage1(QWidget* parent = nullptr, QString basedir = QString());

    bool validatePage();

private:
    QString m_baseDir;

private Q_SLOTS:
    void setNewLocation(); // uses a QFileDialog to get a new project location
};

#endif
