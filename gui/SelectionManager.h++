#ifndef SELECTION_MANAGER_HPP
#define SELECTION_MANAGER_HPP

#include <set>

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include "fem/Project.h++"
#include "Selection.h++"


/**
MVC pattern which manages a list of all objects contained in a given fem::Project object which have been selected
**/
class SelectionManager
	: public sigc::trackable
{
protected:
	fem::Project	*m_project;
	std::set<fem::element_ref_t>	m_elements_selected;
	std::set<fem::node_ref_t>	m_nodes_selected;

public:
	SelectionManager(fem::Project &project);


	// libsigc++ signals
	sigc::signal<void, fem::element_ref_t, bool>	element_selected;
	sigc::signal<void, fem::node_ref_t, bool>	node_selected;
	sigc::signal<void>				selection_cleared;


	// libsigc++ slots
	void selectElement(fem::element_ref_t, bool state = true);
	void selectNode(fem::node_ref_t, bool state = true);

	void clearSelection();

	/**
	returns a pointer to an object of type Selection which stores a set of references to selected objects
	@return	pointer to an object of type Selection, which must be freed by the function which receives it
	**/
	Selection *getSelection();

};

#endif


