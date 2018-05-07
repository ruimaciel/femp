#include "Triangle6.h++"


#include <memory>

#include <libfemp/quadrature_rules/Tetrahedron.h++>
#include <libfemp/FemException.h++>


namespace fem
{


Triangle6::Triangle6()
{
	this->stiffness_degree = 1;
	this->domain_degree = 2;

	this->coordinates.resize(6);


	// specify new quadrature rule
	using namespace quadrature;
	m_stiffness_quadrature_rule = std::unique_ptr<quadrature::Triangle6>( new quadrature::Triangle6() );

	m_domain_quadrature_rule = std::unique_ptr<quadrature::Triangle6>( new quadrature::Triangle6() );

}


std::vector<double>
Triangle6::getN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();

	std::vector<double> N(this->getNodeAmount());

	N[0] = (2*(1-eta-csi)-1)*(1-eta-csi);
	N[1] = csi*(2*csi-1);
	N[2] = eta*(2*eta-1);
	N[3] = 4*csi*(1-eta-csi);
	N[4] = 4*csi*eta;
	N[5] = 4*(1-eta-csi)*eta;

	return N;
}


std::vector<double>
Triangle6::getdNdcsi(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = 1.0-4*(1-eta-csi);
	dNdcsi[1] = 4*csi-1;
	dNdcsi[2] = 0;
	dNdcsi[3] = 4*(1-eta-csi)-4*csi;
	dNdcsi[4] = 4*eta;
	dNdcsi[5] = -4*eta;

	return dNdcsi;
}


std::vector<double>
Triangle6::getdNdeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = 1-4*(1-eta-csi);
	dNdeta[1] = 0;
	dNdeta[2] = 4*eta-1;
	dNdeta[3] = -4*csi;
	dNdeta[4] = 4*csi;
	dNdeta[5] = 4*(1-eta-csi)-4*eta;

	return dNdeta;
}


std::vector<double>
Triangle6::getdNdzeta(const Point &)
{
	std::vector<double> dNdzeta(this->getNodeAmount());

	dNdzeta[0] = 0;
	dNdzeta[1] = 0;
	dNdzeta[2] = 0;
	dNdzeta[3] = 0;
	dNdzeta[4] = 0;
	dNdzeta[5] = 0;

	return dNdzeta;
}


std::vector<fem::Point>
Triangle6::getLocalCoordinates()
{
	//TODO finish
	this->coordinates[0] = Point(	0,	0,	0	);
	this->coordinates[1] = Point(	1,	0,	0	);
	this->coordinates[2] = Point(	0,	1,	0	);
	this->coordinates[3] = Point(	0.5f,	0,	0	);
	this->coordinates[4] = Point(	0.5f,	0.5f,	0	);
	this->coordinates[5] = Point(	0,	0.5f,	0	);

	return this->coordinates;
}


}	// namespace fem

