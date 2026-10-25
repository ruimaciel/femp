#include "ModelWindow.hpp"

#include "viewer/ModelViewport.hpp"

ModelWindow::ModelWindow(femp::Project &project, ViewportColors &colors,
                         QWidget *parent)
    : femp::ui::MdiWindow(parent), femp::ui::BaseWindow("Model") {
  viewport = new ModelViewport(project, this);
  this->setCentralWidget(viewport);

  viewport->setColors(colors);

  femp::ui::WindowWithWireframe::createToolbar(this);

  connectSignalsToSlots();
}

void ModelWindow::connectSignalsToSlots() {
  femp::ui::MdiWindow::connectSignalsToSlots();
  femp::ui::WindowWithWireframe::connectSignalsToSlots(this);
}
