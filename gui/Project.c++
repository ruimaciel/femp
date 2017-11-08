#include "Project.h++"


namespace fem
{


void 
Project::clear()
{
	this->model.clear();
	this->result.clear();
}


void 
Project::pushAnalysisResult(fem::AnalysisResult &new_result)
{
	this->result.push_back(new_result);
}


Model & 
Project::getModel()
{
	return this->model;
}


void 
Project::accept(ProjectVisitor &visitor)
{
	visitor.visit(model,result);
}


}	// fem

