
#ifndef GRADIENT_FIELDREPRESENTATIONPOLICY_H
#define GRADIENT_FIELDREPRESENTATIONPOLICY_H

#include "ElementRepresentationPolicy.h++"
#include "../../../fem/point.h++"
#include "../../../fem/Element.h++"
#include "../../ViewportColors.h++"

#include "GradientFieldPolicy/GradientFieldPolicy.h++"


class GradientFieldRepresentationPolicy 
	: virtual public ElementRepresentationPolicy
{
protected:
	std::vector<fem::point> m_temp_p;
	//typedef std::vector<fem::point>::size_type p_index_t;	// syntactically convenient helper identifier
	typedef unsigned int p_index_t;	// syntactically convenient helper identifier

	GradientFieldPolicy	*m_gradient;	// policy pattern used to calculate and set the gradient values

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
	inline void tri3 (p_index_t p1, p_index_t p2, p_index_t p3, ViewportColors &color);
	inline void tri6 (p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, p_index_t p5, p_index_t p6, ViewportColors &color);
	inline void quad4(p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, ViewportColors &color);
	inline void quad8(p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, p_index_t p5, p_index_t p6, p_index_t p7, p_index_t p8, ViewportColors &color);
	inline void quad9(p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, p_index_t p5, p_index_t p6, p_index_t p7, p_index_t p8, p_index_t p9, ViewportColors &color);


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
