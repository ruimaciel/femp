#ifndef NEWPROJECTWIZARDPAGE1_HPP
#define NEWPROJECTWIZARDPAGE1_HPP

#include "ui/ui_NewProjectWizardPage1.h"

#include <QWizardPage>
#include <QString>


class NewProjectWizardPage1: public QWizardPage, public Ui_NewProjectWizardPage1
{
	public:
		NewProjectWizardPage1(QWidget *parent = 0, QString basedir = QString());
		~NewProjectWizardPage1();

	private:
		QString base_dir;
};


#endif

