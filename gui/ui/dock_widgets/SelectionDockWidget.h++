#ifndef SELECTION_DOCK_WIDGET_HPP
#define SELECTION_DOCK_WIDGET_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDockWidget>

#include "ui_SelectionDockWidget.h"


/**
Dock widget which is intended to provide the user with a simple way to select individual model objects
**/
class SelectionDockWidget
		: public QDockWidget
{
};


#endif
