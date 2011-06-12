#include "PostprocessingWindow.h++"

#include "../viewer/PostprocessingViewport.h++"


PostprocessingWindow::PostprocessingWindow (fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent), 
	WindowWithResults(project, colors, parent), 
	WindowWithPostprocessing(project, colors, parent) ,
	WindowWithGhostSurfaces(project, colors, parent)
{
	viewport = new PostprocessingViewport(project,  parent);
	viewport->setAnalysisResult(project.result.back());

	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	WindowWithResults::createToolbar(project);
	WindowWithGhostSurfaces::createToolbar();
	WindowWithPostprocessing::createToolbar(project);

	connectSignalsToSlots();
}



void PostprocessingWindow::connectSignalsToSlots()
{
}

