#ifndef ANALYSIS_SUMMARY_DIALOG_HPP
#define ANALYSIS_SUMMARY_DIALOG_HPP

#include <QtWidgets/QDialog>
#include <libfemp/AnalysisResult.h++>

#include "ui_AnalysisSummaryDialog.h"

/**
Dialog box intended to display a set of values derived from the results of a given analysis
**/
class AnalysisSummaryDialog
    : public QDialog,
      private Ui::AnalysisSummaryDialog {
public:
    AnalysisSummaryDialog(fem::AnalysisResult const& results, QWidget* parent = nullptr);
};

#endif
