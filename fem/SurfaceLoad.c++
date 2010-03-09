#include "SurfaceLoad.h++"


namespace fem
{

SurfaceLoad::SurfaceLoad()
{
}


SurfaceLoad::SurfaceLoad(const SurfaceLoad &copied)
{
	type = copied.type;
	node_reference = copied.node_reference;
	surface_forces = copied.surface_forces;
}


SurfaceLoad::~SurfaceLoad()
{
}


void SurfaceLoad::clear()
{
	type = Element::FE_INVALID;
	node_reference.clear();
	surface_forces.clear();
}

}
