#include "SurfaceLoad.h++"


namespace fem
{

SurfaceLoad::SurfaceLoad()
{
	force[0] = 0;
	force[1] = 0;
	force[2] = 0;
}


SurfaceLoad::SurfaceLoad(const SurfaceLoad &copied)
{
	force[0] = copied.force[0];
	force[1] = copied.force[1];
	force[2] = copied.force[2];
}


SurfaceLoad::~SurfaceLoad()
{
}

}
