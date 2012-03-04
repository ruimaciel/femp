#include "ISRightClick.h++"

#include <iostream>

#include "Input.h++"
#include "../BaseViewport.h++"

namespace InputStates
{

void 
RightClick::press(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "RightClick::press(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
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
RightClick::release(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	//std::cerr << "RightClick::release(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	//TODO check if left button was released
	this->rightRelease(viewport, event, input);
}


void 
RightClick::rightRelease(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "RightClick::rightRelease(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	input->changeState(&viewport->m_is_start);
}


void 
RightClick::move(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "RightClick::move(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
}


}

