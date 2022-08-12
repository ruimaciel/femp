#ifndef VIEWPORT_STATE_DISPLACEMENTS_HPP
#define VIEWPORT_STATE_DISPLACEMENTS_HPP

#include <QMouseEvent>

#include "../BaseViewport.h++"
#include "../SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsPolicy.h++"
#include "../SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationFlyweightFactory.h++"
#include "../SceneGraphComponents/SceneComponentFactory.h++"
#include "ViewportState.h++"

class BaseViewport;

/**
 * A pattern for the State pattern which is used to render the displacements
 */
class VPStateDisplacements : public ViewportState {
   protected:
	ElementRepresentationFlyweightFactory m_element_representation_factory;
	DisplacementsPolicy m_displacements;  // the displacements view renders displacements
	SGC::SceneComponentFactory m_factory;

   public:
	VPStateDisplacements();
	~VPStateDisplacements();

	void initialize(BaseViewport* viewport);
	void populateScenegraph(BaseViewport* viewport);

	/**
	 * Configures the viewport to render the scene according to new_result
	 */
	void setAnalysisResult(fem::AnalysisResult& new_result);

	void setDisplacementsScale(float new_scale);

	/**
	 * Tweaks the way the viewport is rendered according to the current selection
	 */
	void setSelection(Selection);

	void keyPressEvent(BaseViewport* viewport, QKeyEvent* event);

	/**
	 * Sets the relevant policies to render the OpenGL triangles with a wireframe
	 * This isn't implemented in ViewportStates which won't render Opaque objects
	 */
	void setTrianglesVisible(bool const state);
};

#endif
