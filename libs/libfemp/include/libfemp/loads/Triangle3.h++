#ifndef FEMP_TRIANGLE3_HPP
#define FEMP_TRIANGLE3_HPP

#include <vector>

#include "../Point3D.h++"
#include "TriangleFamily.h++"

namespace fem {

class Triangle3 : public TriangleFamily {
	public:
	Triangle3();

	virtual std::vector<fem::Point3D> getLocalCoordinates() const override;

	std::vector<double> getN(const Point3D& p) const override;

	std::vector<double> getdNdcsi(const Point3D& p) const override;

	std::vector<double> getdNdeta(const Point3D& p) const override;

	/**
	 * return the number of nodes that an element of this particular type has
	 * @return the number of nodes
	 */
	virtual int getNodeAmount() const override {
		return 3;
	}
};

}  // namespace fem

#endif
