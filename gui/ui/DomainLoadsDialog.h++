#ifndef DOMAIN_LOADS_DIALOG_HPP
#define DOMAIN_LOADS_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDialog>

#include "fem/point.h++"
#include "fem/Model.h++"

#include "ui_DomainLoadsDialog.h"


class DomainLoadsDialog
	: public QDialog, private Ui_DomainLoadsDialog
{
private:
	size_t load_pattern;

public:
	DomainLoadsDialog(fem::Model &model, QWidget *parent = NULL);
	~DomainLoadsDialog();

	size_t	getLoadPattern();
	fem::point getForce();
};


#endif
