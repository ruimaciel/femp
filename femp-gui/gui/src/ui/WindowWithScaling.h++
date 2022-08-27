#ifndef FEMP_WINDOW_WITH_SCALING_HPP
#define FEMP_WINDOW_WITH_SCALING_HPP

#include <QDoubleSpinBox>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

#include "MdiWindow.h++"
#include "WindowWith.h++"

/**
 * Provides a window with a toolbar which sets a scale
 */
class WindowWithScaling : public WindowWith {
	public:
	void createToolbar(QMainWindow* parent, fem::Project& results);

	/**
	 * Adds menu entries to the window's menu bar
	 */
	void createMenuBar(QMainWindow* parent, QMenuBar*);

	public slots:
	void setDisplacementsScale(double);

	protected:
	void connectSignalsToSlots(QMainWindow* parent);

	protected:
	QToolBar* m_toolBarScaling;	 // toolbar to provide a user to select which
								 // result to run
	QDoubleSpinBox* m_doubleSpinBoxScaling;
	QAction* m_actionSetTensionRanges;	// action to call a dialog which sets the
										// values for the max an min values of any
										// given field

	QMenu* m_menuScaling;
};

#endif
