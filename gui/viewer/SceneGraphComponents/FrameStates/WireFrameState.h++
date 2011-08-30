#ifndef SGC_FRAME_STATE_HPP
#define SGC_FRAME_STATE_HPP

#include "FrameState.h++"


namespace SGC	// namespace for all scene graph components
{

/**
State pattern used to render an element's surface frames, which doesn't render them
**/
class WireFrameState
	: public FrameState
{
public:
};

}


#endif
