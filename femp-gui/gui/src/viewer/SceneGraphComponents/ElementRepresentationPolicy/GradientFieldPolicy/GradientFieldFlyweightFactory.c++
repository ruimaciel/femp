#include "GradientFieldFlyweightFactory.h++"

#include <QDebug>

GradientFieldPolicy* GradientFieldFlyweightFactory::neutral() {
	return &m_neutral_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::constant(float value) {
	m_constant_policy.value = value;
	return &m_constant_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::strains11() {
	return &m_strain11_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::strains22() {
	return &m_strain22_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::strains33() {
	return &m_strain33_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::strains12() {
	return &m_strain12_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::strains23() {
	return &m_strain23_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::strains13() {
	return &m_strain13_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::stresses11() {
	return &m_stress11_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::stresses22() {
	return &m_stress22_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::stresses33() {
	return &m_stress33_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::stresses12() {
	return &m_stress12_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::stresses23() {
	return &m_stress23_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::stresses13() {
	return &m_stress13_policy;
}

GradientFieldPolicy* GradientFieldFlyweightFactory::vonMises() {
	return &m_von_mises_policy;
}

void GradientFieldFlyweightFactory::setModel(fem::Model& model) {
	m_neutral_policy.setModel(model);  // test pattern
	m_constant_policy.setModel(model);

	m_strain11_policy.setModel(model);
	m_strain22_policy.setModel(model);
	m_strain33_policy.setModel(model);
	m_strain12_policy.setModel(model);
	m_strain23_policy.setModel(model);
	m_strain13_policy.setModel(model);

	m_stress11_policy.setModel(model);
	m_stress22_policy.setModel(model);
	m_stress33_policy.setModel(model);
	m_stress12_policy.setModel(model);
	m_stress23_policy.setModel(model);
	m_stress13_policy.setModel(model);

	m_von_mises_policy.setModel(model);
}

void GradientFieldFlyweightFactory::setAnalysisResult(fem::AnalysisResult& result) {
	qInfo() << "GradientFieldFlyweightFactory::setAnalysisResult(fem::"
			   "AnalysisResult &result)";

	m_neutral_policy.setAnalysisResult(result);	 // test pattern
	m_constant_policy.setAnalysisResult(result);

	m_strain11_policy.setAnalysisResult(result);
	m_strain22_policy.setAnalysisResult(result);
	m_strain33_policy.setAnalysisResult(result);
	m_strain12_policy.setAnalysisResult(result);
	m_strain23_policy.setAnalysisResult(result);
	m_strain13_policy.setAnalysisResult(result);

	m_stress11_policy.setAnalysisResult(result);
	m_stress22_policy.setAnalysisResult(result);
	m_stress33_policy.setAnalysisResult(result);
	m_stress12_policy.setAnalysisResult(result);
	m_stress23_policy.setAnalysisResult(result);
	m_stress13_policy.setAnalysisResult(result);

	m_von_mises_policy.setAnalysisResult(result);
}

void GradientFieldFlyweightFactory::setResultsRanges(fem::ResultsRanges<double>& ranges) {
	qInfo() << "GradientFieldFlyweightFactory::setResultsRanges(fem::"
			   "ResultsRanges<double> &ranges)";

	m_neutral_policy.setResultsRanges(ranges);	// test pattern
	m_constant_policy.setResultsRanges(ranges);

	m_strain11_policy.setResultsRanges(ranges);
	m_strain22_policy.setResultsRanges(ranges);
	m_strain33_policy.setResultsRanges(ranges);
	m_strain12_policy.setResultsRanges(ranges);
	m_strain23_policy.setResultsRanges(ranges);
	m_strain13_policy.setResultsRanges(ranges);

	m_stress11_policy.setResultsRanges(ranges);
	m_stress22_policy.setResultsRanges(ranges);
	m_stress33_policy.setResultsRanges(ranges);
	m_stress12_policy.setResultsRanges(ranges);
	m_stress23_policy.setResultsRanges(ranges);
	m_stress13_policy.setResultsRanges(ranges);

	m_von_mises_policy.setResultsRanges(ranges);
}
