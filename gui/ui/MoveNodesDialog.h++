#ifndef MOVE_NODES_DIALOG_HPP
#define MOVE_NODES_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDialog>

#include <libfemp/point.h++>

#include "ui_MoveNodesDialog.h"


/**
Dialog used by GLDisplacementsWidget to input a new displacements scale
**/
class MoveNodesDialog
	: public QDialog, private Ui::MoveNodesDialog
{
	Q_OBJECT

	public:
		MoveNodesDialog(QWidget *parent = NULL);
		~MoveNodesDialog();

		fem::point getTranslation();
};

#endif
