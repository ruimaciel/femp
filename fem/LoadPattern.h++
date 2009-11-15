#ifndef LOAD_PATTERN_HPP
#define LOAD_PATTERN_HPP

#include <string>
#include <map>

#include "NodalLoad.h++"

namespace fem
{
	/**
	This class defines a set of loads which are applied on the FEM model
	**/
	class LoadPattern
	{
		public:
			LoadPattern();
			LoadPattern(const LoadPattern &);
			~LoadPattern();

			std::string label;	// this load pattern's label

			std::map<size_t,NodalLoad> nodal_loads;	// maps nodal loads to node references


			void addNodalLoad(size_t, point);
	};
}

#endif
