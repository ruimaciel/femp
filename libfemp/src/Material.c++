#include <libfemp/Material.h++>

namespace fem {

Eigen::Matrix<double, 6, 6>
Material::generateD() const
{
    Eigen::Matrix<double, 6, 6> D;

    double a = E / ((1 + nu) * (1 - 2 * nu)); // temp variable

    // attribute values to D
    // isotropic Hooke's law (fish, pg 241)
    D.setZero();
    D(0, 0) = a * (1 - nu);
    D(0, 1) = a * nu;
    D(0, 2) = a * nu;
    D(1, 0) = a * nu;
    D(1, 1) = a * (1 - nu);
    D(1, 2) = a * nu;
    D(2, 0) = a * nu;
    D(2, 1) = a * nu;
    D(2, 2) = a * (1 - nu);
    D(3, 3) = a * (1 - 2 * nu) / 2.0;
    D(4, 4) = a * (1 - 2 * nu) / 2.0;
    D(5, 5) = a * (1 - 2 * nu) / 2.0;
    return D;
}

} // namespace fem
