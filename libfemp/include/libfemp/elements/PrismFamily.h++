#ifndef FEMP_PRISM_FAMILY_HPP
#define FEMP_PRISM_FAMILY_HPP


#include <memory>

#include "BaseElement.h++"
#include <libfemp/quadrature_rules/Prism.h++>


namespace fem
{

class PrismFamily
		: public BaseElement
{
public:
	int stiffness_degree;	// Quadrature rule degree to integrate stiffness matrices
	int domain_degree;	// Quadrature rule degree to integrate domain loads

	std::unique_ptr<quadrature::PrismRule>	m_stiffness_quadrature_rule;	// quadrature rule for stiffness calculations
	std::unique_ptr<quadrature::PrismRule>	m_domain_quadrature_rule;	// quadrature rule for domain calculations

public:
	PrismFamily();

	enum BaseElement::ElementFamily family() const;

	/**
	 * Returns the total number of degrees of freedom
	 **/
	virtual unsigned int getDofAmount() const;

	/**
	Returns a list of
	**/
	std::vector<boost::tuple<fem::Point3D, double> > getStiffnessQuadratureRule();
	std::vector<boost::tuple<fem::Point3D, double> > getDomainQuadratureRule();

protected:
	void generateQuadratureData();
};


}


#endif
