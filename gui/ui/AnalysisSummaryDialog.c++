#include "AnalysisSummaryDialog.h++"


AnalysisSummaryDialog::AnalysisSummaryDialog(fem::AnalysisResult<double> const &results, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	labelEnergy->setNum(results.energy);
	labelDoF->setNum((double)results.d.size());
	labelTime->setNum(results.elapsed_time/1000.0f);
	labelVolume->setNum(results.volume);
}
