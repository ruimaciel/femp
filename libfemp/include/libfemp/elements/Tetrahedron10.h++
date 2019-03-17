#ifndef FEMP_TETRAHEDRON10_HPP
#define FEMP_TETRAHEDRON10_HPP

#include <vector>

#include "TetrahedronFamily.h++"
#include "../Point3D.h++"




namespace fem
{

class Tetrahedron10
		: public TetrahedronFamily
{
public:
	Tetrahedron10();

	std::vector<fem::Point3D> getLocalCoordinates();

	std::vector<double> getN(const Point3D & p);

	std::vector<double> getdNdcsi(const Point3D &p);

	std::vector<double> getdNdeta(const Point3D &p);

	std::vector<double> getdNdzeta(const Point3D &p);

public: // merging with fem::Element
	/**
		return the number of nodes that an element of this particular type has
		@return the number of nodes
		**/
	int getNodeAmount() const	{ return 10; };
};


}

#endif
