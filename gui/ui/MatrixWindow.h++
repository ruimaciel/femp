#ifndef MATRIX_WINDOW_H
#define MATRIX_WINDOW_H

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include <QWidget>
#include <QToolBar>
#include <QComboBox>
#include <QMdiSubWindow>

#include "BaseWindow.h++"
#include "MatrixWidget.h++"
#include "../fem/Project.h++"


/**
MDI window designed to represent the stiffness matrix of an analysis
**/
class MatrixWindow
	:  public QMdiSubWindow, public sigc::trackable, public BaseWindow
{
	Q_OBJECT
protected:
	MatrixWidget *m_matrix_widget;
	fem::Project const *m_project;

public:
	MatrixWindow(fem::Project &project, QWidget *parent = nullptr);

protected:
};

#endif


