#include "DisplacementsWindow.h++"

#include "../viewer/DisplacementsViewport.h++"


DisplacementsWindow::DisplacementsWindow(fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent), WindowWithResults(project, colors, parent), WindowWithGhostSurfaces(project, colors, parent),
	WindowWithScaling(project, colors, parent)
{
	viewport = new DisplacementsViewport(project, this);
	viewport->setAnalysisResult(project.result.back());

	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	// create the toolbars
	DisplacementsWindow::createToolbar();
	WindowWithScaling::createToolbar(project);
	WindowWithResults::createToolbar(project);

	connectSignalsToSlots();
}


void DisplacementsWindow::createToolbar()
{
	actionVisibleGhostSurfaces = new QAction("Original configuration", this);

	visibilityToolBar->addAction(actionVisibleGhostSurfaces);
}


void DisplacementsWindow::setDisplacementsScale(double scale)
{
	this->viewport->setDisplacementsScale((float)scale);
	this->viewport->refresh();
}


void DisplacementsWindow::connectSignalsToSlots()
{
	WindowWithScaling::connectSignalsToSlots();
}


