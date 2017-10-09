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


}

#endif
