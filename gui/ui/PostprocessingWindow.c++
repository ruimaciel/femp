#include "PostprocessingWindow.h++"

#include "../viewer/PostprocessingViewport.h++"


PostprocessingWindow::PostprocessingWindow (fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent)
{
	viewport = new PostprocessingViewport(project,  parent);
	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	connectSignalsToSlots();
}


void PostprocessingWindow::createAnalysisToolar()
{
	analysisComboBox = new QComboBox(this);
	analysisComboBox->insertItem(A_STRAIN_11, "Strain 11");
	analysisComboBox->insertItem(A_STRAIN_22, "Strain 22");
	analysisComboBox->insertItem(A_STRAIN_33, "Strain 33");
	analysisComboBox->insertItem(A_STRAIN_12, "Strain 12");
	analysisComboBox->insertItem(A_STRAIN_13, "Strain 13");
	analysisComboBox->insertItem(A_STRAIN_23, "Strain 23");

	analysisComboBox->insertItem(A_STRESS_11, "Stress 11");
	analysisComboBox->insertItem(A_STRESS_22, "Stress 22");
	analysisComboBox->insertItem(A_STRESS_33, "Stress 33");
	analysisComboBox->insertItem(A_STRESS_12, "Stress 12");
	analysisComboBox->insertItem(A_STRESS_13, "Stress 13");
	analysisComboBox->insertItem(A_STRESS_23, "Stress 23");

	analysisToolBar = addToolBar(tr("Analysis") );
	analysisToolBar->addWidget(analysisComboBox);

}


void PostprocessingWindow::connectSignalsToSlots()
{
}

