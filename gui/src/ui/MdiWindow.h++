#ifndef FEMP_MDI_WINDOW_HPP
#define FEMP_MDI_WINDOW_HPP

#include "viewer/BaseViewport.h++"
#include <QAction>
#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>

#include "../viewer/ViewportData.h++"
#include <options/Options.h++>

#include "ui/ui_MdiWindow.h"

#include "Selection.h++"
#include "SelectionManager.h++"

/**
Base class for all the MDI windows that render the model
**/
class MdiWindow
    : public QMainWindow,
      protected Ui::MdiWindow {
    Q_OBJECT

public:
    MdiWindow(QWidget* parent = nullptr);

    /**
        Sets the toolbar which provides buttons to set camera angles
        **/
    void createViewportToolbar();
    void createVisibilityToolbar();

    /**
        Sets the colors which are used by the viewports
        **/
    void setColors(ViewportColors& colors);

signals:
    void selectionChanged(Selection);
    void selectionCleared();

public slots:
    void setViewportXY();
    void setViewportXZ();
    void setViewportYZ();
    void setViewportIso();

    /**
        Sets the visibility of the nodes
        **/
    void setNodeVisibility(const bool);
    void setNodeRestrictionsVisibility(const bool);

    void setSelection(Selection); // sets the selection
    void clearSelection(); // clears the selection

protected:
    virtual void connectSignalsToSlots();

    void normalizeAngle(int* angle);

public:
    // old libsigc++ slots
    void showSelection(const Selection); // sets the viewport so that only the selected items are shown
    void showAll(); // sets the viewport so that all scenegraph components are shown

    void updateNodeRestriction(size_t const, fem::NodeRestrictions const&);

    BaseViewport* viewport;

protected:
    QToolBar* m_viewportToolBar; // toolbar to set camera angles
    QToolBar* m_visibilityToolBar; // toolbar to set which rendering group (i.e., nodes, surfaces, etc...) is visible

    QAction* m_actionMenuVisibility; // toolbar menu button that toggles the menu bar visibility

    QAction* m_actionViewportXY; // places the camera displaying the XY plane
    QAction* m_actionViewportYZ; // places the camera displaying the XY plane
    QAction* m_actionViewportXZ; // places the camera displaying the XZ plane
    QAction* m_actionViewportIso; // places the camera on an isometric view angle

    QAction* m_actionVisibleNodes;
    QAction* m_actionVisibleRestrictions;
};

#endif
