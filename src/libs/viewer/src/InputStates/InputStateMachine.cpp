#include "InputStateMachine.hpp"

#include <QMouseEvent>
#include <viewer/BaseViewport.hpp>

#include "ISLeftClick.hpp"
#include "ISLeftDrag.hpp"
#include "ISRightClick.hpp"
#include "ISRightDrag.hpp"
#include "ISStart.hpp"
#include "InputState.hpp"

struct InputStateMachine::States {
  InputStates::Start start;
  InputStates::LeftClick left_click;
  InputStates::LeftDrag left_drag;
  InputStates::RightClick right_click;
  InputStates::RightDrag right_drag;
};

InputStateMachine::InputStateMachine()
    : m_states(std::make_unique<States>()), m_current_state(&m_states->start) {}

InputStateMachine::~InputStateMachine() = default;

void InputStateMachine::press(BaseViewport &viewport, QMouseEvent *event) {
  m_current_state->press(viewport, event, this);
  event->accept();
}

void InputStateMachine::release(BaseViewport &viewport, QMouseEvent *event) {
  m_current_state->release(viewport, event, this);
  event->accept();
}

void InputStateMachine::move(BaseViewport &viewport, QMouseEvent *event) {
  m_current_state->move(viewport, event, this);
  event->accept();
}

void InputStateMachine::changeToStart() {
  m_current_state = &m_states->start;
}

void InputStateMachine::changeToLeftClick() {
  m_current_state = &m_states->left_click;
}

void InputStateMachine::changeToLeftDrag() {
  m_current_state = &m_states->left_drag;
}

void InputStateMachine::changeToRightClick() {
  m_current_state = &m_states->right_click;
}

void InputStateMachine::changeToRightDrag() {
  m_current_state = &m_states->right_drag;
}
