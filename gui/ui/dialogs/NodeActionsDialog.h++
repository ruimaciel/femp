#ifndef NODE_ACTIONS_DIALOG_HPP
#define NODE_ACTIONS_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDialog>

#include <libfemp/Point.h++>
#include <libfemp/Model.h++>
#include <libfemp/LoadPattern.h++>

#include "ui/LoadPatternsModel.h++"

#include "ui/ui_NodeActionsDialog.h"


class NodeActionsDialog
		: public QDialog, public sigc::trackable, private Ui::NodeActionsDialog
{
	Q_OBJECT

private:
	size_t load_pattern;

public:
	NodeActionsDialog(LoadPatternsModel &model, QWidget *parent = nullptr);

	size_t	getLoadPattern();
	fem::Point getForce();
	fem::Point getDisplacement();

	void loadPatternCreated(size_t, fem::LoadPattern const &);

protected Q_SLOTS:
	void handleNewLabelButton();

public:	// sigc++ signals
	sigc::signal<void, std::string const &>	create_load_pattern;	// sends a signal for fem::Model to create a new load pattern
};


#endif
