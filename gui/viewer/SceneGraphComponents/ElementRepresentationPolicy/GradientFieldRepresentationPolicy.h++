
#ifndef GRADIENT_FIELDREPRESENTATIONPOLICY_H
#define GRADIENT_FIELDREPRESENTATIONPOLICY_H

#include "ElementRepresentationPolicy.h++"
#include "../../../fem/Element.h++"
#include "../../ViewportColors.h++"


class GradientFieldRepresentationPolicy 
	: virtual public ElementRepresentationPolicy
{
public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	GradientFieldRepresentationPolicy ( );

	/**
	 * Empty Destructor
	 */
	virtual ~GradientFieldRepresentationPolicy ( );


protected:

public:
	/**
	 */
	void tetra4 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void tetra10 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements); 

	/**
	 */
	void hexa8 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void hexa20 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void hexa27 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void prism6 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void prism15 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void prism18 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);


};

#endif // COLORFIELDREPRESENTATIONPOLICY_H
