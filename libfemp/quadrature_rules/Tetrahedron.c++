#include "Tetrahedron.h++"

#include <cmath>

namespace fem
{


std::vector<TetrahedronRule::Point>
Tetrahedron1::operator() () const
{
	return {
		Point{1.0/6, {1.0/4, 1.0/4, 1.0/4} }
	};
}


std::vector<TetrahedronRule::Point>
Tetrahedron4::operator() () const
{
	const double g1 = 0.58541019662496845446;
	const double g2 = 0.13819660112501051518;
	const double w = 1.0/(6*4);

	return {
		Point{ w, {g1, g2, g2}},
		Point{ w, {g2, g1, g2}},
		Point{ w, {g2, g2, g1}},
		Point{ w, {g2, g2, g2}}
	};
}


std::vector<TetrahedronRule::Point>
Tetrahedron8::operator() () const
{
	const double g1 =(55-3*sqrt(17)+sqrt(1022-134*sqrt(17)))/196;
	const double g2 =(55-3*sqrt(17)-sqrt(1022-134*sqrt(17)))/196;

	const double w1 = (1.0/8 + sqrt((1715161837-406006699*sqrt(17))/23101)/3120)/6.0;
	const double w2 = (1.0/8 - sqrt((1715161837-406006699*sqrt(17))/23101)/3120)/6.0;


	return {
		Point{ w1, {1-3*g1, g1, g1}},
		Point{ w1, {g1, 1-3*g1, g1}},
		Point{ w1, {g1, g1, 1-3*g1}},
		Point{ w1, {g1, g1, g1}},
		Point{ w2, {1-3*g2, g2, g2}},
		Point{ w2, {g2, 1-3*g2, g2}},
		Point{ w2, {g2, g2, 1-3*g2}},
		Point{ w2, {g2, g2, g2}}
	};

}


std::vector<TetrahedronRule::Point>
Tetrahedron14::operator() () const
{
	const double g0 = 0.09273525031089122640232391373703060;
	const double g1 = 0.31088591926330060979734573376345783;
	const double g2 = 0.45449629587435035050811947372066056;

	const double w0 = (-1+6*g1*(2+g1*(-7+8*g1))+14*g2-60*g1*(3+4*g1* (-3+4*g1))*g2+4*(-7+30*g1*(3+4*g1*(-3+4*g1)))*g2*g2)/ (120*(g0-g1)*(g1*(-3+8*g1)+6*g2+8*g1*(-3+4*g1)*g2-4* (3+4*g1*(-3+4*g1))*g2*g2+8*g0*g0*(1+12*g1* (-1+2*g1)+4*g2-8*g2*g2)+g0*(-3-96*g1*g1+24*g2*(-1+2*g2)+ g1*(44+32*(1-2*g2)*g2))));
	const double w1 = (-1-20*(1+12*g0*(2*g0-1))*w0+20*g2*(2*g2-1)*(4*w0-1))/ (20*(1+12*g1*(2*g1-1)+4*g2-8*g2*g2));
	const double w2 = (1.0/6.0 - 2*(w0+w1)/3)/6.0;

	// 1 to 4
	return {
		Point{ w0/6.0, {1-3*g0, g0, g0}},
		Point{ w0/6.0, {g0, 1-3*g0, g0}},
		Point{ w0/6.0, {g0, g0, 1-3*g0}},
		Point{ w0/6.0, {g0, g0, g0}},
			//Point{5 to 8
		Point{ w1/6.0, {1-3*g1, g1, g1}},
		Point{ w1/6.0, {g1, 1-3*g1, g1}},
		Point{ w1/6.0, {g1, g1, 1-3*g1}},
		Point{ w1/6.0, {g1, g1, g1}},
			//Point{9 to 14
		Point{ w2, {1.0/2-g2, 1.0/2-g2, g2}},
		Point{ w2, {1.0/2-g2, g2, 1.0/2-g2}},
		Point{ w2, {1.0/2-g2, g2, g2}},
		Point{ w2, {g2, 1.0/2-g2, 1.0/2-g2}},
		Point{ w2, {g2, 1.0/2-g2, g2}},
		Point{ w2, {g2, g2, 1.0/2-g2}},
	};
}


}	// namespace fem

