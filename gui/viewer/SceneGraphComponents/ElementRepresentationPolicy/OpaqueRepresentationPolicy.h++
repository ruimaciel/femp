
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
	virtual ~OpaqueRepresentationPolicy ( );


protected:
	inline void tri3 (fem::point &p1, fem::point &p2, fem::point &p3, ViewportColor &color);
	inline void tri6 (fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4, fem::point &p5, fem::point &p6, ViewportColor &color);
	inline void quad4(fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4, ViewportColor &color);
	inline void quad8(fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4, fem::point &p5, fem::point &p6, fem::point &p7, fem::point &p8, ViewportColor &color);
	inline void quad9(fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4, fem::point &p5, fem::point &p6, fem::point &p7, fem::point &p8, fem::point &p9, ViewportColor &color);

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

#endif // OPAQUEREPRESENTATIONPOLICY_H
