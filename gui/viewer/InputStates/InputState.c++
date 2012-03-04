#include "InputState.h++"

#include <iostream>

#include "../BaseViewport.h++"


void 
InputState::press(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "InputState::press(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	switch(event->buttons() )
	{ 
		case Qt::LeftButton:
			std::cerr << "left" << std::endl;
			break;

		case Qt::RightButton:
			std::cerr << "right" << std::endl;
			break;

		/*
		case (Qt::LeftButton | Qt::RightButton):
			std::cerr << "both" << std::endl;
			break;
		*/

		default:
			std::cerr << "other" << std::endl;
			break;
	}
}


void 
InputState::release(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "InputState::release(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
}


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

