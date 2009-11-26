#include "Model.h++"


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


void Model::setNode(size_t pos, double x, double y, double z)
{
	Node n;
	n.set(x,y,z);
	this->node_list[pos] = n;
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

}
