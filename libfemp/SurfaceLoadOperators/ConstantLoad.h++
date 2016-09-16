#ifndef FEMP_SURFACELOADOPERATORS_CONSTANTLOAD_HPP
#define FEMP_SURFACELOADOPERATORS_CONSTANTLOAD_HPP


#include <libfemp/SurfaceLoadOperators/SurfaceLoadOperator.h++>
#include <libfemp/point.h++>

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
