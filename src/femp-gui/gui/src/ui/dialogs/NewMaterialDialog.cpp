#include "NewMaterialDialog.hpp"

#include <QDoubleValidator>
#include <libfemp/Material.hpp>
#include <vector>

#include "ui/ui_NewMaterialDialog.h"

NewMaterialDialog::NewMaterialDialog(gui::application::IMaterialRepositoryPtr material_repository, QWidget* parent)
	: QDialog(parent), m_material_repository(material_repository), m_ui(std::make_unique<Ui::NewMaterialDialog>()) {
	m_ui->setupUi(this);

	m_ui->lineEditPoisson->setValidator(new QDoubleValidator(-1.5, 0.5, 5, this));
	m_ui->lineEditYoung->setValidator(new QDoubleValidator(0, 10e20, 8, this));

	// signals and slots
	connect(m_ui->buttonBox, SIGNAL(accepted()), this, SLOT(addNewMaterial()));
}

NewMaterialDialog::~NewMaterialDialog() = default;

bool NewMaterialDialog::isDuplicate(QString name) {
	// TODO replace with STL algorithm
	for (auto material : m_material_repository->getMaterialList()) {
		if (material.getLabel() == name.toStdString()) return true;
	}

	return false;
}

void NewMaterialDialog::addNewMaterial() {
	qWarning("NewMaterialDialog:: adding new material");
	// perform sanity checks
	if (m_ui->lineEditMaterialName->text().isEmpty()) {
		m_ui->labelStatus->setText("This material needs a name");
		m_ui->lineEditMaterialName->setFocus();
		return;
	}

	if (isDuplicate(m_ui->lineEditMaterialName->text())) {
		m_ui->labelStatus->setText("A material already has that name");
		m_ui->lineEditMaterialName->setFocus();
		return;
	}

	// if all went well then add a new material
	const std::string label = m_ui->lineEditMaterialName->text().toStdString();
	const double E = m_ui->lineEditYoung->text().toDouble();
	const double nu = m_ui->lineEditPoisson->text().toDouble();

	fem::Material new_material(label, E, nu);

	m_material_repository->pushMaterial(new_material);

	accept();
}
