#include "WindowWithScaling.h++"

#include <assert.h>
#include <QObject>	// for tr()
#include <QString>


void WindowWithScaling::createToolbar(QMainWindow *parent, fem::Project &)
{
	m_scalingDoubleSpinBox = new QDoubleSpinBox(parent);
	m_scalingDoubleSpinBox->setMinimum(0);
	m_scalingDoubleSpinBox->setMaximum(9e99);
	m_scalingDoubleSpinBox->setValue(1);
	m_scalingDoubleSpinBox->setDecimals(12);

	m_scalingToolBar = parent->addToolBar(QObject::tr("Scale"));
	m_scalingToolBar->addWidget(m_scalingDoubleSpinBox);
}


void WindowWithScaling::createMenuBar(QMainWindow *parent,QMenuBar *menu)
{
	m_actionSetTensionRanges = new QAction(QObject::tr("Set tension ranges"), parent);
	m_scaling_menu = menu->addMenu(QObject::tr("Scaling"));
	m_scaling_menu->addAction(m_actionSetTensionRanges);
}


void WindowWithScaling::connectSignalsToSlots(QMainWindow *parent)
{
	QObject::connect(m_scalingDoubleSpinBox,	SIGNAL(valueChanged(double)),	parent,	SLOT(setDisplacementsScale(double) ) );
}

