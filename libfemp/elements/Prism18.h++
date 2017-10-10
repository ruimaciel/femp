#ifndef FEMP_PRISM18_HPP
#define FEMP_PRISM18_HPP

#include <vector>

#include "PrismFamily.h++"
#include "../Point.h++"




namespace fem
{

struct Prism18
	: public PrismFamily
{
public:
	Prism18();
	~Prism18()	{};

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
        int getNodeAmount() const	{ return 18; };
};


}	// namespace fem

#endif
