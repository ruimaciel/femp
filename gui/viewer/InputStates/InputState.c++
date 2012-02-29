#include "InputState.h++"

#include <iostream>


void 
InputState::leftClick(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	// remove after debug
	std::cerr << "InputState::leftClick(Input *input) defaulted" << std::endl;
}


void 
InputState::leftRelease(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	// remove after debug
	std::cerr << "InputState::leftRelease(Input *input) defaulted" << std::endl;
}


void 
InputState::rightClick(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	// remove after debug
	std::cerr << "InputState::rightClick(Input *input) defaulted" << std::endl;
}


void 
InputState::rightRelease(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	// remove after debug
	std::cerr << "InputState::rightRelease(Input *input) defaulted" << std::endl;
}


void 
InputState::move(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	// remove after debug
	std::cerr << "InputState::move(Input *input) defaulted" << std::endl;
}


void 
InputState::changeState(Input &input, InputState *new_state)
{
	input.changeState(new_state);
}

