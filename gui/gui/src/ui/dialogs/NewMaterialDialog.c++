#include "NewMaterialDialog.h++"

#include <QDoubleValidator>
#include <vector>

#include <libfemp/Material.h++>

NewMaterialDialog::NewMaterialDialog(gui::application::IMaterialRepositoryPtr material_repository, QWidget* parent)
    : QDialog(parent)
    , m_material_repository(material_repository)
{
    setupUi(this);

    lineEditPoisson->setValidator(new QDoubleValidator(-1.5, 0.5, 5, this));
    lineEditYoung->setValidator(new QDoubleValidator(0, 10e20, 8, this));

    // signals and slots
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(addNewMaterial()));
}

bool NewMaterialDialog::isDuplicate(QString name)
{
    //TODO replace with STL algorithm
    for (auto material : m_material_repository->getMaterialList()) {
        if (material.getLabel() == name.toStdString())
            return true;
    }

    return false;
}

void NewMaterialDialog::addNewMaterial()
{
    qWarning("NewMaterialDialog:: adding new material");
    // perform sanity checks
    if (lineEditMaterialName->text().isEmpty()) {
        labelStatus->setText("This material needs a name");
        lineEditMaterialName->setFocus();
        return;
    }

    if (isDuplicate(lineEditMaterialName->text())) {
        labelStatus->setText("A material already has that name");
        lineEditMaterialName->setFocus();
        return;
    }

    // if all went well then add a new material
    const std::string label = lineEditMaterialName->text().toStdString();
    const double E = lineEditYoung->text().toDouble();
    const double nu = lineEditPoisson->text().toDouble();

    fem::Material new_material(label, E, nu);

    m_material_repository->pushMaterial(new_material);

    accept();
}
