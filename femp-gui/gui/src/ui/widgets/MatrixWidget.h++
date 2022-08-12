#ifndef MATRIX_WIDGET_H
#define MATRIX_WIDGET_H

#include <Project.h++>
#include <QWidget>
#include <libfemp/AnalysisResult.h++>
#include <ui/models/MatrixModel.h++>

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
