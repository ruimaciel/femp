#include "Input.hpp"

#include <QMouseEvent>
#include <viewer/BaseViewport.hpp>

#include "InputState.hpp"

Input::Input() {
	m_current_state = &m_is_start;	// TODO remove this
}

void Input::press(BaseViewport* viewport, QMouseEvent* event) {
	m_current_state->press(viewport, event, this);
	event->accept();
}

void Input::release(BaseViewport* viewport, QMouseEvent* event) {
	m_current_state->release(viewport, event, this);
	event->accept();
}

void Input::move(BaseViewport* viewport, QMouseEvent* event) {
	m_current_state->move(viewport, event, this);
	event->accept();
}

void Input::changeState(InputState* state) {
	this->m_current_state = state;
}
