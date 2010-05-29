#ifndef DIALOG_SCALE_HPP
#define DIALOG_SCALE_HPP

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
};

#endif
