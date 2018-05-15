#ifndef FEMP_FEMP_QUADRANGLE4_HPP
#define FEMP_FEMP_QUADRANGLE4_HPP

#include <vector>

#include "QuadrangleFamily.h++"
#include "../Point3D.h++"



namespace fem
{

class Quadrangle4
		: public QuadrangleFamily
{
public:
	Quadrangle4();

	virtual std::vector<fem::Point3D> getLocalCoordinates() override;

	std::vector<double> getN(const Point3D & p);

	std::vector<double> getdNdcsi(const Point3D &p);

	std::vector<double> getdNdeta(const Point3D &p);

	std::vector<double> getdNdzeta(const Point3D &p);

	/**
		return the number of nodes that an element of this particular type has
		@return the number of nodes
		**/
	virtual int getNodeAmount() const override { return 4; }
};


}

#endif
