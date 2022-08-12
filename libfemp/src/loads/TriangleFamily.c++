#include <libfemp/FemException.h++>
#include <libfemp/loads/TriangleFamily.h++>

namespace fem {

TriangleFamily::TriangleFamily() {}

TriangleFamily::~TriangleFamily() {}

enum BaseElement::ElementFamily TriangleFamily::family() const { return BaseElement::EF_TRIANGLE; }

unsigned int TriangleFamily::getDofAmount() const { return 3 * this->getNodeAmount(); }

std::vector<quadrature::SurfaceRule::Point> TriangleFamily::getDomainQuadratureRule() const { return (*m_domain_quadrature_rule)(); }
}  // namespace fem
