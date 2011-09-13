#include "VonMisesGradientFieldPolicy.h++"

#include <assert.h>

#include "../../SceneGraphException.h++"


VonMisesGradientFieldPolicy::VonMisesGradientFieldPolicy()
{
}


float 
VonMisesGradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->von_mises[p];
}


float 
VonMisesGradientFieldPolicy::maxVal()
{
	return this->m_analysis_result->max_von_mises;
}


float 
VonMisesGradientFieldPolicy::minVal()
{
	return this->m_analysis_result->min_von_mises;
}


