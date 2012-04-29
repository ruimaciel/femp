#include "WindowWithPostprocessing.h++"

#include <QObject>	// for tr()
#include <QString>


void WindowWithPostprocessing::createToolbar(QMainWindow *parent, fem::Project &)
{
	postprocessingComboBox = new QComboBox(parent);
	QString text;

	postprocessingComboBox->insertItem(P_DISPLACEMENT, QObject::tr("Displacements"));
	postprocessingComboBox->insertItem(P_STRAIN_11, QObject::tr("Strain 11"));
	postprocessingComboBox->insertItem(P_STRAIN_22, QObject::tr("Strain 22"));
	postprocessingComboBox->insertItem(P_STRAIN_33, QObject::tr("Strain 33"));
	postprocessingComboBox->insertItem(P_STRAIN_12, QObject::tr("Strain 12"));
	postprocessingComboBox->insertItem(P_STRAIN_13, QObject::tr("Strain 13"));
	postprocessingComboBox->insertItem(P_STRAIN_23, QObject::tr("Strain 23"));
	postprocessingComboBox->insertItem(P_STRESS_11, QObject::tr("Stress 11"));
	postprocessingComboBox->insertItem(P_STRESS_22, QObject::tr("Stress 22"));
	postprocessingComboBox->insertItem(P_STRESS_33, QObject::tr("Stress 33"));
	postprocessingComboBox->insertItem(P_STRESS_12, QObject::tr("Stress 12"));
	postprocessingComboBox->insertItem(P_STRESS_13, QObject::tr("Stress 13"));
	postprocessingComboBox->insertItem(P_STRESS_23, QObject::tr("Stress 23"));
	postprocessingComboBox->insertItem(P_VON_MISES, QObject::tr("Von Mises"));

	postprocessingToolBar = parent->addToolBar(QObject::tr("Postprocessing"));
	postprocessingToolBar->addWidget(postprocessingComboBox);
}


