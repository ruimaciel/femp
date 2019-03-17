
#ifndef GRADIENT_FIELDREPRESENTATIONPOLICY_H
#define GRADIENT_FIELDREPRESENTATIONPOLICY_H

#include "ElementRepresentationPolicy.h++"

#include <libfemp/Point3D.h++>
#include <libfemp/Element.h++>
#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/ElementResults/ResultsRanges.h++>

#include <options/Options.h++>

#include "GradientFieldPolicy/GradientFieldPolicy.h++"
#include "GradientFieldPolicy/GradientFieldFlyweightFactory.h++"


/**
Represents elements in the scene with a gradient field defined by GradientFieldPolicy, a policy pattern
**/
class GradientFieldRepresentationPolicy 
	: virtual public ElementRepresentationPolicy
{
protected:
	std::vector<fem::Point3D> m_temp_p;
	//typedef std::vector<fem::Point>::size_type p_index_t;	// syntactically convenient helper identifier
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

	void renderStresses11();
	void renderStresses22();
	void renderStresses33();
	void renderStresses12();
	void renderStresses23();
	void renderStresses13();

	void renderVonMises();

	/**
	Sets the objects that are needed to access displacements fields and material info
	**/
	void setModel(fem::Model &model);
	void setAnalysisResult(fem::AnalysisResult &result);
	void setResultsRanges(fem::ResultsRanges<double> &ranges);
};

#endif // COLORFIELDREPRESENTATIONPOLICY_H
