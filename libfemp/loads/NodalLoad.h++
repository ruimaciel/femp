#ifndef FEMP_NODAL_LOAD_HPP
#define FEMP_NODAL_LOAD_HPP

#include <libfemp/Point.h++>

namespace fem
{


/**
 * Represents a load prescribed on a finite element node
 **/
class NodalLoad 
{
public:
	Point force;	// the force being applied in this node

public:
	NodalLoad ();
	NodalLoad (const NodalLoad &);
	~NodalLoad ();


	double x()	const {return force.x();};
	double y()	const {return force.y();};
	double z()	const {return force.z();};

};


}	// namespace fem

#endif
