#ifndef FEMP_VIEWER_RENDERGROUP_HPP
#define FEMP_VIEWER_RENDERGROUP_HPP

// viewer includes
#include <viewer/ViewportData.hpp>

#include "SceneGraphComponents/SceneGraphComponent.hpp"

// gui includes
#include <options/Options.hpp>

// OpenGL includes
#include <GL/gl.h>

// stl includes
#include <list>
#include <memory>

/**
 * Definition of a render group: an independent scene graph branch
 */
struct RenderGroup {
	std::list<std::shared_ptr<SceneGraphComponent>> primitive_components;  // list of primitive components included in this
																		   // group

	SceneGraphComponent scenegraph;

	RenderGroup();

	/**
	 * Generate a new scenegraph tree from the current list of primitive
	 * components
	 */
	void generateSceneGraph();

	void paintGL(ViewportData& data, ViewportColors& colors);

	void setVisible(bool visible = true);
	bool isVisible() const;

	private:
	bool m_render;	// should this group be rendered?
};

#endif
