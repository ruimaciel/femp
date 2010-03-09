#ifndef LOAD_PATTERN_HPP
#define LOAD_PATTERN_HPP

#include <QString>
#include <map>

#include "NodalLoad.h++"
#include "NodalDisplacement.h++"
#include "DomainLoad.h++"
#include "SurfaceLoad.h++"


namespace fem
{
	/**
	This class defines a set of loads which are applied on the FEM model
	**/
	class LoadPattern
	{
		public:
			QString label;	// this load pattern's label
			std::map<size_t,NodalLoad> 	nodal_loads;	// maps nodal loads to node references
			std::map<size_t,NodalDisplacement> 	nodal_displacements;	// maps nodal loads to node references
			std::map<size_t,DomainLoad>	domain_loads;	// maps to element references
			std::vector<SurfaceLoad>	surface_loads;	// lists surface loads

		public:
			LoadPattern();
			LoadPattern(const LoadPattern &);
			~LoadPattern();

			/** Clears all info contained in this load pattern object
			**/
			void clear();

			void addNodalLoad(size_t, point);
			void addNodalDisplacement(size_t, point);

			/**
			sets the domain load for a given element
			@param element	element that will get a new domain load definition
			@param force_shape	a list of forces acting on each of the element's nodes
			**/
			void addDomainLoad(size_t element, point force);

			void addSurfaceLoad(SurfaceLoad &);
	};
}

#endif
