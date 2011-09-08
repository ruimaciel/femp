#ifndef SELECTION_HPP
#define SELECTION_HPP

#include <set>
#include "fem/Project.h++"

/**
A set of objects contained in a given fem::Project object which have been selected
**/
class Selection
{
protected:
	fem::Project	*m_project;

public:
	//crude hack.  must implement some iterator of sorts
	std::set<fem::element_ref_t>	m_elements_selected;
	std::set<fem::node_ref_t>	m_nodes_selected;

public:
	Selection();
	
	void setProject(fem::Project &project);

	void clear();

	void setSelection(Selection);
};

#endif
