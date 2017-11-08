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
	void clear();
	
	/**
	Adds the result of a new analysis process to the result list
	**/
	void pushAnalysisResult(fem::AnalysisResult &new_result);

	/**
	 * returns a reference to the Project's model
	 **/
	Model & getModel();

	/**
	Implements a Visitor design pattern
	**/
	void accept(ProjectVisitor &visitor);

protected:
	Model model;	// the FEM model

public:
	std::vector<AnalysisResult> result;	// a list with all analysis
		
};

}	// namespace fem

#endif
