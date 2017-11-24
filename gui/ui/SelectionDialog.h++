#ifndef SELECTION_DIALOG_HPP
#define SELECTION_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QtWidgets/QDialog>

#include <ui/widgets/SelectionWidget.h++>

#include "../Project.h++"
#include "../SelectionManager.h++"


/** 
Dialog box which uses the selection widget to select objects from a given fem::Project object
**/
class SelectionDialog
	: public QDialog
{
protected:
	SelectionWidget *m_selection_widget;

public:
	SelectionDialog(fem::Project &project, SelectionManager &selection_manager, QWidget *parent = NULL);
};

#endif
