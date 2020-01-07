#ifndef INPUT_STATE_LEFT_DRAG_HPP
#define INPUT_STATE_LEFT_DRAG_HPP

#include "InputState.h++"

namespace InputStates {

/**
 * Represents the initial state for the user input state machine
 */
class LeftDrag
    : public InputState {
public:
    void press(BaseViewport* viewport, QMouseEvent* event, Input* input) override;
    void release(BaseViewport* viewport, QMouseEvent* event, Input* input) override;

    void leftRelease(BaseViewport* viewport, QMouseEvent* event, Input* input) override;

    void move(BaseViewport* viewport, QMouseEvent* event, Input* input) override;
};

}

#endif
