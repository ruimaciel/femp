#include "AnalysisSummaryDialog.hpp"

#include "ui_AnalysisSummaryDialog.h"

AnalysisSummaryDialog::AnalysisSummaryDialog(fem::AnalysisResult const& results, QWidget* parent)
	: QDialog(parent), m_ui(std::make_unique<Ui::AnalysisSummaryDialog>()) {
	m_ui->setupUi(this);

	m_ui->labelEnergy->setNum(results.energy);
	m_ui->labelDoF->setNum((double)results.equation.size());
	m_ui->labelTime->setNum(results.elapsed_time / 1000.0f);
	m_ui->labelVolume->setNum(results.volume);
}

AnalysisSummaryDialog::~AnalysisSummaryDialog() = default;