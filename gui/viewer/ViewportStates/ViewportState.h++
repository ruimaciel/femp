#ifndef VIEWPORT_STATE_HPP
#define VIEWPORT_STATE_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <assert.h>
#include <iostream>
#include <QMouseEvent>

#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>

#include "../../Selection.h++"

#include "../BaseViewport.h++"
#include "../ViewportData.h++"
#include "../ViewportColors.h++"
#include "../Camera.h++"
#include "../SceneGraph.h++"


class BaseViewport;

/*
The base state pattern that is used to implement the ViewportState's model rendering states
*/
class ViewportState
{
protected:
	SceneGraph scenegraph;	// TODO push the scenegraph to the BaseViewport, as it is independent of the state
	float scale;
	
public:
	ViewportState();
	virtual ~ViewportState();

	/*
	Initializes everything needed in a ViewportState once the focus is placed on it
	*/
	virtual void initialize(BaseViewport *viewport) = 0;

	/*
	Adds to the scenegraph all the objects being rendered 
	*/
	virtual void populateScenegraph(BaseViewport *viewport) = 0;


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
	void setRenderGroupVisibility(SceneGraph::Groups group, bool state);

	/*
	Routine which will paint each OpenGL scene
	*/
	void paintGL(BaseViewport *viewport);
	virtual void mousePressEvent(BaseViewport *viewport, QMouseEvent *event);
	virtual void mouseMoveEvent(BaseViewport *viewport, QMouseEvent *event);
	virtual void keyPressEvent ( BaseViewport *viewport, QKeyEvent * event );

	/** 
	visitor pattern for the scenegraph
	**/
	void runSceneGraphOperation(Operation::OperationsVisitor &);

	// libsigc++ slots
	virtual void setSelection(Selection);	// sets the selection
	virtual void clearSelection();		// clears the selection list representation

	virtual void showSelection(const Selection);	// only displays the selected objects

	void setSelectionStart(fem::Point const &p);
	void setSelectionEnd(fem::Point const &p);
	void setSelectionOff();

	/** 
	For debugging purposes
	**/
	void addPickRay(fem::Point const &origin, fem::Point const &destination, float const &radius);

	/**
	Sets the relevant policies to render the OpenGL triangles with a wireframe
	This isn't implemented in ViewportStates which won't render Opaque objects
	**/
	virtual void setTrianglesVisible(bool const state);
};

#endif
