#include <libfemp/loads/DomainLoad.hpp>

namespace fem {

DomainLoad::DomainLoad() {}

DomainLoad::DomainLoad(const DomainLoad& copied) {
	this->force = copied.force;
}

DomainLoad::~DomainLoad() {}

const Point3D& DomainLoad::getForce() const {
	return this->force;
}

DomainLoad& DomainLoad::operator=(DomainLoad const& copied) {
	this->force = copied.force;
	return *this;
}

}  // namespace fem
