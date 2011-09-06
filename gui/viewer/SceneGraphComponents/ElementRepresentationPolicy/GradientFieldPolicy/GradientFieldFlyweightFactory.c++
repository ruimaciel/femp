#include "GradientFieldFlyweightFactory.h++"


GradientFieldPolicy * 
GradientFieldFlyweightFactory::neutral()	
{ 
	return &m_neutral_policy; 
}


GradientFieldPolicy * 
GradientFieldFlyweightFactory::constant(float value)	
{ 
	m_constant_policy.value = value; 
	return &m_constant_policy; 
}


GradientFieldPolicy * 
GradientFieldFlyweightFactory::strains11()
{ 
	return &m_strain11_policy; 
}

GradientFieldPolicy * 
GradientFieldFlyweightFactory::strains22()
{ 
	return &m_strain22_policy; 
}

GradientFieldPolicy * 
GradientFieldFlyweightFactory::strains33()
{ 
	return &m_strain33_policy; 
}


void 
GradientFieldFlyweightFactory::setMaximumGradientValue (float new_maximum)
{
	m_neutral_policy.setMaximumGradientValue(new_maximum);
	m_constant_policy.setMaximumGradientValue(new_maximum);
	m_strain11_policy.setMaximumGradientValue(new_maximum);
	m_strain22_policy.setMaximumGradientValue(new_maximum);
	m_strain33_policy.setMaximumGradientValue(new_maximum);
}


void 
GradientFieldFlyweightFactory::setMinimumGradientValue (float new_minimum)
{
	m_neutral_policy.setMinimumGradientValue(new_minimum);
	m_constant_policy.setMinimumGradientValue(new_minimum);
	m_strain11_policy.setMinimumGradientValue(new_minimum);
	m_strain22_policy.setMinimumGradientValue(new_minimum);
	m_strain33_policy.setMinimumGradientValue(new_minimum);
}


void 
GradientFieldFlyweightFactory::setModel(fem::Model &model)
{
	m_neutral_policy.setModel(model);	// test pattern
	m_constant_policy.setModel(model);

	m_strain11_policy.setModel(model);
	m_strain22_policy.setModel(model);
	m_strain33_policy.setModel(model);
}


void 
GradientFieldFlyweightFactory::setAnalysisResult(fem::AnalysisResult<double> &result)
{
	m_neutral_policy.setAnalysisResult(result);	// test pattern
	m_constant_policy.setAnalysisResult(result);

	m_strain11_policy.setAnalysisResult(result);
	m_strain22_policy.setAnalysisResult(result);
	m_strain33_policy.setAnalysisResult(result);
}

