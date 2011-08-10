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


	protected:
		void connectSignalsToSlots();
};	

#endif
