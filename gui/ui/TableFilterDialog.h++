#ifndef TABLE_FILTER_DIALOG_HPP
#define TABLE_FILTER_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include <QWidget>

#include "ui_TableFilterDialog.h"


/**
Implements a dialog box which is used to toggle the visibility of each column and filter the results
**/
class TableFilterDialog
	: public QDialog, private Ui::TableFilterDialog
{
	Q_OBJECT

public:
	TableFilterDialog(QWidget *parent = NULL);

#define MEMBER_HELPER(XX) \
void set##XX##Visible(bool state)	{ this->checkBox##XX->setChecked(state); } \
bool get##XX##Visible() const		{ return this->checkBox##XX->isChecked(); }
	MEMBER_HELPER(ElementReference);
	MEMBER_HELPER(ElementType);
	MEMBER_HELPER(NodeGlobalReference);
	MEMBER_HELPER(NodeLocalReference);
	MEMBER_HELPER(NodePositionX);
	MEMBER_HELPER(NodePositionY);
	MEMBER_HELPER(NodePositionZ);
	MEMBER_HELPER(NodeDisplacementsX);
	MEMBER_HELPER(NodeDisplacementsY);
	MEMBER_HELPER(NodeDisplacementsZ);
	MEMBER_HELPER(E11);
	MEMBER_HELPER(E22);
	MEMBER_HELPER(E33);
	MEMBER_HELPER(E12);
	MEMBER_HELPER(E23);
	MEMBER_HELPER(E13);
	MEMBER_HELPER(S11);
	MEMBER_HELPER(S22);
	MEMBER_HELPER(S33);
	MEMBER_HELPER(S12);
	MEMBER_HELPER(S23);
	MEMBER_HELPER(S13);
	MEMBER_HELPER(VonMises);
#undef MEMBER_HELPER

};


#endif
