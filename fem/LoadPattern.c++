#include "LoadPattern.h++"


namespace fem
{
	LoadPattern::LoadPattern()
	{
	}


	LoadPattern::LoadPattern(const LoadPattern &copied)
	{
		this->label = copied.label;
	}


	LoadPattern::~LoadPattern()
	{
	}


	void LoadPattern::addNodalLoad(size_t node, point force)
	{
		NodalLoad n;
		n.force = force;
		nodal_loads[node] = n;
	}
}


