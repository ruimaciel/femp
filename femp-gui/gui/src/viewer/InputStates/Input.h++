#ifndef INPUT_HPP
#define INPUT_HPP

#include "InputState.h++"

#include "ISLeftClick.h++" // for the state pattern that handles user input
#include "ISLeftDrag.h++" // for the state pattern that handles user input
#include "ISRightClick.h++" // for the state pattern that handles user input
#include "ISRightDrag.h++" // for the state pattern that handles user input
#include "ISStart.h++"
#include "ISStart.h++" // for the state pattern that handles user input

class BaseViewport;
class QMouseEvent;
class InputState;

/**
 * Defines the interface for a state pattern that handles user input
 */
class Input {
public:
    InputStates::Start m_is_start;
    InputStates::LeftClick m_is_left_click;
    InputStates::LeftDrag m_is_left_drag;
    InputStates::RightClick m_is_right_click;
    InputStates::RightDrag m_is_right_drag;

protected:
    InputState* m_current_state;

public:
    Input();

    void press(BaseViewport*, QMouseEvent* event);
    void release(BaseViewport*, QMouseEvent* event);

    void move(BaseViewport*, QMouseEvent* event);

    friend class InputState;
    void changeState(InputState* new_state);
};

#endif
