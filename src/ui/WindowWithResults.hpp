#ifndef FEMP_WINDOWWITHRESULTS_HPP
#define FEMP_WINDOWWITHRESULTS_HPP

#include "MdiWindow.hpp"
#include "WindowWith.hpp"

// gui includes
#include <Project.hpp>

class QMainWindow;
class QToolBar;
class QComboBox;

/**
 * Provides a window with the ability to select which AnalysisResults<> object
 * to use
 */
class WindowWithResults : public WindowWith {
	protected:
	QToolBar* m_toolBarResults;	 // toolbar to provide a user to select which
								 // result to run
	QComboBox* m_comboBoxResults;

	public:
	void createToolbar(QMainWindow* parent, fem::Project& results);
};

#endif
