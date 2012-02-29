#include "Input.h++"

#include "InputState.h++"


void 
Input::leftClick()
{
	m_current_state->leftClick(this);
}


void 
Input::leftRelease()
{
	m_current_state->leftRelease(this);
}


void 
Input::changeState(InputState *state)
{
	this->m_current_state = state;
}


