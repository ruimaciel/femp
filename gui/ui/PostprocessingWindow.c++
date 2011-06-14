#include "PostprocessingWindow.h++"

#include "../viewer/PostprocessingViewport.h++"


PostprocessingWindow::PostprocessingWindow (fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent), 
	WindowWithResults(project, colors, parent), 
	WindowWithPostprocessing(project, colors, parent) ,
	WindowWithGhostSurfaces(project, colors, parent),
	WindowWithScaling(project, colors, parent)
{
	viewport = new PostprocessingViewport(project,  parent);
	viewport->setAnalysisResult(project.result.back());

	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	WindowWithScaling::createToolbar(project);
	WindowWithResults::createToolbar(project);
	WindowWithGhostSurfaces::createToolbar();
	WindowWithPostprocessing::createToolbar(project);

	connectSignalsToSlots();
}


void PostprocessingWindow::setDisplacementsScale(double scale)
{
	this->viewport->setDisplacementsScale((float)scale);
	this->viewport->refresh();
}


void PostprocessingWindow::setNodeRestrictionsVisibility(const bool state)
{
	WindowWithGhostSurfaces::setNodeRestrictionsVisibility(state);
}


void PostprocessingWindow::setGhostSurfacesVisibility(const bool state)
{
	WindowWithGhostSurfaces::setGhostSurfacesVisibility(state);
}

void PostprocessingWindow::connectSignalsToSlots()
{
	WindowWithGhostSurfaces::connectSignalsToSlots();
	WindowWithScaling::connectSignalsToSlots();
}

