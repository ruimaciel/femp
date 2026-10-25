#include "InputState.hpp"

#include <QDebug>
#include <QMouseEvent>
#include <viewer/BaseViewport.hpp>

InputState::~InputState() {}

void InputState::press(BaseViewport &viewport, QMouseEvent *event,
                       InputStateMachine *input) {
  qCritical() << "InputState::press(BaseViewport &viewport, QMouseEvent "
                 "*event, InputStateMachine *input)";

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

void InputState::release(BaseViewport & /*viewport*/, QMouseEvent * /*event*/,
                         InputStateMachine * /*input*/) {
  qCritical() << "InputState::release(BaseViewport &viewport, QMouseEvent "
                 "*event, InputStateMachine *input)";
}

void InputState::leftClick(BaseViewport & /*viewport*/, QMouseEvent * /*event*/,
                           InputStateMachine * /*input*/) {
  qCritical() << "InputState::leftClick(InputStateMachine *input) defaulted";
}

void InputState::leftRelease(BaseViewport & /*viewport*/,
                             QMouseEvent * /*event*/,
                             InputStateMachine * /*input*/) {
  qCritical() << "InputState::leftRelease(InputStateMachine *input) defaulted";
}

void InputState::rightClick(BaseViewport & /*viewport*/,
                            QMouseEvent * /*event*/,
                            InputStateMachine * /*input*/) {
  qCritical() << "InputState::rightClick(InputStateMachine *input) defaulted";
}

void InputState::rightRelease(BaseViewport & /*viewport*/,
                              QMouseEvent * /*event*/,
                              InputStateMachine * /*input*/) {
  qCritical()
      << "InputState::rightRelease(InputStateMachine *input) defaulted";
}

void InputState::move(BaseViewport & /*viewport*/, QMouseEvent * /*event*/,
                      InputStateMachine * /*input*/) {
  qCritical() << "InputState::move(InputStateMachine *input) defaulted";
}
