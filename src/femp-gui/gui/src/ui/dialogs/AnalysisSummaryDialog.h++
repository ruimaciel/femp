#ifndef ANALYSIS_SUMMARY_DIALOG_HPP
#define ANALYSIS_SUMMARY_DIALOG_HPP

#include <libfemp/AnalysisResult.h++>

// Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
	class AnalysisSummaryDialog;
}

/**
 * Dialog box intended to display a set of values derived from the results of a
 * given analysis
 */
class AnalysisSummaryDialog : public QDialog{
	Q_OBJECT

	public:
	AnalysisSummaryDialog(fem::AnalysisResult const& results, QWidget* parent = nullptr);
	~AnalysisSummaryDialog();

	private:
	std::unique_ptr<Ui::AnalysisSummaryDialog> m_ui;
};

#endif
