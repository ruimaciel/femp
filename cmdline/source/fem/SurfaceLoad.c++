#include "SurfaceLoad.h++"


namespace fem
{

SurfaceLoad::SurfaceLoad()
{
}


SurfaceLoad::SurfaceLoad(const SurfaceLoad &copied)
{
	type = copied.type;
	nodes = copied.nodes;
	surface_forces = copied.surface_forces;
}


SurfaceLoad::~SurfaceLoad()
{
}


void SurfaceLoad::clear()
{
	type = Element::FE_INVALID;
	nodes.clear();
	surface_forces.clear();
}

}
