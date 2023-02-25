#include <libfemp/FemException.h++>
#include <libfemp/loads/Triangle6.h++>
#include <memory>
#include <quadrature_rules/Tetrahedron.h++>

namespace fem {

Triangle6::Triangle6() {
	// specify new quadrature rule
	using namespace quadrature;
	m_domain_quadrature_rule = std::unique_ptr<quadrature::Triangle6>(new quadrature::Triangle6());
}

std::vector<double> Triangle6::getN(const Point3D& p) const {
	const double csi = p.x();
	const double eta = p.y();

	std::vector<double> N(this->getNodeAmount());

	N[0] = (2 * (1 - eta - csi) - 1) * (1 - eta - csi);
	N[1] = csi * (2 * csi - 1);
	N[2] = eta * (2 * eta - 1);
	N[3] = 4 * csi * (1 - eta - csi);
	N[4] = 4 * csi * eta;
	N[5] = 4 * (1 - eta - csi) * eta;

	return N;
}

std::vector<double> Triangle6::getdNdcsi(const Point3D& p) const {
	double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = 1.0 - 4 * (1 - eta - csi);
	dNdcsi[1] = 4 * csi - 1;
	dNdcsi[2] = 0;
	dNdcsi[3] = 4 * (1 - eta - csi) - 4 * csi;
	dNdcsi[4] = 4 * eta;
	dNdcsi[5] = -4 * eta;

	return dNdcsi;
}

std::vector<double> Triangle6::getdNdeta(const Point3D& p) const {
	double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = 1 - 4 * (1 - eta - csi);
	dNdeta[1] = 0;
	dNdeta[2] = 4 * eta - 1;
	dNdeta[3] = -4 * csi;
	dNdeta[4] = 4 * csi;
	dNdeta[5] = 4 * (1 - eta - csi) - 4 * eta;

	return dNdeta;
}

std::vector<fem::Point3D> Triangle6::getLocalCoordinates() const {
	return {
		Point3D(0.0, 0.0, 0), Point3D(1.0, 0.0, 0), Point3D(0.0, 1.0, 0), Point3D(0.5, 0.0, 0), Point3D(0.5, 0.5f, 0), Point3D(0.0, 0.5f, 0),
	};
}

}  // namespace fem
