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


}	//namespace fem

#endif
