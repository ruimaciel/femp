#include "WindowWithScaling.hpp"

// Qt includes
#include <QObject>	// for tr()
#include <QString>

// std includes
#include <assert.h>

void WindowWithScaling::createToolbar(QMainWindow* parent, fem::Project&) {
	m_doubleSpinBoxScaling = new QDoubleSpinBox(parent);
	m_doubleSpinBoxScaling->setMinimum(0);
	m_doubleSpinBoxScaling->setMaximum(9e99);
	m_doubleSpinBoxScaling->setValue(1);
	m_doubleSpinBoxScaling->setDecimals(12);

	m_toolBarScaling = parent->addToolBar(QObject::tr("Scale"));
	m_toolBarScaling->addWidget(m_doubleSpinBoxScaling);
}

void WindowWithScaling::createMenuBar(QMainWindow* parent, QMenuBar* menu) {
	m_actionSetTensionRanges = new QAction(QObject::tr("Set tension ranges"), parent);
	m_menuScaling = menu->addMenu(QObject::tr("Scaling"));
	m_menuScaling->addAction(m_actionSetTensionRanges);
}

void WindowWithScaling::connectSignalsToSlots(QMainWindow* parent) {
	QObject::connect(m_doubleSpinBoxScaling, SIGNAL(valueChanged(double)), parent, SLOT(setDisplacementsScale(double)));
}
