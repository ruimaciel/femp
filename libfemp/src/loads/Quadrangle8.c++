#include <libfemp/loads/Quadrangle8.h++>

#include <memory>

#include <libfemp/FemException.h++>
#include <libfemp/quadrature_rules/Line.h++>

namespace fem {

Quadrangle8::Quadrangle8()
{
    // specify new quadrature rule
    using namespace quadrature;
    LineRule* rule_x = new GaussLegendre3();
    LineRule* rule_y = new GaussLegendre3();
    m_domain_quadrature_rule = std::unique_ptr<QuadrangleCartesianProduct>(new QuadrangleCartesianProduct(rule_x, rule_y));
}

std::vector<double>
Quadrangle8::getN(const Point3D& p) const
{
    const double csi = p.x();
    const double eta = p.y();

    std::vector<double> N(this->getNodeAmount());

    N[0] = (csi - 1) * (1 - eta) * (eta + csi + 1) / 4;
    N[1] = (csi + 1) * (eta - 1) * (eta - csi + 1) / 4;
    N[2] = (csi + 1) * (eta + 1) * (eta + csi - 1) / 4;
    N[3] = (1 - csi) * (eta + 1) * (eta - csi - 1) / 4;
    N[4] = (1 - csi * csi) * (1 - eta) / 2;
    N[5] = (csi + 1) * (1 - eta * eta) / 2;
    N[6] = (1 - csi * csi) * (eta + 1) / 2;
    N[7] = (1 - csi) * (1 - eta * eta) / 2;

    return N;
}

std::vector<double>
Quadrangle8::getdNdcsi(const Point3D& p) const
{
    double csi = p.x();
    double eta = p.y();

    std::vector<double> dNdcsi(this->getNodeAmount());

    dNdcsi[0] = (1 - eta) * (eta + csi + 1) / 4 + (csi - 1) * (1 - eta) / 4;
    dNdcsi[1] = (eta - 1) * (eta - csi + 1) / 4 - (csi + 1) * (eta - 1) / 4;
    dNdcsi[2] = (eta + 1) * (eta + csi - 1) / 4 + (csi + 1) * (eta + 1) / 4;
    dNdcsi[3] = -(eta + 1) * (eta - csi - 1) / 4 - (1 - csi) * (eta + 1) / 4;
    dNdcsi[4] = -csi * (1 - eta);
    dNdcsi[5] = (1 - eta * eta) / 2;
    dNdcsi[6] = -csi * (eta + 1);
    dNdcsi[7] = -(1 - eta * eta) / 2;

    return dNdcsi;
}

std::vector<double>
Quadrangle8::getdNdeta(const Point3D& p) const
{
    double csi = p.x();
    double eta = p.y();

    std::vector<double> dNdeta(this->getNodeAmount());

    dNdeta[0] = (csi - 1) * (1 - eta) / 4 - (csi - 1) * (eta + csi + 1) / 4;
    dNdeta[1] = (csi + 1) * (eta - csi + 1) / 4 + (csi + 1) * (eta - 1) / 4;
    dNdeta[2] = (csi + 1) * (eta + csi - 1) / 4 + (csi + 1) * (eta + 1) / 4;
    dNdeta[3] = (1 - csi) * (eta - csi - 1) / 4 + (1 - csi) * (eta + 1) / 4;
    dNdeta[4] = -(1 - csi * csi) / 2;
    dNdeta[5] = -(csi + 1) * eta;
    dNdeta[6] = (1 - csi * csi) / 2;
    dNdeta[7] = -(1 - csi) * eta;

    return dNdeta;
}

std::vector<fem::Point3D>
Quadrangle8::getLocalCoordinates() const
{
    return {
        Point3D(-0.5, -0.5, 0),
        Point3D(0.5, -0.5, 0),
        Point3D(0.5, 0.5, 0),
        Point3D(-0.5, 0.5, 0),
        Point3D(0.0, -0.5, 0),
        Point3D(0.5, 0.0, 0),
        Point3D(0.0, 0.5, 0),
        Point3D(-0.5, 0.0, 0),
    };
}

} // namespace fem
