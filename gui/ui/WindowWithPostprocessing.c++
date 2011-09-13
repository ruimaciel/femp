#include "WindowWithPostprocessing.h++"

#include <QString>


WindowWithPostprocessing::WindowWithPostprocessing(fem::Project &, ViewportColors &, QWidget *parent)
	: MdiWindow(parent)
{
}


void WindowWithPostprocessing::createToolbar(fem::Project &)
{
	postprocessingComboBox = new QComboBox(this);
	QString text;

	postprocessingComboBox->insertItem(P_DISPLACEMENT, "Displacements");
	postprocessingComboBox->insertItem(P_STRAIN_11, "Strain 11");
	postprocessingComboBox->insertItem(P_STRAIN_22, "Strain 22");
	postprocessingComboBox->insertItem(P_STRAIN_33, "Strain 33");
	postprocessingComboBox->insertItem(P_STRAIN_12, "Strain 12");
	postprocessingComboBox->insertItem(P_STRAIN_13, "Strain 13");
	postprocessingComboBox->insertItem(P_STRAIN_23, "Strain 23");
	postprocessingComboBox->insertItem(P_STRESS_11, "Stress 11");
	postprocessingComboBox->insertItem(P_STRESS_22, "Stress 22");
	postprocessingComboBox->insertItem(P_STRESS_33, "Stress 33");
	postprocessingComboBox->insertItem(P_STRESS_12, "Stress 12");
	postprocessingComboBox->insertItem(P_STRESS_13, "Stress 13");
	postprocessingComboBox->insertItem(P_STRESS_23, "Stress 23");
	postprocessingComboBox->insertItem(P_VON_MISES, "Von Mises");

	postprocessingToolBar = addToolBar(tr("Postprocessing"));
	postprocessingToolBar->addWidget(postprocessingComboBox);
}


