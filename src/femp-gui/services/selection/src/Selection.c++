#include <selection/Selection.h++>

void Selection::selectElement(element_ref_t ref) {
	m_elements_selected.insert(ref);
}

std::set<element_ref_t> Selection::getElementReferences() const {
	return m_elements_selected;
}

void Selection::selectNode(node_ref_t ref) {
	m_nodes_selected.insert(ref);
}

std::set<node_ref_t> Selection::getNodeReferences() const {
	return m_nodes_selected;
}
