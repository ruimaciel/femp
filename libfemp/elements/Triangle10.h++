#ifndef FEMP_TRIANGLE10_HPP
#define FEMP_TRIANGLE10_HPP

#include <vector>

#include "TriangleFamily.h++"
#include "../Point.h++"



namespace fem
{

struct Triangle10
	: public TriangleFamily
{
public:
	Triangle10();
	~Triangle10()	{};

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
	int node_number() const	{ return 10; };
};


}	//namespace fem

#endif
