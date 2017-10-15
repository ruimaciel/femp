#ifndef FEMP_TRIANGLE_FAMILY_HPP
#define FEMP_TRIANGLE_FAMILY_HPP


#include "BaseElement.h++"


namespace fem
{

class TriangleFamily
	: public BaseElement
{
public:
	TriangleFamily();

	enum BaseElement::ElementFamily family() const;

	/**
	 * Returns the total number of degrees of freedom
	 **/
	virtual unsigned int getDofAmount() const	{ return 3*this->getNodeAmount(); }

protected:
	void generateQuadratureData();
};


}

#endif
