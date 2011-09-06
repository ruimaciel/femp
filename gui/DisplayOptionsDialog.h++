#ifndef DISPLAY_OPTIONS_DIALOG_HPP
#define DISPLAY_OPTIONS_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDialog>

#include "fem/Model.h++"

#include "ui/ui_DisplayOptionsDialog.h"


class DisplayOptionsDialog
	: public QDialog, public Ui_DisplayOptionsDialog
{
public:
	DisplayOptionsDialog(fem::Model &model, QWidget *parent = NULL);
	~DisplayOptionsDialog();

	// returns the index to the LoadOptions object that will be rendered
	size_t getLoadPatternIndex();

	bool renderNodalForces();
	bool renderSurfaceForces();
	bool renderDomainForces();
	bool renderNodalDisplacements();
};

#endif
