#include "SurfaceSubdivisionDialog.hpp"

#include "ui_SurfaceSubdivisionDialog.h"

// Qt includes
#include <QSlider>
#include <QSpinBox>

// std includes
#include <cmath>

SurfaceSubdivisionDialog::SurfaceSubdivisionDialog(unsigned short scale, QWidget* parent)
	: QDialog(parent), m_ui(std::make_unique<Ui::SurfaceSubdivisionDialog>()) {
	m_ui->setupUi(this);

	// set the current scale
	m_ui->spinBox->setValue(scale);
	this->updateSlider(scale);

	// connect
	connect(m_ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(updateSlider(int)));
	connect(m_ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(updateSpinBox(int)));
}

SurfaceSubdivisionDialog::~SurfaceSubdivisionDialog() = default;

unsigned short SurfaceSubdivisionDialog::scale() {
	return m_ui->spinBox->value();
}

void SurfaceSubdivisionDialog::updateSlider(int value) {
	using namespace std;
	m_ui->horizontalSlider->setValue(value);
}

void SurfaceSubdivisionDialog::updateSpinBox(int value) {
	using namespace std;
	m_ui->spinBox->setValue(value);
}
