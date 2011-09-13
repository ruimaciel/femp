#include "Stress11GradientFieldPolicy.h++"

#include <assert.h>

#include "../../SceneGraphException.h++"


Stress11GradientFieldPolicy::Stress11GradientFieldPolicy()
{
}


float 
Stress11GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->stresses[p].s11;
}


float 
Stress11GradientFieldPolicy::maxVal()
{
	return this->m_analysis_result->max_stresses.s11;
}


float 
Stress11GradientFieldPolicy::minVal()
{
	return this->m_analysis_result->min_stresses.s11;
}

