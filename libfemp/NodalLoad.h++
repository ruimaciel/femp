#ifndef FEMP_NODAL_LOAD_HPP
#define FEMP_NODAL_LOAD_HPP

#include <libfemp/point.h++>

namespace fem
{


class NodalLoad 
{
public:
	point force;	// the force being applied in this node

public:
	NodalLoad ();
	NodalLoad (const NodalLoad &);
	~NodalLoad ();


	double x()	const {return force.x();};
	double y()	const {return force.y();};
	double z()	const {return force.z();};

};


}

#endif
