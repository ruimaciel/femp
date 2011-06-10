#ifndef SCENE_GRAPH_COMPONENT_NODE_HPP
#define SCENE_GRAPH_COMPONENT_NODE_HPP


#include "SceneGraphComponent.h++"
#include "../OperationsVisitor.h++"

#include "../../fem/Node.h++"
#include "../../fem/NodeRestrictions.h++"
#include "../../fem/LinearAnalysis.h++"


class SGCNode
	: public SceneGraphComponent
{
	protected:
		size_t node_label;
		fem::Node *node;
		std::map<size_t, fem::NodeRestrictions> *node_restrictions_map;

	public:
		SGCNode(size_t, fem::Node &, std::map<size_t, fem::NodeRestrictions> &);
		~SGCNode();


		void setReferenceNode(fem::Node &);

		/*
		Renders this node
		*/
		void paintGL(ViewportData &data, fem::Project &project, ViewportColors &colors);

		/*
		Visitor pattern method
		*/
		void accept(OperationsVisitor &v);
};

#endif
