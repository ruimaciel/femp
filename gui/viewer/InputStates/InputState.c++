#include "InputState.h++"

#include <iostream>


void 
InputState::leftClick(Input *input)
{
	// remove after debug
	std::cerr << "InputState::leftClick(Input *input) defaulted" << std::endl;
}


void 
InputState::leftRelease(Input *input)
{
	// remove after debug
	std::cerr << "InputState::leftRelease(Input *input) defaulted" << std::endl;
}


void 
InputState::changeState(Input &input, InputState *new_state)
{
	input.changeState(new_state);
}

