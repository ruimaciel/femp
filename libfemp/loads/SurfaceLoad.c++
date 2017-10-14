#include "SurfaceLoad.h++"


namespace fem
{

SurfaceLoad::SurfaceLoad()
	: Element()
{
}


std::vector<node_ref_t> 
SurfaceLoad::getNodeReferences() const
{
	return this->nodes;
}


}	// namespace fem

