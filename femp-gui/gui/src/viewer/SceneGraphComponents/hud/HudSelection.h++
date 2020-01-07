#ifndef HUD_SELECTION_HPP
#define HUD_SELECTION_HPP

#include "HudObject.h++"

#include <libfemp/Point3D.h++>

#include "../../ViewportData.h++"
#include <options/Options.h++>

namespace hud {

/**
Renders a rectangle on the window, representing the selection region
**/
class Selection
    : public HudObject {
protected:
    bool m_on;
    fem::Point3D m_start;
    fem::Point3D m_end;

public:
    Selection();

    void paintGL(ViewportData& data, ViewportColors& colors);

    void setStart(fem::Point3D const& p);
    void setEnd(fem::Point3D const& p);
    void off();
};

}

#endif
