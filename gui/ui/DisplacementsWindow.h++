#ifndef DISPLACEMENTS_WINDOW_HPP
#define DISPLACEMENTS_WINDOW_HPP

#include "MdiWindow.h++"

#include "../fem/Project.h++"
#include "../viewer/ViewportColors.h++"


/**
MDI window designed to represent any recovered information from any analysis, such as displacements
**/
class DisplacementsWindow 
	: public MdiWindow
{
	Q_OBJECT

	public:
		DisplacementsWindow (fem::Project &project, ViewportColors &colors, QWidget *parent = 0);


	protected:
		void connectSignalsToSlots();

};	

#endif
