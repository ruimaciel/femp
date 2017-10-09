#ifndef FEMP_PRISM15_HPP
#define FEMP_PRISM15_HPP

#include <vector>

#include "PrismFamily.h++"
#include "../Point.h++"




namespace fem
{

struct Prism15
	: public PrismFamily
{
public:
	Prism15();
	~Prism15()	{};

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
        int node_number() const	{ return 15; };
};


}

#endif
