#include "MdiWindow.h++"

#include <iostream>


/**
Base class for all MDI windows which render a model
**/

MdiWindow::MdiWindow (QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);

	this->viewport = NULL;

	// create the menu
	this->actionMenuVisibility = new QAction(tr("Menu visibility"), this);
	this->actionMenuVisibility->setCheckable(true);
	this->actionMenuVisibility->setChecked(false);
	this->actionMenuVisibility->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_M));
	this->menuBar()->hide();

	this->createViewportToolbar();
	this->createVisibilityToolbar();
}


void
MdiWindow::createViewportToolbar()
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


void
MdiWindow::createVisibilityToolbar()
{
	actionVisibleNodes = new QAction("Nodes",this);
	actionVisibleNodes->setCheckable(true);
	actionVisibleNodes->setChecked(true);

	actionVisibleRestrictions = new QAction("Restrictions",this);
	actionVisibleRestrictions->setCheckable(true);
	actionVisibleRestrictions->setChecked(true);

	visibilityToolBar = addToolBar(tr("Visibility"));
	visibilityToolBar->addAction(actionVisibleNodes);
	visibilityToolBar->addAction(actionVisibleRestrictions);
}


void
MdiWindow::setViewportXY()
{
	viewport->setXRotation(0);
	viewport->setYRotation(0);
	viewport->setZRotation(0);
}


void
MdiWindow::setViewportYZ()
{
	viewport->setXRotation(0);
	viewport->setYRotation(90);
	viewport->setZRotation(0);
}


void
MdiWindow::setViewportXZ()
{
	viewport->setXRotation(90);
	viewport->setYRotation(0);
	viewport->setZRotation(0);
}


void
MdiWindow::setViewportIso()
{
	viewport->setXRotation(45);
	viewport->setYRotation(45);
	viewport->setZRotation(0);
}


void
MdiWindow::setNodeVisibility(const bool state)
{
	this->viewport->setNodeVisibility(state);
	this->viewport->refresh();
}


void
MdiWindow::setNodeRestrictionsVisibility(const bool state)
{
	this->viewport->setNodeRestrictionsVisibility(state);
	this->viewport->refresh();
}


void
MdiWindow::connectSignalsToSlots()
{
	//signals and slots
	connect(actionViewportXY, &QAction::triggered,	this,	&MdiWindow::setViewportXY);
	connect(actionViewportXZ, &QAction::triggered,	this,	&MdiWindow::setViewportXZ);
	connect(actionViewportYZ, &QAction::triggered,	this,	&MdiWindow::setViewportYZ);

	connect(actionVisibleNodes,			&QAction::toggled,	this,	&MdiWindow::setNodeVisibility);
	connect(actionVisibleRestrictions,	&QAction::toggled,	this,	&MdiWindow::setNodeRestrictionsVisibility);

	// libsigc++ signals
	this->viewport->selection_changed.connect(this->selection_changed.make_slot());
}


void
MdiWindow::normalizeAngle(int *angle)
{
	while (*angle < 0)
		*angle += 360 * 16;
	while (*angle > 360 * 16)
		*angle -= 360 * 16;
}


void
MdiWindow::setColors(ViewportColors &colors)
{
	viewport->setColors(colors);
}


void
MdiWindow::setSelection(Selection selection)
{
	std::cout << "void MdiWindow::setSelection(Selection)" << std::endl;
	this->viewport->setSelection(selection);
}


void
MdiWindow::clearSelection()
{
	std::cout << "void MdiWindow::setSelection(Selection): hasn't been implemented" << std::endl;
}


void
MdiWindow::showSelection(const Selection selection)
{
	std::cout << "MdiWindow::viewSelection(const Selection selection)" << std::endl;
	this->viewport->showSelection(selection);
}


void
MdiWindow::showAll()
{
	std::cout << "MdiWindow::viewAll()" << std::endl;
	this->viewport->showAll();
}


void
MdiWindow::updateNodeRestriction(size_t const id, fem::NodeRestrictions const &nr)
{
	std::cout << "MdiWindow::updateNodeRestriction(size_t const id, fem::NodeRestrictions const &nr)" << std::endl;
}


void
MdiWindow::connectToSelectionManager(SelectionManager &selection_manager)
{
	// connects signals to slots
	std::cout << "void MdiWindow::connectToSelectionManager(SelectionManager &selection_manager)" << std::endl;

	selection_manager.selection_changed.connect( sigc::mem_fun(this, & MdiWindow::setSelection));
	this->selection_changed.connect( sigc::mem_fun(selection_manager, &SelectionManager::setSelection));
}


