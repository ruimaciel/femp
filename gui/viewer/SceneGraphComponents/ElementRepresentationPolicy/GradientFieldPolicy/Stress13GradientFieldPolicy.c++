#include "Stress13GradientFieldPolicy.h++"

#include <assert.h>

#include "../../SceneGraphException.h++"


Stress13GradientFieldPolicy::Stress13GradientFieldPolicy()
{
}


float 
Stress13GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->stresses[p].s13;
}


float const & 
Stress13GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &ranges)
{
	return ranges.max_stress13;
}


float const & 
Stress13GradientFieldPolicy::minVal(fem::ResultsRanges<double> const &ranges)
{
	return ranges.min_stress13;
}

