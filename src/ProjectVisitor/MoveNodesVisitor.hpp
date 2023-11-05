#ifndef PROJECTVISITOR_MOVENODESVISITOR_HPP
#define PROJECTVISITOR_MOVENODESVISITOR_HPP

#include "ProjectVisitor.hpp"

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/Node.hpp>
#include <libfemp/Point3D.hpp>

// std includes
#include <set>
#include <vector>

/**
 * Performs a translation on a specific set of nodes
 */
class MoveNodesVisitor : public ProjectVisitor {
	public:
	MoveNodesVisitor(std::set<fem::node_ref_t> selected_nodes, fem::Point3D const& translation);

	void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result) override;

	protected:
	fem::Point3D m_translation;
	std::set<fem::node_ref_t> m_selected_nodes;
};

#endif
