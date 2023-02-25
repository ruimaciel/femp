#ifndef SCALAR_RANGE_DIALOG_HPP
#define SCALAR_RANGE_DIALOG_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QString>
#include <libfemp/ElementResults/ResultsRanges.h++>

#include "ui_ResultsRangeDialog.h"

/**
 * Dialog intended to be used to specify ranges of a given parameter
 */
class ResultsRangeDialog : public QDialog {
	Q_OBJECT

	protected:
	Ui::ResultsRangeDialog ui;

	public:
	ResultsRangeDialog(QWidget* parent = nullptr);

	void setValueRanges(const fem::ResultsRanges<double>&);

	bool getValueRanges(fem::ResultsRanges<double>&) const;
};

#endif
