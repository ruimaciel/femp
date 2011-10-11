#ifndef WINDOW_WITH_GHOST_SURFACES_HPP
#define WINDOW_WITH_GHOST_SURFACES_HPP

#include "MdiWindow.h++"

#include <QWidget>
#include <QComboBox>
#include <QToolBar>

#include "../fem/Project.h++"


/**
Enhances MdiWindow's visibility toolbar to also toggle ghost surfaces (i.e., translucent surfaces in the model's original configuration)
**/
class WindowWithGhostSurfaces
	: public virtual MdiWindow
{
protected:
	QAction *actionVisibleGhostSurfaces;	// used in the visibility toolbar, to refer to the translucent surfaces which represent the original configuration

public:
	WindowWithGhostSurfaces(fem::Project &project, ViewportColors &colors, QWidget *parent = 0);

	void createToolbar();
	
public slots:
	void setGhostSurfacesVisibility(const bool);

protected:
	void connectSignalsToSlots() ;

};


#endif
