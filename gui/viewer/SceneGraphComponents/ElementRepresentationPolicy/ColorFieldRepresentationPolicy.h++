
#ifndef COLORFIELDREPRESENTATIONPOLICY_H
#define COLORFIELDREPRESENTATIONPOLICY_H

#include "ElementRepresentationPolicy.h++"
#include "../../../fem/Element.h++"
#include "../../ViewportColors.h++"


class ColorFieldRepresentationPolicy 
	: virtual public ElementRepresentationPolicy
{
public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	ColorFieldRepresentationPolicy ( );

	/**
	 * Empty Destructor
	 */
	virtual ~ColorFieldRepresentationPolicy ( );


protected:

public:
	/**
	 */
	void tetra4 (fem::Element &element, ViewportColor &color);

	/**
	 */
	void tetra10 (fem::Element &element, ViewportColor &color); 

	/**
	 */
	void hexa8 (fem::Element &element, ViewportColor &color);

	/**
	 */
	void hexa20 (fem::Element &element, ViewportColor &color);

	/**
	 */
	void hexa27 (fem::Element &element, ViewportColor &color);

	/**
	 */
	void prism6 (fem::Element &element, ViewportColor &color);

	/**
	 */
	void prism15 (fem::Element &element, ViewportColor &color);

	/**
	 */
	void prism18 (fem::Element &element, ViewportColor &color);


};

#endif // COLORFIELDREPRESENTATIONPOLICY_H
