#ifndef FEMP_UI_MATRIXWINDOW_HPP
#define FEMP_UI_MATRIXWINDOW_HPP

// ui includes
#include <ui/widgets/MatrixWidget.hpp>

#include "../Project.hpp"
#include "BaseWindow.hpp"

// Qt includes
#include <QMdiSubWindow>

class QWidget;

/**
 * MDI window designed to represent the stiffness matrix of an analysis
 */
class MatrixWindow : public QMdiSubWindow, public BaseWindow {
	Q_OBJECT

	protected:
	MatrixWidget* m_matrixWidget;
	fem::Project const* m_project;

	public:
	MatrixWindow(fem::Project& project, QWidget* parent = nullptr);
};

#endif
