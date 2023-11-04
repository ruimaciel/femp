#ifndef FEMP_TRIANGLE10_HPP
#define FEMP_TRIANGLE10_HPP

#include <vector>

#include "../Point3D.hpp"
#include "TriangleFamily.hpp"

namespace fem {

class Triangle10 : public TriangleFamily {
	public:
	Triangle10();

	virtual std::vector<fem::Point3D> getLocalCoordinates() const override;

	std::vector<double> getN(const Point3D& p) const override;

	std::vector<double> getdNdcsi(const Point3D& p) const override;

	std::vector<double> getdNdeta(const Point3D& p) const override;

	/**
	 * return the number of nodes that an element of this particular type has
	 * @return the number of nodes
	 */
	virtual int getNodeAmount() const override {
		return 10;
	}
};

}  // namespace fem

#endif
