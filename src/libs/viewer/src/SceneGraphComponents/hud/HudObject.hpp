#ifndef FEMP_VIEWER_HUDOBJECT_HPP
#define FEMP_VIEWER_HUDOBJECT_HPP

#include <options/ViewportColors.hpp>
#include <viewer/ViewportData.hpp>

/**
 * Abstract base class for every HUD object which might be rendered
 **/
class HudObject {
	public:
	virtual ~HudObject();

	virtual void paintGL(ViewportData& data, ViewportColors& colors) = 0;
};

#endif
