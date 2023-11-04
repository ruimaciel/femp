#ifndef GRADIENT_FIELD_FLYWEIGHT_FACTORY_HPP
#define GRADIENT_FIELD_FLYWEIGHT_FACTORY_HPP

#include <libfemp/AnalysisResult.hpp>
#include <libfemp/ElementResults/ResultsRanges.hpp>
#include <libfemp/Model.hpp>

#include "ConstantGradientFieldPolicy.hpp"
#include "GradientFieldPolicy.hpp"
#include "NeutralGradientFieldPolicy.hpp"
#include "Strain11GradientFieldPolicy.hpp"
#include "Strain12GradientFieldPolicy.hpp"
#include "Strain13GradientFieldPolicy.hpp"
#include "Strain22GradientFieldPolicy.hpp"
#include "Strain23GradientFieldPolicy.hpp"
#include "Strain33GradientFieldPolicy.hpp"
#include "Stress11GradientFieldPolicy.hpp"
#include "Stress12GradientFieldPolicy.hpp"
#include "Stress13GradientFieldPolicy.hpp"
#include "Stress22GradientFieldPolicy.hpp"
#include "Stress23GradientFieldPolicy.hpp"
#include "Stress33GradientFieldPolicy.hpp"
#include "VonMisesGradientFieldPolicy.hpp"

/**
Flyweight actory pattern to store all gradient field policy classes
**/
class GradientFieldFlyweightFactory {
	protected:
	NeutralGradientFieldPolicy m_neutral_policy;  // test pattern
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
	GradientFieldPolicy* neutral();
	GradientFieldPolicy* constant(float value);
	GradientFieldPolicy* strains11();
	GradientFieldPolicy* strains22();
	GradientFieldPolicy* strains33();
	GradientFieldPolicy* strains12();
	GradientFieldPolicy* strains23();
	GradientFieldPolicy* strains13();

	GradientFieldPolicy* stresses11();
	GradientFieldPolicy* stresses22();
	GradientFieldPolicy* stresses33();
	GradientFieldPolicy* stresses12();
	GradientFieldPolicy* stresses23();
	GradientFieldPolicy* stresses13();

	GradientFieldPolicy* vonMises();

	/**
	 * Sets the objects that are needed to access displacements fields and
	 *material info
	 **/
	void setModel(fem::Model& model);
	void setAnalysisResult(fem::AnalysisResult& result);
	void setResultsRanges(fem::ResultsRanges<double>& ranges);
};

#endif
