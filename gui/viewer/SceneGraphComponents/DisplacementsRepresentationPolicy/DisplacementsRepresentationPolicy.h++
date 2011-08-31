
#ifndef DISPLACEMENTSREPRESENTATIONPOLICY_H
#define DISPLACEMENTSREPRESENTATIONPOLICY_H

#include "../../../fem/Model.h++"
#include "../../../fem/point.h++"

/**
Defines the policy which is followed to represent element displacements
**/
class DisplacementsRepresentationPolicy
{
protected:
	fem::Model *m_model;	// pointer to the current model
	
public:


protected:

public:
	/**
	Must set a reference to a fem::Model class in order to obtain displacements
	**/
	void setModel(fem::Model &model);

	/**
	returns the coordinate of a given point by providing the node's reference
	**/
	virtual fem::point operator[](size_t &node_reference) = 0;

};

#endif // DISPLACEMENTSREPRESENTATIONPOLICY_H
