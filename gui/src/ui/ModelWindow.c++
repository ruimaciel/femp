#include "ModelWindow.h++"

#include "../viewer/ModelViewport.h++"

ModelWindow::ModelWindow(fem::Project& project, ViewportColors& colors, QWidget* parent)
    : MdiWindow(parent)
    , BaseWindow("Model")
{
    viewport = new ModelViewport(project, this);
    this->setCentralWidget(viewport);

    viewport->setColors(colors);

    WindowWithWireframe::createToolbar(this);

    connectSignalsToSlots();
}

void ModelWindow::connectSignalsToSlots()
{
    MdiWindow::connectSignalsToSlots();
    WindowWithWireframe::connectSignalsToSlots(this);
}
