#ifndef VIEWPORT_STATE_MODEL_HPP
#define VIEWPORT_STATE_MODEL_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QMouseEvent>

#include "ViewportState.h++"
#include "../BaseViewport.h++"
#include "../ViewportData.h++"
#include <gui/options/Options.h++>

#include "../SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationFlyweightFactory.h++"
#include "../SceneGraphComponents/DisplacementsRepresentationPolicy/NoDisplacementsPolicy.h++"
#include "../SceneGraphComponents/SceneComponentFactory.h++"


class BaseViewport;

/*
A pattern for the State pattern which is used to render the model space
*/
class VPStateModel
	:public ViewportState
{
protected:
	ElementRepresentationFlyweightFactory		m_element_representation_factory;
	NoDisplacementsPolicy 	m_no_displacements;	// the model view doesn't render displacements
	SGC::SceneComponentFactory m_factory;

public:
	VPStateModel();
	~VPStateModel();

	void initialize(BaseViewport *viewport);
	void populateScenegraph(BaseViewport *viewport);

	/**
	Tweaks the way the viewport is rendered according to the current selection
	**/
	void setSelection(Selection);

	void keyPressEvent ( BaseViewport *viewport, QKeyEvent * event );

	/**
	Sets the relevant policies to render the OpenGL triangles with a wireframe
	This isn't implemented in ViewportStates which won't render Opaque objects
	**/
	void setTrianglesVisible(bool const state);
};


#endif
