#ifndef SELECTION_HPP
#define SELECTION_HPP

#include <set>
#include "fem/Project.h++"
#include "fem/Element.h++"
#include "fem/Node.h++"

/**
A set of objects contained in a given fem::Project object which have been selected
**/
class Selection
{
public:
	//crude hack.  must implement some iterator of sorts
	std::set<fem::element_ref_t>	m_elements_selected;
	std::set<fem::node_ref_t>	m_nodes_selected;

public:
	void clear();

	void setSelection(Selection);

	void selectElement(const fem::element_ref_t &ref);
	void deselectElement(const fem::element_ref_t &ref);
	void selectNode(const fem::node_ref_t &ref);
	void deselectNode(const fem::node_ref_t &ref);
};

#endif
