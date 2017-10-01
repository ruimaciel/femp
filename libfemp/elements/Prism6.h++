#ifndef FEMP_PRISM6_HPP
#define FEMP_PRISM6_HPP

#include <vector>

#include "PrismFamily.h++"
#include "../Point.h++"




namespace fem
{

struct Prism6
	: public PrismFamily
{
public:
	Prism6();
	~Prism6()	{};

	std::vector<fem::Point> & setCoordinates();

	std::vector<double> & setN(const Point & p);

	std::vector<double> & setdNdcsi(const Point &p);
	std::vector<double> & setdNdcsi(const double &csi, const double &eta, const double &zeta = 0);

	std::vector<double> & setdNdeta(const Point &p);
	std::vector<double> & setdNdeta(const double &csi, const double &eta, const double &zeta = 0);

	std::vector<double> & setdNdzeta(const Point &p);
	std::vector<double> & setdNdzeta(const double &csi, const double &eta, const double &zeta = 0);

public: // merging with fem::Element
        void set(std::vector<size_t> &nodes);

        /** 
        return the number of nodes that an element of this particular type has
        @return the number of nodes
        **/
        int node_number() const	{ return 16; };
};


}	// namespace fem

#endif
