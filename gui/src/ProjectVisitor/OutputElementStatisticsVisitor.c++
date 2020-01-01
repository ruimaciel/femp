#include "OutputElementStatisticsVisitor.h++"

#include <assert.h>
#include <cmath>
#include <limits>

#include <QDebug>

#include <libfemp/AnalysisResult.h++>
#include <libfemp/Element.h++>
#include <libfemp/Node.h++>

OutputElementStatisticsVisitor::OutputElementStatisticsVisitor(Selection const& selection)
    : m_selection(selection)
{
}

void OutputElementStatisticsVisitor::visit(fem::Model& model, std::vector<fem::AnalysisResult>&)
{
    float de = 0; // maximum/external diameter
    float di = std::numeric_limits<float>::max(); // minimum/internal diameter

    for (auto element : model.getElementList()) {
        auto dim = [&](fem::node_ref_t i, fem::node_ref_t j) -> float {
            fem::Point3D const& p1 = model.getNode(element.getNode(i));
            fem::Point3D const& p2 = model.getNode(element.getNode(j));
            return (p1 - p2).norm();
        };

        auto set = [&](int const i, int const j) {
            de = (de < dim(i, j)) ? dim(i, j) : de;
            di = (di > dim(i, j)) ? dim(i, j) : di;
        };

        switch (element.family()) {
        case fem::Element::EF_TETRAHEDRON: {
            set(0, 1);
            set(0, 2);
            set(0, 3);
            set(1, 3);
            set(2, 3);
        } break;

        case fem::Element::EF_PRISM: {
            set(0, 1);
            set(0, 2);
            set(0, 3);
            set(3, 4);
            set(3, 5);
            set(4, 1);
            set(5, 2);
        } break;

        case fem::Element::EF_HEXAHEDRON: {
            set(0, 1);
            set(0, 2);
            set(0, 3);
            set(0, 4);
            set(4, 5);
            set(4, 6);
            set(4, 7);
            set(1, 5);
            set(2, 6);
            set(3, 7);
        } break;

        default:
            break;
        }
    }

    qInfo() << "external diameter: " << de;
    qInfo() << "internal diameter: " << di;
}
