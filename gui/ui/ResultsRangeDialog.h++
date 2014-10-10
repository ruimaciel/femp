#ifndef SCALAR_RANGE_DIALOG_HPP
#define SCALAR_RANGE_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDialog>
#include <QString>
#include <QDialogButtonBox>

#include "ui_ResultsRangeDialog.h"

#include <libfemp/ElementResults/ResultsRanges.h++>


/**
Dialog intended to be used to specify ranges of a given parameter
**/
class ResultsRangeDialog
	: public QDialog
{
	Q_OBJECT

protected:
	Ui::ResultsRangeDialog ui;

public:
	ResultsRangeDialog(QWidget *parent = NULL);

	void setValueRanges(const fem::ResultsRanges<double> &);

	bool getValueRanges(fem::ResultsRanges<double> &) const;

protected:
	void connectSignalsToSlots();
};


#endif
