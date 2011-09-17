#include "Strain23GradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

#include "../../../../fem/point.h++"


Strain23GradientFieldPolicy::Strain23GradientFieldPolicy()
{
	/*
	m_max_value = ranges.max_strain23;
	m_min_value = ranges.min_strain23;
	*/
}


float 
Strain23GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->strains[p].e23;
}



float const & 
Strain23GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &ranges)
{
	return ranges.max_strain23;
}


float const & 
Strain23GradientFieldPolicy::minVal(fem::ResultsRanges<double> const &ranges)
{
	return ranges.min_strain23;
}

