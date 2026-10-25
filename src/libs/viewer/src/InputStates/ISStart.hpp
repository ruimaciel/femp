#ifndef FEMP_VIEWER_ISSTART_HPP
#define FEMP_VIEWER_ISSTART_HPP

#include "InputState.hpp"

namespace InputStates {

/**
 * Represents the initial state for the user input state machine
 */
class Start : public InputState {
public:
  void press(BaseViewport &viewport, QMouseEvent *event,
             InputStateMachine *input) override;
  void leftClick(BaseViewport &viewport, QMouseEvent *event,
                 InputStateMachine *input) override;
  void rightClick(BaseViewport &viewport, QMouseEvent *event,
                  InputStateMachine *input) override;
};
} // namespace InputStates

#endif
