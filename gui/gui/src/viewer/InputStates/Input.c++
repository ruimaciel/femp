#include "Input.h++"

#include "../BaseViewport.h++"
#include "InputState.h++"

Input::Input()
{
    m_current_state = &m_s_start; //TODO remove this
}

void Input::press(BaseViewport* viewport, QMouseEvent* event)
{
    m_current_state->press(viewport, event, this);
    event->accept();
}

void Input::release(BaseViewport* viewport, QMouseEvent* event)
{
    m_current_state->release(viewport, event, this);
    event->accept();
}

void Input::move(BaseViewport* viewport, QMouseEvent* event)
{
    m_current_state->move(viewport, event, this);
    event->accept();
}

void Input::changeState(InputState* state)
{
    this->m_current_state = state;
}
