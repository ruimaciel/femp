#include "AnalysisSummaryDialog.h++"


AnalysisSummaryDialog::AnalysisSummaryDialog(fem::AnalysisResult const &results, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	labelEnergy->setNum(results.energy);
	labelDoF->setNum((double)results.equation.size());
	labelTime->setNum(results.elapsed_time/1000.0f);
	labelVolume->setNum(results.volume);
}
