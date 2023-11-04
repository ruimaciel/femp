#include "NoDisplacementsPolicy.hpp"

#include <assert.h>

fem::Point3D NoDisplacementsPolicy::operator[](size_t& node_reference) {
	assert(this->m_model != nullptr);

	return this->m_model->getNode(node_reference);
}
