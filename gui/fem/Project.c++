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
Project::pushAnalysisResult(fem::AnalysisResult<double> &new_result)
{
	this->result.push_back(new_result);
}


}
