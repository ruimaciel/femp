#ifndef PROJECTVISITOR_OUTPUTELEMENTSTATISTICSVISITOR_HPP
#define PROJECTVISITOR_OUTPUTELEMENTSTATISTICSVISITOR_HPP

#include "ProjectVisitor.hpp"

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Model.hpp>

/**
 * Outputs the results which were calculated in a set of nodes
 */
class OutputElementStatisticsVisitor : public ProjectVisitor {
	public:
	explicit OutputElementStatisticsVisitor();

	void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result) override;

	protected:
};

#endif
