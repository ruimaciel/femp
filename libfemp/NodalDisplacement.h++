#ifndef FEMP_NODAL_DISPLACEMENT_HPP
#define FEMP_NODAL_DISPLACEMENT_HPP

#include <libfemp/point.h++>

namespace fem
{


class NodalDisplacement {
public:
	//TODO change this
	point displacement;

public:
	NodalDisplacement ();
	NodalDisplacement (const NodalDisplacement &copied);
	~NodalDisplacement ();

};


}	// namespace fem

#endif
