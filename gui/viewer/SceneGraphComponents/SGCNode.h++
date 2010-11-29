#ifndef SCENE_GRAPH_COMPONENT_NODE_HPP
#define SCENE_GRAPH_COMPONENT_NODE_HPP


#include "SceneGraphComponent.h++"
#include "../OperationsVisitor.h++"

#include "../../fem/Node.h++"
#include "../../fem/LinearAnalysis.h++"


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

		/*
		Visitor pattern method
		*/
		void accept(OperationsVisitor &v);
};

#endif
