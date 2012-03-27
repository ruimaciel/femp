#include "StressFieldRepresentationPolicy.h++"
#include "StressField/StressFieldFactory.h++"

#include <iostream>	// debugging purposes
#include <limits>	// for infinite

// Constructors/Destructors
//  

StressFieldRepresentationPolicy::StressFieldRepresentationPolicy ( ) 
{
	m_model = nullptr;
	m_result = nullptr;
	m_negative_principal_stress_visible = true;
	m_positive_principal_stress_visible = true;

	m_diameter = std::numeric_limits<float>::infinity();	// initial value
}


//  
// Methods
//  

void
StressFieldRepresentationPolicy::tetra4 (fem::element_ref_t const &ref, fem::Element &, ViewportColors &color, DisplacementsRepresentationPolicy *)
{
	assert(m_model != nullptr);
	assert(m_result != nullptr);

	m_representation[ref].render(m_diameter, m_max, m_min, m_positive_principal_stress_visible, m_negative_principal_stress_visible, color);
}


/**
 */
void
StressFieldRepresentationPolicy::tetra10 (fem::element_ref_t const &ref, fem::Element &, ViewportColors &color, DisplacementsRepresentationPolicy * /*displacements*/)
{
	assert(m_model != nullptr);
	assert(m_result != nullptr);

	m_representation[ref].render(m_diameter, m_max, m_min, m_positive_principal_stress_visible, m_negative_principal_stress_visible, color);
}
 

/**
 */
void
StressFieldRepresentationPolicy::hexa8 (fem::element_ref_t const &ref, fem::Element &, ViewportColors &color, DisplacementsRepresentationPolicy * /*displacements*/)
{
	m_representation[ref].render(m_diameter, m_max, m_min, m_positive_principal_stress_visible, m_negative_principal_stress_visible, color);
}


/**
 */
void
StressFieldRepresentationPolicy::hexa20 (fem::element_ref_t const &ref, fem::Element &, ViewportColors &color, DisplacementsRepresentationPolicy * /*displacements*/)
{
	m_representation[ref].render(m_diameter, m_max, m_min, m_positive_principal_stress_visible, m_negative_principal_stress_visible, color);	
}


/**
 */
void
StressFieldRepresentationPolicy::hexa27 (fem::element_ref_t const &ref, fem::Element &, ViewportColors &color, DisplacementsRepresentationPolicy * /*displacements*/)
{
	m_representation[ref].render(m_diameter, m_max, m_min, m_positive_principal_stress_visible, m_negative_principal_stress_visible, color);
}


/**
 */
void
StressFieldRepresentationPolicy::prism6 (fem::element_ref_t const &ref, fem::Element &, ViewportColors &color, DisplacementsRepresentationPolicy * /*displacements*/)
{
	m_representation[ref].render(m_diameter, m_max, m_min, m_positive_principal_stress_visible, m_negative_principal_stress_visible, color);
}


/**
 */
void
StressFieldRepresentationPolicy::prism15 (fem::element_ref_t const &ref, fem::Element &, ViewportColors &color, DisplacementsRepresentationPolicy * /*displacements*/)
{
	m_representation[ref].render(m_diameter, m_max, m_min, m_positive_principal_stress_visible, m_negative_principal_stress_visible, color);
}


/**
 */
void
StressFieldRepresentationPolicy::prism18 (fem::element_ref_t const &ref, fem::Element &, ViewportColors &color, DisplacementsRepresentationPolicy * /*displacements*/)
{
	m_representation[ref].render(m_diameter, m_max, m_min, m_positive_principal_stress_visible, m_negative_principal_stress_visible, color);
}


void 
StressFieldRepresentationPolicy::setModel(fem::Model &model)
{
	m_model = &model;
}


void 
StressFieldRepresentationPolicy::setAnalysisResult(fem::AnalysisResult<double> &result)
{
	m_result = &result;

	// updates all values needed to represent the stress field
	generateData();
}


void 
StressFieldRepresentationPolicy::showNegativePrincipalStressesVisibility(bool state)
{
	m_negative_principal_stress_visible = state;
}


void
StressFieldRepresentationPolicy::showPositivePrincipalStressesVisibility(bool state)
{
	m_positive_principal_stress_visible = state;
}


void 
StressFieldRepresentationPolicy::generateData()
{
	assert(m_model != NULL);

	StressFieldRepresentation::StressFieldFactory factory(m_diameter, *this->m_model, *this->m_result);

	for( std::vector<fem::Element>::size_type n = 0; n < m_model->element_list.size(); n++)
	{
		m_representation[n] = factory(m_model->element_list[n]);
	}

	// updates the maxium positive and negative stresses
	m_max = factory.max();
	m_min = factory.min();
}

