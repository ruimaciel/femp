#ifndef VIEWPORT_STATE_MODEL_HPP
#define VIEWPORT_STATE_MODEL_HPP

#include <QMouseEvent>
#include <options/Options.hpp>
#include <viewer/ViewportData.hpp>

#include "../SceneGraphComponents/DisplacementsRepresentationPolicy/NoDisplacementsPolicy.hpp"
#include "../SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationFlyweightFactory.hpp"
#include "../SceneGraphComponents/SceneComponentFactory.hpp"
#include "ViewportState.hpp"

class BaseViewport;

/**
 * A pattern for the State pattern which is used to render the model space
 */
class VPStateModel : public ViewportState {
	protected:
	ElementRepresentationFlyweightFactory m_element_representation_factory;
	NoDisplacementsPolicy m_no_displacements;  // the model view doesn't render displacements
	SGC::SceneComponentFactory m_factory;

	public:
	VPStateModel();
	~VPStateModel();

	void initialize(BaseViewport* viewport) override;
	void populateScenegraph(BaseViewport* viewport) override;

	/**
	 * Tweaks the way the viewport is rendered according to the current selection
	 */
	void setSelection(Selection) override;

	void keyPressEvent(BaseViewport* viewport, QKeyEvent* event) override;

	/**
	 * Sets the relevant policies to render the OpenGL triangles with a wireframe
	 * This isn't implemented in ViewportStates which won't render Opaque objects
	 */
	void setTrianglesVisible(bool const state) override;
};

#endif
