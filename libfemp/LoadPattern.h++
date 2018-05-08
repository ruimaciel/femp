#ifndef FEMP_LOAD_PATTERN_HPP
#define FEMP_LOAD_PATTERN_HPP

#include <string>
#include <map>
#include <vector>

#include <libfemp/NodalDisplacement.h++>
#include <libfemp/loads/NodalLoad.h++>
#include <libfemp/loads/SurfaceLoad.h++>
#include <libfemp/loads/DomainLoad.h++>


namespace fem
{

/**
This class defines a set of loads which are applied on the FEM model
**/
class LoadPattern
{
private:
	std::string m_label;	// this load pattern's label

public:
	std::map<size_t,NodalLoad> 	nodal_loads;	// maps nodal loads to node references
	std::map<size_t,NodalDisplacement> 	nodal_displacements;	// maps nodal loads to node references
	std::map<size_t,DomainLoad>	domain_loads;	// maps to element references
	std::vector<SurfaceLoad *>	surface_loads;	// lists surface loads

public:
	/**
	 * Class default constructor
	 **/
	LoadPattern();

	/** Clears all info contained in this load pattern object
	**/
	void clear();

	/** checks if this load pattern has any load set **/
	bool empty() const;


	/**
	 * returns the label
	 **/
	std::string const & getLabel() const;

	/**
	 * sets the label
	 **/
	void setLabel(std::string const &label);

	void addNodalLoad(size_t, Point);
	void addNodalDisplacement(size_t, Point);

	/**
	sets the domain load for a given element
	@param element	element that will get a new domain load definition
	@param force_shape	a list of forces acting on each of the element's nodes
	**/
	void addDomainLoad(size_t element, Point force);

	void addSurfaceLoad(SurfaceLoad *surfaceload);
};


}	// namespace fem

#endif
