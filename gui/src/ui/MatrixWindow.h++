#ifndef FEMP_MATRIX_WINDOW_H
#define FEMP_MATRIX_WINDOW_H

#include <sigc++/sigc++.h> // to side step a compiler error caused by a conflict with Qt and libsigc++

#include <QComboBox>
#include <QMdiSubWindow>
#include <QToolBar>
#include <QWidget>

#include "../Project.h++"
#include "BaseWindow.h++"
#include <ui/widgets/MatrixWidget.h++>

/**
MDI window designed to represent the stiffness matrix of an analysis
**/
class MatrixWindow
    : public QMdiSubWindow,
      public BaseWindow {
    Q_OBJECT

protected:
    MatrixWidget* m_matrixWidget;
    fem::Project const* m_project;

public:
    MatrixWindow(fem::Project& project, QWidget* parent = nullptr);
};

#endif
