#ifndef MODEL_WINDOW_HPP
#define MODEL_WINDOW_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include "BaseWindow.h++"
#include "MdiWindow.h++"
#include "WindowWithWireframe.h++"

#include "../fem/Project.h++"
#include "../viewer/ViewportColors.h++"

/**
MDI window designed to represent the model
**/
class ModelWindow 
	: virtual public MdiWindow, 
	virtual public WindowWithWireframe, public BaseWindow
{
	Q_OBJECT

public:
	ModelWindow (fem::Project &project, ViewportColors &colors, QWidget *parent = 0);

protected:
	void connectSignalsToSlots();

};	

#endif
