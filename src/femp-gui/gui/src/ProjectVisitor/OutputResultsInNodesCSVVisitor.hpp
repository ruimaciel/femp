#ifndef PROJECTVISITOR_OUTPUTRESULTSINNODESCSVVISITOR_HPP
#define PROJECTVISITOR_OUTPUTRESULTSINNODESCSVVISITOR_HPP

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
 * Outputs the results which were calculated in a set of nodes in CSV format
 */
class OutputResultsInNodesCSVVisitor : public ProjectVisitor {
	public:
	OutputResultsInNodesCSVVisitor(Selection selection, fem::AnalysisResult* result, QTextStream& os);

	void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result) override;

	protected:
	fem::AnalysisResult* m_result;
	QTextStream* m_out;
	Selection m_selection;
};

#endif
