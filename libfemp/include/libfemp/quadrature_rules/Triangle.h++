#ifndef FEM_QUADRATURE_TRIANGLE_HPP
#define FEM_QUADRATURE_TRIANGLE_HPP

#include "QuadraturePoint.h++"
#include "SurfaceRule.h++"
#include <memory>
#include <vector>

#include "Line.h++"

namespace fem {
namespace quadrature {

    /**
 * Interface used by all quadrature rules over the square
 **/
    class TriangleRule : public SurfaceRule {
    public:
        using Point = QuadraturePoint<2>; // helper alias

    public:
        virtual ~TriangleRule();

        /**
     * functor that returns the quadrature rule
     **/
        virtual std::vector<Point> operator()() const = 0;
    };

    /**
 * 1-point quadrature rule over the unit triangle
 **/
    class Triangle1
        : public TriangleRule {
    public:
        virtual std::vector<Point> operator()() const override;
    };

    /**
 * 3-point quadrature rule over the unit triangle
 **/
    class Triangle3
        : public TriangleRule {
    public:
        virtual std::vector<Point> operator()() const override;
    };

    /**
 * 6-point quadrature rule over the unit triangle
 **/
    class Triangle6
        : public TriangleRule {
    public:
        virtual std::vector<Point> operator()() const override;
    };

    /**
 * 7-point quadrature rule over the unit triangle
 **/
    class Triangle7
        : public TriangleRule {
    public:
        virtual std::vector<Point> operator()() const override;
    };

} // namespace quadrature
} // namespace fem

#endif
