#ifndef SURFACE_LOAD_OPERATOR_HPP
#define SURFACE_LOAD_OPERATOR_HPP


#include "../Model.h++"
#include "../SurfaceLoad.h++"

namespace fem
{
/**
Abstract base class for an operator which is applied to a surface load
**/

class SurfaceLoadOperator
{
public:
	SurfaceLoadOperator();

	/**
	functor
	**/
	virtual void operator() (fem::SurfaceLoad &surface_load, fem::Model &model) = 0;
};

}	// namespace fem
#endif

