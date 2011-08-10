#ifndef DIALOG_SCALE_HPP
#define DIALOG_SCALE_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDialog>

#include "ui_DialogScale.h"


/**
Dialog used by GLDisplacementsWidget to input a new displacements scale
**/
class DialogScale
	: public QDialog, private Ui_DialogScale
{
	Q_OBJECT

	public:
		DialogScale(float scale, QWidget *parent = NULL);
		~DialogScale();

		double scale();
	
	protected slots:
		void updateSpinBox(int );
		void updateSlider(double);
};

#endif
