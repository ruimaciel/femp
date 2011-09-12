
#ifndef GRADIENT_FIELDREPRESENTATIONPOLICY_H
#define GRADIENT_FIELDREPRESENTATIONPOLICY_H

#include "ElementRepresentationPolicy.h++"
#include "../../../fem/point.h++"
#include "../../../fem/Element.h++"
#include "../../ViewportColors.h++"

#include "GradientFieldPolicy/GradientFieldPolicy.h++"
#include "GradientFieldPolicy/GradientFieldFlyweightFactory.h++"


/**
Represents elements in the scene with a gradient field defined by GradientFieldPolicy, a policy pattern
**/
class GradientFieldRepresentationPolicy 
	: virtual public ElementRepresentationPolicy
{
protected:
	std::vector<fem::point> m_temp_p;
	//typedef std::vector<fem::point>::size_type p_index_t;	// syntactically convenient helper identifier
	typedef unsigned int p_index_t;	// syntactically convenient helper identifier

	GradientFieldPolicy	*m_gradient;	// policy pattern used to calculate and set the gradient values
	GradientFieldFlyweightFactory m_gradient_flyweight_factory;

public:
	GradientFieldRepresentationPolicy ( );
	virtual ~GradientFieldRepresentationPolicy ( );


protected:
	inline void tri3 (fem::element_ref_t const &ref, p_index_t p1, p_index_t p2, p_index_t p3, ViewportColors &colors);
	inline void tri6 (fem::element_ref_t const &ref, p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, p_index_t p5, p_index_t p6, ViewportColors &colors);
	inline void quad4(fem::element_ref_t const &ref, p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, ViewportColors &colors);
	inline void quad8(fem::element_ref_t const &ref, p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, p_index_t p5, p_index_t p6, p_index_t p7, p_index_t p8, ViewportColors &colors);
	inline void quad9(fem::element_ref_t const &ref, p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, p_index_t p5, p_index_t p6, p_index_t p7, p_index_t p8, p_index_t p9, ViewportColors &colors);


public:
	/**
	 */
	void tetra4 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);
	void tetra10 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements); 
	void hexa8 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);
	void hexa20 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);
	void hexa27 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);
	void prism6 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);
	void prism15 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);
	void prism18 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	sets the gradient rendering policy 
	**/
	void renderNeutral();
	void renderConstant(float value);
	void renderStrains11();
	void renderStrains22();
	void renderStrains33();
	void renderStrains12();
	void renderStrains23();
	void renderStrains13();

	/**
	Sets the rendering limits
	**/
	void setMaximumGradientValue (float new_maximum);
	void setMinimumGradientValue (float new_minimum);

	/**
	Sets the objects that are needed to access displacements fields and material info
	**/
	void setModel(fem::Model &model);
	void setAnalysisResult(fem::AnalysisResult<double> &result);
};

#endif // COLORFIELDREPRESENTATIONPOLICY_H
