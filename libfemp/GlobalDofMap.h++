#ifndef FEMP_GLOBAL_DOF_MAP_HPP
#define FEMP_GLOBAL_DOF_MAP_HPP


#include <map>

#include <libfemp/GlobalDof.h++>

namespace fem
{


/**
 * data structure that maps GlobalDof objects to a global DoF reference number
 **/
class GlobalDofMap
{
private:
	struct MappingData {
		size_t	index;
	};

	std::map<GlobalDof, struct MappingData>	m_global_dof_map;

public:

	/**
	 * class constructor
	 **/
	GlobalDofMap();

	/**
	 * Clears the mapping
	 **/
	void clear();

	/**
	 * adds a GlobalDof to the index
	 **/
	void pushGlobalDof(GlobalDof const &gdof);

	/**
	 * Returns the index of a global dof
	 **/
	size_t getIndex(GlobalDof const &gdof) const;

};


}	// namespace fem

#endif
