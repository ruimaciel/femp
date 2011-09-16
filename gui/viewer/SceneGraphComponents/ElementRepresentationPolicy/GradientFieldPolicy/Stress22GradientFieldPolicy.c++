#include "Stress22GradientFieldPolicy.h++"

#include <assert.h>

#include "../../SceneGraphException.h++"


Stress22GradientFieldPolicy::Stress22GradientFieldPolicy()
{
}


float 
Stress22GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->stresses[p].s22;
}


float 
Stress22GradientFieldPolicy::maxVal()
{
	return this->m_analysis_result->ranges.max_stress22;
}


float 
Stress22GradientFieldPolicy::minVal()
{
	return this->m_analysis_result->ranges.min_stress22;
}

