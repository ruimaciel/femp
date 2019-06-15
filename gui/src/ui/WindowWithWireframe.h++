#ifndef FEMP_WINDOW_WITH_WIREFRAME_HPP
#define FEMP_WINDOW_WITH_WIREFRAME_HPP

#include "MdiWindow.h++"

#include <QComboBox>
#include <QMainWindow>
#include <QToolBar>

#include "WindowWith.h++"

/**
Provides a window with the UI needed to select between rendering wireframe, surfaces or both
**/
class WindowWithWireframe
    : public WindowWith {
public:
    enum RenderingType {
        R_WIREFRAMES = 1, // values defined so that bit masking works
        R_SURFACES = 2,
        R_BOTH = 3
    };

public:
    void createToolbar(QMainWindow* parent);

protected:
    QComboBox* m_comboBoxElementRendering;
    QToolBar* m_toolBarToggleElementRendering;
};

#endif
