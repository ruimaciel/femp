#include <quadrature_rules/Quadrangle.h++>

namespace fem {
namespace quadrature {

    QuadrangleCartesianProduct::QuadrangleCartesianProduct(LineRule* rule1, LineRule* rule2)
    {
        m_rule1 = std::unique_ptr<LineRule>(rule1);
        m_rule2 = std::unique_ptr<LineRule>(rule2);
    }

    std::vector<QuadrangleRule::Point>
    QuadrangleCartesianProduct::operator()() const
    {
        std::vector<QuadrangleRule::Point> square_rule;

        for (LineRule::Point& p1 : (*m_rule1)()) {
            for (LineRule::Point& p2 : (*m_rule2)()) {
                square_rule.push_back(Point{ p1.weight * p2.weight, { p1.x[0], p2.x[0] } });
            }
        }

        return square_rule;
    }

    QuadrangleRule::~QuadrangleRule() {}

} // namespace quadrature
} // namespace fem
