#include "WindowWithScaling.h++"

#include <assert.h>
#include <QObject>	// for tr()
#include <QString>


void WindowWithScaling::createToolbar(QMainWindow *parent, fem::Project &)
{
	scalingDoubleSpinBox = new QDoubleSpinBox(parent);
	scalingDoubleSpinBox->setMinimum(0);
	scalingDoubleSpinBox->setMaximum(9e99);
	scalingDoubleSpinBox->setValue(1);
	scalingDoubleSpinBox->setDecimals(12);

	scalingToolBar = parent->addToolBar(QObject::tr("Scale"));
	scalingToolBar->addWidget(scalingDoubleSpinBox);
}


void WindowWithScaling::createMenuBar(QMainWindow *parent,QMenuBar *menu)
{
	actionSetTensionRanges = new QAction(QObject::tr("Set tension ranges"), parent);
	m_scaling_menu = menu->addMenu(QObject::tr("Scaling"));
	m_scaling_menu->addAction(actionSetTensionRanges);
}


void WindowWithScaling::connectSignalsToSlots(QMainWindow *parent)
{
	QObject::connect(scalingDoubleSpinBox,	SIGNAL(valueChanged(double)),	parent,	SLOT(setDisplacementsScale(double) ) );
}

