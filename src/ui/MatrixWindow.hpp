#ifndef FEMP_MATRIXWINDOW_H
#define FEMP_MATRIXWINDOW_H

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
