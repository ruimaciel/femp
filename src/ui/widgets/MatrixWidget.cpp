#include "MatrixWidget.hpp"

#include <Project.hpp>
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/Node.hpp>
#include <ui/models/MatrixModel.hpp>

#include "ui_MatrixWidget.h"

namespace femp::ui {

struct MatrixWidget::Private {
  Ui::MatrixWidget ui;
};

MatrixWidget::MatrixWidget(femp::Project &project, QWidget *parent)
    : QWidget(parent), m_private(std::make_unique<Private>()) {
  m_private->ui.setupUi(this);

  MatrixModel *m_model = new MatrixModel(project, parent);
  m_private->ui.tableView->setModel(m_model);
}

MatrixWidget::~MatrixWidget() = default;

} // namespace femp::ui
