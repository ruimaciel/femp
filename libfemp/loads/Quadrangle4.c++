#include "Quadrangle4.h++"

#include <memory>

#include <libfemp/quadrature_rules/Line.h++>
#include <libfemp/FemException.h++>


namespace fem
{


Quadrangle4::Quadrangle4()
{
	this->stiffness_degree = 1;
	this->domain_degree = 1;

	this->coordinates.resize(4);


	// specify new quadrature rule
	using namespace quadrature;
	LineRule * rule_x = new GaussLegendre2();
	LineRule * rule_y = new GaussLegendre2();

	m_stiffness_quadrature_rule = std::unique_ptr<QuadrangleCartesianProduct>( new QuadrangleCartesianProduct(rule_x, rule_y));

	rule_x = new GaussLegendre2();
	rule_y = new GaussLegendre2();
	m_domain_quadrature_rule = std::unique_ptr<QuadrangleCartesianProduct>( new QuadrangleCartesianProduct(rule_x, rule_y));

}


std::vector<double>
Quadrangle4::getN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();

	std::vector<double> N(this->getNodeAmount());

	N[0] = (1-csi)*(1-eta)/4;
	N[1] = (1+csi)*(1-eta)/4;
	N[2] = (1+csi)*(1+eta)/4;
	N[3] = (1-csi)*(1+eta)/4;

	return N;
}


std::vector<double>
Quadrangle4::getdNdcsi(const Point &p)
{
	// double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = (eta-1)/4;
	dNdcsi[1] = (1-eta)/4;
	dNdcsi[2] = (1+eta)/4;
	dNdcsi[3] = (-1-eta)/4;

	return dNdcsi;
}


std::vector<double>
Quadrangle4::getdNdeta(const Point &p)
{
	double csi = p.x();
	// double eta = p.y();

	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = (csi-1)/4;
	dNdeta[1] = (-1-csi)/4;
	dNdeta[2] = (1+csi)/4;
	dNdeta[3] = (1-csi)/4;

	return dNdeta;
}


std::vector<double>
Quadrangle4::getdNdzeta(const Point &)
{
	std::vector<double> dNdzeta(this->getNodeAmount());

	dNdzeta[0] = 0;
	dNdzeta[1] = 0;
	dNdzeta[2] = 0;
	dNdzeta[3] = 0;

	return dNdzeta;
}


std::vector<fem::Point>
Quadrangle4::getLocalCoordinates()
{
	this->coordinates[0] = Point(	-0.5,	-0.5,	0	);
	this->coordinates[1] = Point(	0.5,	-0.5,	0	);
	this->coordinates[2] = Point(	0.5,	0.5,	0	);
	this->coordinates[3] = Point(	-0.5,	0.5,	0	);

	return this->coordinates;
}


}	// namespace fem

