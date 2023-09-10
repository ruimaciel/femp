#ifndef FEMP_SELECTION_HPP
#define FEMP_SELECTION_HPP

#include <cstddef>
#include <set>

using element_ref_t = std::size_t;
using node_ref_t = std::size_t;

class Selection {
	public:
	void selectElement(element_ref_t ref);

	std::set<element_ref_t> getElementReferences() const;

	void selectNode(node_ref_t ref);

	std::set<node_ref_t> getNodeReferences() const;

	protected:
	std::set<element_ref_t> m_elements_selected;
	std::set<node_ref_t> m_nodes_selected;
};

#endif
