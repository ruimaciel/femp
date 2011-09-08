#ifndef SCENE_GRAPH_COMPONENT_NODE_RESTRICTION_HPP
#define SCENE_GRAPH_COMPONENT_NODE_RESTRICTION_HPP


#include "SceneGraphComponent.h++"
#include "Operations/OperationsVisitor.h++"

#include "../ViewportData.h++"
#include "../ViewportColors.h++"
#include "../../fem/Model.h++"

#include "../../fem/Node.h++"
#include "../../fem/NodeRestrictions.h++"
#include "../../fem/LinearAnalysis.h++"
#include "DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"


namespace SGC
{

class NodeRestrictions
	: public SceneGraphComponent
{
protected:
	fem::node_ref_t	m_node_reference;
	fem::node_restriction_ref_t	m_node_restrictions_reference;
	fem::NodeRestrictions *m_node_restrictions;
	DisplacementsRepresentationPolicy *m_displacements;

public:
	NodeRestrictions(const fem::node_ref_t &node_reference, const fem::node_restriction_ref_t &node_restrictions_reference, fem::NodeRestrictions &node_restrictions, DisplacementsRepresentationPolicy *displacements);
	//Element(fem::Element &reference_element, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements);
	~NodeRestrictions();


	/*
	Renders this node
	*/
	// void paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> * result,  float &scale, ViewportColors &colors);
	void paintGL(ViewportData &data, ViewportColors &colors);

	/*
	Visitor pattern method
	*/
	void accept(OperationsVisitor &visitor);

protected:
	void renderNodeRestriction();
};

}	// namespace SGC

#endif
