#include <libfemp/FemException.hpp>
#include <libfemp/loads/Quadrangle4.hpp>
#include <memory>
#include <quadrature_rules/Line.hpp>

namespace fem {

Quadrangle4::Quadrangle4() {
	// specify new quadrature rule
	using namespace quadrature;
	LineRule* rule_x = new GaussLegendre2();
	LineRule* rule_y = new GaussLegendre2();
	m_domain_quadrature_rule = std::unique_ptr<QuadrangleCartesianProduct>(new QuadrangleCartesianProduct(rule_x, rule_y));
}

std::vector<double> Quadrangle4::getN(const Point3D& p) const {
	const double csi = p.x();
	const double eta = p.y();

	std::vector<double> N(this->getNodeAmount());

	N[0] = (1 - csi) * (1 - eta) / 4;
	N[1] = (1 + csi) * (1 - eta) / 4;
	N[2] = (1 + csi) * (1 + eta) / 4;
	N[3] = (1 - csi) * (1 + eta) / 4;

	return N;
}

std::vector<double> Quadrangle4::getdNdcsi(const Point3D& p) const {
	// double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = (eta - 1) / 4;
	dNdcsi[1] = (1 - eta) / 4;
	dNdcsi[2] = (1 + eta) / 4;
	dNdcsi[3] = (-1 - eta) / 4;

	return dNdcsi;
}

std::vector<double> Quadrangle4::getdNdeta(const Point3D& p) const {
	double csi = p.x();
	// double eta = p.y();

	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = (csi - 1) / 4;
	dNdeta[1] = (-1 - csi) / 4;
	dNdeta[2] = (1 + csi) / 4;
	dNdeta[3] = (1 - csi) / 4;

	return dNdeta;
}

std::vector<fem::Point3D> Quadrangle4::getLocalCoordinates() const {
	return {
		Point3D(-0.5, -0.5, 0),
		Point3D(0.5, -0.5, 0),
		Point3D(0.5, 0.5, 0),
		Point3D(-0.5, 0.5, 0),
	};
}

}  // namespace fem
