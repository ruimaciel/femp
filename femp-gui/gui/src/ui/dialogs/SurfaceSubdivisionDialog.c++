#include "SurfaceSubdivisionDialog.h++"

#include <QSlider>
#include <QSpinBox>
#include <cmath>

SurfaceSubdivisionDialog::SurfaceSubdivisionDialog(unsigned short scale, QWidget* parent) : QDialog(parent) {
	setupUi(this);

	// set the current scale
	this->spinBox->setValue(scale);
	this->updateSlider(scale);

	// connect
	connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(updateSlider(int)));
	connect(horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(updateSpinBox(int)));
}

unsigned short SurfaceSubdivisionDialog::scale() { return this->spinBox->value(); }

void SurfaceSubdivisionDialog::updateSlider(int value) {
	using namespace std;
	this->horizontalSlider->setValue(value);
}

void SurfaceSubdivisionDialog::updateSpinBox(int value) {
	using namespace std;
	this->spinBox->setValue(value);
}
