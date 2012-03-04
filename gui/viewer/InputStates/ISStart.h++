#ifndef INPUT_STATE_START_HPP 
#define INPUT_STATE_START_HPP 

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include "InputState.h++"


namespace InputStates
{

/**
Represents the initial state for the user input state machine
**/
class Start
	: public InputState
{
public:
	void leftClick(BaseViewport *viewport, QMouseEvent *event, Input *input);
	/*
	virtual void leftRelease(BaseViewport *viewport, QMouseEvent *event, Input *input);
	virtual void rightClick(BaseViewport *viewport, QMouseEvent *event, Input *input);
	virtual void rightRelease(BaseViewport *viewport, QMouseEvent *event, Input *input);
	virtual void move(BaseViewport *viewport, QMouseEvent *event, Input *input);
	*/
};


}

#endif
