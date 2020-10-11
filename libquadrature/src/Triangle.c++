#include <quadrature_rules/Triangle.h++>

#include <cmath>

namespace fem {
namespace quadrature {

    std::vector<TriangleRule::Point>
    Triangle1::operator()() const
    {
        return {
            Point { 0.5, { 1.0 / 3.0, 1.0 / 3.0 } }
        };
    }

    std::vector<TriangleRule::Point>
    Triangle3::operator()() const
    {
        return {
            Point { 1.0 / 6, { 2.0 / 3, 1.0 / 6.0 } },
            Point { 1.0 / 6, { 1.0 / 6, 2.0 / 3.0 } },
            Point { 1.0 / 6, { 1.0 / 6, 1.0 / 6.0 } }
        };
    }

    std::vector<TriangleRule::Point>
    Triangle6::operator()() const
    {
        const double g1 = (8 - sqrt(10.0) + sqrt(38.0 - 44.0 * sqrt(2.0 / 5))) / 18;
        const double g2 = (8 - sqrt(10.0) - sqrt(38.0 - 44.0 * sqrt(2.0 / 5))) / 18;
        const double w1 = (620 + sqrt(213125 - 53320 * sqrt(10))) / (2 * 3720);
        const double w2 = (620 - sqrt(213125 - 53320 * sqrt(10))) / (2 * 3720);

        return {
            Point { w1, { 1.0 - 2.0 * g1, g1 } },
            Point { w1, { g1, 1.0 - 2.0 * g1 } },
            Point { w1, { g1, g1 } },
            Point { w2, { 1.0 - 2.0 * g2, g2 } },
            Point { w2, { g2, 1.0 - 2.0 * g2 } },
            Point { w2, { g2, g2 } }
        };
    }

    std::vector<TriangleRule::Point>
    Triangle7::operator()() const
    {
        const double g1 = (6.0 - sqrt(15)) / 21;
        const double g2 = (6.0 + sqrt(15)) / 21;
        const double w1 = (155.0 - sqrt(15)) / (2 * 1200);
        const double w2 = (155.0 + sqrt(15)) / (2 * 1200);

        return {
            Point { w1, { 1.0 - 2.0 * g1, g1 } },
            Point { w1, { g1, 1.0 - 2.0 * g1 } },
            Point { w1, { g1, g1 } },
            Point { w2, { 1.0 - 2.0 * g2, g2 } },
            Point { w2, { g2, 1.0 - 2.0 * g2 } },
            Point { w2, { g2, g2 } },
            Point { 9.0 / (2 * 40), { 1.0 / 3, 1.0 / 3 } }
        };
    }

    TriangleRule::~TriangleRule() {}

} // namespace quadrature
} // namespace fem
