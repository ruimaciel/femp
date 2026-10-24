#include "ModelWindow.hpp"

#include "viewer/ModelViewport.hpp"

ModelWindow::ModelWindow(femp::Project &project, ViewportColors &colors,
                         QWidget *parent)
    : MdiWindow(parent), BaseWindow("Model") {
  viewport = new ModelViewport(project, this);
  this->setCentralWidget(viewport);

  viewport->setColors(colors);

  WindowWithWireframe::createToolbar(this);

  connectSignalsToSlots();
}

void ModelWindow::connectSignalsToSlots() {
  MdiWindow::connectSignalsToSlots();
  WindowWithWireframe::connectSignalsToSlots(this);
}
