#ifndef PROJECTVISITOR_PROJECTVISITOR_HPP
#define PROJECTVISITOR_PROJECTVISITOR_HPP

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Model.hpp>

// stl includes
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
