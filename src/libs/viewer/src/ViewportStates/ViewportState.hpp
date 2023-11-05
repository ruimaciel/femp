#ifndef FEMP_VIEWER_VIEWPORTSTATE_HPP
#define FEMP_VIEWER_VIEWPORTSTATE_HPP

#include <QMouseEvent>
#include <libfemp/AnalysisResult.hpp>
#include <selection/Selection.hpp>

#include "../SceneGraph.hpp"

class BaseViewport;

/**
 * The base state pattern that is used to implement the ViewportState's model
 * rendering states
 */
class ViewportState {
	protected:
	SceneGraph scenegraph;
	float scale = 1.0f;

	public:
	virtual ~ViewportState();

	/**
	 * Initializes everything needed in a ViewportState once the focus is placed
	 * on it
	 */
	virtual void initialize(BaseViewport* viewport) = 0;

	/**
	 * Adds to the scenegraph all the objects being rendered
	 */
	virtual void populateScenegraph(BaseViewport* viewport) = 0;

	/**
	 * Configures the viewport to render the scene according to new_result
	 */
	virtual void setAnalysisResult(fem::AnalysisResult& new_result);

	virtual void setDisplacementsScale(float new_scale);

	/**
	 * Sets the visibility of a SceneGraph render group
	 * @param	group	scene graph render group code, as defined in class
	 * SceneGraph
	 * @param	state	true if visible, false if invisible
	 */
	void setRenderGroupVisibility(SceneGraph::Groups group, bool state);

	/**
	 * Routine which will paint each OpenGL scene
	 */
	void paintGL(BaseViewport* viewport);
	virtual void mousePressEvent(BaseViewport* viewport, QMouseEvent* event);
	virtual void mouseMoveEvent(BaseViewport* viewport, QMouseEvent* event);
	virtual void keyPressEvent(BaseViewport* viewport, QKeyEvent* event);

	/**
	 * Visitor pattern for the scenegraph
	 */
	void runSceneGraphOperation(Operation::OperationsVisitor&);

	virtual void setSelection(Selection);  // sets the selection
	virtual void clearSelection();		   // clears the selection list representation

	virtual void showSelection(const Selection);  // only displays the selected objects

	void setSelectionStart(fem::Point3D const& p);
	void setSelectionEnd(fem::Point3D const& p);
	void setSelectionOff();

	/**
	 * For debugging purposes
	 */
	void addPickRay(fem::Point3D const& origin, fem::Point3D const& destination, float const& radius);

	/**
	 * Sets the relevant policies to render the OpenGL triangles with a wireframe
	 * This isn't implemented in ViewportStates which won't render Opaque objects
	 */
	virtual void setTrianglesVisible(bool const state);
};

#endif
