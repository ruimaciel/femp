#ifndef POSTPROCESSING__WINDOW_HPP
#define POSTPROCESSING__WINDOW_HPP

#include "MdiWindow.h++"

#include <QWidget>
#include <QComboBox>

#include "../fem/Project.h++"
#include "../viewer/ViewportColors.h++"

/**
MDI window designed to represent the model
**/
class PostprocessingWindow 
	: public MdiWindow
{
	Q_OBJECT

	protected:
		enum AnalysisType {
			A_STRAIN_11, A_STRAIN_22, A_STRAIN_33, A_STRAIN_12,A_STRAIN_13,A_STRAIN_23,
			A_STRESS_11, A_STRESS_22, A_STRESS_33, A_STRESS_12,A_STRESS_13,A_STRESS_23
		};

		QToolBar *analysisToolBar;	// toolbar to select which value to represent
		QComboBox *analysisComboBox;

	public:
		PostprocessingWindow (fem::Project &project, ViewportColors &colors, QWidget *parent = 0);


		void createAnalysisToolar();


	protected:
		void connectSignalsToSlots();
};	

#endif
