#include "Project.h++"

namespace fem {

Project::Project()
    : m_domainModel(m_model)
{

}

Project::~Project()
{

}

void Project::clear()
{
    this->m_model.clear();
    this->result.clear();
}

void Project::pushAnalysisResult(fem::AnalysisResult& new_result)
{
    this->result.push_back(new_result);
}

Model&
Project::getModel()
{
    return this->m_model;
}

gui::Model & Project::getDomainModel()
{
    return this->m_domainModel;
}

void Project::accept(ProjectVisitor& visitor)
{
    visitor.visit(m_model, result);
}

} // fem
