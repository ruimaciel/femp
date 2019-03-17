#include "Strain12GradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

#include <libfemp/Point3D.h++>


Strain12GradientFieldPolicy::Strain12GradientFieldPolicy()
{
	/*
	m_max_value = ranges.max_strain12;
	m_min_value = ranges.min_strain12;
	*/
}


float 
Strain12GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p) const
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->strains[p].e12;
}



float 
Strain12GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &ranges) const
{
	return ranges.max_strain12;
}


float 
Strain12GradientFieldPolicy::minVal(fem::ResultsRanges<double> const &ranges) const
{
	return ranges.min_strain12;
}

