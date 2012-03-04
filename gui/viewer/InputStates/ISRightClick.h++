#ifndef INPUT_STATE_RIGHT_CLICK_HPP 
#define INPUT_STATE_RIGHT_CLICK_HPP 

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include "InputState.h++"


namespace InputStates
{

/**
Represents the initial state for the user input state machine
**/
class RightClick
	: public InputState
{
public:
	void press(BaseViewport *viewport, QMouseEvent *event, Input *input);
	void release(BaseViewport *viewport, QMouseEvent *event, Input *input);

	//void leftClick(BaseViewport *viewport, QMouseEvent *event, Input *input);
	//void leftRelease(BaseViewport *viewport, QMouseEvent *event, Input *input);
	//void rightClick(BaseViewport *viewport, QMouseEvent *event, Input *input);
	void rightRelease(BaseViewport *viewport, QMouseEvent *event, Input *input);
	void move(BaseViewport *viewport, QMouseEvent *event, Input *input);
};


}

#endif
