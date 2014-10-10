#ifndef WINDOW_WITH_RESULTS_HPP
#define WINDOW_WITH_RESULTS_HPP

#include "MdiWindow.h++"

#include <QMainWindow>
#include <QComboBox>
#include <QToolBar>

#include "WindowWith.h++"


/**
Provides a window with the ability to select which AnalysisResults<> object to use
**/
class WindowWithResults
	: public WindowWith
{
protected:
	QToolBar *resultsToolBar;	// toolbar to provide a user to select which result to run
	QComboBox *resultsComboBox;

public:
	void createToolbar(QMainWindow *parent, fem::Project &results);
};


#endif
