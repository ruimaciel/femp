#include <libfemp/loads/QuadrangleFamily.h++>


#include <libfemp/FemException.h++>


namespace fem
{


QuadrangleFamily::QuadrangleFamily()
{
}


enum BaseElement::ElementFamily
QuadrangleFamily::family() const
{
	return BaseElement::EF_QUADRILATERAL;
}

unsigned int
QuadrangleFamily::getDofAmount() const
{
	return 3*this->getNodeAmount();
}


std::vector<quadrature::SurfaceRule::Point> QuadrangleFamily::getDomainQuadratureRule() const
{
	return (*m_domain_quadrature_rule)();
}


}	// namespace fem

