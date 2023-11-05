#ifndef FEMP_VIEWER_NODISPLACEMENTSPOLICY_HPP
#define FEMP_VIEWER_NODISPLACEMENTSPOLICY_HPP

#include "DisplacementsRepresentationPolicy.hpp"

/**
 * Concrete displacements policy where displacements are null
 **/
class NoDisplacementsPolicy : virtual public DisplacementsRepresentationPolicy {
	public:
	/**
	 * Returns the coordinate of a given point by providing the node's reference
	 **/
	fem::Point3D operator[](size_t& node_reference) override;
};

#endif	// NODISPLACEMENTSPOLICY_HPP
