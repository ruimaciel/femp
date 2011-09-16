#ifndef POSTPROCESSING__WINDOW_HPP
#define POSTPROCESSING__WINDOW_HPP

#include "MdiWindow.h++"
#include "WindowWithResults.h++"
#include "WindowWithPostprocessing.h++"
#include "WindowWithScaling.h++"

#include <QWidget>
#include <QToolBar>
#include <QComboBox>

#include "../fem/Project.h++"
#include "../fem/AnalysisResult.h++"
#include "../fem/ElementResults/ResultsRanges.h++"
#include "../viewer/ViewportColors.h++"

#include "Selection.h++"
#include "SelectionManager.h++"


/**
MDI window designed to represent the model
**/
class PostprocessingWindow 
	: virtual public MdiWindow, virtual public WindowWithResults, virtual public WindowWithPostprocessing, virtual public WindowWithScaling
{
	Q_OBJECT

	protected:
		enum AnalysisType {
			A_DISPLACEMENT = 0,
			A_STRAIN_11, A_STRAIN_22, A_STRAIN_33, A_STRAIN_12,A_STRAIN_13,A_STRAIN_23,
			A_STRESS_11, A_STRESS_22, A_STRESS_33, A_STRESS_12,A_STRESS_13,A_STRESS_23,
			A_VON_MISES
		};

		QToolBar *toggleMenuBarVisibilityToolBar;	
		QComboBox *analysisComboBox;

		fem::AnalysisResult<double> *m_result;	// pointer to the current analysis result, which will point to a reference

		//gradient values
		fem::ResultsRanges<double> m_results_ranges;	// used to set values for representation

	public:
		PostprocessingWindow (fem::Project &project, fem::AnalysisResult<double> &result, ViewportColors &colors, QWidget *parent = 0);


	public slots:
		void setDisplacementsScale(double scale);

		// this member is needed because I can't get the connect() in WindowWithGhostSurfaces to have any effect
		void setNodeRestrictionsVisibility(const bool state);
		void setGhostSurfacesVisibility(const bool state);

		// sets the postprocessing state according
		void setPostprocessingState(int state);
		void toggleMenuBarVisibility(bool);

		void setAnalysisResult(fem::AnalysisResult<double> &result);

		/**
		Calls ResultsRangeDialog and sets m_results_ranges accordingly
		**/
		void setResultsRanges();

	protected:
		void connectSignalsToSlots();

		void createToolBars(fem::Project &);

		void setGradientValuesRange(const fem::AnalysisResult<double> &result);


	public:
		// libsigc++ slots
		void setSelection(Selection);	// sets the selection
		void clearSelection();		// clears the selection

		/**
		Handles all libsigc++ connections between this window and an object of type SelectionManager
		**/
		void connectToSelectionManager(SelectionManager &);
};	

#endif
