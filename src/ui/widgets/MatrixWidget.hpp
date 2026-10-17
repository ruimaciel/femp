#ifndef FEMP_UI_MATRIX_WIDGET_HPP
#define FEMP_UI_MATRIX_WIDGET_HPP

#include <QWidget>

#include <memory>

namespace fem {
class Project;
}

/**
Widget used in MDI windows to display the stiffness matrix of a given analysis
**/
class MatrixWidget : public QWidget {
  Q_OBJECT

public:
  MatrixWidget(fem::Project &project, QWidget *parent = nullptr);
  ~MatrixWidget() override;

private:
  struct Private;
  std::unique_ptr<Private> m_private;
};

#endif
