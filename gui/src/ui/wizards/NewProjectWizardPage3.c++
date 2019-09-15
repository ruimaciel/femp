#include "NewProjectWizardPage3.h++"

#include <QFileDialog>

#include "Document.h++" // for the loading test
#include <libfemp/SurfaceLoadOperators/ConstantLoad.h++>
#include <libfemp/SurfaceLoadOperators/SurfaceNormalLoad.h++>
#include <ui/dialogs/NewMaterialDialog.h++>

NewProjectWizardPage3::NewProjectWizardPage3(Document& document)
    : m_document(document)
{
    setupUi(this);

    // set the variable
    m_successfulImport = false;

    // connect signals
    connect(toolButtonSelectFile, SIGNAL(clicked()), this, SLOT(getFileFromDialog()));
    connect(lineEditFilePath, SIGNAL(returnPressed()), this, SLOT(loadMeshFile()));
    connect(pushButtonNewMaterial, SIGNAL(clicked()), this, SLOT(addNewMaterial()));

    // load the materials combo
    loadMaterialsCombo();
}

bool NewProjectWizardPage3::validatePage()
{
    return m_successfulImport;
}

void NewProjectWizardPage3::loadMaterialsCombo()
{
    fem::Model& femp_model = this->m_document.getProject().getModel();

    for (auto material : femp_model.getMaterialList()) {
        comboBoxMaterialsList->addItem(QString::fromStdString(material.getLabel()));
    }
    if (comboBoxMaterialsList->count() > 0) {
        lineEditFilePath->setEnabled(true);
        toolButtonSelectFile->setEnabled(true);
    }
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
    if (validMeshFile()) {
        // load a mesh from a given file
        std::string file_name;
        //file_name = lineEditFilePath->text().toStdString();	// Qt screws up this conversion
        file_name = lineEditFilePath->text().toUtf8().data(); // hack

        // open the file for parsing
        std::ifstream file;

        file.open(file_name);

        fem::Model& femp_model = m_document.getProject().getModel();
        if (!file.good()) {
            // clear the model except the materials list
            auto material_list = femp_model.getMaterialList();
            femp_model.clear();
            std::for_each(material_list.begin(), material_list.end(), [&femp_model](fem::Material& material) { femp_model.pushMaterial(material); });

            // update the UI
            labelNodesNumber->setText("");
            labelElementsNumber->setText("");
            labelError->setText(tr("Failed to open the file"));

            m_successfulImport = false;
            return;
        }

        fem::SurfaceNormalLoad o;
        o.setLoadMagnitude(-1.0f);

        m_parser.setSurfaceLoadOperator(o);
        // parse the file
        switch (m_parser(file, femp_model)) {
        case Parser::Error::ERR_OK: {
            // update the UI accordingly
            QString temp;
            temp.setNum(femp_model.getNodeMap().size());
            labelNodesNumber->setText(temp);
            temp.setNum(femp_model.numberOfElements());
            labelElementsNumber->setText(temp);
            labelError->setText("");

            m_successfulImport = true;
        } break;

        default:
            // clear the model except the materials list
            auto material_list = femp_model.getMaterialList();
            femp_model.clear();
            std::for_each(material_list.begin(), material_list.end(), [&femp_model](fem::Material& material) { femp_model.pushMaterial(material); });
            //TODO clear the list when exiting

            // update the UI
            labelNodesNumber->setText("");
            labelElementsNumber->setText("");
            labelError->setText(QString::fromStdString(m_parser.error.message));

            m_successfulImport = false;
            break;
        }

        emit completeChanged();
        file.close();
    }
}

bool NewProjectWizardPage3::isComplete() const
{
    return m_successfulImport;
}

void NewProjectWizardPage3::getFileFromDialog(void)
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("MSH file (*.msh)"));
    if (dialog.exec() == QDialog::Accepted) {
        // a file was chosen
        lineEditFilePath->setText(dialog.selectedFiles().first());
    }

    //TODO load the file
    loadMeshFile();
}

void NewProjectWizardPage3::addNewMaterial(void)
{
    NewMaterialDialog dialog(m_document.getProject().getModel(), this);
    switch (dialog.exec()) {
    case QDialog::Accepted:
        loadMaterialsCombo();

        // and now turn on the UI
        lineEditFilePath->setEnabled(true);
        toolButtonSelectFile->setEnabled(true);
        break;

    case QDialog::Rejected:
        break;
    }
}
