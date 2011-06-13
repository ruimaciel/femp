#include "WindowWithScaling.h++"

#include <QString>


WindowWithScaling::WindowWithScaling(fem::Project &, ViewportColors &, QWidget *parent)
	: MdiWindow(parent)
{
}


void WindowWithScaling::createToolbar(fem::Project &)
{
	scalingDoubleSpinBox = new QDoubleSpinBox(this);
	scalingDoubleSpinBox->setMinimum(0.5);
	scalingDoubleSpinBox->setValue(1);

	scalingToolBar = addToolBar(tr("Scale"));
	scalingToolBar->addWidget(scalingDoubleSpinBox);
}



void WindowWithScaling::connectSignalsToSlots()
{
	connect(scalingDoubleSpinBox,	SIGNAL(valueChanged(double)),	this,	SLOT(setDisplacementsScale(double) ) );
}

