#ifndef INPUT_STATE_RIGHT_CLICK_HPP
#define INPUT_STATE_RIGHT_CLICK_HPP

#include "InputState.h++"

namespace InputStates {

/**
 * Represents the initial state for the user input state machine
 */
class RightClick
    : public InputState {
public:
    void press(BaseViewport* viewport, QMouseEvent* event, Input* input) override;
    void release(BaseViewport* viewport, QMouseEvent* event, Input* input) override;

    void rightRelease(BaseViewport* viewport, QMouseEvent* event, Input* input) override;

    void move(BaseViewport* viewport, QMouseEvent* event, Input* input) override;
};
}

#endif
