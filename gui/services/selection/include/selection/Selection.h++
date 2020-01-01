#ifndef FEMP_SELECTION_HPP
#define FEMP_SELECTION_HPP

#include <set>

using element_ref_t = size_t;
using node_ref_t = size_t;

class Selection {
public:
    void clear();

    void setSelection(Selection const&);

    void selectElement(const element_ref_t& ref);

    void deselectElement(const element_ref_t& ref);

    std::set<element_ref_t> getElementReferences() const;

    void selectNode(const node_ref_t& ref);

    void deselectNode(const node_ref_t& ref);

    std::set<node_ref_t> getNodeReferences() const;

protected:
    std::set<element_ref_t> m_elements_selected;
    std::set<node_ref_t> m_nodes_selected;
};

#endif
