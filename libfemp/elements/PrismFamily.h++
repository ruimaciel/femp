#ifndef FEMP_PRISM_FAMILY_HPP
#define FEMP_PRISM_FAMILY_HPP


#include "BaseElement.h++"


namespace fem
{

class PrismFamily
	: public BaseElement
{
public:
	int stiffness_degree;	// Quadrature rule degree to integrate stiffness matrices
	int domain_degree;	// Quadrature rule degree to integrate domain loads

public:
	PrismFamily();

	enum BaseElement::ElementFamily family() const;

	/**
	 * Returns the total number of degrees of freedom
	 **/
	virtual unsigned int getDofAmount() const	{ return 3*this->getNodeAmount(); }

	/**
	Returns a list of
	**/
	std::vector<boost::tuple<fem::Point, double> > getStiffnessQuadratureRule()	{ return this->ipwpl[stiffness_degree]; }
	std::vector<boost::tuple<fem::Point, double> > getDomainQuadratureRule()	{ return this->ipwpl[domain_degree]; }

protected:
	void generateQuadratureData();
};


}


#endif
