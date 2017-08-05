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


}	// namespace fem

