#include "NodeRestrictions.h++"


namespace fem
{

NodeRestrictions:: NodeRestrictions()
{
	this->dx = false;
	this->dy = false;
	this->dz = false;
	this->rx = false;
	this->ry = false;
	this->rz = false;
}


NodeRestrictions::NodeRestrictions(const NodeRestrictions &copied)
{
	this->dx = copied.dx;
	this->dy = copied.dy;
	this->dz = copied.dz;
	this->rx = copied.rx;
	this->ry = copied.ry;
	this->rz = copied.rz;
}


NodeRestrictions::~NodeRestrictions()
{
}

}
