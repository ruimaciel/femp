#ifndef PROJECT_HPP
#define PROJECT_HPP

#include "Model.h++"
#include "AnalysisResult.h++"
#include "ProjectVisitor/ProjectVisitor.h++"

#include <vector>

/**
This class is intended to describe a FEM project in it's entirely, which includes:
- a FEM model
- a series of analysis results
**/
namespace fem
{

class Project
{
public:
	Model model;	// the FEM model
	std::vector<AnalysisResult<double> > result;	// a list with all analysis
		
public:
	void clear();
	
	/**
	Adds the result of a new analysis process to the result list
	**/
	void pushAnalysisResult(fem::AnalysisResult<double> &new_result);

	/**
	Implements a Visitor design pattern
	**/
	void Accept(ProjectVisitor &visitor);
};

}
#endif
