#include "Model.h++"
#include <algorithm>

#include <cstdlib>
#include <cstring>

#include <iostream>	//TODO remove this: debugging only
#include <vector>
#include <stack>

#include "FemException.h++"



namespace fem
{

Model::Model()
{
	default_material = 0;

	// add default steel material
	Material material;

	material.label = "Steel";
	material.type = Material::MAT_LINEAR_ELASTIC;
	material.E = 200e9;
	material.nu = 0.3;

	this->material_list.push_back(material);

}


Model::~Model()
{
}


void 
Model::clear()
{
	node_list.clear();
	element_list.clear();
	material_list.clear();
	node_restrictions_list.clear();
	load_pattern_list.clear();

	m_node_groups.clear();
	m_element_groups.clear();
}


void 
Model::setNode(size_t ref, double x, double y, double z)
{
	Node n;
	n.set(x,y,z);
	this->node_list[ref] = n;
}


void 
Model::setNode(size_t ref, fem::point p)
{
	Node n;
	n.x(p.x());
	n.y(p.y());
	n.z(p.z());
	this->node_list[ref] = n;
}


Model::Error 
Model::pushMaterial(fem::Material &material)
{
	material_list.push_back(material);
	return ERR_OK;
}


Model::Error 
Model::pushElement(fem::Element &e)
{
	// check if element is valid
	switch(e.type)
	{
		case Element::FE_TETRAHEDRON4:
			if(e.nodes.size() != 4)
				return ERR_NODE_NUMBER;
			break;;

		case Element::FE_TETRAHEDRON10:
			if(e.nodes.size() != 10)
				return ERR_NODE_NUMBER;
			break;;

		case Element::FE_HEXAHEDRON8:
			if(e.nodes.size() != 8)
				return ERR_NODE_NUMBER;
			break;;

		case Element::FE_HEXAHEDRON20:
			if(e.nodes.size() != 20)
				return ERR_NODE_NUMBER;
			break;;

		case Element::FE_HEXAHEDRON27:
			if(e.nodes.size() != 27)
				return ERR_NODE_NUMBER;
			break;;

		case Element::FE_PRISM6:
			if(e.nodes.size() != 6)
				return ERR_NODE_NUMBER;
			break;;

		case Element::FE_PRISM15:
			if(e.nodes.size() != 15)
				return ERR_NODE_NUMBER;
			break;;

		case Element::FE_PRISM18:
			if(e.nodes.size() != 18)
				return ERR_NODE_NUMBER;
			break;;

		default:
			throw FemException("Stumbled on a unsupported type");
			std::cerr << "Model::Error Model::pushElement(): unsupported element type " << e.type << std::endl;
			return ERR_UNSUPPORTED_ELEMENT;
			break;
	}

	// push element to the element list
	e.material = default_material;
	this->element_list.push_back(e);

	return ERR_OK;
}


Model::Error 
Model::pushElement(fem::Element::Type type, std::vector<size_t> nodes)
{
	fem::Element e;
	e.set(type,nodes);

	return this->pushElement(e);
}


enum Model::Error 
Model::pushNodeRestrictions(size_t pos, fem::NodeRestrictions nr)
{
	// check if node is set
	if(node_list.find(pos) == node_list.end())
	{
		throw FemException("Invalid node reference");
		return ERR_INVALID_NODE_REFERENCE;
	}
	

	//TODO perform aditional error checking

	// push node restrictions object
	node_restrictions_list[pos] = nr;

	// everything went smoothly
	return ERR_OK;
}


enum Model::Error 
Model::popNodeRestrictions(node_ref_t const &node)
{
	node_restrictions_list.erase(node);
	return ERR_OK;
}


enum Model::Error 
Model::pushLoadPattern(fem::LoadPattern lp)
{
	//TODO perform error checks

	load_pattern_list.push_back(lp);

	return ERR_OK;
}


enum Model::Error 
Model::pushNodeGroup(fem::NodeGroup &new_node_group)
{
	this->m_node_groups.push_back(new_node_group);
	return ERR_OK;
}


enum Model::Error 
Model::pushElementGroup(fem::ElementGroup &new_element_group)
{
	this->m_element_groups.push_back(new_element_group);
	return ERR_OK;
}


enum Model::Error 
Model::sanity_check()
{
	// check if the Element's nodes are right
	for( std::vector<Element>::iterator it = element_list.begin(); it != element_list.end(); it++)
	{
		// check if the referenced material exists
		if(material_list.size() > (size_t)it->material)
			return ERR_INVALID_MATERIAL_REFERENCE;

		// check node's type
		switch(it->type)
		{
			case Element::FE_LINE2:
				if(it->nodes.size() != 2)
				{
					return ERR_NODE_NUMBER;
				}
				break;

			case Element::FE_TETRAHEDRON4:
				if(it->nodes.size() != 4)
				{
					return ERR_NODE_NUMBER;
				}
				break;

			case Element::FE_TETRAHEDRON10:
				if(it->nodes.size() != 10)
				{
					return ERR_NODE_NUMBER;
				}
				break;


			case Element::FE_HEXAHEDRON8:
				if(it->nodes.size() != 8)
				{
					return ERR_NODE_NUMBER;
				}
				break;

			case Element::FE_HEXAHEDRON20:
				if(it->nodes.size() != 20)
				{
					return ERR_NODE_NUMBER;
				}
				break;

			case Element::FE_HEXAHEDRON27:
				if(it->nodes.size() != 27)
				{
					return ERR_NODE_NUMBER;
				}
				break;

			default:
				return ERR_UNSUPPORTED_ELEMENT;
				break;
		}

		// run a sanity check on the node's references
		for(std::vector<size_t>::iterator n = it->nodes.begin(); n != it->nodes.end(); n++)
		{
			if(node_list.find(*n) == node_list.end())
			{
				throw FemException("Element node reference");	// clear up this error
				return ERR_ELEMENT_NODE_REFERENCE;
			}
		}
	}

	//TODO test node_restrictions_list
	return ERR_OK;
}


}
