#ifndef GRADIENT_FIELD_FLYWEIGHT_FACTORY_HPP
#define GRADIENT_FIELD_FLYWEIGHT_FACTORY_HPP

#include "GradientFieldPolicy.h++"


#include "NeutralGradientFieldPolicy.h++"
#include "ConstantGradientFieldPolicy.h++"
#include "Strain11GradientFieldPolicy.h++"
#include "Strain22GradientFieldPolicy.h++"
#include "Strain33GradientFieldPolicy.h++"
#include "Strain12GradientFieldPolicy.h++"
#include "Strain23GradientFieldPolicy.h++"
#include "Strain13GradientFieldPolicy.h++"

#include "Stress11GradientFieldPolicy.h++"
#include "Stress22GradientFieldPolicy.h++"
#include "Stress33GradientFieldPolicy.h++"
#include "Stress12GradientFieldPolicy.h++"
#include "Stress23GradientFieldPolicy.h++"
#include "Stress13GradientFieldPolicy.h++"

#include "VonMisesGradientFieldPolicy.h++"

#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/ElementResults/ResultsRanges.h++>


/**
Flyweight actory pattern to store all gradient field policy classes
**/
class GradientFieldFlyweightFactory
{
protected:
	NeutralGradientFieldPolicy m_neutral_policy;	// test pattern
	ConstantGradientFieldPolicy m_constant_policy;
	Strain11GradientFieldPolicy m_strain11_policy;
	Strain22GradientFieldPolicy m_strain22_policy;
	Strain33GradientFieldPolicy m_strain33_policy;
	Strain12GradientFieldPolicy m_strain12_policy;
	Strain23GradientFieldPolicy m_strain23_policy;
	Strain13GradientFieldPolicy m_strain13_policy;

	Stress11GradientFieldPolicy m_stress11_policy;
	Stress22GradientFieldPolicy m_stress22_policy;
	Stress33GradientFieldPolicy m_stress33_policy;
	Stress12GradientFieldPolicy m_stress12_policy;
	Stress23GradientFieldPolicy m_stress23_policy;
	Stress13GradientFieldPolicy m_stress13_policy;

	VonMisesGradientFieldPolicy m_von_mises_policy;

public:
	GradientFieldPolicy * neutral();
	GradientFieldPolicy * constant(float value);
	GradientFieldPolicy * strains11();
	GradientFieldPolicy * strains22();
	GradientFieldPolicy * strains33();
	GradientFieldPolicy * strains12();
	GradientFieldPolicy * strains23();
	GradientFieldPolicy * strains13();

	GradientFieldPolicy * stresses11();
	GradientFieldPolicy * stresses22();
	GradientFieldPolicy * stresses33();
	GradientFieldPolicy * stresses12();
	GradientFieldPolicy * stresses23();
	GradientFieldPolicy * stresses13();

	GradientFieldPolicy * vonMises();

	/**
	Sets the objects that are needed to access displacements fields and material info
	**/
	void setModel(fem::Model &model);
	void setAnalysisResult(fem::AnalysisResult<double> &result);
	void setResultsRanges(fem::ResultsRanges<double> &ranges);
};

#endif
