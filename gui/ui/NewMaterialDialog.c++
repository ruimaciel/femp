#include "NewMaterialDialog.h++"

#include <vector>

#include <libfemp/Material.h++>


NewMaterialDialog::NewMaterialDialog(fem::Model &model, QWidget *parent)
	: QDialog(parent), m_model(model)
{
	setupUi(this);
	
	lineEditPoisson->setValidator(new QDoubleValidator(-1.5,0.5,5,this));
	lineEditYoung->setValidator(new QDoubleValidator(0,10e20,8,this));

	// signals and slots
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(addNewMaterial()));
}


NewMaterialDialog::~NewMaterialDialog()
{
}


bool NewMaterialDialog::isDuplicate(QString name)
{
	for(std::vector<fem::Material>::iterator i = m_model.material_list.begin(); i != m_model.material_list.end(); i++)
	{
		if(i->label == name.toStdString())
			return true;
	}

	return false;
}


void NewMaterialDialog::checkMaterialName()
{
	//TODO finish
}


void NewMaterialDialog::addNewMaterial()
{
	qWarning("NewMaterialDialog:: adding new material");
	// perform sanity checks
	if(lineEditMaterialName->text().isEmpty())
	{
		labelStatus->setText("This material needs a name");
		lineEditMaterialName->setFocus();
		return;
	}

	if(isDuplicate(lineEditMaterialName->text()) )
	{
		labelStatus->setText("A material already has that name");
		lineEditMaterialName->setFocus();
		return;
	}


	// if all went well then add a new material
	fem::Material new_material;

	new_material.label = lineEditMaterialName->text().toStdString();
	new_material.E = lineEditYoung->text().toDouble();
	new_material.nu = lineEditPoisson->text().toDouble();

	m_model.material_list.push_back(new_material);

	accept();

}


