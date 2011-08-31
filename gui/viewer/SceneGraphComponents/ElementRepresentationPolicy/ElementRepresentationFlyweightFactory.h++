
#ifndef ELEMENTREPRESENTATIONFLYWEIGHTFACTORY_H
#define ELEMENTREPRESENTATIONFLYWEIGHTFACTORY_H

#include "ElementRepresentationPolicy.h++"
#include "OpaqueRepresentationPolicy.h++"
#include "ColorFieldRepresentationPolicy.h++"
#include "TensorFieldRepresentationPolicy.h++"


/**
A flyweight factory pattern to store and provide ways to represent an element
**/
class ElementRepresentationFlyweightFactory
{
protected:
	OpaqueRepresentationPolicy 	m_opaque_policy;
	ColorFieldRepresentationPolicy	m_color_policy;
	TensorFieldRepresentationPolicy	m_tensor_policy;

public:
	ElementRepresentationFlyweightFactory ( );
	virtual ~ElementRepresentationFlyweightFactory ( );


protected:

public:
	/**
	Sets the current displacements policy for all the ElementRepresentationPolicy objects
	@param	displacements	pointer to a DisplacementsRepresentationPolicy object
	**/
	void setDisplacementsRepresentationPolicy(DisplacementsRepresentationPolicy *displacements);

	ElementRepresentationPolicy * opaque();
	ElementRepresentationPolicy * gradient();
	ElementRepresentationPolicy * tensor();

};

#endif // ELEMENTREPRESENTATIONFLYWEIGHTFACTORY_H
