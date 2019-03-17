#include "Stress33GradientFieldPolicy.h++"

#include <assert.h>

#include "../../SceneGraphException.h++"


Stress33GradientFieldPolicy::Stress33GradientFieldPolicy()
{
}


float 
Stress33GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p) const
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->stresses[p].s33;
}


float 
Stress33GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &ranges) const
{
	return ranges.max_stress33;
}


float 
Stress33GradientFieldPolicy::minVal(fem::ResultsRanges<double> const &ranges) const
{
	return ranges.min_stress33;
}

