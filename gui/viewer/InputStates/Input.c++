#include "Input.h++"

#include "InputState.h++"


Input::Input()
{
}


void 
Input::leftClick(BaseViewport *viewport, QMouseEvent *event)
{
	m_current_state->leftClick(viewport, event, this);
}


void 
Input::leftRelease(BaseViewport *viewport, QMouseEvent *event)
{
	m_current_state->leftRelease(viewport,  event,this);
}


void 
Input::rightClick(BaseViewport *viewport, QMouseEvent *event)
{
	m_current_state->rightClick(viewport, event, this);
}


void 
Input::rightRelease(BaseViewport *viewport, QMouseEvent *event)
{
	m_current_state->rightRelease(viewport,  event,this);
}


void 
Input::move(BaseViewport *viewport, QMouseEvent *event)
{
	m_current_state->move(viewport, event, this);
}


void 
Input::changeState(InputState *state)
{
	this->m_current_state = state;
}


