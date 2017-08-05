#include "DomainLoad.h++"


namespace fem
{

DomainLoad::DomainLoad()
{
}


DomainLoad::DomainLoad(const DomainLoad &copied)
{
	this->force = copied.force;
}


DomainLoad::~DomainLoad()
{
}


const Point & 
DomainLoad::getForce() const
{
	return this->force;
}


}	// namespace fem
