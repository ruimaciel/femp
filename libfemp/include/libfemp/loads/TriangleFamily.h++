#ifndef FEMP_TRIANGLE_FAMILY_HPP
#define FEMP_TRIANGLE_FAMILY_HPP


#include <memory>

#include "../elements/BaseElement.h++"
#include <libfemp/quadrature_rules/Triangle.h++>
#include "SurfaceLoad.h++"


namespace fem
{

class TriangleFamily
		: public SurfaceLoad
{
public:
	std::unique_ptr<quadrature::TriangleRule>	m_domain_quadrature_rule;	// quadrature rule for domain calculations

public:
	TriangleFamily();

	enum BaseElement::ElementFamily family() const;

	virtual int getNodeAmount() const = 0;

	/**
	 * Returns the total number of degrees of freedom
	 **/
	virtual unsigned int getDofAmount() const	{ return 3*this->getNodeAmount(); }

	/**
	Returns a list of quadrature rules
	**/
	std::vector<quadrature::SurfaceRule::Point> getDomainQuadratureRule() const override;
};


}	// namespace fem

#endif