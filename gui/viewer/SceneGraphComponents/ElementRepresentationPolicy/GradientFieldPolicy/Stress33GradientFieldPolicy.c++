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


float const & 
Stress33GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &ranges)
{
	return ranges.max_stress33;
}


float const & 
Stress33GradientFieldPolicy::minVal(fem::ResultsRanges<double> const &ranges)
{
	return ranges.min_stress33;
}

