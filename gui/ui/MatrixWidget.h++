#ifndef MATRIX_WIDGET_H
#define MATRIX_WIDGET_H

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QWidget>

#include "../Project.h++"
#include <libfemp/AnalysisResult.h++>

#include "ui_MatrixWidget.h"
#include "MatrixModel.h++"


/**
Widget used in MDI windows to display the stiffness matrix of a given analysis
**/
class MatrixWidget
	:public QWidget, private Ui::MatrixWidget
{
	Q_OBJECT

protected:
	fem::Project const *m_project;
	fem::AnalysisResult<double> const *m_result;
	MatrixModel *m_model;

public:
	MatrixWidget(fem::Project &project, QWidget *parent = nullptr);
};

#endif
