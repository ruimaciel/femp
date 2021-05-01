#ifndef FEMP_QUADRANGLE8_HPP
#define FEMP_QUADRANGLE8_HPP

#include <vector>

#include "../Point3D.h++"
#include "QuadrangleFamily.h++"

namespace fem {

class Quadrangle8
    : public QuadrangleFamily {
public:
    Quadrangle8();

    virtual std::vector<fem::Point3D> getLocalCoordinates() const override;

    std::vector<double> getN(const Point3D& p) const override;

    std::vector<double> getdNdcsi(const Point3D& p) const override;

    std::vector<double> getdNdeta(const Point3D& p) const override;

    /**
     * return the number of nodes that an element of this particular type has
     * @return the number of nodes
     */
    virtual int getNodeAmount() const override { return 8; }
};
}

#endif
