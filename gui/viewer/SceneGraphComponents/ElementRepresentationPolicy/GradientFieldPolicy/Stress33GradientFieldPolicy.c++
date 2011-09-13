#include "Stress33GradientFieldPolicy.h++"

#include <assert.h>

#include "../../SceneGraphException.h++"


Stress33GradientFieldPolicy::Stress33GradientFieldPolicy()
{
}


float 
Stress33GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->stresses[p].s33;
}


float 
Stress33GradientFieldPolicy::maxVal()
{
	return this->m_analysis_result->max_stresses.s33;
}


float 
Stress33GradientFieldPolicy::minVal()
{
	return this->m_analysis_result->min_stresses.s33;
}

