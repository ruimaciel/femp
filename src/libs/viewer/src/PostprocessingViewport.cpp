#include <viewer/PostprocessingViewport.hpp>

#include "SceneGraph.hpp"

PostprocessingViewport::PostprocessingViewport(fem::Project& project, fem::AnalysisResult& result, fem::ResultsRanges<double>& ranges, QWidget* parent)
	: BaseViewport(project, parent) {
	this->m_analysis_result = nullptr;
	this->setAnalysisResult(result);
	this->setResultsRanges(ranges);

	this->showDisplacements();

	this->setFocusPolicy(Qt::StrongFocus);
}

PostprocessingViewport::~PostprocessingViewport() {}

void PostprocessingViewport::setAnalysisResult(fem::AnalysisResult& result) {
	this->m_analysis_result = &result;
	this->m_vp_state_displacements.setAnalysisResult(result);
	this->m_vp_state_gradients.setAnalysisResult(result);
}

void PostprocessingViewport::setResultsRanges(fem::ResultsRanges<double>& ranges) {
	this->m_vp_state_gradients.setResultsRanges(ranges);
}

void PostprocessingViewport::showDisplacements() {
	this->setState(&this->m_vp_state_displacements);
}

void PostprocessingViewport::showStrain11() {
	this->m_vp_state_gradients.renderStrains11();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showStrain22() {
	this->m_vp_state_gradients.renderStrains22();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showStrain33() {
	this->m_vp_state_gradients.renderStrains33();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showStrain12() {
	this->m_vp_state_gradients.renderStrains12();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showStrain23() {
	this->m_vp_state_gradients.renderStrains23();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showStrain13() {
	this->m_vp_state_gradients.renderStrains13();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showStress11() {
	this->m_vp_state_gradients.renderStresses11();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showStress22() {
	this->m_vp_state_gradients.renderStresses22();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showStress33() {
	this->m_vp_state_gradients.renderStresses33();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showStress12() {
	this->m_vp_state_gradients.renderStresses12();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showStress23() {
	this->m_vp_state_gradients.renderStresses23();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showStress13() {
	this->m_vp_state_gradients.renderStresses13();
	this->setState(&this->m_vp_state_gradients);
}

void PostprocessingViewport::showVonMises() {
	this->m_vp_state_gradients.renderVonMises();
	this->setState(&this->m_vp_state_gradients);
}
