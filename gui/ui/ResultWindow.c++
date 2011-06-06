#include "ResultWindow.h++"


ResultWindow::ResultWindow(fem::Model &model, ViewportColors &colors, fem::AnalysisResult<double> &analysis, QWidget *parent)
	: MdiWindow(parent)
{
	viewport = new DisplacementsViewport(&model, analysis, this);
	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	connectSignalsToSlots();
}


void ResultWindow::connectSignalsToSlots()
{
}


