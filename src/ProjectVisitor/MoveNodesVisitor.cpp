#include "MoveNodesVisitor.hpp"

MoveNodesVisitor::MoveNodesVisitor(std::set<fem::node_ref_t> node_ref_set, fem::Point3D const& translation)
	: m_selected_nodes{node_ref_set}, m_translation{translation} {}

void MoveNodesVisitor::visit(fem::Model& model, std::vector<fem::AnalysisResult>&) {
	for (fem::node_ref_t node_ref : m_selected_nodes) {
		model.getNode(node_ref) += m_translation;
	}
}
