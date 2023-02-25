#ifndef NODISPLACEMENTSPOLICY_H
#define NODISPLACEMENTSPOLICY_H

#include "DisplacementsRepresentationPolicy.h++"

/**
 * Concrete displacements policy where displacements are null
 **/
class NoDisplacementsPolicy : virtual public DisplacementsRepresentationPolicy {
	public:
	NoDisplacementsPolicy();
	virtual ~NoDisplacementsPolicy();

	protected:
	public:
	/**
	 * Returns the coordinate of a given point by providing the node's reference
	 **/
	fem::Point3D operator[](size_t& node_reference) override;
};

#endif	// NODISPLACEMENTSPOLICY_H
