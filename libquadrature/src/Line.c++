#include <cmath>
#include <quadrature_rules/Line.h++>

namespace fem {
namespace quadrature {

std::vector<LineRule::Point> GaussLegendre1::operator()() const { return {Point{2, {0}}}; };

std::vector<LineRule::Point> GaussLegendre2::operator()() const { return {Point{1, {-sqrt(1.0 / 3.0)}}, Point{1, {sqrt(1.0 / 3.0)}}}; };

std::vector<LineRule::Point> GaussLegendre3::operator()() const {
	return {Point{5.0 / 9, {-sqrt(3.0 / 5.0)}}, Point{8.0 / 9, {0.0}}, Point{5.0 / 9, {sqrt(3.0 / 5.0)}}};
};

std::vector<LineRule::Point> Simpson::operator()() const { return {Point{1.0 / 3, {-1.0}}, Point{4.0 / 3, {0.0}}, Point{1.0 / 3, {1.0}}}; };

LineRule::~LineRule() {}

}  // namespace quadrature
}  // namespace fem
