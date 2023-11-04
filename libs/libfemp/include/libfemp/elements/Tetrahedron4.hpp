#ifndef FEMP_TETRAHEDRON4_HPP
#define FEMP_TETRAHEDRON4_HPP

#include <vector>

#include "../Point3D.hpp"
#include "TetrahedronFamily.hpp"

namespace fem {

class Tetrahedron4 : public TetrahedronFamily {
	public:
	Tetrahedron4();

	std::vector<fem::Point3D> getLocalCoordinates() override;

	std::vector<double> getN(const Point3D& p) override;

	std::vector<double> getdNdcsi(const Point3D& p) override;

	std::vector<double> getdNdeta(const Point3D& p) override;

	std::vector<double> getdNdzeta(const Point3D& p) override;

	public:	 // merging with fem::Element
	/**
	 * return the number of nodes that an element of this particular type has
	 * @return the number of nodes
	 */
	int getNodeAmount() const override;
};

}  // namespace fem

#endif
