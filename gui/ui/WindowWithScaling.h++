#ifndef WINDOW_WITH_SCALING_HPP
#define WINDOW_WITH_SCALING_HPP

#include "MdiWindow.h++"

#include <QWidget>
#include <QDoubleSpinBox>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>

#include "../fem/Project.h++"


/**
Provides a window with a toolbar which sets a scale
**/
class WindowWithScaling
	: public virtual MdiWindow
{
protected:
	QToolBar *scalingToolBar;	// toolbar to provide a user to select which result to run
	QDoubleSpinBox *scalingDoubleSpinBox;
	QAction *actionSetTensionRanges;	// action to call a dialog which sets the values for the max an min values of any given field

	QMenu * m_scaling_menu;

public:
	WindowWithScaling(fem::Project &project, ViewportColors &colors, QWidget *parent = 0);

	void createToolbar(fem::Project &results);

	/**
	Adds menu entries to the window's menu bar
	**/
	void createMenuBar(QMenuBar *);

public slots:
	void setDisplacementsScale(double);
	

protected:
	void connectSignalsToSlots();
};


#endif
