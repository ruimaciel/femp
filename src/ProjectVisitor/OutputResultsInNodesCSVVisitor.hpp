#ifndef FEMP_PROJECTVISITOR_OUTPUTRESULTSINNODESCSVVISITOR_HPP
#define FEMP_PROJECTVISITOR_OUTPUTRESULTSINNODESCSVVISITOR_HPP

#include "ProjectVisitor.hpp"

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Model.hpp>

// Qt includes
#include <QTextStream>

// stl includes
#include <set>
#include <vector>

/**
 * Outputs the results which were calculated in a set of nodes in CSV format
 */
class OutputResultsInNodesCSVVisitor : public ProjectVisitor {
	public:
	OutputResultsInNodesCSVVisitor(std::set<fem::node_ref_t> selected_nodes, fem::AnalysisResult* result, QTextStream& os);

	void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result) override;

	protected:
	fem::AnalysisResult* m_result;
	QTextStream* m_out;
	std::set<fem::node_ref_t> m_selected_nodes;
};

#endif
