#ifndef FEMP_DIALOGSCALE_HPP
#define FEMP_DIALOGSCALE_HPP

#include <QDialog>

#include "ui_DialogScale.h"

/**
 * Dialog used by GLDisplacementsWidget to input a new displacements scale
 */
class DialogScale : public QDialog, private Ui::DialogScale {
	Q_OBJECT

   public:
	DialogScale(float scale, QWidget* parent = nullptr);

	double getScale();

   protected slots:
	void updateSpinBox(int);
	void updateSlider(double);
};

#endif
