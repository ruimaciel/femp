#ifndef WINDOW_WITH_RESULTS_HPP
#define WINDOW_WITH_RESULTS_HPP

#include "MdiWindow.h++"

#include <QWidget>
#include <QComboBox>
#include <QToolBar>

#include "../fem/Project.h++"


/**
Provides a window with the ability to select which AnalysisResults<> object to use
**/
class WindowWithResults
	: public virtual MdiWindow
{
protected:
	QToolBar *resultsToolBar;	// toolbar to provide a user to select which result to run
	QComboBox *resultsComboBox;

public:
	WindowWithResults(fem::Project &project, ViewportColors &colors, QWidget *parent = 0);

	void createToolbar(fem::Project &results);
};


#endif
