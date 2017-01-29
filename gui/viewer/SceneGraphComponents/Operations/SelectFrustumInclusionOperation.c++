#include "SelectFrustumInclusionOperation.h++"

#include <iostream>

#include <Project.h++>


namespace Operation
{


SelectFrustumInclusionOperation::SelectFrustumInclusionOperation(Selection &selection, std::array<fem::Point,4> const &near, std::array<fem::Point,4> const &far)
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
	if(node.render)
	{
		for(int i = 0; i < 4; i++)
		{
			if( dot_product(m_normal[i], node.pos() - m_near[i]) < 0)
				return;
		}

		m_selection->selectNode(node.reference());
	}
}


void 
SelectFrustumInclusionOperation::visit(SGC::Element & /*element*/)
{
	//nasty hack: elements are analyzed in the end, after all nodes have been selected
}


void 
SelectFrustumInclusionOperation::selectInclusiveElements(fem::Project &project)
{
	std::set<fem::node_ref_t>::const_iterator i;

	fem::Model &femp_model = project.getModel();
	auto element_list = femp_model.getElementList();
	for( std::vector<fem::Element>::size_type n = 0; n < element_list.size(); n++)
	{
		
		for(auto node: element_list[n].nodes)
		{
			i = m_selection->m_nodes_selected.find(node);
			if(i == m_selection->m_nodes_selected.end())
				break;
		}

		// all elements in the node were found
		if(i != m_selection->m_nodes_selected.end())
		{
			m_selection->selectElement(n);
		}
	}
}


void 
SelectFrustumInclusionOperation::calculateNormalVectors(std::array<fem::Point, 4> const &near, std::array<fem::Point, 4> const &far)
{
	auto calc = [](fem::Point const &p0, fem::Point const &p1, fem::Point const &p2) -> fem::Point
	{
		// calculates the normal vector which is perpendicular to the plane defined by (p1-p0),(p2-p0)
		fem::Point n = cross_product( p1-p0, p2-p0);
		n.normalize();
		return n;
	};

	m_normal[0] = calc(near[0], near[1], far[0]);
	m_normal[1] = calc(near[1], near[2], far[1]);
	m_normal[2] = calc(near[2], near[3], far[2]);
	m_normal[3] = calc(near[3], near[0], far[3]);
}


}
