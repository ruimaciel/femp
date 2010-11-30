#ifndef SCENE_GRAPH_COMPONENT_HPP
#define SCENE_GRAPH_COMPONENT_HPP


#include <list>

#include "../ViewportData.h++"
#include "../ViewportColors.h++"

#include "../boundaries/BoundaryStrategy.h++"	// a definition of a bounding volume through the use of a strategy pattern
#include "../boundaries/SphericalBoundary.h++"

#include "../OperationsVisitor.h++"

#include "../../fem/Model.h++"
#include "../../fem/LinearAnalysis.h++"



/*
Component class which is used to implement a bounding volume hierarchy for the scene graph through a composit design pattern
**/
class SceneGraphComponent
{
	public:
		std::list<SceneGraphComponent *> children;	// list of all child objects which are a part of the composition
		SphericalBoundary boundary;	// a boundary volume which contains this component

		static float detail_factor;	// test value which is used to set the detail level of the drawings

	public:
		bool selected;

	public:
		SceneGraphComponent();
		~SceneGraphComponent();

		static void setDetailFactor(const float & new_detail_factor) { detail_factor = new_detail_factor; }

		/*
		Render the content of this Scenegraph component
		*/
		virtual void paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors);

		/*
		Pushes a new scenegraph component to this component's children's list
		This routine makes a copy of object new_component and adds a pointer to thew new object in the children's list
		*/
		void pushComponent(SceneGraphComponent *new_component);

		/*
		Method to be able to implement a Visitor pattern for operations on selected objects
		*/
		virtual void accept(OperationsVisitor &v);
};


#endif
