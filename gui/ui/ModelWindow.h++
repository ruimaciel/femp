#ifndef MODEL_WINDOW_HPP
#define MODEL_WINDOW_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include "MdiWindow.h++"

#include "../fem/Project.h++"
#include "../viewer/ViewportColors.h++"

/**
MDI window designed to represent the model
**/
class ModelWindow 
	: public MdiWindow
{
	Q_OBJECT

public:
	ModelWindow (fem::Project &project, ViewportColors &colors, QWidget *parent = 0);

	void connectToSelectionManager(SelectionManager &selection_manager);

protected:
	void connectSignalsToSlots();

public:
	// libsigc++ slots
	void setSelection(Selection);	// sets the selection
	void clearSelection();		// clears the selection

};	

#endif
