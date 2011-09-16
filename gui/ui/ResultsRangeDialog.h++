#ifndef SCALAR_RANGE_DIALOG_HPP
#define SCALAR_RANGE_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDialog>
#include <QString>
#include <QDialogButtonBox>

#include "ui_ResultsRangeDialog.h"
#include "../fem/ElementResults/Stresses.h++"
#include "../fem/ElementResults/Strains.h++"


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

	void setStresses(const fem::Stresses<double> &min, const fem::Stresses<double> &max);
	/*
	void setStress11(const double);
	void setStress22(const double);
	void setStress33(const double);
	void setStress12(const double);
	void setStress23(const double);
	void setStress13(const double);
	*/

	void setStrains(const fem::Strains<double> &min, const fem::Strains<double> &max);
	/*
	void setStrain11(const double);
	void setStrain22(const double);
	void setStrain33(const double);
	void setStrain12(const double);
	void setStrain23(const double);
	void setStrain13(const double);
	*/

	void setVonMises(const double, const double);

	bool getStresses(fem::Stresses<double> &, fem::Stresses<double> &) const;
	bool getStrains(fem::Strains<double> &, fem::Strains<double> &) const;
	void getVonMises(double &, double &) const;

protected:
	void connectSignalsToSlots();
};


#endif
