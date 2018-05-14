#ifndef FEMP_QUADRANGLE9_HPP
#define FEMP_QUADRANGLE9_HPP

#include <vector>

#include "QuadrangleFamily.h++"
#include "../Point3D.h++"



namespace fem
{

class Quadrangle9
		: public QuadrangleFamily
{
public:
	Quadrangle9();

	std::vector<fem::Point3D> getLocalCoordinates();

	std::vector<double> getN(const Point3D & p);

	std::vector<double> getdNdcsi(const Point3D &p);

	std::vector<double> getdNdeta(const Point3D &p);

	std::vector<double> getdNdzeta(const Point3D &p);

	/**
		return the number of nodes that an element of this particular type has
		@return the number of nodes
		**/
	virtual int getNodeAmount() const override { return 9; }
};


}

#endif
