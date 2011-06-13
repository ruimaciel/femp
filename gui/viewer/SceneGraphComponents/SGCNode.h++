#ifndef SCENE_GRAPH_COMPONENT_NODE_HPP
#define SCENE_GRAPH_COMPONENT_NODE_HPP


#include "SceneGraphComponent.h++"
#include "../OperationsVisitor.h++"

#include "../../fem/Project.h++"
#include "../../fem/Node.h++"
#include "../../fem/NodeRestrictions.h++"
#include "../../fem/LinearAnalysis.h++"


class SGCNode
	: public SceneGraphComponent
{
	protected:
		size_t node_label;
		fem::Node *node;

	public:
		SGCNode(size_t, fem::Project &project);
		~SGCNode();


		/*
		Renders this node
		*/
		void paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result, float &scale, ViewportColors &colors);

		/*
		Visitor pattern method
		*/
		void accept(OperationsVisitor &v);
};

#endif
