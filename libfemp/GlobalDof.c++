#include "GlobalDof.h++"


namespace fem
{

GlobalDof::GlobalDof(Node const &node, ParameterType &parameter_type)
	: m_node(node), m_parameter_type(parameter_type)
{
}


Node 
GlobalDof::getNode() const
{
	return this->m_node;
}


ParameterType 
GlobalDof::getParameterType() const
{
	return this->m_parameter_type;
}


GlobalDof &
GlobalDof::operator=(const GlobalDof & copied)
{
	this->m_node = copied.getNode();
	this->m_parameter_type = copied.getParameterType();

	return *this;
}


/**
 * Relational order operator
 **/
bool operator==(const GlobalDof &lhs, const GlobalDof &rhs)
{
	Node const node_a = lhs.getNode();
	Node const node_b = rhs.getNode();

	// lexicographical order of [x, y, z, param]

	return	node_a.x() == node_b.x() && 
		node_a.y() == node_b.y() && 
		node_a.z() == node_b.z() && 
		lhs.getParameterType() == rhs.getParameterType();
}


/**
 * Relational order operator
 **/
bool operator<(const GlobalDof &lhs, const GlobalDof &rhs)
{
	Node const node_a = lhs.getNode();
	Node const node_b = rhs.getNode();

	// lexicographical order of [x, y, z, param]

	if(node_a.x() < node_b.x())
		return true;
	else if(node_a.x() > node_b.x())
		return false;
	else
	{
		if(node_a.y() < node_b.y())
			return true;
		else if(node_a.y() > node_b.y())
			return false;
		else
		{
			if(node_a.z() < node_b.z())
				return true;
			else if(node_a.z() > node_b.z())
				return false;
			else
			{
				return lhs.getParameterType() < rhs.getParameterType();
			}
		}
	}
}


}	// namespace fem

