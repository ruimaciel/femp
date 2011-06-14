#include "WindowWithGhostSurfaces.h++"

#include <QString>


WindowWithGhostSurfaces::WindowWithGhostSurfaces(fem::Project &, ViewportColors &, QWidget *parent)
	: MdiWindow(parent)
{
}


void WindowWithGhostSurfaces::createToolbar()
{
	actionVisibleGhostSurfaces = new QAction("Original configuration", this);
	actionVisibleGhostSurfaces->setCheckable(true);
	actionVisibleGhostSurfaces->setChecked(true);

	visibilityToolBar->addAction(actionVisibleGhostSurfaces);
}


void WindowWithGhostSurfaces::setGhostSurfacesVisibility(const bool state)
{
	qWarning("WindowWithGhostSurfaces::setGhostSurfacesVisibility()");
	this->viewport->setRenderGoupVisibility(SceneGraph::RG_GHOST_SURFACES, state);
	this->viewport->refresh();
}


void WindowWithGhostSurfaces::connectSignalsToSlots()
{
	connect(actionVisibleGhostSurfaces,	SIGNAL(toggled(bool)),	this,	SLOT(setGhostSurfacesVisibility(bool)));
}
