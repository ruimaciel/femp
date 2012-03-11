#ifndef SCENE_GRAPH_COMPONENT_PICK_RAY_HPP
#define SCENE_GRAPH_COMPONENT_PICK_RAY_HPP


#include "SceneGraphComponent.h++"
#include "Operations/OperationsVisitor.h++"

#include "../../fem/point.h++"
#include "../../fem/NodeRestrictions.h++"
#include "../../fem/LinearAnalysis.h++"

#include "DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"


namespace SGC
{

/**
Scene graph component used to debug picking operation
**/
class PickRay
	: public SceneGraphComponent
{
protected:
	fem::point m_origin, m_destination;
	float radius;

public:
	PickRay(fem::point const &origin,fem::point const &destination, float const &radius);
	~PickRay();

	/*
	Renders this node
	*/
	void paintGL(ViewportData &data, ViewportColors &colors);

	/*
	Visitor pattern method
	*/
	void accept(Operation::OperationsVisitor &visitor);
};

}	// namespace SGC

#endif
