#ifndef SGC_SURFACE_STATE_FLYWEIGHT_FACTORY_HPP
#define SGC_SURFACE_STATE_FLYWEIGHT_FACTORY_HPP

#include "SurfaceState.h++"
#include "OpaqueState.h++"
#include "FieldState.h++"


namespace SGC	// namespace for all scene graph components
{

/**
Flyweight factory which manages the different instances of frame state objects
**/
class SurfaceStateFlyweightFactory
{
protected:
	OpaqueState	m_opaque_state;
	FieldState	m_field_state;

public:
	SurfaceState * stateOpaque();
	SurfaceState * stateField();
};

}

#endif
