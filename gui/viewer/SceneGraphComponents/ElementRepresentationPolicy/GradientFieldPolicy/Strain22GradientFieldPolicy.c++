#include "Strain22GradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

#include <libfemp/Point.h++>


Strain22GradientFieldPolicy::Strain22GradientFieldPolicy()
{
	/*
	m_max_value = ranges.max_strain22;
	m_min_value = ranges.min_strain22;
	*/
}


float 
Strain22GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p) const
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->strains[p].e22;
}



float 
Strain22GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &ranges) const
{
	return ranges.max_strain22;
}


float 
Strain22GradientFieldPolicy::minVal(fem::ResultsRanges<double> const &ranges) const
{
	return ranges.min_strain22;
}

