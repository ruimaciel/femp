#include "BaseWindow.hpp"

femp::ui::BaseWindow::BaseWindow(QString const &label) {
  this->m_windowLabel = label;
}

QString femp::ui::BaseWindow::label() const { return m_windowLabel; }
