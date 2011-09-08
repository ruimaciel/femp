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


namespace SGC
{

class NodeRestrictions
	: public SceneGraphComponent
{
protected:
	fem::Node	* m_node;
	fem::NodeRestrictions *m_node_restrictions;

public:
	NodeRestrictions(fem::Node &node, fem::NodeRestrictions &node_restrictions);
	~NodeRestrictions();


	/*
	Renders this node
	*/
	void paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> * result,  float &scale, ViewportColors &colors);

	/*
	Visitor pattern method
	*/
	void accept(OperationsVisitor &visitor);

protected:
	void renderNodeRestriction();
};

}	// namespace SGC

#endif
