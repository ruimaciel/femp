#ifndef FEMP_SURFACELOADOPERATORS_SURFACENORMALLOAD_HPP
#define FEMP_SURFACELOADOPERATORS_SURFACENORMALLOAD_HPP


#include <libfemp/SurfaceLoadOperators/SurfaceLoadOperator.h++>
#include <libfemp/elements/BaseElement.h++>
#include <libfemp/loads/Triangle3.h++>
#include <libfemp/loads/Triangle6.h++>
#include <libfemp/loads/Quadrangle4.h++>
#include <libfemp/loads/Quadrangle8.h++>
#include <libfemp/loads/Quadrangle9.h++>


namespace fem
{

/**
Defines a surface load which is normal to the surface
**/
class SurfaceNormalLoad
	: public SurfaceLoadOperator
{
protected:
	float m_magnitude;
	fem::BaseElement *element;	// used to store a pointer to the current object: nasty hack due to the way fem::Element was done

	fem::Triangle3 m_tri3;
	fem::Triangle6 m_tri6;
	fem::Quadrangle4 m_quad4;
	fem::Quadrangle8 m_quad8;
	fem::Quadrangle9 m_quad9;

public:
	SurfaceNormalLoad();

	void setLoadMagnitude(float const &magnitude);

	void operator() (fem::SurfaceLoad &surface_load, fem::Model &model);
};

}	// namespace fem


#endif
