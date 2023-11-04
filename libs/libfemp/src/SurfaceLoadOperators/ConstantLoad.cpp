#include <libfemp/SurfaceLoadOperators/ConstantLoad.hpp>

namespace fem {

ConstantLoad::ConstantLoad() {}

void ConstantLoad::setLoad(fem::Point3D const& force) {
	this->m_force = force;
}

void ConstantLoad::operator()(fem::SurfaceLoad& surface_load, fem::Model&) {
	surface_load.surface_forces.clear();
	for (unsigned int n = 0; n < surface_load.getNodeAmount(); n++) {
		surface_load.surface_forces.push_back(m_force);
	}
}

}  // namespace fem
