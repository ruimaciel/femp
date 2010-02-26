#include "NewProjectWizardPage3.h++"

#include <QFileDialog>
#include "Document.h++"	// for the loading test


NewProjectWizardPage3::NewProjectWizardPage3()
{
	setupUi(this);

	// set the variable
	successful_import = false;

	// connect signals
	connect(toolButtonSelectFile, SIGNAL(clicked()), this, SLOT(getFileFromDialog()));
	connect(lineEditFilePath, SIGNAL(returnPressed()), this, SLOT(loadMeshFile()));
}


NewProjectWizardPage3::~NewProjectWizardPage3()
{
}


bool NewProjectWizardPage3::validatePage()
{
	return successful_import;
}


bool NewProjectWizardPage3::validMeshFile()
{
	// checks if a given mesh file is valid

	//TODO
	// file path must be non-null
	return true;
}


void NewProjectWizardPage3::loadMeshFile()
{
	// proceed if the file is valid
	if(validMeshFile() )
	{
		// load a mesh from a given file
		switch(document->importMesh(lineEditFilePath->text()) )
		{
			case Document::ERR_OK:
				{
				// update the UI accordingly
				QString temp;
				temp.setNum(document->model.node_list.size());
				labelNodesNumber->setText(temp);
				temp.setNum(document->model.element_list.size());
				labelElementsNumber->setText(temp);
				labelError->setText("");

				successful_import = true;
				}
				break;

			default:
				// clear the model except the materials list
				document->model.node_list.clear();
				document->model.element_list.clear();
				document->model.node_restrictions_list.clear();
				document->model.load_pattern_list.clear();
				//TODO clear the list when exiting

				// update the UI
				labelNodesNumber->setText("");
				labelElementsNumber->setText("");
				labelError->setText("Failed to load");

				successful_import = false;
				break;
		}

		emit completeChanged();
	}
}


bool NewProjectWizardPage3::isComplete() const
{
	return successful_import;
}


void NewProjectWizardPage3::getFileFromDialog(void)
{
	 QFileDialog dialog(this);
	 dialog.setFileMode(QFileDialog::ExistingFile);
	 dialog.setNameFilter(tr("*.msh"));
	 if(dialog.exec() == QDialog::Accepted)
	 {
	 	// a file was chosen
		lineEditFilePath->setText(dialog.selectedFiles().first());
	 }

	 //TODO load the file
	 loadMeshFile();
}

