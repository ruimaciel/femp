#include <libfemp/loads/SurfaceLoad.h++>

#include <memory>

#include <libfemp/FemException.h++>
#include <libfemp/Model.h++>
#include <libfemp/Point2D.h++>
#include <libfemp/elements/BaseElement.h++>
#include <libfemp/loads/Quadrangle4.h++>
#include <libfemp/loads/Quadrangle8.h++>
#include <libfemp/loads/Quadrangle9.h++>
#include <libfemp/loads/Triangle10.h++>
#include <libfemp/loads/Triangle3.h++>
#include <libfemp/loads/Triangle6.h++>

namespace fem {

SurfaceLoad::~SurfaceLoad() {}

std::vector<node_ref_t>
SurfaceLoad::getNodeReferences() const
{
    return Element::getNodeReferences();
}

int SurfaceLoad::getNodeAmount() const
{
    //TODO replace with concrete class member variables after migration to polymorphic surface loads
    return getNodeReferences().size();
}

unsigned int SurfaceLoad::getDofAmount() const
{
    //TODO replace with concrete class member variables after migration to polymorphic surface loads
    return getNodeAmount() * 3;
}

Eigen::VectorXd
SurfaceLoad::getForceVector(Model& model) const
{
    const int node_amount = getNodeAmount();
    const int dof_amount = getDofAmount();

    Eigen::VectorXd f_elem;
    f_elem.resize(dof_amount);
    f_elem.setZero();

    auto node_references = getNodeReferences();

    Eigen::Matrix3d J;

    for (auto quadrature_point : getDomainQuadratureRule()) {
        // get shape function and shape function derivatives in this integration Point's coordinate
        const Point2D& point = quadrature_point.x;
        std::vector<double> N = getN(point);
        std::vector<double> dNdcsi = getdNdcsi(point);
        std::vector<double> dNdeta = getdNdeta(point);

        // calculate the Jacobian
        J.setZero();

        for (int n = 0; n < node_amount; n++) {
            auto const& node_ref = node_references[n];
            fem::Node const& node = model.getNode(node_ref);
            double const& X = node.x();
            double const& Y = node.y();
            double const& Z = node.z();

            J(0, 0) += dNdcsi[n] * X;
            J(0, 1) += dNdcsi[n] * Y;
            J(0, 2) += dNdcsi[n] * Z;
            J(1, 0) += dNdeta[n] * X;
            J(1, 1) += dNdeta[n] * Y;
            J(1, 2) += dNdeta[n] * Z;
        }

        J = J * J.transpose();

        double detJ = J(0, 0) * J(1, 1) - J(1, 0) * J(0, 1);

        if (detJ <= 0) {
            throw FemException("surface load returns a negative determinant");
        }

        detJ = sqrt(detJ);

        // calculate q(csi, eta, zeta)
        fem::Point3D q(0, 0, 0);
        for (int j = 0; j < node_amount; j++) {
            q += N[j] * this->surface_forces[j];
        }

        const double& W = quadrature_point.weight;
        for (int n = 0; n < node_amount; n++) {
            const double cN = N[n];

            f_elem(3 * n) += cN * q.x() * detJ * W;
            f_elem(3 * n + 1) += cN * q.y() * detJ * W;
            f_elem(3 * n + 2) += cN * q.z() * detJ * W;
        }
    }

    return f_elem;
}

SurfaceLoad* SurfaceLoad::makeSurfaceLoad(const Element* element)
{
    SurfaceLoad* surfaceLoad = nullptr;

    switch (element->getType()) {
    case Element::FE_TRIANGLE3:
        surfaceLoad = new Triangle3();
        break;

    case Element::FE_TRIANGLE6:
        surfaceLoad = new Triangle6();
        break;

    case Element::FE_QUADRANGLE4:
        surfaceLoad = new Quadrangle4();
        break;

    case Element::FE_QUADRANGLE8:
        surfaceLoad = new Quadrangle8();
        break;

    case Element::FE_QUADRANGLE9:
        surfaceLoad = new Quadrangle9();
        break;

    default:
        throw FemException("invalid surface load type");
        break;
    }

    surfaceLoad->nodes = element->nodes;

    return surfaceLoad;
}

} // namespace fem
