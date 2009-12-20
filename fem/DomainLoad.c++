#include "DomainLoad.h++"


namespace fem
{

DomainLoad::DomainLoad()
{
}


DomainLoad::DomainLoad(const DomainLoad &copied)
{
	this->force_shape = copied.force_shape;
}


DomainLoad::~DomainLoad()
{
}

}
