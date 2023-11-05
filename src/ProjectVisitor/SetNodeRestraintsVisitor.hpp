#ifndef PROJECTVISITOR_SETNODERESTRAINTVISITOR_HPP
#define PROJECTVISITOR_SETNODERESTRAINTVISITOR_HPP

#include "ProjectVisitor.hpp"

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/Node.hpp>
#include <libfemp/NodeRestrictions.hpp>

// stl includes
#include <set>
#include <vector>

/**
 * Sets node restraints in a specific set of nodes
 */
class SetNodeRestraintsVisitor : public ProjectVisitor {
	public:
	SetNodeRestraintsVisitor(std::set<fem::node_ref_t> selected_nodes, fem::NodeRestrictions const& restrictions);

	void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result) override;

	protected:
	std::set<fem::node_ref_t> m_selected_nodes;
	fem::NodeRestrictions m_restrictions;
};

#endif
