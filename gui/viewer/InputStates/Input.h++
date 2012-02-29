#ifndef INPUT_HPP
#define INPUT_HPP

#include "InputState.h++"

class InputState;

/**
Defines the interface for a state pattern that handles user input
**/
class Input
{
protected:
	InputState *m_current_state;

public:
	void leftClick();
	void leftRelease();
	void move();

protected:
	friend class InputState;
	void changeState(InputState *new_state);
};

#endif
