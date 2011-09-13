#include "Strain33GradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

#include "../../../../fem/point.h++"


Strain33GradientFieldPolicy::Strain33GradientFieldPolicy()
{
	/*
	m_max_value = this->m_analysis_result->max_strains.e33;
	m_min_value = this->m_analysis_result->min_strains.e33;
	*/
}


float 
Strain33GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->m_analysis_result->results[ref]->strains[p].e33;
}



float 
Strain33GradientFieldPolicy::maxVal()
{
	return this->m_analysis_result->max_strains.e33;
}


float 
Strain33GradientFieldPolicy::minVal()
{
	return this->m_analysis_result->min_strains.e33;
}

