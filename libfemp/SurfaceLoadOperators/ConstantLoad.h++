#ifndef CONSTANT_LOAD_HPP
#define CONSTANT_LOAD_HPP

#include "SurfaceLoadOperator.h++"

#include "../point.h++"

namespace fem
{

/**
Applies a constant load in relation to the global coordinate system
**/
class ConstantLoad
	: public SurfaceLoadOperator
{
protected:
	fem::point m_force;

public:
	ConstantLoad();

	void setLoad(fem::point const &force);

	void operator() (fem::SurfaceLoad &surface_load, fem::Model &model);
};

}	// namespace fem

#endif
