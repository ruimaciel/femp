#ifndef OUTPUT_RESULTS_IN_NODES_VISITOR_HPP
#define OUTPUT_RESULTS_IN_NODES_VISITOR_HPP

#include <QTextStream>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/Model.h++>
#include <selection/Selection.h++>

#include "ProjectVisitor.h++"

/**
 * Outputs the results which were calculated in a set of nodes
 */
class OutputResultsInNodesVisitor : public ProjectVisitor {
	public:
	OutputResultsInNodesVisitor(Selection selection, fem::AnalysisResult* result, QTextStream& os);

	void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result);

	protected:
	fem::AnalysisResult* m_result;
	QTextStream* m_out;
	Selection m_selection;
};

#endif
