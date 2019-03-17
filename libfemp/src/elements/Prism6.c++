#include <libfemp/elements/Prism6.h++>


#include <libfemp/FemException.h++>


namespace fem
{


Prism6::Prism6()
	: PrismFamily()
{
	this->type = BaseElement::FE_PRISM6;
	this->stiffness_degree = 2;
	this->domain_degree = 2;

	this->coordinates.resize(6);


	// specify new quadrature rule
	using namespace quadrature;
	TriangleRule * rule_xy = new Triangle3();
	LineRule * rule_z = new GaussLegendre2();

	m_stiffness_quadrature_rule = std::unique_ptr<PrismCartesianProduct>( new PrismCartesianProduct(rule_xy, rule_z));

	rule_xy = new Triangle3();
	rule_z = new GaussLegendre2();
	m_domain_quadrature_rule = std::unique_ptr<PrismCartesianProduct>( new PrismCartesianProduct(rule_xy, rule_z));

}


std::vector<double>
Prism6::getN(const Point3D &p)
{
	const double csi = p.x();
	const double eta = p.y();
	const double zeta = p.z();

	std::vector<double> N(this->getNodeAmount());

	N[0] = (-eta-csi+1)*(1-zeta)/2;
	N[1] = csi*(1-zeta)/2;
	N[2] = eta*(1-zeta)/2;
	N[3] = (-eta-csi+1)*(zeta+1)/2;
	N[4] = csi*(zeta+1)/2;
	N[5] = eta*(zeta+1)/2;

	return N;
}


std::vector<double>
Prism6::getdNdcsi(const Point3D &p)
{
	// double csi = p.x();
	// double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = -(1-zeta)/2;
	dNdcsi[1] = (1-zeta)/2;
	dNdcsi[2] = 0;
	dNdcsi[3] = -(zeta+1)/2;
	dNdcsi[4] = (zeta+1)/2;
	dNdcsi[5] = 0;

	return dNdcsi;
}


std::vector<double>
Prism6::getdNdeta(const Point3D &p)
{
	// double csi = p.x();
	// double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = -(1-zeta)/2;
	dNdeta[1] = 0;
	dNdeta[2] = (1-zeta)/2;
	dNdeta[3] = -(zeta+1)/2;
	dNdeta[4] = 0;
	dNdeta[5] = (zeta+1)/2;

	return dNdeta;
}


std::vector<double>
Prism6::getdNdzeta(const Point3D &p)
{
	double csi = p.x();
	double eta = p.y();
	// double zeta = p.z();

	std::vector<double> dNdzeta(this->getNodeAmount());

	dNdzeta[0] = -(-eta-csi+1)/2;
	dNdzeta[1] = -csi/2;
	dNdzeta[2] = -eta/2;
	dNdzeta[3] = (-eta-csi+1)/2;
	dNdzeta[4] = csi/2;
	dNdzeta[5] = eta/2;

	return dNdzeta;
}

std::vector<fem::Point3D>
Prism6::getLocalCoordinates()
{
	this->coordinates[0] = Point3D(	0,	0,	-1	);
	this->coordinates[1] = Point3D(	1,	0,	-1	);
	this->coordinates[2] = Point3D(	0,	1,	-1	);
	this->coordinates[3] = Point3D(	0,	0,	1	);
	this->coordinates[4] = Point3D(	1,	0,	1	);
	this->coordinates[5] = Point3D(	0,	1,	1	);

	return this->coordinates;
}


}	// namespace fem

