#ifndef SCENE_GRAPH_COMPONENT_NODE_HPP
#define SCENE_GRAPH_COMPONENT_NODE_HPP


#include "SceneGraphComponent.h++"
#include "Operations/OperationsVisitor.h++"

#include "../../fem/Node.h++"
#include "../../fem/NodeRestrictions.h++"
#include "../../fem/LinearAnalysis.h++"

#include "DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"


/**
Scene graph component which renders a node
**/
class SGCNode
	: public SceneGraphComponent
{
protected:
	size_t node_label;
	fem::Node *m_node;
	DisplacementsRepresentationPolicy *m_displacements;

public:
	SGCNode(size_t, fem::Node &node, DisplacementsRepresentationPolicy *displacements);
	~SGCNode();


	/*
	Renders this node
	*/
	void paintGL(ViewportData &data, ViewportColors &colors);

	/*
	Visitor pattern method
	*/
	void accept(OperationsVisitor &visitor);
};

#endif
