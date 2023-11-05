#include "Project.hpp"

namespace fem {

Project::Project() : m_domainModel(std::make_shared<domain::Model>(m_model)) {}

Project::~Project() {}

void Project::clear() {
	this->m_model.clear();
	this->m_analysisResults.clear();
}

void Project::pushAnalysisResult(fem::AnalysisResult& new_result) {
	this->m_analysisResults.push_back(new_result);
}

fem::Model& Project::getModel() {
	return this->m_model;
}

std::shared_ptr<domain::Model> Project::getDomainModel() {
	return this->m_domainModel;
}

std::vector<fem::AnalysisResult>& Project::getAnalysisResults() {
	return this->m_analysisResults;
}

void Project::accept(ProjectVisitor& visitor) {
	visitor.visit(m_model, m_analysisResults);
}

}  // namespace fem
