#ifndef INPUT_HPP
#define INPUT_HPP

#include <sigc++/sigc++.h> // to side step a compiler error caused by a conflict with Qt and libsigc++

#include "InputState.h++"

#include "ISStart.h++"

class BaseViewport;
class QMouseEvent;
class InputState;

/**
Defines the interface for a state pattern that handles user input
**/
class Input {
protected:
    InputState* m_current_state;

    InputStates::Start m_s_start;

public:
    Input();

    void press(BaseViewport*, QMouseEvent* event);
    void release(BaseViewport*, QMouseEvent* event);

    void move(BaseViewport*, QMouseEvent* event);

    friend class InputState;
    void changeState(InputState* new_state);
};

#endif
