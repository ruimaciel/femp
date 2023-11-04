#include "WindowWithPostprocessing.hpp"

// Qt includes
#include <QComboBox>
#include <QMainWindow>
#include <QObject>	// for tr()
#include <QString>
#include <QToolBar>

void WindowWithPostprocessing::createToolbar(QMainWindow* parent, fem::Project&) {
	m_postprocessingComboBox = new QComboBox(parent);
	QString text;

	m_postprocessingComboBox->insertItem(P_DISPLACEMENT, QObject::tr("Displacements"));
	m_postprocessingComboBox->insertItem(P_STRAIN_11, QObject::tr("Strain 11"));
	m_postprocessingComboBox->insertItem(P_STRAIN_22, QObject::tr("Strain 22"));
	m_postprocessingComboBox->insertItem(P_STRAIN_33, QObject::tr("Strain 33"));
	m_postprocessingComboBox->insertItem(P_STRAIN_12, QObject::tr("Strain 12"));
	m_postprocessingComboBox->insertItem(P_STRAIN_13, QObject::tr("Strain 13"));
	m_postprocessingComboBox->insertItem(P_STRAIN_23, QObject::tr("Strain 23"));
	m_postprocessingComboBox->insertItem(P_STRESS_11, QObject::tr("Stress 11"));
	m_postprocessingComboBox->insertItem(P_STRESS_22, QObject::tr("Stress 22"));
	m_postprocessingComboBox->insertItem(P_STRESS_33, QObject::tr("Stress 33"));
	m_postprocessingComboBox->insertItem(P_STRESS_12, QObject::tr("Stress 12"));
	m_postprocessingComboBox->insertItem(P_STRESS_13, QObject::tr("Stress 13"));
	m_postprocessingComboBox->insertItem(P_STRESS_23, QObject::tr("Stress 23"));
	m_postprocessingComboBox->insertItem(P_VON_MISES, QObject::tr("Von Mises"));

	m_postprocessingToolBar = parent->addToolBar(QObject::tr("Postprocessing"));
	m_postprocessingToolBar->addWidget(m_postprocessingComboBox);
}
