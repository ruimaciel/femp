#include "CollisionDetection.hpp"

bool collided(const SphericalBoundary& sphere, const fem::Point3D& near, const fem::Point3D& far) {
	/* taken from
		http://wiki.cgsociety.org/index.php/Ray_Sphere_Intersection
		*/

	fem::Point3D d = far - near;
	fem::Point3D oc = near - sphere.center;

	float A = dot_product(d, d);
	float B = 2 * dot_product(oc, d);
	float C = dot_product(oc, oc) - sphere.radius2;

	if (B * B - 4 * A * C < 0) return false;
	return true;
}
