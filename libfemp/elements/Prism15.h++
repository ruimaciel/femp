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

	std::vector<double> getN(const Point & p);

	std::vector<double> getdNdcsi(const Point &p);

	std::vector<double> getdNdeta(const Point &p);

	std::vector<double> getdNdzeta(const Point &p);

public: // merging with fem::Element
	void get(std::vector<size_t> &nodes);

        /** 
        return the number of nodes that an element of this particular type has
        @return the number of nodes
        **/
        int node_number() const	{ return 15; };
};


}

#endif
