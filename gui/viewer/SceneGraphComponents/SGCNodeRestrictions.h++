#ifndef SCENE_GRAPH_COMPONENT_NODE_RESTRICTION_HPP
#define SCENE_GRAPH_COMPONENT_NODE_RESTRICTION_HPP


#include "SceneGraphComponent.h++"
#include "../OperationsVisitor.h++"

#include "../ViewportData.h++"
#include "../ViewportColors.h++"
#include "../../fem/Model.h++"

#include "../../fem/Node.h++"
#include "../../fem/NodeRestrictions.h++"
#include "../../fem/LinearAnalysis.h++"


class SGCNodeRestrictions
	: public SceneGraphComponent
{
	protected:
		fem::Node	* m_node;
		fem::NodeRestrictions *m_node_restrictions;

	public:
		SGCNodeRestrictions(fem::Node &node, fem::NodeRestrictions &node_restrictions);
		~SGCNodeRestrictions();


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
