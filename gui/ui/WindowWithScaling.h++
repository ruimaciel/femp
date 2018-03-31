#ifndef WINDOW_WITH_SCALING_HPP
#define WINDOW_WITH_SCALING_HPP

#include "MdiWindow.h++"

#include <QMainWindow>
#include <QDoubleSpinBox>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>

#include "WindowWith.h++"


/**
Provides a window with a toolbar which sets a scale
**/
class WindowWithScaling
	: public WindowWith
{
public:
	void createToolbar(QMainWindow *parent, fem::Project &results);

	/**
	Adds menu entries to the window's menu bar
	**/
	void createMenuBar(QMainWindow *parent, QMenuBar *);

public slots:
	void setDisplacementsScale(double);
	
protected:
	void connectSignalsToSlots(QMainWindow *parent);


protected:
	QToolBar *scalingToolBar;	// toolbar to provide a user to select which result to run
	QDoubleSpinBox *scalingDoubleSpinBox;
	QAction *actionSetTensionRanges;	// action to call a dialog which sets the values for the max an min values of any given field

	QMenu * m_scaling_menu;
};


#endif
