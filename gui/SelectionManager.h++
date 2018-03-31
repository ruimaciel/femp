#ifndef SELECTION_MANAGER_HPP
#define SELECTION_MANAGER_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include <libfemp/Element.h++>
#include <libfemp/Node.h++>

#include "Selection.h++"


/**
MVC pattern which manages a list of all objects contained in a given fem::Project object which have been selected
**/
class SelectionManager
	: public sigc::trackable
{
public:

	// libsigc++ slots
	void setSelection(Selection const &);

	void clearSelection();

	void selectElement(const fem::element_ref_t &ref);

	void deselectElement(const fem::element_ref_t &ref);

	void selectNode(const fem::node_ref_t &ref);

	void deselectNode(const fem::node_ref_t &ref);

	/**
	returns a pointer to an object of type Selection which stores a set of references to selected objects
	@return	an object of type Selection
	**/
	Selection const & getSelection() const;

protected:
	Selection m_selection;

public:
	// libsigc++ signals
	sigc::signal<void, Selection const &>	selection_changed;
	sigc::signal<void>			selection_cleared;

};

#endif


