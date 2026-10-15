#ifndef FEMP_UI_MDIWINDOW_HPP
#define FEMP_UI_MDIWINDOW_HPP

// ui includes
#include "ui/ui_MdiWindow.h"

// gui includes
#include <selection/Selection.hpp>

// Qt includes
#include <QMainWindow>
#include <QWidget>

#include <cstddef>
#include <memory>

class QAction;
class BaseViewport;
class QToolBar;
class ViewportColors;

namespace fem {
class NodeRestrictions;
}

/**
 * Base class for all the MDI windows that render the model
 */
class MdiWindow : public QMainWindow, protected Ui::MdiWindow {
  Q_OBJECT

public:
  MdiWindow(QWidget *parent = nullptr);
  ~MdiWindow() override;

  /**
   * Sets the toolbar which provides buttons to set camera angles
   */
  void createViewportToolbar();
  void createVisibilityToolbar();

  /**
   * Sets the colors which are used by the viewports
   */
  void setColors(ViewportColors &colors);

signals:
  void selectionChanged(Selection);
  void selectionCleared();

public slots:
  void setViewportXY();
  void setViewportXZ();
  void setViewportYZ();
  void setViewportIso();

  /**
   * Sets the visibility of the nodes
   */
  void setNodeVisibility(const bool);
  void setNodeRestrictionsVisibility(const bool);

  void setSelection(Selection); // sets the selection
  void clearSelection();        // clears the selection

protected:
  virtual void connectSignalsToSlots();

  void normalizeAngle(int *angle);

public:
  /**
   * Sets the viewport so that only the selected items are shown
   */
  void showSelection(const Selection);

  /**
   * Sets the viewport so that all scenegraph components are shown
   */
  void showAll();

  void updateNodeRestriction(std::size_t const, fem::NodeRestrictions const &);

  BaseViewport *viewport;

protected:
  QToolBar *m_viewportToolBar;   // toolbar to set camera angles
  QToolBar *m_visibilityToolBar; // toolbar to set which rendering group (i.e.,
                                 // nodes, surfaces, etc...) is visible

  QAction *m_actionMenuVisibility; // toolbar menu button that toggles the menu
                                   // bar visibility

private:
  struct Private;
  std::unique_ptr<Private> d;
};

#endif
