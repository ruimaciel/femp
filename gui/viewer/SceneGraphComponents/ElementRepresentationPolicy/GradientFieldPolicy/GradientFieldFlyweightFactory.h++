#ifndef GRADIENT_FIELD_FLYWEIGHT_FACTORY_HPP
#define GRADIENT_FIELD_FLYWEIGHT_FACTORY_HPP

#include "GradientFieldPolicy.h++"

#include "NeutralGradientFieldPolicy.h++"
#include "ConstantGradientFieldPolicy.h++"
#include "Strain11GradientFieldPolicy.h++"


/**
Flyweight actory pattern to store all gradient field policy classes
**/
class GradientFieldFlyweightFactory
{
protected:
	NeutralGradientFieldPolicy m_neutral_policy;	// test pattern
	ConstantGradientFieldPolicy m_constant_policy;
	Strain11GradientFieldPolicy m_strain11_policy;

public:
	GradientFieldPolicy * neutral();
	GradientFieldPolicy * constant(float value);

	void setMaximumGradientValue (float new_maximum);
	void setMinimumGradientValue (float new_minimum);

	/**
	Sets the objects that are needed to access displacements fields and material info
	**/
	void setModel(fem::Model &model);
	void setAnalysisResult(fem::AnalysisResult<double> &result);
};

#endif
