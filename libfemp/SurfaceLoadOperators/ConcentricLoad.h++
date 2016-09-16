#ifndef FEMP_SURFACELOADOPERATORS_CONCENTRICLOAD_HPP
#define FEMP_SURFACELOADOPERATORS_CONCENTRICLOAD_HPP


#include <libfemp/SurfaceLoadOperators/SurfaceLoadOperator.h++>
#include <libfemp/elements/BaseElement.h++>
#include <libfemp/elements/Triangle3.h++>
#include <libfemp/elements/Triangle6.h++>
#include <libfemp/elements/Quadrangle4.h++>
#include <libfemp/elements/Quadrangle8.h++>
#include <libfemp/elements/Quadrangle9.h++>


namespace fem
{

/**
Defines a surface load whose load vectors converge in a point in space
**/
class ConcentricLoad
	: public SurfaceLoadOperator
{
protected:
	float m_magnitude;
	fem::point m_center;	// the center point where the pressure converges

	fem::BaseElement<float> *element;	// used to store a pointer to the current object: nasty hack due to the way fem::Element was done

	fem::Triangle3<float> m_tri3;
	fem::Triangle6<float> m_tri6;
	fem::Quadrangle4<float> m_quad4;
	fem::Quadrangle8<float> m_quad8;
	fem::Quadrangle9<float> m_quad9;

public:
	ConcentricLoad();

	void setLoadMagnitude(float const &magnitude);
	void setConvergencePoint(fem::point const &center);

	void operator() (fem::SurfaceLoad &surface_load, fem::Model &model);
};

}	// namespace fem

#endif
