#ifndef QUADRATURE_OPTIONS_DIALOG_HPP
#define QUADRATURE_OPTIONS_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include "ui_QuadratureRulesOptionsDialog.h"

#include <libfemp/Analysis.h++>


class QuadratureRulesOptionsDialog
		: public QDialog, private Ui_QuadratureRulesOptionsDialog
{
	Q_OBJECT

protected:
	fem::Analysis<double> *analysis;

public:
	QuadratureRulesOptionsDialog(fem::Analysis<double> &analysis, QWidget *parent = nullptr);
	~QuadratureRulesOptionsDialog();

protected slots:
	void setSpinBoxValues();
	void setQuadratureRule();
};



#endif
