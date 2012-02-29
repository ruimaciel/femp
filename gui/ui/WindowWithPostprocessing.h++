#ifndef WINDOW_WITH_POSTPROCESSING_HPP
#define WINDOW_WITH_POSTPROCESSING_HPP

#include "MdiWindow.h++"

#include <QWidget>
#include <QComboBox>
#include <QToolBar>

#include "../fem/Project.h++"


/**
Provides a window with the ability to select which AnalysisResults<> object to use
**/
class WindowWithPostprocessing
	: public virtual MdiWindow
{
protected:
	enum PostprocessingType {
		P_DISPLACEMENT,
		P_STRAIN_11, P_STRAIN_22, P_STRAIN_33, P_STRAIN_12, P_STRAIN_13, P_STRAIN_23, 
		P_STRESS_11, P_STRESS_22, P_STRESS_33, P_STRESS_12, P_STRESS_13, P_STRESS_23,
		P_VON_MISES, 
		P_TENSION_FIELD
	};

	QToolBar *postprocessingToolBar;	// toolbar to provide a user to select which result to run
	QComboBox *postprocessingComboBox;

public:
	WindowWithPostprocessing(fem::Project &project, ViewportColors &colors, QWidget *parent = 0);

	void createToolbar(fem::Project &results);
};


#endif
