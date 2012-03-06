#include "ISLeftDrag.h++"

#include <iostream>

#include "Input.h++"
#include "../BaseViewport.h++"

namespace InputStates
{

void 
LeftDrag::press(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "LeftDrag::press(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
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
LeftDrag::release(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	//std::cerr << "LeftDrag::release(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	//TODO check if left button was released
	this->leftRelease(viewport, event, input);
}


void 
LeftDrag::leftRelease(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "LeftDrag::leftRelease(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	viewport->state->setSelectionOff();
	input->changeState(&viewport->m_is_start);
}


void 
LeftDrag::move(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "LeftDrag::move(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	{
		fem::point near;
		near.x((float)event->x());
		near.y((float)event->y());

		viewport->state->setSelectionEnd(near);
	}
}


}

