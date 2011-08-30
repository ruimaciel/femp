#include "FrameStateFlyweightFactory.h++"

FrameState *
FrameStateFlyweightFactory::stateNoFrame()
{
	return &m_no_frame_state;
}


FrameState *
FrameStateFlyweightFactory::stateWireFrame()
{
	return &m_wire_frame_state;
}


