#include "MdiWindow.h++"


/**
Base class for all MDI windows which render a model
**/
MdiWindow::MdiWindow (QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);

	this->viewport = NULL;

	this->createViewportToolbar();

	//signals and slots
	connect(actionViewportXY, SIGNAL(triggered()),	this,	SLOT(setViewportXY()));
	connect(actionViewportXZ, SIGNAL(triggered()),	this,	SLOT(setViewportXZ()));
	connect(actionViewportYZ, SIGNAL(triggered()),	this,	SLOT(setViewportYZ()));
}


void MdiWindow::createViewportToolbar()
{
	// create actions
	actionViewportXY = new QAction("XY", this);
	actionViewportYZ = new QAction("YZ", this);
	actionViewportXZ = new QAction("XZ", this);
	actionViewportIso = new QAction("iso", this);

	// create and populate the toolbar
	viewportToolBar = addToolBar(tr("Viewport"));
	viewportToolBar->addAction(actionViewportXY);
	viewportToolBar->addAction(actionViewportYZ);
	viewportToolBar->addAction(actionViewportXZ);
	viewportToolBar->addAction(actionViewportIso);
}


void MdiWindow::setViewportXY()
{
	viewport->setXRotation(0);
	viewport->setYRotation(0);
	viewport->setZRotation(0);
}


void MdiWindow::setViewportYZ()
{
	viewport->setXRotation(0);
	viewport->setYRotation(90);
	viewport->setZRotation(0);
}


void MdiWindow::setViewportXZ()
{
	viewport->setXRotation(90);
	viewport->setYRotation(0);
	viewport->setZRotation(0);
}

void MdiWindow::setViewportIso()
{
	viewport->setXRotation(45);
	viewport->setYRotation(45);
	viewport->setZRotation(0);
}


void MdiWindow::normalizeAngle(int *angle)
{
	while (*angle < 0)
		*angle += 360 * 16;
	while (*angle > 360 * 16)
		*angle -= 360 * 16;
}


void MdiWindow::setColors(ViewportColors &colors)
{
	viewport->setColors(colors);
}
