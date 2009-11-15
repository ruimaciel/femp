#include "Element.h++"


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

}
