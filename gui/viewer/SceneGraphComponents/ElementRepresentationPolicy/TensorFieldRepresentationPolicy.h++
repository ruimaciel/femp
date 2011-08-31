
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
	void tetra4 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void tetra10 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacements); 

	/**
	 */
	void hexa8 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void hexa20 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void hexa27 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void prism6 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void prism15 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */

};

#endif // TENSORFIELDREPRESENTATIONPOLICY_H
