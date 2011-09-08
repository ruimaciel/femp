#ifndef VIEWPORT_STATE_HPP
#define VIEWPORT_STATE_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <assert.h>
#include <QMouseEvent>

#include "../../fem/Model.h++"
#include "../../fem/AnalysisResult.h++"

#include "../../Selection.h++"

#include "../ViewportData.h++"
#include "../ViewportColors.h++"
#include "../Camera.h++"
#include "../SceneGraph.h++"


/*
The base state pattern that is used to implement the Viewport's model rendering states
*/
template <class Viewport>
class ViewportState
{
protected:
	SceneGraph scenegraph;
	float scale;
	
public:
	ViewportState();

	/*
	Initializes everything needed in a ViewportState once the focus is placed on it
	*/
	virtual void initialize(Viewport *viewport) = 0;

	/*
	Adds to the scenegraph all the objects being rendered 
	*/
	virtual void populateScenegraph(Viewport *viewport) = 0;


	/**
	Configures the viewport to render the scene according to new_result
	**/
	virtual void setAnalysisResult(fem::AnalysisResult<double> &new_result);

	virtual void setDisplacementsScale(float new_scale);

	/**
	Sets the visibility of a SceneGraph render group
	@param	group	scene graph render group code, as defined in class SceneGraph
	@param	state	true if visible, false if invisible
	**/
	void setRenderGoupVisibility(SceneGraph::Groups group, bool state);

	/*
	Routine which will paint each OpenGL scene
	*/
	virtual void paintGL(Viewport *viewport)	= 0;
	virtual void mousePressEvent(Viewport *viewport, QMouseEvent *event) = 0;
	virtual void mouseMoveEvent(Viewport *viewport, QMouseEvent *event);
	virtual void keyPressEvent ( Viewport *viewport, QKeyEvent * event );

	// libsigc++ slots
	virtual void setSelection(Selection);	// sets the selection
	virtual void clearSelection();		// clears the selection list representation
};


template <class Viewport>
ViewportState<Viewport>::ViewportState()
{
}


template <class Viewport>
void
ViewportState<Viewport>::setAnalysisResult(fem::AnalysisResult<double> &)
{
}


template<class Viewport>
void
ViewportState<Viewport>::setDisplacementsScale(float new_scale)
{
	this->scale = new_scale;
}


template<class Viewport>
void
ViewportState<Viewport>::setRenderGoupVisibility(SceneGraph::Groups group, bool state)
{
	this->scenegraph.rendering_groups[group].render = state;
}


template <class Viewport>
void
ViewportState<Viewport>::mouseMoveEvent(Viewport *viewport, QMouseEvent *event)
{
	assert(viewport != NULL);

	int dx = event->x() - viewport->viewport_data.lastPos.x();
	int dy = event->y() - viewport->viewport_data.lastPos.y();

	if (event->buttons() & Qt::LeftButton) 
	{
		//TODO set action for left click button
	} else if (event->buttons() & Qt::RightButton) 
	{
		viewport->viewport_data.camera.rotation.data[0] += dy/pow(2,viewport->viewport_data.zoom);
		viewport->viewport_data.camera.rotation.data[1] += dx/pow(2,viewport->viewport_data.zoom);
	}

	viewport->viewport_data.lastPos = event->pos();
}


template <class Viewport>
void
ViewportState<Viewport>::keyPressEvent ( Viewport *, QKeyEvent * event )
{
	qWarning("not keypressed");
	event->ignore();
}


template <class Viewport>
void
ViewportState<Viewport>::setSelection(Selection)
{
}


template <class Viewport>
void 
ViewportState<Viewport>::clearSelection()
{
}


#endif
