#include "Model.h++"


namespace fem
{

Model::Model()
{
}


Model::~Model()
{
}


void Model::setNode(size_t pos, double x, double y, double z)
{
	Node n;
	n.set(x,y,z);
	this->node_list[pos] = n;
}

}

