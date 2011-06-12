#include "WindowWithGhostSurfaces.h++"

#include <QString>


WindowWithGhostSurfaces::WindowWithGhostSurfaces(fem::Project &, ViewportColors &, QWidget *parent)
	: MdiWindow(parent)
{
}


void WindowWithGhostSurfaces::createToolbar()
{
	actionVisibleGhostSurfaces = new QAction("Original configuration", this);

	visibilityToolBar->addAction(actionVisibleGhostSurfaces);
}


