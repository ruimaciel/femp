
#ifndef TENSORFIELDREPRESENTATIONPOLICY_H
#define TENSORFIELDREPRESENTATIONPOLICY_H

#include "ElementRepresentationPolicy.h++"
#include "../../../fem/AnalysisResult.h++"
#include "../../../fem/Element.h++"
#include "../../ViewportColors.h++"


class TensionFieldRepresentationPolicy 
	: virtual public ElementRepresentationPolicy
{
protected:
	fem::Model *m_model;
	fem::AnalysisResult<double> *m_result;

public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	TensionFieldRepresentationPolicy ( );

	/**
	 * Empty Destructor
	 */
	virtual ~TensionFieldRepresentationPolicy ( );


protected:
	void renderTensor(fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color);

public:
	/**
	 */
	void tetra4 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void tetra10 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements); 

	/**
	 */
	void hexa8 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void hexa20 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void hexa27 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void prism6 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void prism15 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);

	/**
	 */
	void prism18 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements);


	void setModel(fem::Model &model);
	void setAnalysisResult(fem::AnalysisResult<double> &result);


};

#endif // TENSORFIELDREPRESENTATIONPOLICY_H
