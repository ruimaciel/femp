#include <libfemp/FemException.h++>
#include <libfemp/elements/Hexahedron27.h++>
#include <memory>
#include <quadrature_rules/Line.h++>

namespace fem {

Hexahedron27::Hexahedron27() : HexahedronFamily() {
	this->stiffness_degree = 3;
	this->domain_degree = 2;

	this->coordinates.resize(27);

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

std::vector<double> Hexahedron27::getN(const Point3D& p) {
	const double csi = p.x();
	const double eta = p.y();
	const double zeta = p.z();

	std::vector<double> N(this->getNodeAmount());

	N[0] = (csi - 1) * csi * (eta - 1) * eta * (zeta - 1) * zeta / 8;
	N[1] = csi * (csi + 1) * (eta - 1) * eta * (zeta - 1) * zeta / 8;
	N[2] = csi * (csi + 1) * eta * (eta + 1) * (zeta - 1) * zeta / 8;
	N[3] = (csi - 1) * csi * eta * (eta + 1) * (zeta - 1) * zeta / 8;
	N[4] = (csi - 1) * csi * (eta - 1) * eta * zeta * (zeta + 1) / 8;
	N[5] = csi * (csi + 1) * (eta - 1) * eta * zeta * (zeta + 1) / 8;
	N[6] = csi * (csi + 1) * eta * (eta + 1) * zeta * (zeta + 1) / 8;
	N[7] = (csi - 1) * csi * eta * (eta + 1) * zeta * (zeta + 1) / 8;
	N[8] = -(csi - 1) * (csi + 1) * (eta - 1) * eta * (zeta - 1) * zeta / 4;
	N[9] = -(csi - 1) * csi * (eta - 1) * (eta + 1) * (zeta - 1) * zeta / 4;
	N[10] = -(csi - 1) * csi * (eta - 1) * eta * (zeta - 1) * (zeta + 1) / 4;
	N[11] = -csi * (csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1) * zeta / 4;
	N[12] = -csi * (csi + 1) * (eta - 1) * eta * (zeta - 1) * (zeta + 1) / 4;
	N[13] = -(csi - 1) * (csi + 1) * eta * (eta + 1) * (zeta - 1) * zeta / 4;
	N[14] = -csi * (csi + 1) * eta * (eta + 1) * (zeta - 1) * (zeta + 1) / 4;
	N[15] = -(csi - 1) * csi * eta * (eta + 1) * (zeta - 1) * (zeta + 1) / 4;
	N[16] = -(csi - 1) * (csi + 1) * (eta - 1) * eta * zeta * (zeta + 1) / 4;
	N[17] = -(csi - 1) * csi * (eta - 1) * (eta + 1) * zeta * (zeta + 1) / 4;
	N[18] = -csi * (csi + 1) * (eta - 1) * (eta + 1) * zeta * (zeta + 1) / 4;
	N[19] = -(csi - 1) * (csi + 1) * eta * (eta + 1) * zeta * (zeta + 1) / 4;
	N[20] = (csi - 1) * (csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1) * zeta / 2;
	N[21] = (csi - 1) * (csi + 1) * (eta - 1) * eta * (zeta - 1) * (zeta + 1) / 2;
	N[22] = (csi - 1) * csi * (eta - 1) * (eta + 1) * (zeta - 1) * (zeta + 1) / 2;
	N[23] = csi * (csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1) * (zeta + 1) / 2;
	N[24] = (csi - 1) * (csi + 1) * eta * (eta + 1) * (zeta - 1) * (zeta + 1) / 2;
	N[25] = (csi - 1) * (csi + 1) * (eta - 1) * (eta + 1) * zeta * (zeta + 1) / 2;
	N[26] = -(csi - 1) * (csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1) * (zeta + 1);

	return N;
}

std::vector<double> Hexahedron27::getdNdcsi(const Point3D& p) {
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = csi * (eta - 1) * eta * (zeta - 1) * zeta / 8 + (csi - 1) * (eta - 1) * eta * (zeta - 1) * zeta / 8;
	dNdcsi[1] = (csi + 1) * (eta - 1) * eta * (zeta - 1) * zeta / 8 + csi * (eta - 1) * eta * (zeta - 1) * zeta / 8;
	dNdcsi[2] = (csi + 1) * eta * (eta + 1) * (zeta - 1) * zeta / 8 + csi * eta * (eta + 1) * (zeta - 1) * zeta / 8;
	dNdcsi[3] = csi * eta * (eta + 1) * (zeta - 1) * zeta / 8 + (csi - 1) * eta * (eta + 1) * (zeta - 1) * zeta / 8;
	dNdcsi[4] = csi * (eta - 1) * eta * zeta * (zeta + 1) / 8 + (csi - 1) * (eta - 1) * eta * zeta * (zeta + 1) / 8;
	dNdcsi[5] = (csi + 1) * (eta - 1) * eta * zeta * (zeta + 1) / 8 + csi * (eta - 1) * eta * zeta * (zeta + 1) / 8;
	dNdcsi[6] = (csi + 1) * eta * (eta + 1) * zeta * (zeta + 1) / 8 + csi * eta * (eta + 1) * zeta * (zeta + 1) / 8;
	dNdcsi[7] = csi * eta * (eta + 1) * zeta * (zeta + 1) / 8 + (csi - 1) * eta * (eta + 1) * zeta * (zeta + 1) / 8;
	dNdcsi[8] = -(csi + 1) * (eta - 1) * eta * (zeta - 1) * zeta / 4 - (csi - 1) * (eta - 1) * eta * (zeta - 1) * zeta / 4;
	dNdcsi[9] = -csi * (eta - 1) * (eta + 1) * (zeta - 1) * zeta / 4 - (csi - 1) * (eta - 1) * (eta + 1) * (zeta - 1) * zeta / 4;
	dNdcsi[10] = -csi * (eta - 1) * eta * (zeta - 1) * (zeta + 1) / 4 - (csi - 1) * (eta - 1) * eta * (zeta - 1) * (zeta + 1) / 4;
	dNdcsi[11] = -(csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1) * zeta / 4 - csi * (eta - 1) * (eta + 1) * (zeta - 1) * zeta / 4;
	dNdcsi[12] = -(csi + 1) * (eta - 1) * eta * (zeta - 1) * (zeta + 1) / 4 - csi * (eta - 1) * eta * (zeta - 1) * (zeta + 1) / 4;
	dNdcsi[13] = -(csi + 1) * eta * (eta + 1) * (zeta - 1) * zeta / 4 - (csi - 1) * eta * (eta + 1) * (zeta - 1) * zeta / 4;
	dNdcsi[14] = -(csi + 1) * eta * (eta + 1) * (zeta - 1) * (zeta + 1) / 4 - csi * eta * (eta + 1) * (zeta - 1) * (zeta + 1) / 4;
	dNdcsi[15] = -csi * eta * (eta + 1) * (zeta - 1) * (zeta + 1) / 4 - (csi - 1) * eta * (eta + 1) * (zeta - 1) * (zeta + 1) / 4;
	dNdcsi[16] = -(csi + 1) * (eta - 1) * eta * zeta * (zeta + 1) / 4 - (csi - 1) * (eta - 1) * eta * zeta * (zeta + 1) / 4;
	dNdcsi[17] = -csi * (eta - 1) * (eta + 1) * zeta * (zeta + 1) / 4 - (csi - 1) * (eta - 1) * (eta + 1) * zeta * (zeta + 1) / 4;
	dNdcsi[18] = -(csi + 1) * (eta - 1) * (eta + 1) * zeta * (zeta + 1) / 4 - csi * (eta - 1) * (eta + 1) * zeta * (zeta + 1) / 4;
	dNdcsi[19] = -(csi + 1) * eta * (eta + 1) * zeta * (zeta + 1) / 4 - (csi - 1) * eta * (eta + 1) * zeta * (zeta + 1) / 4;
	dNdcsi[20] = (csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1) * zeta / 2 + (csi - 1) * (eta - 1) * (eta + 1) * (zeta - 1) * zeta / 2;
	dNdcsi[21] = (csi + 1) * (eta - 1) * eta * (zeta - 1) * (zeta + 1) / 2 + (csi - 1) * (eta - 1) * eta * (zeta - 1) * (zeta + 1) / 2;
	dNdcsi[22] = csi * (eta - 1) * (eta + 1) * (zeta - 1) * (zeta + 1) / 2 + (csi - 1) * (eta - 1) * (eta + 1) * (zeta - 1) * (zeta + 1) / 2;
	dNdcsi[23] = (csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1) * (zeta + 1) / 2 + csi * (eta - 1) * (eta + 1) * (zeta - 1) * (zeta + 1) / 2;
	dNdcsi[24] = (csi + 1) * eta * (eta + 1) * (zeta - 1) * (zeta + 1) / 2 + (csi - 1) * eta * (eta + 1) * (zeta - 1) * (zeta + 1) / 2;
	dNdcsi[25] = (csi + 1) * (eta - 1) * (eta + 1) * zeta * (zeta + 1) / 2 + (csi - 1) * (eta - 1) * (eta + 1) * zeta * (zeta + 1) / 2;
	dNdcsi[26] = -(csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1) * (zeta + 1) - (csi - 1) * (eta - 1) * (eta + 1) * (zeta - 1) * (zeta + 1);

	return dNdcsi;
}

std::vector<double> Hexahedron27::getdNdeta(const Point3D& p) {
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = (csi - 1) * csi * eta * (zeta - 1) * zeta / 8 + (csi - 1) * csi * (eta - 1) * (zeta - 1) * zeta / 8;
	dNdeta[1] = csi * (csi + 1) * eta * (zeta - 1) * zeta / 8 + csi * (csi + 1) * (eta - 1) * (zeta - 1) * zeta / 8;
	dNdeta[2] = csi * (csi + 1) * (eta + 1) * (zeta - 1) * zeta / 8 + csi * (csi + 1) * eta * (zeta - 1) * zeta / 8;
	dNdeta[3] = (csi - 1) * csi * (eta + 1) * (zeta - 1) * zeta / 8 + (csi - 1) * csi * eta * (zeta - 1) * zeta / 8;
	dNdeta[4] = (csi - 1) * csi * eta * zeta * (zeta + 1) / 8 + (csi - 1) * csi * (eta - 1) * zeta * (zeta + 1) / 8;
	dNdeta[5] = csi * (csi + 1) * eta * zeta * (zeta + 1) / 8 + csi * (csi + 1) * (eta - 1) * zeta * (zeta + 1) / 8;
	dNdeta[6] = csi * (csi + 1) * (eta + 1) * zeta * (zeta + 1) / 8 + csi * (csi + 1) * eta * zeta * (zeta + 1) / 8;
	dNdeta[7] = (csi - 1) * csi * (eta + 1) * zeta * (zeta + 1) / 8 + (csi - 1) * csi * eta * zeta * (zeta + 1) / 8;
	dNdeta[8] = -(csi - 1) * (csi + 1) * eta * (zeta - 1) * zeta / 4 - (csi - 1) * (csi + 1) * (eta - 1) * (zeta - 1) * zeta / 4;
	dNdeta[9] = -(csi - 1) * csi * (eta + 1) * (zeta - 1) * zeta / 4 - (csi - 1) * csi * (eta - 1) * (zeta - 1) * zeta / 4;
	dNdeta[10] = -(csi - 1) * csi * eta * (zeta - 1) * (zeta + 1) / 4 - (csi - 1) * csi * (eta - 1) * (zeta - 1) * (zeta + 1) / 4;
	dNdeta[11] = -csi * (csi + 1) * (eta + 1) * (zeta - 1) * zeta / 4 - csi * (csi + 1) * (eta - 1) * (zeta - 1) * zeta / 4;
	dNdeta[12] = -csi * (csi + 1) * eta * (zeta - 1) * (zeta + 1) / 4 - csi * (csi + 1) * (eta - 1) * (zeta - 1) * (zeta + 1) / 4;
	dNdeta[13] = -(csi - 1) * (csi + 1) * (eta + 1) * (zeta - 1) * zeta / 4 - (csi - 1) * (csi + 1) * eta * (zeta - 1) * zeta / 4;
	dNdeta[14] = -csi * (csi + 1) * (eta + 1) * (zeta - 1) * (zeta + 1) / 4 - csi * (csi + 1) * eta * (zeta - 1) * (zeta + 1) / 4;
	dNdeta[15] = -(csi - 1) * csi * (eta + 1) * (zeta - 1) * (zeta + 1) / 4 - (csi - 1) * csi * eta * (zeta - 1) * (zeta + 1) / 4;
	dNdeta[16] = -(csi - 1) * (csi + 1) * eta * zeta * (zeta + 1) / 4 - (csi - 1) * (csi + 1) * (eta - 1) * zeta * (zeta + 1) / 4;
	dNdeta[17] = -(csi - 1) * csi * (eta + 1) * zeta * (zeta + 1) / 4 - (csi - 1) * csi * (eta - 1) * zeta * (zeta + 1) / 4;
	dNdeta[18] = -csi * (csi + 1) * (eta + 1) * zeta * (zeta + 1) / 4 - csi * (csi + 1) * (eta - 1) * zeta * (zeta + 1) / 4;
	dNdeta[19] = -(csi - 1) * (csi + 1) * (eta + 1) * zeta * (zeta + 1) / 4 - (csi - 1) * (csi + 1) * eta * zeta * (zeta + 1) / 4;
	dNdeta[20] = (csi - 1) * (csi + 1) * (eta + 1) * (zeta - 1) * zeta / 2 + (csi - 1) * (csi + 1) * (eta - 1) * (zeta - 1) * zeta / 2;
	dNdeta[21] = (csi - 1) * (csi + 1) * eta * (zeta - 1) * (zeta + 1) / 2 + (csi - 1) * (csi + 1) * (eta - 1) * (zeta - 1) * (zeta + 1) / 2;
	dNdeta[22] = (csi - 1) * csi * (eta + 1) * (zeta - 1) * (zeta + 1) / 2 + (csi - 1) * csi * (eta - 1) * (zeta - 1) * (zeta + 1) / 2;
	dNdeta[23] = csi * (csi + 1) * (eta + 1) * (zeta - 1) * (zeta + 1) / 2 + csi * (csi + 1) * (eta - 1) * (zeta - 1) * (zeta + 1) / 2;
	dNdeta[24] = (csi - 1) * (csi + 1) * (eta + 1) * (zeta - 1) * (zeta + 1) / 2 + (csi - 1) * (csi + 1) * eta * (zeta - 1) * (zeta + 1) / 2;
	dNdeta[25] = (csi - 1) * (csi + 1) * (eta + 1) * zeta * (zeta + 1) / 2 + (csi - 1) * (csi + 1) * (eta - 1) * zeta * (zeta + 1) / 2;
	dNdeta[26] = -(csi - 1) * (csi + 1) * (eta + 1) * (zeta - 1) * (zeta + 1) - (csi - 1) * (csi + 1) * (eta - 1) * (zeta - 1) * (zeta + 1);

	return dNdeta;
}

std::vector<double> Hexahedron27::getdNdzeta(const Point3D& p) {
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdzeta(this->getNodeAmount());

	dNdzeta[0] = (csi - 1) * csi * (eta - 1) * eta * zeta / 8 + (csi - 1) * csi * (eta - 1) * eta * (zeta - 1) / 8;
	dNdzeta[1] = csi * (csi + 1) * (eta - 1) * eta * zeta / 8 + csi * (csi + 1) * (eta - 1) * eta * (zeta - 1) / 8;
	dNdzeta[2] = csi * (csi + 1) * eta * (eta + 1) * zeta / 8 + csi * (csi + 1) * eta * (eta + 1) * (zeta - 1) / 8;
	dNdzeta[3] = (csi - 1) * csi * eta * (eta + 1) * zeta / 8 + (csi - 1) * csi * eta * (eta + 1) * (zeta - 1) / 8;
	dNdzeta[4] = (csi - 1) * csi * (eta - 1) * eta * (zeta + 1) / 8 + (csi - 1) * csi * (eta - 1) * eta * zeta / 8;
	dNdzeta[5] = csi * (csi + 1) * (eta - 1) * eta * (zeta + 1) / 8 + csi * (csi + 1) * (eta - 1) * eta * zeta / 8;
	dNdzeta[6] = csi * (csi + 1) * eta * (eta + 1) * (zeta + 1) / 8 + csi * (csi + 1) * eta * (eta + 1) * zeta / 8;
	dNdzeta[7] = (csi - 1) * csi * eta * (eta + 1) * (zeta + 1) / 8 + (csi - 1) * csi * eta * (eta + 1) * zeta / 8;
	dNdzeta[8] = -(csi - 1) * (csi + 1) * (eta - 1) * eta * zeta / 4 - (csi - 1) * (csi + 1) * (eta - 1) * eta * (zeta - 1) / 4;
	dNdzeta[9] = -(csi - 1) * csi * (eta - 1) * (eta + 1) * zeta / 4 - (csi - 1) * csi * (eta - 1) * (eta + 1) * (zeta - 1) / 4;
	dNdzeta[10] = -(csi - 1) * csi * (eta - 1) * eta * (zeta + 1) / 4 - (csi - 1) * csi * (eta - 1) * eta * (zeta - 1) / 4;
	dNdzeta[11] = -csi * (csi + 1) * (eta - 1) * (eta + 1) * zeta / 4 - csi * (csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1) / 4;
	dNdzeta[12] = -csi * (csi + 1) * (eta - 1) * eta * (zeta + 1) / 4 - csi * (csi + 1) * (eta - 1) * eta * (zeta - 1) / 4;
	dNdzeta[13] = -(csi - 1) * (csi + 1) * eta * (eta + 1) * zeta / 4 - (csi - 1) * (csi + 1) * eta * (eta + 1) * (zeta - 1) / 4;
	dNdzeta[14] = -csi * (csi + 1) * eta * (eta + 1) * (zeta + 1) / 4 - csi * (csi + 1) * eta * (eta + 1) * (zeta - 1) / 4;
	dNdzeta[15] = -(csi - 1) * csi * eta * (eta + 1) * (zeta + 1) / 4 - (csi - 1) * csi * eta * (eta + 1) * (zeta - 1) / 4;
	dNdzeta[16] = -(csi - 1) * (csi + 1) * (eta - 1) * eta * (zeta + 1) / 4 - (csi - 1) * (csi + 1) * (eta - 1) * eta * zeta / 4;
	dNdzeta[17] = -(csi - 1) * csi * (eta - 1) * (eta + 1) * (zeta + 1) / 4 - (csi - 1) * csi * (eta - 1) * (eta + 1) * zeta / 4;
	dNdzeta[18] = -csi * (csi + 1) * (eta - 1) * (eta + 1) * (zeta + 1) / 4 - csi * (csi + 1) * (eta - 1) * (eta + 1) * zeta / 4;
	dNdzeta[19] = -(csi - 1) * (csi + 1) * eta * (eta + 1) * (zeta + 1) / 4 - (csi - 1) * (csi + 1) * eta * (eta + 1) * zeta / 4;
	dNdzeta[20] = (csi - 1) * (csi + 1) * (eta - 1) * (eta + 1) * zeta / 2 + (csi - 1) * (csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1) / 2;
	dNdzeta[21] = (csi - 1) * (csi + 1) * (eta - 1) * eta * (zeta + 1) / 2 + (csi - 1) * (csi + 1) * (eta - 1) * eta * (zeta - 1) / 2;
	dNdzeta[22] = (csi - 1) * csi * (eta - 1) * (eta + 1) * (zeta + 1) / 2 + (csi - 1) * csi * (eta - 1) * (eta + 1) * (zeta - 1) / 2;
	dNdzeta[23] = csi * (csi + 1) * (eta - 1) * (eta + 1) * (zeta + 1) / 2 + csi * (csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1) / 2;
	dNdzeta[24] = (csi - 1) * (csi + 1) * eta * (eta + 1) * (zeta + 1) / 2 + (csi - 1) * (csi + 1) * eta * (eta + 1) * (zeta - 1) / 2;
	dNdzeta[25] = (csi - 1) * (csi + 1) * (eta - 1) * (eta + 1) * (zeta + 1) / 2 + (csi - 1) * (csi + 1) * (eta - 1) * (eta + 1) * zeta / 2;
	dNdzeta[26] = -(csi - 1) * (csi + 1) * (eta - 1) * (eta + 1) * (zeta + 1) - (csi - 1) * (csi + 1) * (eta - 1) * (eta + 1) * (zeta - 1);

	return dNdzeta;
}

int Hexahedron27::getNodeAmount() const {
	return 27;
}

std::vector<fem::Point3D> Hexahedron27::getLocalCoordinates() {
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

	this->coordinates[20] = Point3D(0, 0, 1);
	this->coordinates[21] = Point3D(0, -1, 0);
	this->coordinates[22] = Point3D(-1, 0, 0);
	this->coordinates[23] = Point3D(1, 0, 0);
	this->coordinates[24] = Point3D(0, 1, 0);
	this->coordinates[25] = Point3D(0, 0, 1);
	this->coordinates[26] = Point3D(0, 0, 0);

	return this->coordinates;
}

}  // namespace fem
