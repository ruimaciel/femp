#ifndef DOMAIN_LOADS_DIALOG_HPP
#define DOMAIN_LOADS_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDialog>

#include <libfemp/Point.h++>
#include <libfemp/Model.h++>
#include <libfemp/LoadPattern.h++>

#include "LoadPatternsModel.h++"

#include "ui_DomainLoadsDialog.h"


class DomainLoadsDialog
	: public QDialog, public sigc::trackable, private Ui::DomainLoadsDialog
{
	Q_OBJECT

public:
	DomainLoadsDialog(LoadPatternsModel &model, QWidget *parent = NULL);

	size_t	getLoadPattern();

	fem::Point getForce();

	void loadPatternCreated(size_t, fem::LoadPattern const &);


protected Q_SLOTS:

	void handleNewLabelButton();

public:	// sigc++ signals
	sigc::signal<void, std::string const &>	create_load_pattern;	// sends a signal for fem::Model to create a new load pattern 

private:
	size_t load_pattern;

};


#endif
