#ifndef SCENE_GRAPH_COMPONENT_NODE_HPP
#define SCENE_GRAPH_COMPONENT_NODE_HPP


#include "SceneGraphComponent.h++"
#include "Operations/OperationsVisitor.h++"

#include "../../fem/Node.h++"
#include "../../fem/NodeRestrictions.h++"
#include "../../fem/LinearAnalysis.h++"

#include "DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"


namespace SGC
{

/**
Scene graph component which renders a node
**/
class Node
	: public SceneGraphComponent
{
protected:
	fem::node_ref_t node_label;
	fem::Node *m_node;
	DisplacementsRepresentationPolicy *m_displacements;

public:
	Node(size_t, fem::Node &node, DisplacementsRepresentationPolicy *displacements);
	~Node();


	/*
	Renders this node
	*/
	void paintGL(ViewportData &data, ViewportColors &colors);

	fem::node_ref_t const &reference() const	{ return node_label; }

	fem::point const &pos()	const	{ return *m_node; }

	/*
	Visitor pattern method
	*/
	void accept(OperationsVisitor &visitor);
};

}	// namespace SGC

#endif
