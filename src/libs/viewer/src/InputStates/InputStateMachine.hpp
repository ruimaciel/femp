#ifndef FEMP_VIEWER_INPUT_STATE_MACHINE_HPP
#define FEMP_VIEWER_INPUT_STATE_MACHINE_HPP

#include <memory>

#include "InputState.hpp"

class BaseViewport;
class QMouseEvent;
namespace InputStates {
class Start;
class LeftClick;
class LeftDrag;
class RightClick;
class RightDrag;
} // namespace InputStates

/**
 * Routes viewport events through the active input state.
 */
class InputStateMachine {
public:
  InputStateMachine();
  ~InputStateMachine();

  InputStateMachine(const InputStateMachine &) = delete;
  InputStateMachine &operator=(const InputStateMachine &) = delete;
  InputStateMachine(InputStateMachine &&) = delete;
  InputStateMachine &operator=(InputStateMachine &&) = delete;

  void press(BaseViewport &, QMouseEvent *event);
  void release(BaseViewport &, QMouseEvent *event);
  void move(BaseViewport &, QMouseEvent *event);

private:
  struct States;
  std::unique_ptr<States> m_states;
  InputState *m_current_state;

  void changeToStart();
  void changeToLeftClick();
  void changeToLeftDrag();
  void changeToRightClick();
  void changeToRightDrag();

  friend class InputStates::Start;
  friend class InputStates::LeftClick;
  friend class InputStates::LeftDrag;
  friend class InputStates::RightClick;
  friend class InputStates::RightDrag;
};

#endif
