#ifndef FEMP_WINDOWWITHPOSTPROCESSING_HPP
#define FEMP_WINDOWWITHPOSTPROCESSING_HPP

#include "MdiWindow.h++"

// gui includes
#include <Project.h++>

class QMainWindow;
class QToolBar;
class QComboBox;

#include "WindowWith.h++"

/**
 * Provides a window with the ability to select which AnalysisResults<> object
 * to use
 */
class WindowWithPostprocessing : public WindowWith {
	protected:
	enum PostprocessingType {
		P_DISPLACEMENT,
		P_STRAIN_11,
		P_STRAIN_22,
		P_STRAIN_33,
		P_STRAIN_12,
		P_STRAIN_13,
		P_STRAIN_23,
		P_STRESS_11,
		P_STRESS_22,
		P_STRESS_33,
		P_STRESS_12,
		P_STRESS_13,
		P_STRESS_23,
		P_VON_MISES
	};

	QToolBar* m_postprocessingToolBar;	// toolbar to provide a user to select
										// which result to run
	QComboBox* m_postprocessingComboBox;

	public:
	void createToolbar(QMainWindow* parent, fem::Project& results);
};

#endif
