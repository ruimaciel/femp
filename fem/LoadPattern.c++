#include "LoadPattern.h++"


namespace fem
{
	LoadPattern::LoadPattern()
	{
	}


	LoadPattern::LoadPattern(const LoadPattern &copied)
	{
		this->label = copied.label;
		this->nodal_loads = copied.nodal_loads;
		this->nodal_displacements = copied.nodal_displacements;
		this->domain_loads = copied.domain_loads;
	}


	LoadPattern::~LoadPattern()
	{
	}


	void LoadPattern::clear()
	{
		label.clear();
		nodal_loads.clear();
		nodal_displacements.clear();
		domain_loads.clear();
		//TODO add surface loads
	}


	void LoadPattern::addNodalLoad(size_t node, point force)
	{
		//TODO perform sanity checks
		NodalLoad n;
		n.force = force;
		nodal_loads[node] = n;
	}

	void LoadPattern::addNodalDisplacement(size_t node, point displacement)
	{
		//TODO perform sanity checks
		NodalDisplacement n;
		n.displacement = displacement;
		nodal_displacements[node] = n;
	}

	void LoadPattern::addDomainLoad(size_t element, std::vector<point> force_shape)
	{
		//TODO perform sanity checks
		DomainLoad n;
		n.force_shape = force_shape;
		domain_loads[element] = n;
	}
}


