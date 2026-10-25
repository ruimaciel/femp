#include "ISStart.hpp"

#include <QDebug>
#include <QMouseEvent>
#include <viewer/BaseViewport.hpp>

#include "../ViewportStates/ViewportState.hpp"
#include "InputStateMachine.hpp"

namespace InputStates {

void Start::press(BaseViewport &viewport, QMouseEvent *event,
                  InputStateMachine *input) {
  switch (event->buttons()) {
  case Qt::LeftButton:
    this->leftClick(viewport, event, input);
    break;

  case Qt::RightButton:
    this->rightClick(viewport, event, input);
    break;

  default:
    qCritical() << "other";
    break;
  }
}

void Start::leftClick(BaseViewport &viewport, QMouseEvent *event,
                      InputStateMachine *input) {
  fem::Point3D near;
  near.x((float)event->x());
  near.y((float)event->y());
  viewport.state->setSelectionStart(near);

  // register place where mouse is clicked
  viewport.viewport_data.lastPos = event->pos();

  input->changeToLeftClick();
}

void Start::rightClick(BaseViewport &viewport, QMouseEvent *event,
                       InputStateMachine *input) {
  viewport.viewport_data.lastPos = event->pos(); // for the rotate
  input->changeToRightClick();
}
} // namespace InputStates
