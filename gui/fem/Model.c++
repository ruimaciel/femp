#include "Model.h++"
#include <algorithm>


namespace fem
{

Model::Model()
{
	default_material = 0;
}


Model::~Model()
{
}


void Model::clear()
{
	node_list.clear();
	element_list.clear();
	material_list.clear();
	node_restrictions_list.clear();
	load_pattern_list.clear();
}


void Model::setNode(size_t ref, double x, double y, double z)
{
	Node n;
	n.set(x,y,z);
	this->node_list[ref] = n;
}


void Model::setNode(size_t ref, fem::point p)
{
	Node n;
	n.x(p.x());
	n.y(p.y());
	n.z(p.z());
	this->node_list[ref] = n;
}


void Model::pushElement(fem::Element e)
{
	e.material = default_material;
	this->element_list.push_back(e);
}


void Model::pushElement(fem::Element::Type type, std::vector<size_t> nodes)
{
	fem::Element e;
	e.set(type,nodes);
	e.material = default_material;
	this->pushElement(e);
}


enum Model::Error Model::pushNodeRestrictions(size_t pos, fem::NodeRestrictions nr)
{
	// check if node is set
	if(node_list.find(pos) == node_list.end())
		return ERR_INVALID_NODE_REFERENCE;

	//TODO perform aditional error checking

	// push node restrictions object
	node_restrictions_list[pos] = nr;

	// everything went smoothly
	return ERR_OK;
}


enum Model::Error Model::pushLoadPattern(fem::LoadPattern lp)
{
	//TODO perform error checks

	load_pattern_list.push_back(lp);

	return ERR_OK;
}


enum Model::Error Model::sanity_check()
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
				return ERR_ELEMENT_NODE_REFERENCE;
		}
	}

	//test node_restrictions_list
	//TODO finish this
	return ERR_OK;
}


}
