#ifndef DISPLACEMENTS_WINDOW_HPP
#define DISPLACEMENTS_WINDOW_HPP

#include "MdiWindow.h++"
#include "WindowWithResults.h++"

#include <QComboBox>

#include "../fem/Project.h++"
#include "../viewer/ViewportColors.h++"


/**
MDI window designed to represent any recovered information from any analysis, such as displacements
**/
class DisplacementsWindow 
	: virtual public MdiWindow, virtual public WindowWithResults
{
	Q_OBJECT

	protected:
		QToolBar *resultsToolBar;	// toolbar to provide a user to select which result to run
		QComboBox *resultsComboBox;

	public:
		DisplacementsWindow (fem::Project &project, ViewportColors &colors, QWidget *parent = 0);

	protected:
		void connectSignalsToSlots();

};	

#endif
