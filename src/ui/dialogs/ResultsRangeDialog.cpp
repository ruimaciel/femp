#include "ResultsRangeDialog.hpp"

#include "ui_ResultsRangeDialog.h"

// Qt includes
#include <QVBoxLayout>

ResultsRangeDialog::ResultsRangeDialog(QWidget* parent) : QDialog(parent) {
	m_ui->setupUi(this);
}

ResultsRangeDialog::~ResultsRangeDialog() = default;

void ResultsRangeDialog::setValueRanges(const fem::ResultsRanges<double>& ranges) {
	// Strains
	m_ui->lineEditStrain11Min->setText(QString::number(ranges.min_strain11));
	m_ui->lineEditStrain11Max->setText(QString::number(ranges.max_strain11));
	m_ui->lineEditStrain22Min->setText(QString::number(ranges.min_strain22));
	m_ui->lineEditStrain22Max->setText(QString::number(ranges.max_strain22));
	m_ui->lineEditStrain33Min->setText(QString::number(ranges.min_strain33));
	m_ui->lineEditStrain33Max->setText(QString::number(ranges.max_strain33));
	m_ui->lineEditStrain12Min->setText(QString::number(ranges.min_strain12));
	m_ui->lineEditStrain12Max->setText(QString::number(ranges.max_strain12));
	m_ui->lineEditStrain23Min->setText(QString::number(ranges.min_strain23));
	m_ui->lineEditStrain23Max->setText(QString::number(ranges.max_strain23));
	m_ui->lineEditStrain13Min->setText(QString::number(ranges.min_strain13));
	m_ui->lineEditStrain13Max->setText(QString::number(ranges.max_strain13));

	// Stresses
	m_ui->lineEditStress11Min->setText(QString::number(ranges.min_stress11));
	m_ui->lineEditStress11Max->setText(QString::number(ranges.max_stress11));
	m_ui->lineEditStress22Min->setText(QString::number(ranges.min_stress22));
	m_ui->lineEditStress22Max->setText(QString::number(ranges.max_stress22));
	m_ui->lineEditStress33Min->setText(QString::number(ranges.min_stress33));
	m_ui->lineEditStress33Max->setText(QString::number(ranges.max_stress33));
	m_ui->lineEditStress12Min->setText(QString::number(ranges.min_stress12));
	m_ui->lineEditStress12Max->setText(QString::number(ranges.max_stress12));
	m_ui->lineEditStress23Min->setText(QString::number(ranges.min_stress23));
	m_ui->lineEditStress23Max->setText(QString::number(ranges.max_stress23));
	m_ui->lineEditStress13Min->setText(QString::number(ranges.min_stress13));
	m_ui->lineEditStress13Max->setText(QString::number(ranges.max_stress13));

	m_ui->lineEditVonMisesMin->setText(QString::number(ranges.min_von_mises));
	m_ui->lineEditVonMisesMax->setText(QString::number(ranges.max_von_mises));
}

bool ResultsRangeDialog::getValueRanges(fem::ResultsRanges<double>& ranges) const {
	// Strains
	ranges.min_strain11 = m_ui->lineEditStrain11Min->text().toDouble();
	ranges.max_strain11 = m_ui->lineEditStrain11Max->text().toDouble();
	ranges.min_strain22 = m_ui->lineEditStrain22Min->text().toDouble();
	ranges.max_strain22 = m_ui->lineEditStrain22Max->text().toDouble();
	ranges.min_strain33 = m_ui->lineEditStrain33Min->text().toDouble();
	ranges.max_strain33 = m_ui->lineEditStrain33Max->text().toDouble();
	ranges.min_strain12 = m_ui->lineEditStrain12Min->text().toDouble();
	ranges.max_strain12 = m_ui->lineEditStrain12Max->text().toDouble();
	ranges.min_strain23 = m_ui->lineEditStrain23Min->text().toDouble();
	ranges.max_strain23 = m_ui->lineEditStrain23Max->text().toDouble();
	ranges.min_strain13 = m_ui->lineEditStrain13Min->text().toDouble();
	ranges.max_strain13 = m_ui->lineEditStrain13Max->text().toDouble();

	// Stresses
	ranges.min_stress11 = m_ui->lineEditStress11Min->text().toDouble();
	ranges.max_stress11 = m_ui->lineEditStress11Max->text().toDouble();
	ranges.min_stress22 = m_ui->lineEditStress22Min->text().toDouble();
	ranges.max_stress22 = m_ui->lineEditStress22Max->text().toDouble();
	ranges.min_stress33 = m_ui->lineEditStress33Min->text().toDouble();
	ranges.max_stress33 = m_ui->lineEditStress33Max->text().toDouble();
	ranges.min_stress12 = m_ui->lineEditStress12Min->text().toDouble();
	ranges.max_stress12 = m_ui->lineEditStress12Max->text().toDouble();
	ranges.min_stress23 = m_ui->lineEditStress23Min->text().toDouble();
	ranges.max_stress23 = m_ui->lineEditStress23Max->text().toDouble();
	ranges.min_stress13 = m_ui->lineEditStress13Min->text().toDouble();
	ranges.max_stress13 = m_ui->lineEditStress13Max->text().toDouble();

	ranges.min_von_mises = m_ui->lineEditVonMisesMin->text().toDouble();
	ranges.max_von_mises = m_ui->lineEditVonMisesMax->text().toDouble();

	// TODO test this
	return true;
}
