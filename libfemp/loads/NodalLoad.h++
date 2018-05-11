#ifndef FEMP_NODAL_LOAD_HPP
#define FEMP_NODAL_LOAD_HPP

#include <libfemp/Point3D.h++>

namespace fem
{


/**
 * Represents a load prescribed on a finite element node
 **/
class NodalLoad 
{
public:
	Point3D force;	// the force being applied in this node

public:
	NodalLoad ();
	NodalLoad (const NodalLoad &);
	~NodalLoad ();


	double x()	const {return force.x();};
	double y()	const {return force.y();};
	double z()	const {return force.z();};

	/**
	 * returns the force vector
	 **/
	const Point3D & getForce() const;

};


}	// namespace fem

#endif
