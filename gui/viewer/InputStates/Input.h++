#ifndef INPUT_HPP
#define INPUT_HPP

#include <Qt>	// for QMouseEvent

#include "InputState.h++"
#include "../BaseViewport.h++"

class BaseViewport;
class InputState;

/**
Defines the interface for a state pattern that handles user input
**/
class Input
{
protected:
	InputState *m_current_state;

public:
	Input();

	void leftClick(BaseViewport *, QMouseEvent *event);
	void leftRelease(BaseViewport *, QMouseEvent *event);
	void rightClick(BaseViewport *, QMouseEvent *event);
	void rightRelease(BaseViewport *, QMouseEvent *event);
	void move(BaseViewport *, QMouseEvent *event);

protected:
	friend class InputState;
	void changeState(InputState *new_state);
};

#endif
