#include "Strain13GradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

#include "../../../../fem/point.h++"


Strain13GradientFieldPolicy::Strain13GradientFieldPolicy()
{
	m_max_value = this->m_analysis_result->max_strains.e13;
	m_min_value = this->m_analysis_result->min_strains.e13;
}


float 
Strain13GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->strains[p].e13;
}


