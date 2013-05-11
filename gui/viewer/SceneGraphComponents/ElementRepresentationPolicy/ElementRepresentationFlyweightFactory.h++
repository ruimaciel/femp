
#ifndef ELEMENTREPRESENTATIONFLYWEIGHTFACTORY_H
#define ELEMENTREPRESENTATIONFLYWEIGHTFACTORY_H

#include "ElementRepresentationPolicy.h++"
#include "OpaqueRepresentationPolicy.h++"
#include "GradientFieldRepresentationPolicy.h++"
#include "GradientFieldPolicy/GradientFieldPolicy.h++"
//#include "TensorFieldRepresentationPolicy.h++"


/**
A flyweight factory pattern to store and provide ways to represent an element
**/
class ElementRepresentationFlyweightFactory
{
protected:
	OpaqueRepresentationPolicy 	m_opaque_policy;
	GradientFieldRepresentationPolicy	m_gradient_policy;
	//TensorFieldRepresentationPolicy	m_tensor_policy;

public:
	ElementRepresentationFlyweightFactory ( );


protected:

public:
	/**
	Sets the current displacements policy for all the ElementRepresentationPolicy objects
	@param	displacements	pointer to a DisplacementsRepresentationPolicy object
	**/
	void setDisplacementsRepresentationPolicy(DisplacementsRepresentationPolicy *displacements);

	ElementRepresentationPolicy * opaque();
	ElementRepresentationPolicy * gradient();
	//ElementRepresentationPolicy * tensor();

	/**
	Toggles opengl wireframe rendering on all relevant policies
	**/
	void setTriangleWireframeRendering(bool const state);
	void toggleTriangleWireframeRendering();


	void setSurfaceSubdivisionLevel(unsigned short level);
};

#endif // ELEMENTREPRESENTATIONFLYWEIGHTFACTORY_H
