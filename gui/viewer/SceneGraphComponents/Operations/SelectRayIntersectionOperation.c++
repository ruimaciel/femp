#include "SelectRayIntersectionOperation.h++"

#include <iostream>


namespace Operation
{


SelectRayIntersectionOperation::SelectRayIntersectionOperation(Selection &selection, fem::point const &origin, fem::point const &destination, float const &radius)
{
	this->m_selection = &selection;
	m_origin = origin;
	m_destination = destination;
	r = radius;	// TODO change this to reflect render radius


	std::cerr << "pick ray: " << origin << ", " << destination << ", radius: " << radius << std::endl;
}


void 
SelectRayIntersectionOperation::visit(SceneGraphComponent &) 
{
}


void 
SelectRayIntersectionOperation::visit(SGC::Node &node)
{
	/*
	if( m_selection.m_nodes_selected.find(node.reference()) != m_selection.m_nodes_selected.end())
		node.render = m_render_state;
	else
		node.render = !m_render_state;
	 */
	fem::point d = (m_destination - m_origin);
	A = dot_product(d,d);
	B = 2*dot_product(m_origin - node.pos(),d);
	C = dot_product(m_origin - node.pos(), m_origin - node.pos() ) - r*r;

	if( B*B - 4*A*C >= 0 )
	{
		// ray intersects node
		//TODO tweak this so that the closest node is the only node selected
		m_selection->selectNode(node.reference());
		std::cerr << "selected" << node.reference() << ", " << node.pos() << std::endl;
	}
	else
		std::cerr << "not selected" << node.reference() << ", " << node.pos() << std::endl;
}


void 
SelectRayIntersectionOperation::visit(SGC::Element &element)
{
	// if element is selected
	/*
	if( m_selection.m_elements_selected.find(element.reference()) != m_selection.m_elements_selected.end())
		element.render = m_render_state;
	else
		element.render = !m_render_state;
	*/
	//std::cerr << "SelectRayIntersectionOperation::visit(SGC::Element &element)" << std::endl;
}


}


