#ifndef FEMP_UI_WINDOWWITHPOSTPROCESSING_HPP
#define FEMP_UI_WINDOWWITHPOSTPROCESSING_HPP

#include "MdiWindow.hpp"

// gui includes
#include <Project.hpp>

class QMainWindow;
class QToolBar;
class QComboBox;

#include "WindowWith.hpp"

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
		P_FEMP_VIEWER_11,
		P_FEMP_VIEWER_22,
		P_FEMP_VIEWER_33,
		P_FEMP_VIEWER_12,
		P_FEMP_VIEWER_13,
		P_FEMP_VIEWER_23,
		P_VON_MISES
	};

	QToolBar* m_postprocessingToolBar;	// toolbar to provide a user to select
										// which result to run
	QComboBox* m_postprocessingComboBox;

	public:
	void createToolbar(QMainWindow* parent, fem::Project& results);
};

#endif
