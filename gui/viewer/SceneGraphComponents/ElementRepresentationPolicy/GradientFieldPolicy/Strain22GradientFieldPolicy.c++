#include "Strain22GradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

#include "../../../../fem/point.h++"


Strain22GradientFieldPolicy::Strain22GradientFieldPolicy()
{
	/*
	m_max_value = this->m_analysis_result->ranges.max_strain22;
	m_min_value = this->m_analysis_result->ranges.min_strain22;
	*/
}


float 
Strain22GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->strains[p].e22;
}



float 
Strain22GradientFieldPolicy::maxVal()
{
	return this->m_analysis_result->ranges.max_strain22;
}


float 
Strain22GradientFieldPolicy::minVal()
{
	return this->m_analysis_result->ranges.min_strain22;
}

