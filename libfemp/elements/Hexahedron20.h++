#ifndef FEMP_HEXAHEDRON20_HPP
#define FEMP_HEXAHEDRON20_HPP

#include <vector>

#include "HexahedronFamily.h++"
#include "../Point.h++"




namespace fem
{

struct Hexahedron20
	: public HexahedronFamily
{
public:
	Hexahedron20();
	~Hexahedron20()	{};

	std::vector<fem::Point> & setCoordinates();

	std::vector<double> & setN(const Point & p);

	std::vector<double> & setdNdcsi(const Point &p);

	std::vector<double> & setdNdeta(const Point &p);

	std::vector<double> & setdNdzeta(const Point &p);

public: // merging with fem::Element
        void set(std::vector<size_t> &nodes);

        /** 
        return the number of nodes that an element of this particular type has
        @return the number of nodes
        **/
        int node_number() const	{ return 20; };
};


}	// namespace femp

#endif
