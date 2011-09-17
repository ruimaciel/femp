#include "NeutralGradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

NeutralGradientFieldPolicy::NeutralGradientFieldPolicy()
{
}


float 
NeutralGradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return 0;
}


float const &
NeutralGradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &ranges)
{
	return 1;
}


float const & 
NeutralGradientFieldPolicy::minVal(fem::ResultsRanges<double> const &ranges)
{
	return -1;
}

