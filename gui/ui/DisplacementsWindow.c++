#include "DisplacementsWindow.h++"

#include "../viewer/DisplacementsViewport.h++"


DisplacementsWindow::DisplacementsWindow(fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent), 
	WindowWithResults(project, colors, parent), 
	WindowWithGhostSurfaces(project, colors, parent),
	WindowWithScaling(project, colors, parent)
{
	viewport = new DisplacementsViewport(project, this);
	viewport->setAnalysisResult(project.result.back());

	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	// create the toolbars
	DisplacementsWindow::createToolbar();
	WindowWithResults::createToolbar(project);
	WindowWithGhostSurfaces::createToolbar();
	WindowWithScaling::createToolbar(project);

	connectSignalsToSlots();
}


void DisplacementsWindow::createToolbar()
{
}



void DisplacementsWindow::setDisplacementsScale(double scale)
{
	this->viewport->setDisplacementsScale((float)scale);
	this->viewport->refresh();
}


void DisplacementsWindow::setNodeRestrictionsVisibility(const bool state)
{
	WindowWithGhostSurfaces::setNodeRestrictionsVisibility(state);
}


void DisplacementsWindow::setGhostSurfacesVisibility(const bool state)
{
	WindowWithGhostSurfaces::setGhostSurfacesVisibility(state);
}

void DisplacementsWindow::connectSignalsToSlots()
{
	WindowWithGhostSurfaces::connectSignalsToSlots();
	WindowWithScaling::connectSignalsToSlots();
}


