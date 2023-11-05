#ifndef FEMP_VIEWER_ISLEFTDRAG_HPP
#define FEMP_VIEWER_ISLEFTDRAG_HPP

#include "InputState.hpp"

namespace InputStates {

/**
 * Represents the initial state for the user input state machine
 */
class LeftDrag : public InputState {
	public:
	void press(BaseViewport* viewport, QMouseEvent* event, Input* input) override;
	void release(BaseViewport* viewport, QMouseEvent* event, Input* input) override;

	void leftRelease(BaseViewport* viewport, QMouseEvent* event, Input* input) override;

	void move(BaseViewport* viewport, QMouseEvent* event, Input* input) override;
};
}  // namespace InputStates

#endif
