#ifndef INPUT_STATE_HPP
#define INPUT_STATE_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

class Input;
class QMouseEvent;
class BaseViewport;

/**
Implements the interface for each state in the state pattern defined by the Input class
**/
class InputState
{
public:

    virtual ~InputState();

    /**
    depending on the state, checks which mouse button has been pressed
    **/
    virtual void press(BaseViewport *viewport, QMouseEvent *event, Input *input);
    /**
    depending on the state, checks which mouse button has been released
    **/
    virtual void release(BaseViewport *viewport, QMouseEvent *event, Input *input);

    virtual void leftClick(BaseViewport *viewport, QMouseEvent *event, Input *input);
    virtual void leftRelease(BaseViewport *viewport, QMouseEvent *event, Input *input);
    virtual void rightClick(BaseViewport *viewport, QMouseEvent *event, Input *input);
    virtual void rightRelease(BaseViewport *viewport, QMouseEvent *event, Input *input);
    virtual void move(BaseViewport *viewport, QMouseEvent *event, Input *input);


protected:
    void changeState(Input &input, InputState *new_state);
};

#endif
