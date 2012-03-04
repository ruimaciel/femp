#include "ISLeftClick.h++"

#include <iostream>

#include "Input.h++"
#include "../BaseViewport.h++"

namespace InputStates
{

void 
LeftClick::press(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "LeftClick::press(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
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
LeftClick::release(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	//std::cerr << "LeftClick::release(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	//TODO check if left button was released
	this->leftRelease(viewport, event, input);
}


void 
LeftClick::leftRelease(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "LeftClick::leftRelease(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	input->changeState(&viewport->m_is_start);
}


void 
LeftClick::move(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "LeftClick::move(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
}


}

