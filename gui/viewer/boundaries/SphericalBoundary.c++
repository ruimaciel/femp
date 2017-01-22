#include "SphericalBoundary.h++"


#include <cmath>

SphericalBoundary::SphericalBoundary()
	:BoundaryStrategy()
{
	
}


SphericalBoundary::~SphericalBoundary()
{
}


bool SphericalBoundary::inside(const fem::Point &p)
{
	fem::Point d = p-center;
	if(dot_product(d,d) > radius2 )
		return false;

	return true;
}


void SphericalBoundary::setPoint(const fem::Point &p)
{
	this->radius2 = 0;
	this->center = p;
}


/*
   Resizes the spherical boundary, if needed, to include a new fem::Point
 */
void SphericalBoundary::addPoint(const fem::Point &p)
{
	/*
	given a circle and a fem::Point, if the fem::Point isn't inside the circle then define a new cirlce center and radius to include the new fem::Point
	*/
	fem::Point l = center - p;
	float dl = l.norm();
	if(dl*dl > radius2)
	{
		/*
		C_{n+1} = (C_n - P)*norm(C_n-P)/( norm(C_n+P) + r) + P
		*/
		center = l*( (dl + sqrt(radius2))/(2*dl)) + p;

		radius2 = radius2 + dl*dl;
	}
}
