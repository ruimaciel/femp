#ifndef FEMP_TETRAHEDRON10_HPP
#define FEMP_TETRAHEDRON10_HPP

#include <vector>

#include "TetrahedronFamily.h++"
#include "../Point.h++"




namespace fem
{

struct Tetrahedron10
	: public TetrahedronFamily
{
public:
	Tetrahedron10();
	~Tetrahedron10()	{};

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
        int node_number() const	{ return 10; };
};


}

#endif
