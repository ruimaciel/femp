#ifndef PROJECT_VISITOR_HPP
#define PROJECT_VISITOR_HPP

#include <vector>

#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>

/**
Visitor class that is used to implement a Visitor design pattern for the Project class
**/
class ProjectVisitor
{
public:
	virtual void visit(fem::Model &model, std::vector<fem::AnalysisResult<double> > &result) = 0;
};

#endif
