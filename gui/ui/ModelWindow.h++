#ifndef MODEL_WINDOW_HPP
#define MODEL_WINDOW_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include <QMainWindow>
#include "BaseWindow.h++"
#include "MdiWindow.h++"
#include "WindowWithWireframe.h++"

#include "../Project.h++"
#include <gui/options/Options.h++>

/**
MDI window designed to represent the model
**/
class ModelWindow
		: public MdiWindow,
		public WindowWithWireframe,
		public BaseWindow
{
	Q_OBJECT

public:
	ModelWindow (fem::Project &project, ViewportColors &colors, QWidget *parent = nullptr);

protected:
	void connectSignalsToSlots();

};

#endif
