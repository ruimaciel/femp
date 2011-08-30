#ifndef SGC_FRAME_STATE_FLYWEIGHT_FACTORY_HPP
#define SGC_FRAME_STATE_FLYWEIGHT_FACTORY_HPP

#include "FrameState.h++"
#include "NoFrameState.h++"
#include "WireFrameState.h++"


namespace SGC	// namespace for all scene graph components
{

/**
Flyweight factory which manages the different instances of frame state objects
**/
class FrameStateFlyweightFactory
{
protected:
	NoFrameState m_no_frame_state;
	WireFrameState m_wire_frame_state;

public:
	FrameState * stateNoFrame();
	FrameState * stateWireFrame();
};

}

#endif
