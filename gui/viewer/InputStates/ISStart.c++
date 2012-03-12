#include "ISStart.h++"

#include <iostream>

#include "Input.h++"
#include "../BaseViewport.h++"

namespace InputStates
{

void 
Start::press(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	// std::cerr << "Start::press(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
	switch(event->buttons() )
	{ 
		case Qt::LeftButton:
			this->leftClick(viewport, event, input);
			break;

		case Qt::RightButton:
			this->rightClick(viewport, event, input);
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
Start::release(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
}


void 
Start::leftClick(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	fem::point near;
	//TODO rename this
	near.x((float)event->x());
	near.y((float)event->y());
	viewport->state->setSelectionStart(near);

	// register place where mouse is clicked
	viewport->viewport_data.lastPos = event->pos();

	input->changeState(&viewport->m_is_left_click);
}


void 
Start::rightClick(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	viewport->viewport_data.lastPos = event->pos(); // for the rotate
	input->changeState(&viewport->m_is_right_click);
}


void 
Start::move(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
}


}

