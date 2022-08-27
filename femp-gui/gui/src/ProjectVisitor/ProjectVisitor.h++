#ifndef PROJECT_VISITOR_HPP
#define PROJECT_VISITOR_HPP

#include <libfemp/AnalysisResult.h++>
#include <libfemp/Model.h++>
#include <vector>

/**
 * Visitor class that is used to implement a Visitor design pattern for the
 * Project class
 */
class ProjectVisitor {
	public:
	virtual ~ProjectVisitor();
	virtual void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result) = 0;
};

#endif
