#ifndef NODE_ACTIONS_DIALOG_HPP
#define NODE_ACTIONS_DIALOG_HPP

#include <QDialog>

#include "fem/point.h++"
#include "fem/Model.h++"

#include "ui/ui_NodeActionsDialog.h"


class NodeActionsDialog
	: public QDialog, private Ui_NodeActionsDialog
{
private:
	size_t load_pattern;

public:
	NodeActionsDialog(fem::Model &model, QWidget *parent = NULL);
	~NodeActionsDialog();

	size_t	getLoadPattern();
	fem::point getForce();
	fem::point getDisplacement();

};


#endif
