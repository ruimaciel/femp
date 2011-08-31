
#ifndef TENSORFIELDREPRESENTATIONPOLICY_H
#define TENSORFIELDREPRESENTATIONPOLICY_H

#include "ElementRepresentationPolicy.h++"
#include "../../../fem/Element.h++"
#include "../../ViewportColors.h++"


class TensorFieldRepresentationPolicy 
	: virtual public ElementRepresentationPolicy
{
public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	TensorFieldRepresentationPolicy ( );

	/**
	 * Empty Destructor
	 */
	virtual ~TensorFieldRepresentationPolicy ( );


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

};

#endif // TENSORFIELDREPRESENTATIONPOLICY_H
