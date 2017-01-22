#ifndef HUD_SELECTION_HPP
#define HUD_SELECTION_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include "HudObject.h++"

#include <libfemp/Point.h++>

#include "../../ViewportData.h++"
#include "../../ViewportColors.h++"


namespace hud
{

/**
Renders a rectangle on the window, representing the selection region
**/
class Selection
	: public HudObject
{
protected:
	bool		m_on;
	fem::Point	m_start;
	fem::Point	m_end;

public:
	Selection();

	void paintGL(ViewportData &data, ViewportColors &colors);

	void setStart(fem::Point const &p);
	void setEnd(fem::Point const &p);
	void off()	{m_on = false;}
};

}

#endif
