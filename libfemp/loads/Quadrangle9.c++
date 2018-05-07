#include "Quadrangle9.h++"

#include <memory>

#include <libfemp/quadrature_rules/Line.h++>
#include <libfemp/FemException.h++>


namespace fem
{


Quadrangle9::Quadrangle9()
{
	this->stiffness_degree = 1;
	this->domain_degree = 2;

	this->coordinates.resize(9);

	// specify new quadrature rule
	using namespace quadrature;
	LineRule * rule_x = new GaussLegendre3();
	LineRule * rule_y = new GaussLegendre3();

	m_stiffness_quadrature_rule = std::unique_ptr<QuadrangleCartesianProduct>( new QuadrangleCartesianProduct(rule_x, rule_y));

	rule_x = new GaussLegendre3();
	rule_y = new GaussLegendre3();
	m_domain_quadrature_rule = std::unique_ptr<QuadrangleCartesianProduct>( new QuadrangleCartesianProduct(rule_x, rule_y));

}


std::vector<double>
Quadrangle9::getN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();

	std::vector<double> N(this->getNodeAmount());

	N[0] = (csi-1)*csi*(eta-1)*eta/4;
	N[1] = csi*(csi+1)*(eta-1)*eta/4;
	N[2] = csi*(csi+1)*eta*(eta+1)/4;
	N[3] = (csi-1)*csi*eta*(eta+1)/4;
	N[4] = (1-csi)*(csi+1)*(eta-1)*eta/2;
	N[5] = csi*(csi+1)*(1-eta)*(eta+1)/2;
	N[6] = (1-csi)*(csi+1)*eta*(eta+1)/2;
	N[7] = (csi-1)*csi*(1-eta)*(eta+1)/2;
	N[8] = (1-csi)*(csi+1)*(1-eta)*(eta+1);

	return N;
}


std::vector<double>
Quadrangle9::getdNdcsi(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = csi*(eta-1)*eta/4+(csi-1)*(eta-1)*eta/4;
	dNdcsi[1] = (csi+1)*(eta-1)*eta/4+csi*(eta-1)*eta/4;
	dNdcsi[2] = (csi+1)*eta*(eta+1)/4+csi*eta*(eta+1)/4;
	dNdcsi[3] = csi*eta*(eta+1)/4+(csi-1)*eta*(eta+1)/4;
	dNdcsi[4] = (1-csi)*(eta-1)*eta/2-(csi+1)*(eta-1)*eta/2;
	dNdcsi[5] = (csi+1)*(1-eta)*(eta+1)/2+csi*(1-eta)*(eta+1)/2;
	dNdcsi[6] = (1-csi)*eta*(eta+1)/2-(csi+1)*eta*(eta+1)/2;
	dNdcsi[7] = csi*(1-eta)*(eta+1)/2+(csi-1)*(1-eta)*(eta+1)/2;
	dNdcsi[8] = (1-csi)*(1-eta)*(eta+1)-(csi+1)*(1-eta)*(eta+1);

	return dNdcsi;
}


std::vector<double>
Quadrangle9::getdNdeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = (csi-1)*csi*eta/4+(csi-1)*csi*(eta-1)/4;
	dNdeta[1] = csi*(csi+1)*eta/4+csi*(csi+1)*(eta-1)/4;
	dNdeta[2] = csi*(csi+1)*(eta+1)/4+csi*(csi+1)*eta/4;
	dNdeta[3] = (csi-1)*csi*(eta+1)/4+(csi-1)*csi*eta/4;
	dNdeta[4] = (1-csi)*(csi+1)*eta/2+(1-csi)*(csi+1)*(eta-1)/2;
	dNdeta[5] = csi*(csi+1)*(1-eta)/2-csi*(csi+1)*(eta+1)/2;
	dNdeta[6] = (1-csi)*(csi+1)*(eta+1)/2+(1-csi)*(csi+1)*eta/2;
	dNdeta[7] = (csi-1)*csi*(1-eta)/2-(csi-1)*csi*(eta+1)/2;
	dNdeta[8] = (1-csi)*(csi+1)*(1-eta)-(1-csi)*(csi+1)*(eta+1);

	return dNdeta;
}


std::vector<double>
Quadrangle9::getdNdzeta(const Point &)
{
	std::vector<double> dNdzeta(this->getNodeAmount());

	dNdzeta[0] = 0;
	dNdzeta[1] = 0;
	dNdzeta[2] = 0;
	dNdzeta[3] = 0;
	dNdzeta[4] = 0;
	dNdzeta[5] = 0;
	dNdzeta[6] = 0;
	dNdzeta[7] = 0;
	dNdzeta[8] = 0;

	return dNdzeta;
}

std::vector<fem::Point>
Quadrangle9::getLocalCoordinates()
{
	this->coordinates[0] = Point(	-0.5,	-0.5,	0	);
	this->coordinates[1] = Point(	0.5,	-0.5,	0	);
	this->coordinates[2] = Point(	0.5,	0.5,	0	);
	this->coordinates[3] = Point(	-0.5,	0.5,	0	);
	this->coordinates[4] = Point(	0,	-0.5,	0	);
	this->coordinates[5] = Point(	0.5,	0,	0	);
	this->coordinates[6] = Point(	0,	0.5,	0	);
	this->coordinates[7] = Point(	-0.5,	0,	0	);
	this->coordinates[8] = Point(	0,	0,	0	);

	return this->coordinates;
}


}	// namespace fem

