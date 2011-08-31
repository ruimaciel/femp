
#ifndef ELEMENTREPRESENTATIONPOLICY_H
#define ELEMENTREPRESENTATIONPOLICY_H


#include "../DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"
#include "../../../fem/Element.h++"
#include "../../ViewportColors.h++"


/**
Defines a policy to represent elements according to specific criteria.
Each member function runs a set of OpenGL commands.
**/
class ElementRepresentationPolicy
{
protected:
	DisplacementsRepresentationPolicy *m_displacement;

public:
	void setDisplacementPolicy(DisplacementsRepresentationPolicy *displacement);

	/**
	 */
	virtual void tetra4 (fem::Element &element, ViewportColor &color) = 0;

	/**
	 */
	virtual void tetra10 (fem::Element &element, ViewportColor &color) = 0; 

	/**
	 */
	virtual void hexa8 (fem::Element &element, ViewportColor &color) = 0;

	/**
	 */
	virtual void hexa20 (fem::Element &element, ViewportColor &color) = 0;

	/**
	 */
	virtual void hexa27 (fem::Element &element, ViewportColor &color) = 0;

	/**
	 */
	virtual void prism6 (fem::Element &element, ViewportColor &color) = 0;

	/**
	 */
	virtual void prism15 (fem::Element &element, ViewportColor &color) = 0;

	/**
	 */
	virtual void prism18 (fem::Element &element, ViewportColor &color) = 0;

};

#endif // ELEMENTREPRESENTATIONPOLICY_H
