#include "RunPropertiesDialog.h++"


RunPropertiesDialog::RunPropertiesDialog(fem::AnalysisResult<double> &result, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	this->setValues(result);
}


void RunPropertiesDialog::setValues(fem::AnalysisResult<double> &result)
{
	this->labelEnergyValue.setNum(result.energy);
	this->labelTimeValue.setNum(result.elapsed_time);
}


