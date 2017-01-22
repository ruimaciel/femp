#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>

#include <ProjectVisitor/ProjectVisitor.h++>

#include <vector>

/**
This class is intended to describe a FEM project in it's entirely, which includes:
- a FEM model
- a series of analysis results
**/
namespace fem
{

class Project
	: public sigc::trackable
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
	void accept(ProjectVisitor &visitor);
};

}
#endif
