
#ifndef NODISPLACEMENTSPOLICY_H
#define NODISPLACEMENTSPOLICY_H

#include "DisplacementsRepresentationPolicy.h++"


/**
Concrete displacements policy where displacements are null
**/
class NoDisplacementsPolicy 
	: virtual public DisplacementsRepresentationPolicy
{
public:
	NoDisplacementsPolicy ( );
	virtual ~NoDisplacementsPolicy ( );


protected:

public:
	/**
	returns the coordinate of a given point by providing the node's reference
	**/
	fem::point operator[](size_t &node_reference);

};

#endif // NODISPLACEMENTSPOLICY_H
