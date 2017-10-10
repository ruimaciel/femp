#ifndef FEMP_HEXAHEDRON8_HPP
#define FEMP_HEXAHEDRON8_HPP

#include <vector>

#include "HexahedronFamily.h++"
#include "../Point.h++"




namespace fem
{

struct Hexahedron8
	: public HexahedronFamily
{
public:
	Hexahedron8();
	~Hexahedron8()	{};

	std::vector<fem::Point> & setCoordinates();

	std::vector<double> getN(const Point & p);

	std::vector<double> getdNdcsi(const Point &p);

	std::vector<double> getdNdeta(const Point &p);

	std::vector<double> getdNdzeta(const Point &p);

public: // merging with fem::Element
        /** 
        return the number of nodes that an element of this particular type has
        @return the number of nodes
        **/
        int node_number() const	{ return 8; };
};


}	// namespace fem

#endif
