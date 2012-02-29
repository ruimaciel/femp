#ifndef INPUT_STATE_HPP
#define INPUT_STATE_HPP

#include <Qt>	// for QMouseEvent

#include "Input.h++"
#include "../BaseViewport.h++"

class Input;
class BaseViewport;

/**
Implements the interface for each state in the state pattern defined by the Input class
**/
class InputState
{
public:
	virtual void leftClick(BaseViewport *viewport, QMouseEvent *event, Input *input);
	virtual void leftRelease(BaseViewport *viewport, QMouseEvent *event, Input *input);
	virtual void rightClick(BaseViewport *viewport, QMouseEvent *event, Input *input);
	virtual void rightRelease(BaseViewport *viewport, QMouseEvent *event, Input *input);
	virtual void move(BaseViewport *viewport, QMouseEvent *event, Input *input);

protected:
	void changeState(Input &input, InputState *new_state);
};

#endif
