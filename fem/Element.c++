#include "Element.h++"

#include <iostream>

namespace fem
{

Element::Element()
{
}


Element::Element(const Element &copied)
{
	this->material = copied.material;
	this->nodes = copied.nodes;
	this->type = copied.type;
}

Element::~Element()
{
}

void Element::set(Type type, std::vector<size_t> nodes)
{
	switch(type)
	{
		case FE_LINE2:
			if(nodes.size() != 2)
			{
				std::cerr << "error: FE_LINE2 needs 2 nodes" << std::endl;
				return;
			}
			break;

		case FE_TETRAHEDRON4:
			if(nodes.size() != 4)
			{
				std::cerr << "error: FE_TETRAHEDRON4 needs 4 nodes, has " << nodes.size() << std::endl;
				return;
			}
			break;

		case FE_HEXAHEDRON8:
			if(nodes.size() != 8)
			{
				std::cerr << "error: FE_HEXAHEDRON8 needs 8 nodes" << std::endl;
				return;
			}
			break;

		default:
			std::cerr << "error: unsupported type" << std::endl;
			return;
			break;
	}
	this->type = type;
	this->nodes = nodes;
}


}
