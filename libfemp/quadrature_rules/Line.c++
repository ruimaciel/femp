#include "Line.h++"

#include <cmath>

namespace fem
{


std::vector<LineRule::Point>
GaussLegendre1::operator() () const
{
	   return { Point{2,{0}} };
};


std::vector<LineRule::Point>
GaussLegendre2::operator() () const
{
	return { 
		Point{1,{-sqrt(1.0/3.0)}},
		Point{1,{ sqrt(1.0/3.0)}}
	};
};


std::vector<LineRule::Point>
GaussLegendre3::operator() () const
{
	return { 
		Point{5.0/9, {-sqrt(3.0/5.0)}},
		Point{8.0/9, {0.0} },
		Point{5.0/9, { sqrt(3.0/5.0)}}
	};
};


}	// namespace fem

