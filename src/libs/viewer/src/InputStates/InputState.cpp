#include "InputState.hpp"

#include <QDebug>
#include <QMouseEvent>
#include <viewer/BaseViewport.hpp>

#include "Input.hpp"  // for the state pattern that handles user input

InputState::~InputState() {}

void InputState::press(BaseViewport* viewport, QMouseEvent* event, Input* input) {
	qCritical() << "InputState::press(BaseViewport *viewport, QMouseEvent "
				   "*event, Input *input)";

	switch (event->buttons()) {
		case Qt::LeftButton:
			this->leftClick(viewport, event, input);
			break;

		case Qt::RightButton:
			this->rightClick(viewport, event, input);
			break;

		default:
			qCritical() << "other";
			break;
	}
}

void InputState::release(BaseViewport* /*viewport*/, QMouseEvent* /*event*/, Input* /*input*/) {
	qCritical() << "InputState::release(BaseViewport *viewport, QMouseEvent "
				   "*event, Input *input)";
}

void InputState::leftClick(BaseViewport* /*viewport*/, QMouseEvent* /*event*/, Input* /*input*/) {
	qCritical() << "InputState::leftClick(Input *input) defaulted";
}

void InputState::leftRelease(BaseViewport* /*viewport*/, QMouseEvent* /*event*/, Input* /*input*/) {
	qCritical() << "InputState::leftRelease(Input *input) defaulted";
}

void InputState::rightClick(BaseViewport* /*viewport*/, QMouseEvent* /*event*/, Input* /*input*/) {
	qCritical() << "InputState::rightClick(Input *input) defaulted";
}

void InputState::rightRelease(BaseViewport* /*viewport*/, QMouseEvent* /*event*/, Input* /*input*/) {
	qCritical() << "InputState::rightRelease(Input *input) defaulted";
}

void InputState::move(BaseViewport* /*viewport*/, QMouseEvent* /*event*/, Input* /*input*/) {
	qCritical() << "InputState::move(Input *input) defaulted";
}

void InputState::changeState(Input& input, InputState* new_state) {
	input.changeState(new_state);
}
