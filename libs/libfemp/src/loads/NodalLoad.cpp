#include <libfemp/loads/NodalLoad.hpp>

namespace fem {

NodalLoad::NodalLoad() {}

NodalLoad::NodalLoad(Point3D force) {
	m_force = force;
}

Point3D NodalLoad::getForce() const {
	return m_force;
}

}  // namespace fem
