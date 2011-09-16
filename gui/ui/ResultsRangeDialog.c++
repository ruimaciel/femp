#include "ResultsRangeDialog.h++"

#include <QVBoxLayout>


ResultsRangeDialog::ResultsRangeDialog(QWidget *parent )
	: QDialog(parent)
{
	ui.setupUi(this);
	connectSignalsToSlots();
}


void 
ResultsRangeDialog::setStresses(const fem::Stresses<double> &min, const fem::Stresses<double> &max)
{
	//TODO finish others
	ui.lineEditStress11Min->setText(QString::number(min.s11));	ui.lineEditStress11Max->setText(QString::number(max.s11));
}


void 
ResultsRangeDialog::setStrains(const fem::Strains<double> &min, const fem::Strains<double> &max)
{
	//TODO finish others
}


void 
ResultsRangeDialog::setVonMises(const double min, const double max)
{
}


bool 
ResultsRangeDialog::getStresses(fem::Stresses<double> &min, fem::Stresses<double> &max) const
{

	return true;
}


bool 
ResultsRangeDialog::getStrains(fem::Strains<double> &, fem::Strains<double> &) const
{
	//TODO finish this

	return true;
}


void 
ResultsRangeDialog::getVonMises(double &min, double &max) const
{
}


void 
ResultsRangeDialog::connectSignalsToSlots()
{
}



