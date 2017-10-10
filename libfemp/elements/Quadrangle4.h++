#ifndef FEMP_FEMP_QUADRANGLE4_HPP
#define FEMP_FEMP_QUADRANGLE4_HPP

#include <vector>

#include "QuadrangleFamily.h++"
#include "../Point.h++"



namespace fem
{

struct Quadrangle4
	: public QuadrangleFamily
{
	public:
		Quadrangle4();
		~Quadrangle4()	{};

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
        int node_number() const	{ return 4; };
};


}

#endif
