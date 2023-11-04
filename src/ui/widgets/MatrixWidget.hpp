#ifndef MATRIX_WIDGET_H
#define MATRIX_WIDGET_H

#include <Project.hpp>
#include <QWidget>
#include <libfemp/AnalysisResult.hpp>
#include <ui/models/MatrixModel.hpp>

#include "ui_MatrixWidget.h"

/**
Widget used in MDI windows to display the stiffness matrix of a given analysis
**/
class MatrixWidget : public QWidget, private Ui::MatrixWidget {
	Q_OBJECT

	public:
	MatrixWidget(fem::Project& project, QWidget* parent = nullptr);
};

#endif
