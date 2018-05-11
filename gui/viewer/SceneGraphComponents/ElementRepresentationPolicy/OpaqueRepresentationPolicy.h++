
#ifndef OPAQUEREPRESENTATIONPOLICY_H
#define OPAQUEREPRESENTATIONPOLICY_H

#include "ElementRepresentationPolicy.h++"
#include <libfemp/Point3D.h++>
#include <libfemp/Element.h++>
#include <gui/options/Options.h++>


class OpaqueRepresentationPolicy 
	: virtual public ElementRepresentationPolicy
{
protected:
	std::vector<fem::Point3D> m_temp_p;
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
	inline void tri3 (fem::Point3D &p1, fem::Point3D &p2, fem::Point3D &p3, ViewportColors &color);
	inline void tri6 (fem::Point3D &p1, fem::Point3D &p2, fem::Point3D &p3, fem::Point3D &p4, fem::Point3D &p5, fem::Point3D &p6, ViewportColors &color);
	inline void quad4(fem::Point3D &p1, fem::Point3D &p2, fem::Point3D &p3, fem::Point3D &p4, ViewportColors &color);
	inline void quad8(fem::Point3D &p1, fem::Point3D &p2, fem::Point3D &p3, fem::Point3D &p4, fem::Point3D &p5, fem::Point3D &p6, fem::Point3D &p7, fem::Point3D &p8, ViewportColors &color);
	inline void quad9(fem::Point3D &p1, fem::Point3D &p2, fem::Point3D &p3, fem::Point3D &p4, fem::Point3D &p5, fem::Point3D &p6, fem::Point3D &p7, fem::Point3D &p8, fem::Point3D &p9, ViewportColors &color);

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
