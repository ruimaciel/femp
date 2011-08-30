#include "SurfaceStateFlyweightFactory.h++"

SurfaceState *
SurfaceStateFlyweightFactory::stateOpaque()
{
	return &m_opaque_state;
}


SurfaceState *
SurfaceStateFlyweightFactory::stateField()
{
	return &m_field_state;
}


