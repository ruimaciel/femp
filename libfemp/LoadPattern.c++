#include "LoadPattern.h++"


namespace fem
{


LoadPattern::LoadPattern()
{
}


LoadPattern::LoadPattern(const LoadPattern &copied)
{
	this->setLabel(copied.getLabel() );
	this->nodal_loads = copied.nodal_loads;
	this->nodal_displacements = copied.nodal_displacements;
	this->domain_loads = copied.domain_loads;
	this->surface_loads = copied.surface_loads;
}


LoadPattern::~LoadPattern()
{
}


void 
LoadPattern::clear()
{
	m_label.clear();
	nodal_loads.clear();
	nodal_displacements.clear();
	domain_loads.clear();
	surface_loads.clear();
}


bool 
LoadPattern::empty() const
{
	if(!nodal_loads.empty()) return false;
	if(!domain_loads.empty()) return false;
	if(!surface_loads.empty()) return false;
	if(!nodal_displacements.empty()) return false;
	return true;
}


std::string const & 
LoadPattern::getLabel() const
{
	return this->m_label;
}


void 
LoadPattern::setLabel(std::string const &label)
{
	this->m_label = label;
}


void 
LoadPattern::addNodalLoad(size_t node, Point force)
{
	//TODO perform sanity checks
	NodalLoad n;
	n.force = force;
	nodal_loads[node] = n;
}


void 
LoadPattern::addNodalDisplacement(size_t node, Point displacement)
{
	//TODO perform sanity checks
	NodalDisplacement n;
	n.displacement = displacement;
	nodal_displacements[node] = n;
}


void 
LoadPattern::addDomainLoad(size_t element, Point force)
{
	//TODO perform sanity checks
	DomainLoad n;
	n.force = force;
	domain_loads[element] = n;
}


void 
LoadPattern::addSurfaceLoad(SurfaceLoad &lp)
{
	surface_loads.push_back(lp);
}


}	// namespace fem


