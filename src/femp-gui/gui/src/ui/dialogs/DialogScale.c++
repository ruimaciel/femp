#include "DialogScale.h++"

#include "ui_DialogScale.h"

// Qt includes
#include <QSlider>
#include <QSpinBox>

// std includes
#include <cmath>

DialogScale::DialogScale(float scale, QWidget* parent) : QDialog(parent), m_ui(std::make_unique<Ui::DialogScale>()) {
	m_ui->setupUi(this);

	// set the current scale
	m_ui->doubleSpinBox->setValue(scale);
	updateSlider(scale);

	// connect
	connect(m_ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(updateSlider(double)));
	connect(m_ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(updateSpinBox(int)));
}

DialogScale::~DialogScale() = default;

double DialogScale::getScale() {
	return m_ui->doubleSpinBox->value();
}

void DialogScale::updateSlider(double value) {
	using namespace std;
	m_ui->horizontalSlider->setValue(ceil(log10(value)));
}

void DialogScale::updateSpinBox(int value) {
	using namespace std;
	m_ui->doubleSpinBox->setValue(pow(10, value));
}
