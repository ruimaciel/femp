#ifndef FEM_QUADRATURE_HEXAHEDRON_HPP
#define FEM_QUADRATURE_HEXAHEDRON_HPP

#include "VolumeRule.h++"
#include <memory>
#include <vector>

#include "Line.h++"

namespace fem {
namespace quadrature {

    /**
 * Interface used by all quadrature rules over the square
 **/
    class HexahedronRule : public VolumeRule {
    public:
        virtual ~HexahedronRule();

        /**
	 * functor that returns the quadrature rule
	 **/
        virtual std::vector<QuadraturePoint> operator()() const = 0;
    };

    /**
 * Assembles a cubature rule on a square with a cartesian product of two
 * quadrature rules
 **/
    class HexahedronCartesianProduct
        : public HexahedronRule {
    private:
        std::unique_ptr<LineRule> m_rule_x, m_rule_y, m_rule_z;

    public:
        HexahedronCartesianProduct(LineRule* rule_x, LineRule* rule_y, LineRule* rule_z);

        virtual std::vector<QuadraturePoint> operator()() const override;
    };

} // namespace quadrature
} // namespace fem

#endif
