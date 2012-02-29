#ifndef INPUT_STATE_HPP
#define INPUT_STATE_HPP

#include "Input.h++"

class Input;

/**
Implements the interface for each state in the state pattern defined by the Input class
**/
class InputState
{
public:
	virtual void leftClick(Input *input);
	virtual void leftRelease(Input *input);

protected:
	void changeState(Input &input, InputState *new_state);
};

#endif
