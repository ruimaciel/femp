#ifndef LOADPATTERNDIALOG_HPP
#define LOADPATTERNDIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QtWidgets/QDialog>
#include <string>

#include "ui_LoadPatternDialog.h"
/**
USAGE EXPLANATION
**/
class LoadPatternDialog
	: public QDialog, private Ui::LoadPatternDialog
{
	Q_OBJECT

public:
	LoadPatternDialog(QWidget *parent = NULL);


	std::string getLabel() const;
};

#endif
