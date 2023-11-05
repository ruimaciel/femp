#ifndef FEMP_VIEWER_ISRIGHTCLICK_HPP
#define FEMP_VIEWER_ISRIGHTCLICK_HPP

#include "InputState.hpp"

namespace InputStates {

/**
 * Represents the initial state for the user input state machine
 */
class RightClick : public InputState {
	public:
	void press(BaseViewport* viewport, QMouseEvent* event, Input* input) override;
	void release(BaseViewport* viewport, QMouseEvent* event, Input* input) override;

	void rightRelease(BaseViewport* viewport, QMouseEvent* event, Input* input) override;

	void move(BaseViewport* viewport, QMouseEvent* event, Input* input) override;
};
}  // namespace InputStates

#endif
