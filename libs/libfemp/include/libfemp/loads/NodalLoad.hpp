#ifndef FEMP_NODALLOAD_HPP
#define FEMP_NODALLOAD_HPP

#include <libfemp/Point3D.hpp>

namespace fem {

/**
 * Represents a load prescribed on a finite element node
 **/
class NodalLoad {
	public:
	NodalLoad();
	NodalLoad(Point3D m_force);

	/**
	 * returns the force vector
	 */
	Point3D getForce() const;

	private:
	Point3D m_force;  // the force being applied in this node
};

}  // namespace fem

#endif
