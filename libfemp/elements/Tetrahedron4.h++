#ifndef FEMP_TETRAHEDRON4_HPP
#define FEMP_TETRAHEDRON4_HPP

#include <vector>

#include "TetrahedronFamily.h++"
#include "../Point.h++"




namespace fem
{

struct Tetrahedron4
	: public TetrahedronFamily
{
public:
	Tetrahedron4();
	~Tetrahedron4()	{};

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
        int node_number() const	{ return 4; };
};


}	// namespace fem

#endif
