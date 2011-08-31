#include "DisplacementsPolicy.h++"

// Constructors/Destructors
//  

DisplacementsPolicy::DisplacementsPolicy ( ) 
	: DisplacementsRepresentationPolicy()
{
	this->m_result = NULL;
}


DisplacementsPolicy::~DisplacementsPolicy ( ) 
{ 
}


fem::point 
DisplacementsPolicy::operator[](size_t &node_reference)
{
	assert(this->m_model != NULL);
	assert(this->m_result != NULL);

	return this->m_model->node_list[node_reference] + m_scale * this->m_result->displacements[node_reference];
}


void 
DisplacementsPolicy::setAnalysisResult(fem::AnalysisResult<double> &result)
{
	this->m_result = &result;
}


void 
DisplacementsPolicy::setDisplacementsScale(float scale)
{
	assert(scale >= 0);

	this->m_scale = scale;
}
