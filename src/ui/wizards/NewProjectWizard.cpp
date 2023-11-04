#include "NewProjectWizard.hpp"

#include <QDir>
#include <QMessageBox>

NewProjectWizard::NewProjectWizard(Document& doc, QWidget* parent) : QWizard(parent) {
	// clear the model, start with a clean slate
	doc.clear();
	// TODO crude hack
	doc.setProjectType(Document::TYPE_SOLID3D);

	// TODO rename ProjectWizardPage2 class
	addPage(new NewProjectWizardPage2);
	addPage(new NewProjectWizardPage3(doc.getProject()));
}

void NewProjectWizard::accept() {
	// TODO emit type depending on the result
	Q_EMIT newProject(Document::TYPE_SOLID3D);

	QDialog::accept();
}
