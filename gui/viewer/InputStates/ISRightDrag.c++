#include "ISRightDrag.h++"

#include <iostream>

#include "Input.h++"
#include "../BaseViewport.h++"

namespace InputStates
{

void 
RightDrag::press(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "RightDrag::press(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	switch(event->buttons() )
	{ 
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
RightDrag::release(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	//std::cerr << "RightDrag::release(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	//TODO check if left button was released
	this->rightRelease(viewport, event, input);
}


void 
RightDrag::rightRelease(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "RightDrag::rightRelease(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	input->changeState(&viewport->m_is_start);
}


void 
RightDrag::move(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "RightDrag::move(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
}


}

