#ifndef WINDOW_WITH_SCALING_HPP
#define WINDOW_WITH_SCALING_HPP

#include "MdiWindow.h++"

#include <QWidget>
#include <QDoubleSpinBox>
#include <QToolBar>

#include "../fem/Project.h++"


/**
Provides a window with a toolbar which sets a scale
**/
class WindowWithScaling
	: public virtual MdiWindow
{
	protected:
		enum PostprocessingType {
			P_STRAIN_11, P_STRAIN_22, P_STRAIN_33, P_STRAIN_12, P_STRAIN_13, P_STRAIN_23, 
			P_STRESS_11, P_STRESS_22, P_STRESS_33, P_STRESS_12, P_STRESS_13, P_STRESS_23
		};

		QToolBar *scalingToolBar;	// toolbar to provide a user to select which result to run
		QDoubleSpinBox *scalingDoubleSpinBox;

	public:
		WindowWithScaling(fem::Project &project, ViewportColors &colors, QWidget *parent = 0);

		void createToolbar(fem::Project &results);

	public slots:
		void setDisplacementsScale(double);
		

	protected:
		void connectSignalsToSlots();
};


#endif
