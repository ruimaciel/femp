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
	std::set<fem::element_ref_t>	m_elements_seleted;
	std::set<fem::node_ref_t>	m_nodes_seleted;

public:
	Selection(fem::Project *project);

	/**
	Methods to add references to objects
	**/
	void addElement(const fem::element_ref_t &);
	void addNode(const fem::node_ref_t &);
};

#endif
