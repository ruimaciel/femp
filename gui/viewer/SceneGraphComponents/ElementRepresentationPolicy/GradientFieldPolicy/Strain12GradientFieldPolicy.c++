#include "Strain12GradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

#include "../../../../fem/point.h++"


Strain12GradientFieldPolicy::Strain12GradientFieldPolicy()
{
	/*
	m_max_value = ranges.max_strain12;
	m_min_value = ranges.min_strain12;
	*/
}


float 
Strain12GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->strains[p].e12;
}



float const & 
Strain12GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &ranges)
{
	return ranges.max_strain12;
}


float const & 
Strain12GradientFieldPolicy::minVal(fem::ResultsRanges<double> const &ranges)
{
	return ranges.min_strain12;
}

