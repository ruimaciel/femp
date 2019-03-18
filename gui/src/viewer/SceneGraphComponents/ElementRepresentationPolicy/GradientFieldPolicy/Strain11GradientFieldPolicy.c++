#include "Strain11GradientFieldPolicy.h++"

#include <assert.h>

#include "../../SceneGraphException.h++"

#include <libfemp/Point3D.h++>


Strain11GradientFieldPolicy::Strain11GradientFieldPolicy()
{
	/*
	assert(m_analysis_result != NULL);
	m_max_value = ranges.max_strain11;
	m_min_value = ranges.min_strain11;
	*/
}


float 
Strain11GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p) const
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->strains[p].e11;
}


float 
Strain11GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &ranges) const
{
	return ranges.max_strain11;
}


float 
Strain11GradientFieldPolicy::minVal(fem::ResultsRanges<double> const &ranges) const
{
	return ranges.min_strain11;
}
