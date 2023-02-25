#include "NoDisplacementsPolicy.h++"

#include <assert.h>

// Constructors/Destructors
//

NoDisplacementsPolicy::NoDisplacementsPolicy() {}

NoDisplacementsPolicy::~NoDisplacementsPolicy() {}

fem::Point3D NoDisplacementsPolicy::operator[](size_t& node_reference) {
	assert(this->m_model != nullptr);

	return this->m_model->getNode(node_reference);
}
