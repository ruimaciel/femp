#ifndef FEMP_PRISM_FAMILY_HPP
#define FEMP_PRISM_FAMILY_HPP


#include "BaseElement.h++"


namespace fem
{

struct PrismFamily
	: public BaseElement
{
	PrismFamily();

	enum BaseElement::ElementFamily family() const;

	/**
	 * Returns the total number of degrees of freedom
	 **/
	virtual unsigned int getDofAmount() const	{ return 3*this->node_number(); }

protected:
	void generateQuadratureData();
};


}


#endif
