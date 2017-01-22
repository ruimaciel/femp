#include "CollisionDetection.h++"


bool collided(const SphericalBoundary &sphere, const fem::Point &near, const fem::Point &far)
{
	/* taken from
	http://wiki.cgsociety.org/index.php/Ray_Sphere_Intersection
	*/
	using namespace fem;

	fem::Point d = far - near;
	fem::Point oc = near - sphere.center;

	float A = dot_product(d,d);
	float B = 2*dot_product(oc,d);
	float C = dot_product(oc,oc)-sphere.radius2;

	if(B*B - 4*A*C < 0 )
		return false;
	return true;
}

