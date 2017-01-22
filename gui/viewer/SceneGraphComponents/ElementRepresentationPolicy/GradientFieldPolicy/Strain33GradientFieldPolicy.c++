#include "Strain33GradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

#include <libfemp/Point.h++>


Strain33GradientFieldPolicy::Strain33GradientFieldPolicy()
{
	/*
	m_max_value = ranges.max_strain33;
	m_min_value = ranges.min_strain33;
	*/
}


float 
Strain33GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p) const
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->strains[p].e33;
}



float 
Strain33GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &ranges) const
{
	return ranges.max_strain33;
}


float 
Strain33GradientFieldPolicy::minVal(fem::ResultsRanges<double> const &ranges) const
{
	return ranges.min_strain33;
}

