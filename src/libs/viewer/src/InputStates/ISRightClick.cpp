#include "ISRightClick.hpp"

#include <QDebug>
#include <QMouseEvent>
#include <viewer/BaseViewport.hpp>

#include "InputStateMachine.hpp"

namespace InputStates {

void RightClick::press(BaseViewport & /*viewport*/, QMouseEvent *event,
                       InputStateMachine * /*input*/) {
  switch (event->buttons()) {
  default:
    qCritical() << "other";
    break;
  }
}

void RightClick::release(BaseViewport &viewport, QMouseEvent *event,
                         InputStateMachine *input) {
  // TODO check if left button was released
  this->rightRelease(viewport, event, input);
}

void RightClick::rightRelease(BaseViewport & /*viewport*/, QMouseEvent * /*event*/,
                              InputStateMachine *input) {
  input->changeToStart();
}

void RightClick::move(BaseViewport & /*viewport*/, QMouseEvent * /*event*/,
                      InputStateMachine *input) {
  input->changeToRightDrag();
}
} // namespace InputStates
