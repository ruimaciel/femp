#ifndef HUD_OBJECT_HPP
#define HUD_OBJECT_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include "../../ViewportData.h++"
#include <gui/options/ViewportColors.h++>


/**
Abstract base class for every HUD object which might be rendered
**/
class HudObject
{
public:
  virtual ~HudObject();

  virtual void paintGL(ViewportData &data, ViewportColors &colors) = 0;
};


#endif
