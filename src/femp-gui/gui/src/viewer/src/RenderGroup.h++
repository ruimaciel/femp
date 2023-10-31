#ifndef VIEWER_RENDERGROUP_HPP
#define VIEWER_RENDERGROUP_HPP

// viewer includes
#include "SceneGraphComponents/SceneGraphComponent.h++"
#include <viewer/ViewportData.h++>

// gui includes
#include <options/Options.h++>

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
