#ifndef FEMP_QUADRANGLE_FAMILY_HPP
#define FEMP_QUADRANGLE_FAMILY_HPP


#include <memory>

#include "../elements/BaseElement.h++"
#include <libfemp/quadrature_rules/Quadrangle.h++>
#include "SurfaceLoad.h++"


namespace fem
{

class QuadrangleFamily
		: public SurfaceLoad
{
public:
	std::unique_ptr<quadrature::QuadrangleRule>	m_domain_quadrature_rule;	// quadrature rule for domain calculations

public:
	QuadrangleFamily();

	enum BaseElement::ElementFamily family() const;

	virtual int getNodeAmount() const = 0;

	/**
	 * Returns the total number of degrees of freedom
	 **/
	virtual unsigned int getDofAmount() const;

	/**
	Returns a list of quadrature rules
	**/
	std::vector<quadrature::SurfaceRule::Point> getDomainQuadratureRule() const override;
};


}	// namespace fem

#endif
