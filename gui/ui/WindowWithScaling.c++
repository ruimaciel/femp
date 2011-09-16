#include "WindowWithScaling.h++"

#include <assert.h>
#include <QString>


WindowWithScaling::WindowWithScaling(fem::Project &, ViewportColors &, QWidget *parent)
	: MdiWindow(parent)
{
	actionSetTensionRanges = new QAction("Set tension ranges", this);
}


void WindowWithScaling::createToolbar(fem::Project &)
{
	scalingDoubleSpinBox = new QDoubleSpinBox(this);
	scalingDoubleSpinBox->setMinimum(0);
	scalingDoubleSpinBox->setMaximum(9e99);
	scalingDoubleSpinBox->setValue(1);

	scalingToolBar = addToolBar(tr("Scale"));
	scalingToolBar->addWidget(scalingDoubleSpinBox);
}


void WindowWithScaling::createMenuBar(QMenuBar *menu)
{
	assert(menu != NULL);

	m_scaling_menu = menu->addMenu(tr("Scaling"));
	m_scaling_menu->addAction(actionSetTensionRanges);
}


void WindowWithScaling::connectSignalsToSlots()
{
	connect(scalingDoubleSpinBox,	SIGNAL(valueChanged(double)),	this,	SLOT(setDisplacementsScale(double) ) );
}

