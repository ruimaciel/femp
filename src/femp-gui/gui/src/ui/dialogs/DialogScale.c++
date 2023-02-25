#include "DialogScale.h++"

#include <QSlider>
#include <QSpinBox>
#include <cmath>

DialogScale::DialogScale(float scale, QWidget* parent) : QDialog(parent) {
	setupUi(this);

	// set the current scale
	this->doubleSpinBox->setValue(scale);
	this->updateSlider(scale);

	// connect
	connect(doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(updateSlider(double)));
	connect(horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(updateSpinBox(int)));
}

double DialogScale::getScale() {
	return this->doubleSpinBox->value();
}

void DialogScale::updateSlider(double value) {
	using namespace std;
	this->horizontalSlider->setValue(ceil(log10(value)));
}

void DialogScale::updateSpinBox(int value) {
	using namespace std;
	this->doubleSpinBox->setValue(pow(10, value));
}
