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

	this->coordinates.resize(3);


	// specify new quadrature rule
	using namespace quadrature;
	m_stiffness_quadrature_rule = std::unique_ptr<quadrature::Triangle3>( new quadrature::Triangle3() );

	m_domain_quadrature_rule = std::unique_ptr<quadrature::Triangle3>( new quadrature::Triangle3() );

}


std::vector<double>
Triangle3::getN(const Point &p)
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
Triangle3::getdNdcsi(const Point &)
{
	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = -1;
	dNdcsi[1] = 1;
	dNdcsi[2] = 0;

	return dNdcsi;
}


std::vector<double>
Triangle3::getdNdeta(const Point &)
{
	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = -1;
	dNdeta[1] = 0;
	dNdeta[2] = 1;

	return dNdeta;
}


std::vector<double>
Triangle3::getdNdzeta(const Point &)
{
	std::vector<double> dNdzeta(this->getNodeAmount());

	dNdzeta[0] = 0;
	dNdzeta[1] = 0;
	dNdzeta[2] = 0;

	return dNdzeta;
}


std::vector<fem::Point>
Triangle3::getLocalCoordinates()
{
	this->coordinates[0] = Point(	0,	0,	0	);
	this->coordinates[1] = Point(	1,	0,	0	);
	this->coordinates[2] = Point(	0,	1,	0	);

	return this->coordinates;
}


}	// namespace fem

