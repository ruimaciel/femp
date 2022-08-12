#include "ResultsRangeDialog.h++"

#include <QVBoxLayout>

ResultsRangeDialog::ResultsRangeDialog(QWidget* parent) : QDialog(parent) { ui.setupUi(this); }

void ResultsRangeDialog::setValueRanges(const fem::ResultsRanges<double>& ranges) {
	// Strains
	ui.lineEditStrain11Min->setText(QString::number(ranges.min_strain11));
	ui.lineEditStrain11Max->setText(QString::number(ranges.max_strain11));
	ui.lineEditStrain22Min->setText(QString::number(ranges.min_strain22));
	ui.lineEditStrain22Max->setText(QString::number(ranges.max_strain22));
	ui.lineEditStrain33Min->setText(QString::number(ranges.min_strain33));
	ui.lineEditStrain33Max->setText(QString::number(ranges.max_strain33));
	ui.lineEditStrain12Min->setText(QString::number(ranges.min_strain12));
	ui.lineEditStrain12Max->setText(QString::number(ranges.max_strain12));
	ui.lineEditStrain23Min->setText(QString::number(ranges.min_strain23));
	ui.lineEditStrain23Max->setText(QString::number(ranges.max_strain23));
	ui.lineEditStrain13Min->setText(QString::number(ranges.min_strain13));
	ui.lineEditStrain13Max->setText(QString::number(ranges.max_strain13));

	// Stresses
	ui.lineEditStress11Min->setText(QString::number(ranges.min_stress11));
	ui.lineEditStress11Max->setText(QString::number(ranges.max_stress11));
	ui.lineEditStress22Min->setText(QString::number(ranges.min_stress22));
	ui.lineEditStress22Max->setText(QString::number(ranges.max_stress22));
	ui.lineEditStress33Min->setText(QString::number(ranges.min_stress33));
	ui.lineEditStress33Max->setText(QString::number(ranges.max_stress33));
	ui.lineEditStress12Min->setText(QString::number(ranges.min_stress12));
	ui.lineEditStress12Max->setText(QString::number(ranges.max_stress12));
	ui.lineEditStress23Min->setText(QString::number(ranges.min_stress23));
	ui.lineEditStress23Max->setText(QString::number(ranges.max_stress23));
	ui.lineEditStress13Min->setText(QString::number(ranges.min_stress13));
	ui.lineEditStress13Max->setText(QString::number(ranges.max_stress13));

	ui.lineEditVonMisesMin->setText(QString::number(ranges.min_von_mises));
	ui.lineEditVonMisesMax->setText(QString::number(ranges.max_von_mises));
}

bool ResultsRangeDialog::getValueRanges(fem::ResultsRanges<double>& ranges) const {
	// Strains
	ranges.min_strain11 = ui.lineEditStrain11Min->text().toDouble();
	ranges.max_strain11 = ui.lineEditStrain11Max->text().toDouble();
	ranges.min_strain22 = ui.lineEditStrain22Min->text().toDouble();
	ranges.max_strain22 = ui.lineEditStrain22Max->text().toDouble();
	ranges.min_strain33 = ui.lineEditStrain33Min->text().toDouble();
	ranges.max_strain33 = ui.lineEditStrain33Max->text().toDouble();
	ranges.min_strain12 = ui.lineEditStrain12Min->text().toDouble();
	ranges.max_strain12 = ui.lineEditStrain12Max->text().toDouble();
	ranges.min_strain23 = ui.lineEditStrain23Min->text().toDouble();
	ranges.max_strain23 = ui.lineEditStrain23Max->text().toDouble();
	ranges.min_strain13 = ui.lineEditStrain13Min->text().toDouble();
	ranges.max_strain13 = ui.lineEditStrain13Max->text().toDouble();

	// Stresses
	ranges.min_stress11 = ui.lineEditStress11Min->text().toDouble();
	ranges.max_stress11 = ui.lineEditStress11Max->text().toDouble();
	ranges.min_stress22 = ui.lineEditStress22Min->text().toDouble();
	ranges.max_stress22 = ui.lineEditStress22Max->text().toDouble();
	ranges.min_stress33 = ui.lineEditStress33Min->text().toDouble();
	ranges.max_stress33 = ui.lineEditStress33Max->text().toDouble();
	ranges.min_stress12 = ui.lineEditStress12Min->text().toDouble();
	ranges.max_stress12 = ui.lineEditStress12Max->text().toDouble();
	ranges.min_stress23 = ui.lineEditStress23Min->text().toDouble();
	ranges.max_stress23 = ui.lineEditStress23Max->text().toDouble();
	ranges.min_stress13 = ui.lineEditStress13Min->text().toDouble();
	ranges.max_stress13 = ui.lineEditStress13Max->text().toDouble();

	ranges.min_von_mises = ui.lineEditVonMisesMin->text().toDouble();
	ranges.max_von_mises = ui.lineEditVonMisesMax->text().toDouble();

	// TODO test this
	return true;
}
