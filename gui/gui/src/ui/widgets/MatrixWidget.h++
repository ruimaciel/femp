#ifndef MATRIX_WIDGET_H
#define MATRIX_WIDGET_H

#include <QWidget>

#include <Project.h++>
#include <libfemp/AnalysisResult.h++>

#include "ui_MatrixWidget.h"
#include <ui/models/MatrixModel.h++>

/**
Widget used in MDI windows to display the stiffness matrix of a given analysis
**/
class MatrixWidget
    : public QWidget,
      private Ui::MatrixWidget {
    Q_OBJECT

public:
    MatrixWidget(fem::Project& project, QWidget* parent = nullptr);
};

#endif
