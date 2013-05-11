
#ifndef OPAQUEREPRESENTATIONPOLICY_H
#define OPAQUEREPRESENTATIONPOLICY_H

#include "ElementRepresentationPolicy.h++"
#include "../../../fem/point.h++"
#include "../../../fem/Element.h++"
#include "../../ViewportColors.h++"


class OpaqueRepresentationPolicy 
	: virtual public ElementRepresentationPolicy
{
protected:
	std::vector<fem::point> m_temp_p;
	bool m_triangle_wireframe_representation;

public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	OpaqueRepresentationPolicy ( );

	/**
	 * Empty Destructor
	 */

protected:
	inline void tri3 (fem::point &p1, fem::point &p2, fem::point &p3, ViewportColors &color);
	inline void tri6 (fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4, fem::point &p5, fem::point &p6, ViewportColors &color);
	inline void quad4(fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4, ViewportColors &color);
	inline void quad8(fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4, fem::point &p5, fem::point &p6, fem::point &p7, fem::point &p8, ViewportColors &color);
	inline void quad9(fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4, fem::point &p5, fem::point &p6, fem::point &p7, fem::point &p8, fem::point &p9, ViewportColors &color);

public:
	/**
	 */
	void tetra4 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement);

	/**
	 */
	void tetra10 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement); 

	/**
	 */
	void hexa8 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement);

	/**
	 */
	void hexa20 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement);

	/**
	 */
	void hexa27 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement);

	/**
	 */
	void prism6 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement);

	/**
	 */
	void prism15 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement);

	/**
	 */
	void prism18 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement);


	/**
	Toggles the OpenGL wireframe representation
	**/
	void setTriangleWireframeRendering(bool const state);
	void toggleTriangleWireframeRendering();
};

#endif // OPAQUEREPRESENTATIONPOLICY_H
