#ifndef PROJECTVISITOR_OUTPUTELEMENTSTATISTICSVISITOR_HPP
#define PROJECTVISITOR_OUTPUTELEMENTSTATISTICSVISITOR_HPP

#include "ProjectVisitor.hpp"

// services includes
#include <selection/Selection.hpp>

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Model.hpp>

// Qt includes
#include <QTextStream>

// stl includes
#include <vector>

/**
 * Outputs the results which were calculated in a set of nodes
 */
class OutputElementStatisticsVisitor : public ProjectVisitor {
	public:
	explicit OutputElementStatisticsVisitor(Selection selection);

	void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result) override;

	protected:
	Selection m_selection;
};

#endif
