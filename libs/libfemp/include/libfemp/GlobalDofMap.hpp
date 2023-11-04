#ifndef FEMP_GLOBALDOFMAP_HPP
#define FEMP_GLOBALDOFMAP_HPP

#include <libfemp/GlobalDof.hpp>

// std includes
#include <map>

namespace fem {

/**
 * Maps GlobalDof objects to a global DoF reference number
 */
class GlobalDofMap {
	private:
	struct MappingData {
		size_t index;
	};

	std::map<GlobalDof, struct MappingData> m_global_dof_map;

	public:
	/**
	 * class constructor
	 */
	GlobalDofMap();

	/**
	 * adds a GlobalDof to the index
	 */
	void pushGlobalDof(GlobalDof const& gdof);

	/**
	 * Returns the index of a global dof
	 */
	size_t getIndex(GlobalDof const& gdof) const;
};

}  // namespace fem

#endif
