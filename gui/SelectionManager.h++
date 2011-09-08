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
	Selection m_selection;

public:
	void setProject(fem::Project &project);

	// libsigc++ signals
	sigc::signal<void, Selection>	selection_changed;
	sigc::signal<void>		selection_cleared;

	// libsigc++ slots
	void setSelection(Selection);
	void clearSelection();

	/**
	returns a pointer to an object of type Selection which stores a set of references to selected objects
	@return	an object of type Selection
	**/
	Selection getSelection();

};

#endif


