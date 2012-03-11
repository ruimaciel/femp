#include "SelectFrustumInclusionOperation.h++"

#include <iostream>

SelectFrustumInclusionOperation::SelectFrustumInclusionOperation(Selection &selection, std::array<fem::point,4> const &near, std::array<fem::point,4> const &far)
{
	this->m_selection = &selection;
	m_near = near;
	m_far = far;

	calculateNormalVectors(near, far);
}


void 
SelectFrustumInclusionOperation::visit(SceneGraphComponent &) 
{
	
}


void 
SelectFrustumInclusionOperation::visit(SGC::Node &node)
{
	// test first plane
	for(int i = 0; i < 4; i++)
	{
		std::cerr << "normal[" << i << "]: " << m_normal[i] << std::endl;
		if( dot_product(m_normal[i], node.pos() - m_near[i]) < 0)
			return;
	}

	m_selection->selectNode(node.reference());
}


void 
SelectFrustumInclusionOperation::visit(SGC::Element &element)
{
}


void 
SelectFrustumInclusionOperation::calculateNormalVectors(std::array<fem::point, 4> const &near, std::array<fem::point, 4> const &far)
{
	auto calc = [](fem::point const &p0, fem::point const &p1, fem::point const &p2) -> fem::point
	{
		// calculates the normal vector which is perpendicular to the plane defined by (p1-p0),(p2-p0)
		fem::point n = cross_product( p1-p0, p2-p0);
		std::cerr << "calculate normal" << n << std::endl;
		n.normalize();
		return n;
	};

	m_normal[0] = calc(near[0], near[1], far[0]);
	m_normal[1] = calc(near[1], near[2], far[1]);
	m_normal[2] = calc(near[2], near[3], far[2]);
	m_normal[3] = calc(near[3], near[0], far[3]);
}


