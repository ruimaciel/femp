#include <libfemp/loads/TriangleFamily.h++>


#include <libfemp/FemException.h++>


namespace fem
{


TriangleFamily::TriangleFamily()
{
}


enum BaseElement::ElementFamily
TriangleFamily::family() const
{
	return BaseElement::EF_TRIANGLE;
}


std::vector<quadrature::SurfaceRule::Point>
TriangleFamily::getDomainQuadratureRule() const
{
	return (*m_domain_quadrature_rule)();
}

}

