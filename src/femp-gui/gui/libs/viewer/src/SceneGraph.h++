#ifndef SCENE_GRAPH_HPP
#define SCENE_GRAPH_HPP

#include <GL/gl.h>

#include <list>
#include <map>
#include <memory>

class SceneGraphComponent;

#include <options/Options.h++>

#include "RenderGroup.h++"
#include "SceneGraphComponents/hud/HudSelection.h++"
#include <viewer/ViewportData.h++>

/**
 * Facade pattern for the scenegraph structure
 **/
class SceneGraph {
	public:
	enum Groups	 // common groups for all scenegraphs
	{
		RG_NODES,			// the element nodes
		RG_SURFACES,		// the opaque surfaces used in ModelViewport an
							// DisplacementsViewport
		RG_WIREFRAME,		// wireframe of the opaque surfaces.  This group and
							// RG_SURFACES are mutually explusive
		RG_GHOST_SURFACES,	// surfaces rendered in the displacement viewport to
							// show the model's original configuration
		RG_NODE_RESTRICTIONS
	};

	public:
	SceneGraph();
	~SceneGraph();

	/**
	 * Clears all the data structures managed by this class
	 **/
	void clear();

	void paint(ViewportData& viewport_data, ViewportColors colors);

	/**
	 * Generic routine to add a primitive component to this scenegraph
	 * The template was provided for syntax convenience only; this class only
	 *accepts specific types derived from SceneGraphComponent
	 * @param group	destination RenderGroup
	 * @param *newcomponent	new scenegraph component
	 **/
	void addPrimitiveComponent(enum Groups group, std::shared_ptr<SceneGraphComponent> new_component);

	/**
	 * Generate a new scenegraph tree from the current list of primitive
	 *components
	 **/
	void generateSceneGraph();

	/**
	 * visitor pattern for the scenegraph
	 * @param	visitor	class which will act on each object
	 **/
	void runOperation(Operation::OperationsVisitor&);

	void setSelectionStart(fem::Point3D const& p);
	void setSelectionEnd(fem::Point3D const& p);
	void setSelectionOff();

	public:
	std::map<enum Groups, RenderGroup> rendering_groups;

	private:
	/**
	 * This is the master list of all scene graph objects in this scene graph.
	 * It is used to store every object of type SGCSurface (etc...) managed by
	 *this scenegraph.
	 **/
	std::list<std::shared_ptr<SceneGraphComponent>> m_primitive_components;

	hud::Selection m_selection;	 // HUD object to render selection
};

#endif
