#include "MdiWindow.h++"

#include <QDebug>

/**
Base class for all MDI windows which render a model
**/

MdiWindow::MdiWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setupUi(this);

    this->viewport = nullptr;

    // create the menu
    this->m_actionMenuVisibility = new QAction(tr("Menu visibility"), this);
    this->m_actionMenuVisibility->setCheckable(true);
    this->m_actionMenuVisibility->setChecked(false);
    this->m_actionMenuVisibility->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_M));
    this->menuBar()->hide();

    this->createViewportToolbar();
    this->createVisibilityToolbar();
}

void MdiWindow::createViewportToolbar()
{
    // create actions
    m_actionViewportXY = new QAction("XY", this);
    m_actionViewportYZ = new QAction("YZ", this);
    m_actionViewportXZ = new QAction("XZ", this);
    m_actionViewportIso = new QAction("iso", this);

    // create and populate the toolbar
    m_viewportToolBar = addToolBar(tr("Viewport"));
    m_viewportToolBar->addAction(m_actionViewportXY);
    m_viewportToolBar->addAction(m_actionViewportYZ);
    m_viewportToolBar->addAction(m_actionViewportXZ);
    m_viewportToolBar->addAction(m_actionViewportIso);
}

void MdiWindow::createVisibilityToolbar()
{
    m_actionVisibleNodes = new QAction("Nodes", this);
    m_actionVisibleNodes->setCheckable(true);
    m_actionVisibleNodes->setChecked(true);

    m_actionVisibleRestrictions = new QAction("Restrictions", this);
    m_actionVisibleRestrictions->setCheckable(true);
    m_actionVisibleRestrictions->setChecked(true);

    m_visibilityToolBar = addToolBar(tr("Visibility"));
    m_visibilityToolBar->addAction(m_actionVisibleNodes);
    m_visibilityToolBar->addAction(m_actionVisibleRestrictions);
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

void MdiWindow::setNodeVisibility(const bool state)
{
    this->viewport->setNodeVisibility(state);
    this->viewport->refresh();
}

void MdiWindow::setNodeRestrictionsVisibility(const bool state)
{
    this->viewport->setNodeRestrictionsVisibility(state);
    this->viewport->refresh();
}

void MdiWindow::connectSignalsToSlots()
{
    //signals and slots
    connect(m_actionViewportXY, &QAction::triggered, this, &MdiWindow::setViewportXY);
    connect(m_actionViewportXZ, &QAction::triggered, this, &MdiWindow::setViewportXZ);
    connect(m_actionViewportYZ, &QAction::triggered, this, &MdiWindow::setViewportYZ);

    connect(m_actionVisibleNodes, &QAction::toggled, this, &MdiWindow::setNodeVisibility);
    connect(m_actionVisibleRestrictions, &QAction::toggled, this, &MdiWindow::setNodeRestrictionsVisibility);

    // libsigc++ signals
    this->viewport->selection_changed.connect(this->selection_changed.make_slot());
}

void MdiWindow::normalizeAngle(int* angle)
{
    while (*angle < 0)
        *angle += 360 * 16;
    while (*angle > 360 * 16)
        *angle -= 360 * 16;
}

void MdiWindow::setColors(ViewportColors& colors)
{
    viewport->setColors(colors);
}

void MdiWindow::setSelection(Selection selection)
{
    qInfo() << "void MdiWindow::setSelection(Selection)";

    this->viewport->setSelection(selection);
}

void MdiWindow::clearSelection()
{
    qInfo() << "void MdiWindow::setSelection(Selection): hasn't been implemented";
}

void MdiWindow::showSelection(const Selection selection)
{
    qInfo() << "MdiWindow::viewSelection(const Selection selection)";
    this->viewport->showSelection(selection);
}

void MdiWindow::showAll()
{
    qInfo() << "MdiWindow::viewAll()";
    this->viewport->showAll();
}

void MdiWindow::updateNodeRestriction(size_t const id, fem::NodeRestrictions const& nr)
{
    qInfo() << "MdiWindow::updateNodeRestriction(size_t const id, fem::NodeRestrictions const &nr)";
}

void MdiWindow::connectToSelectionManager(SelectionManager& selection_manager)
{
    qInfo() << "void MdiWindow::connectToSelectionManager(SelectionManager &selection_manager)";

    selection_manager.selection_changed.connect(sigc::mem_fun(this, &MdiWindow::setSelection));
    this->selection_changed.connect(sigc::mem_fun(selection_manager, &SelectionManager::setSelection));
}
