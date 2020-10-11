#ifndef VOLUMERULE_H
#define VOLUMERULE_H

#include <array>
#include <vector>

namespace fem {
namespace quadrature {

/**
 * Interface used by all quadrature rules over the square
 */
class VolumeRule {
public:
    struct QuadraturePoint {
        double weight;
        std::array<double, 3> x;
    };

public:
    virtual ~VolumeRule() {}

    /**
     * functor that returns the quadrature rule
     */
    virtual std::vector<QuadraturePoint> operator()() const = 0;
};

} // namespace quadrature
} // namespace fem

#endif // VOLUME_H
