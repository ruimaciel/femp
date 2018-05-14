#include "Triangle3.h++"


#include <memory>

#include <libfemp/quadrature_rules/Tetrahedron.h++>
#include <libfemp/FemException.h++>


namespace fem
{


Triangle3::Triangle3()
{
	this->stiffness_degree = 1;
	this->domain_degree = 1;

	// specify new quadrature rule
	using namespace quadrature;
	m_stiffness_quadrature_rule = std::unique_ptr<quadrature::Triangle3>( new quadrature::Triangle3() );

	m_domain_quadrature_rule = std::unique_ptr<quadrature::Triangle3>( new quadrature::Triangle3() );

}


std::vector<double>
Triangle3::getN(const Point3D &p)
{
	const double csi = p.x();
	const double eta = p.y();

	std::vector<double> N(this->getNodeAmount());

	N[0] = 1-csi-eta;
	N[1] = csi;
	N[2] = eta;

	return N;
}


std::vector<double>
Triangle3::getdNdcsi(const Point3D &)
{
	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = -1;
	dNdcsi[1] = 1;
	dNdcsi[2] = 0;

	return dNdcsi;
}


std::vector<double>
Triangle3::getdNdeta(const Point3D &)
{
	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = -1;
	dNdeta[1] = 0;
	dNdeta[2] = 1;

	return dNdeta;
}


std::vector<double>
Triangle3::getdNdzeta(const Point3D &)
{
	std::vector<double> dNdzeta(this->getNodeAmount());

	dNdzeta[0] = 0;
	dNdzeta[1] = 0;
	dNdzeta[2] = 0;

	return dNdzeta;
}


std::vector<fem::Point3D>
Triangle3::getLocalCoordinates()
{
	return {
		Point3D(	0,	0,	0	),
		Point3D(	1,	0,	0	),
		Point3D(	0,	1,	0	),
	};
}


}	// namespace fem

