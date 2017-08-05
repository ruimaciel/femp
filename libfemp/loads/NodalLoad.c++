#include "NodalLoad.h++"

namespace fem
{

NodalLoad::NodalLoad ()
{
}


NodalLoad::NodalLoad (const NodalLoad &copied)
{
	this->force = copied.force;
}


NodalLoad::~NodalLoad ()
{
}


const Point & 
NodalLoad::getForce() const
{
	return this->force;
}


}	// namespace fem

