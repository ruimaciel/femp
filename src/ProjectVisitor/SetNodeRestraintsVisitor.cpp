#include "SetNodeRestraintsVisitor.hpp"

SetNodeRestraintsVisitor::SetNodeRestraintsVisitor(std::set<fem::node_ref_t> selected_nodes, fem::NodeRestrictions const& restrictions)
	: m_selected_nodes{selected_nodes}, m_restrictions{restrictions} {}

void SetNodeRestraintsVisitor::visit(fem::Model& model, std::vector<fem::AnalysisResult>&) {
	if (m_restrictions.free()) {
		for (fem::node_ref_t node : m_selected_nodes) {
			model.popNodeRestrictions(node);
		}
	} else {
		for (fem::node_ref_t node : m_selected_nodes) {
			model.pushNodeRestrictions(node, m_restrictions);
		}
	}
}
