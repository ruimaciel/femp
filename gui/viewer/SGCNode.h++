#ifndef SCENE_GRAPH_COMPONENT_NODE_HPP
#define SCENE_GRAPH_COMPONENT_NODE_HPP


#include "SceneGraphComponent.h++"

#include "../fem/Node.h++"


class SGCNode
	: public SceneGraphComponent
{
	protected:
		fem::Node *node;

	public:
		SGCNode();
		~SGCNode();


		void setReferenceNode(fem::Node &);

		/*
		Renders this node
		*/
		void paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors);
};

#endif
