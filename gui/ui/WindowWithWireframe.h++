#ifndef WINDOW_WITH_WIREFRAME_HPP
#define WINDOW_WITH_WIREFRAME_HPP

#include "MdiWindow.h++"

#include <QWidget>
#include <QComboBox>
#include <QToolBar>

#include "../fem/Project.h++"


/**
Provides a window with the UI needed to select between rendering wireframe, surfaces or both
**/
class WindowWithWireframe
	: public virtual MdiWindow
{
public:
	enum RenderingType {
		R_WIREFRAMES 	= 1,	// values defined so that bit masking works
		R_SURFACES	= 2,
		R_BOTH		= 3
	};

protected:

	QComboBox *elementRenderingComboBox;
	QToolBar *toggleElementRenderingToolBar;	

public:
	WindowWithWireframe(QWidget *parent = 0);

	void createToolbar();
};


#endif
