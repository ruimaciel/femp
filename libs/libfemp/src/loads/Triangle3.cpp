#include <libfemp/FemException.hpp>
#include <libfemp/loads/Triangle3.hpp>
#include <memory>
#include <quadrature_rules/Tetrahedron.hpp>

namespace fem {

Triangle3::Triangle3() {
	// specify new quadrature rule
	using namespace quadrature;
	m_domain_quadrature_rule = std::unique_ptr<quadrature::Triangle3>(new quadrature::Triangle3());
}

std::vector<double> Triangle3::getN(const Point3D& p) const {
	const double csi = p.x();
	const double eta = p.y();

	std::vector<double> N(this->getNodeAmount());

	N[0] = 1 - csi - eta;
	N[1] = csi;
	N[2] = eta;

	return N;
}

std::vector<double> Triangle3::getdNdcsi(const Point3D&) const {
	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = -1;
	dNdcsi[1] = 1;
	dNdcsi[2] = 0;

	return dNdcsi;
}

std::vector<double> Triangle3::getdNdeta(const Point3D&) const {
	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = -1;
	dNdeta[1] = 0;
	dNdeta[2] = 1;

	return dNdeta;
}

std::vector<fem::Point3D> Triangle3::getLocalCoordinates() const {
	return {
		Point3D(0, 0, 0),
		Point3D(1, 0, 0),
		Point3D(0, 1, 0),
	};
}

}  // namespace fem
