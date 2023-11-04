#include <libfemp/FemException.hpp>
#include <libfemp/loads/TriangleFamily.hpp>

namespace fem {

TriangleFamily::TriangleFamily() {}

TriangleFamily::~TriangleFamily() {}

enum BaseElement::ElementFamily TriangleFamily::family() const {
	return BaseElement::EF_TRIANGLE;
}

unsigned int TriangleFamily::getDofAmount() const {
	return 3 * this->getNodeAmount();
}

std::vector<quadrature::SurfaceRule::Point> TriangleFamily::getDomainQuadratureRule() const {
	return (*m_domain_quadrature_rule)();
}
}  // namespace fem
