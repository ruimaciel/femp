#include <libfemp/elements/Hexahedron20.h++>

#include <memory>

#include <libfemp/FemException.h++>
#include <libfemp/quadrature_rules/Line.h++>

namespace fem {

Hexahedron20::Hexahedron20()
    : HexahedronFamily()
{
    this->stiffness_degree = 3;
    this->domain_degree = 2;

    this->coordinates.resize(20);

    // specify new quadrature rule
    using namespace quadrature;
    LineRule* rule_x = new GaussLegendre3();
    LineRule* rule_y = new GaussLegendre3();
    LineRule* rule_z = new GaussLegendre3();

    m_stiffness_quadrature_rule = std::unique_ptr<HexahedronCartesianProduct>(new HexahedronCartesianProduct(rule_x, rule_y, rule_z));

    rule_x = new GaussLegendre3();
    rule_y = new GaussLegendre3();
    rule_z = new GaussLegendre3();
    m_domain_quadrature_rule = std::unique_ptr<HexahedronCartesianProduct>(new HexahedronCartesianProduct(rule_x, rule_y, rule_z));
}

std::vector<double>
Hexahedron20::getN(const Point3D& p)
{
    const double csi = p.x();
    const double eta = p.y();
    const double zeta = p.z();

    std::vector<double> N(this->getNodeAmount());

    N[0] = (1 - csi) * (1 - eta) * (1 - zeta) * (-zeta - eta - csi - 2) / 8;
    N[1] = (csi + 1) * (1 - eta) * (1 - zeta) * (-zeta - eta + csi - 2) / 8;
    N[2] = (csi + 1) * (eta + 1) * (1 - zeta) * (-zeta + eta + csi - 2) / 8;
    N[3] = (1 - csi) * (eta + 1) * (1 - zeta) * (-zeta + eta - csi - 2) / 8;
    N[4] = (1 - csi) * (1 - eta) * (zeta + 1) * (zeta - eta - csi - 2) / 8;
    N[5] = (csi + 1) * (1 - eta) * (zeta + 1) * (zeta - eta + csi - 2) / 8;
    N[6] = (csi + 1) * (eta + 1) * (zeta + 1) * (zeta + eta + csi - 2) / 8;
    N[7] = (1 - csi) * (eta + 1) * (zeta + 1) * (zeta + eta - csi - 2) / 8;
    N[8] = (1 - csi * csi) * (1 - eta) * (1 - zeta) / 4;
    N[9] = (1 - csi) * (1 - eta * eta) * (1 - zeta) / 4;
    N[10] = (1 - csi) * (1 - eta) * (1 - zeta * zeta) / 4;
    N[11] = (csi + 1) * (1 - eta * eta) * (1 - zeta) / 4;
    N[12] = (csi + 1) * (1 - eta) * (1 - zeta * zeta) / 4;
    N[13] = (1 - csi * csi) * (eta + 1) * (1 - zeta) / 4;
    N[14] = (csi + 1) * (eta + 1) * (1 - zeta * zeta) / 4;
    N[15] = (1 - csi) * (eta + 1) * (1 - zeta * zeta) / 4;
    N[16] = (1 - csi * csi) * (1 - eta) * (zeta + 1) / 4;
    N[17] = (1 - csi) * (1 - eta * eta) * (zeta + 1) / 4;
    N[18] = (csi + 1) * (1 - eta * eta) * (zeta + 1) / 4;
    N[19] = (1 - csi * csi) * (eta + 1) * (zeta + 1) / 4;

    return N;
}

std::vector<double>
Hexahedron20::getdNdcsi(const Point3D& p)
{
    double csi = p.x();
    double eta = p.y();
    double zeta = p.z();

    std::vector<double> dNdcsi(this->getNodeAmount());

    dNdcsi[0] = (eta - 1) * (zeta - 1) * (zeta + eta + 2 * csi + 1) / 8;
    dNdcsi[1] = -(eta - 1) * (zeta - 1) * (zeta + eta - 2 * csi + 1) / 8;
    dNdcsi[2] = (eta + 1) * (zeta - 1) * (zeta - eta - 2 * csi + 1) / 8;
    dNdcsi[3] = -(eta + 1) * (zeta - 1) * (zeta - eta + 2 * csi + 1) / 8;
    dNdcsi[4] = (eta - 1) * (zeta + 1) * (zeta - eta - 2 * csi - 1) / 8;
    dNdcsi[5] = -(eta - 1) * (zeta + 1) * (zeta - eta + 2 * csi - 1) / 8;
    dNdcsi[6] = (eta + 1) * (zeta + 1) * (zeta + eta + 2 * csi - 1) / 8;
    dNdcsi[7] = -(eta + 1) * (zeta + 1) * (zeta + eta - 2 * csi - 1) / 8;
    dNdcsi[8] = -csi * (1 - eta) * (1 - zeta) / 2;
    dNdcsi[9] = -(1 - eta * eta) * (1 - zeta) / 4;
    dNdcsi[10] = -(1 - eta) * (1 - zeta * zeta) / 4;
    dNdcsi[11] = (1 - eta * eta) * (1 - zeta) / 4;
    dNdcsi[12] = (1 - eta) * (1 - zeta * zeta) / 4;
    dNdcsi[13] = -csi * (eta + 1) * (1 - zeta) / 2;
    dNdcsi[14] = (eta + 1) * (1 - zeta * zeta) / 4;
    dNdcsi[15] = -(eta + 1) * (1 - zeta * zeta) / 4;
    dNdcsi[16] = -csi * (1 - eta) * (zeta + 1) / 2;
    dNdcsi[17] = -(1 - eta * eta) * (zeta + 1) / 4;
    dNdcsi[18] = (1 - eta * eta) * (zeta + 1) / 4;
    dNdcsi[19] = -csi * (eta + 1) * (zeta + 1) / 2;

    return dNdcsi;
}

std::vector<double>
Hexahedron20::getdNdeta(const Point3D& p)
{
    double csi = p.x();
    double eta = p.y();
    double zeta = p.z();

    std::vector<double> dNdeta(this->getNodeAmount());

    dNdeta[0] = (csi - 1) * (zeta - 1) * (zeta + 2 * eta + csi + 1) / 8;
    dNdeta[1] = (csi + 1) * (1 - zeta) * (zeta + 2 * eta - csi + 1) / 8;
    dNdeta[2] = (csi + 1) * (zeta - 1) * (zeta - 2 * eta - csi + 1) / 8;
    dNdeta[3] = (csi - 1) * (1 - zeta) * (zeta - 2 * eta + csi + 1) / 8;
    dNdeta[4] = (csi - 1) * (zeta + 1) * (zeta - 2 * eta - csi - 1) / 8;
    dNdeta[5] = -(csi + 1) * (zeta + 1) * (zeta - 2 * eta + csi - 1) / 8;
    dNdeta[6] = (csi + 1) * (zeta + 1) * (zeta + 2 * eta + csi - 1) / 8;
    dNdeta[7] = (1 - csi) * (zeta + 1) * (zeta + 2 * eta - csi - 1) / 8;
    dNdeta[8] = (1 - csi * csi) * (zeta - 1) / 4;
    dNdeta[9] = (1 - csi) * eta * (zeta - 1) / 2;
    dNdeta[10] = (csi - 1) * (1 - zeta * zeta) / 4;
    dNdeta[11] = (csi + 1) * eta * (zeta - 1) / 2;
    dNdeta[12] = (csi + 1) * (zeta * zeta - 1) / 4;
    dNdeta[13] = (1 - csi * csi) * (1 - zeta) / 4;
    dNdeta[14] = (csi + 1) * (1 - zeta * zeta) / 4;
    dNdeta[15] = (1 - csi) * (1 - zeta * zeta) / 4;
    dNdeta[16] = (csi * csi - 1) * (zeta + 1) / 4;
    dNdeta[17] = (csi - 1) * eta * (zeta + 1) / 2;
    dNdeta[18] = -(csi + 1) * eta * (zeta + 1) / 2;
    dNdeta[19] = (1 - csi * csi) * (zeta + 1) / 4;

    return dNdeta;
}

std::vector<double>
Hexahedron20::getdNdzeta(const Point3D& p)
{
    double csi = p.x();
    double eta = p.y();
    double zeta = p.z();

    std::vector<double> dNdzeta(this->getNodeAmount());

    dNdzeta[0] = (csi - 1) * (eta - 1) * (2 * zeta + eta + csi + 1) / 8;
    dNdzeta[1] = -(csi + 1) * (eta - 1) * (2 * zeta + eta - csi + 1) / 8;
    dNdzeta[2] = (csi + 1) * (eta + 1) * (2 * zeta - eta - csi + 1) / 8;
    dNdzeta[3] = -(csi - 1) * (eta + 1) * (2 * zeta - eta + csi + 1) / 8;
    dNdzeta[4] = (csi - 1) * (eta - 1) * (2 * zeta - eta - csi - 1) / 8;
    dNdzeta[5] = -(csi + 1) * (eta - 1) * (2 * zeta - eta + csi - 1) / 8;
    dNdzeta[6] = (csi + 1) * (eta + 1) * (2 * zeta + eta + csi - 1) / 8;
    dNdzeta[7] = -(csi - 1) * (eta + 1) * (2 * zeta + eta - csi - 1) / 8;
    dNdzeta[8] = -(1 - csi * csi) * (1 - eta) / 4;
    dNdzeta[9] = -(1 - csi) * (1 - eta * eta) / 4;
    dNdzeta[10] = -(1 - csi) * (1 - eta) * zeta / 2;
    dNdzeta[11] = -(csi + 1) * (1 - eta * eta) / 4;
    dNdzeta[12] = -(csi + 1) * (1 - eta) * zeta / 2;
    dNdzeta[13] = -(1 - csi * csi) * (eta + 1) / 4;
    dNdzeta[14] = -(csi + 1) * (eta + 1) * zeta / 2;
    dNdzeta[15] = -(1 - csi) * (eta + 1) * zeta / 2;
    dNdzeta[16] = (1 - csi * csi) * (1 - eta) / 4;
    dNdzeta[17] = (1 - csi) * (1 - eta * eta) / 4;
    dNdzeta[18] = (csi + 1) * (1 - eta * eta) / 4;
    dNdzeta[19] = (1 - csi * csi) * (eta + 1) / 4;

    return dNdzeta;
}

int Hexahedron20::getNodeAmount() const
{
    return 20;
}

std::vector<fem::Point3D>
Hexahedron20::getLocalCoordinates()
{
    this->coordinates[0] = Point3D(-1, -1, -1);
    this->coordinates[1] = Point3D(1, -1, -1);
    this->coordinates[2] = Point3D(1, 1, -1);
    this->coordinates[3] = Point3D(-1, 1, -1);

    this->coordinates[4] = Point3D(-1, -1, 1);
    this->coordinates[5] = Point3D(1, -1, 1);
    this->coordinates[6] = Point3D(1, 1, 1);
    this->coordinates[7] = Point3D(-1, 1, 1);

    this->coordinates[8] = Point3D(0, -1, -1);
    this->coordinates[9] = Point3D(-1, 0, -1);
    this->coordinates[10] = Point3D(-1, -1, 0);
    this->coordinates[11] = Point3D(1, 0, -1);
    this->coordinates[12] = Point3D(1, -1, 0);
    this->coordinates[13] = Point3D(0, 1, -1);
    this->coordinates[14] = Point3D(1, 1, 0);
    this->coordinates[15] = Point3D(-1, 1, 0);
    this->coordinates[16] = Point3D(0, -1, 1);
    this->coordinates[17] = Point3D(-1, 0, 1);
    this->coordinates[18] = Point3D(1, 0, 1);
    this->coordinates[19] = Point3D(0, 1, 1);

    return this->coordinates;
}

} // namespace fem
