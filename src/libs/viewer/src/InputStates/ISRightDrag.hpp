#ifndef FEMP_VIEWER_ISRIGHTDRAG_HPP
#define FEMP_VIEWER_ISRIGHTDRAG_HPP

#include "InputState.hpp"

namespace InputStates {

/**
 * Represents the initial state for the user input state machine
 */
class RightDrag : public InputState {
	public:
	void press(BaseViewport* viewport, QMouseEvent* event, Input* input) override;
	void release(BaseViewport* viewport, QMouseEvent* event, Input* input) override;

	void rightRelease(BaseViewport* viewport, QMouseEvent* event, Input* input) override;

	void move(BaseViewport* viewport, QMouseEvent* event, Input* input) override;
};
}  // namespace InputStates

#endif
