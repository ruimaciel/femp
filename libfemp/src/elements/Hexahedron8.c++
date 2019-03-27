#include <libfemp/elements/Hexahedron8.h++>

#include <memory>

#include <libfemp/quadrature_rules/Line.h++>
#include <libfemp/FemException.h++>


namespace fem
{


Hexahedron8::Hexahedron8()
	: HexahedronFamily()
{
	this->type = BaseElement::FE_HEXAHEDRON8;
	this->stiffness_degree = 2;
	this->domain_degree = 1;

	this->coordinates.resize(8);


	// specify new quadrature rule
	using namespace quadrature;
	LineRule * rule_x = new GaussLegendre2();
	LineRule * rule_y = new GaussLegendre2();
	LineRule * rule_z = new GaussLegendre2();

	m_stiffness_quadrature_rule = std::unique_ptr<HexahedronCartesianProduct>( new HexahedronCartesianProduct(rule_x, rule_y, rule_z));

	rule_x = new GaussLegendre2();
	rule_y = new GaussLegendre2();
	rule_z = new GaussLegendre2();
	m_domain_quadrature_rule = std::unique_ptr<HexahedronCartesianProduct>( new HexahedronCartesianProduct(rule_x, rule_y, rule_z));

}


std::vector<double>
Hexahedron8::getN(const Point3D &p)
{
	const double csi = p.x();
	const double eta = p.y();
	const double zeta = p.z();

	std::vector<double> N(this->getNodeAmount());

	N[0] = (1-csi)*(1-eta)*(1-zeta)/8;
	N[1] = (csi+1)*(1-eta)*(1-zeta)/8;
	N[2] = (csi+1)*(eta+1)*(1-zeta)/8;
	N[3] = (1-csi)*(eta+1)*(1-zeta)/8;
	N[4] = (1-csi)*(1-eta)*(zeta+1)/8;
	N[5] = (csi+1)*(1-eta)*(zeta+1)/8;
	N[6] = (csi+1)*(eta+1)*(zeta+1)/8;
	N[7] = (1-csi)*(eta+1)*(zeta+1)/8;

	return N;
}


std::vector<double>
Hexahedron8::getdNdcsi(const Point3D &p)
{
	//double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[ 0] = -(1-eta)*(1-zeta)/8;
	dNdcsi[ 1] = (1-eta)*(1-zeta)/8;
	dNdcsi[ 2] = (eta+1)*(1-zeta)/8;
	dNdcsi[ 3] = -(eta+1)*(1-zeta)/8;
	dNdcsi[ 4] = -(1-eta)*(zeta+1)/8;
	dNdcsi[ 5] = (1-eta)*(zeta+1)/8;
	dNdcsi[ 6] = (eta+1)*(zeta+1)/8;
	dNdcsi[ 7] = -(eta+1)*(zeta+1)/8;

	return dNdcsi;
}


std::vector<double>
Hexahedron8::getdNdeta(const Point3D &p)
{
	double csi = p.x();
	//double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[ 0] = -(1-csi)*(1-zeta)/8;
	dNdeta[ 1] = -(csi+1)*(1-zeta)/8;
	dNdeta[ 2] = (csi+1)*(1-zeta)/8;
	dNdeta[ 3] = (1-csi)*(1-zeta)/8;
	dNdeta[ 4] = -(1-csi)*(zeta+1)/8;
	dNdeta[ 5] = -(csi+1)*(zeta+1)/8;
	dNdeta[ 6] = (csi+1)*(zeta+1)/8;
	dNdeta[ 7] = (1-csi)*(zeta+1)/8;

	return dNdeta;
}


std::vector<double>
Hexahedron8::getdNdzeta(const Point3D &p)
{
	double csi = p.x();
	double eta = p.y();
	//double zeta = p.z();

	std::vector<double> dNdzeta(this->getNodeAmount());

	dNdzeta[ 0] = -(1-csi)*(1-eta)/8;
	dNdzeta[ 1] = -(csi+1)*(1-eta)/8;
	dNdzeta[ 2] = -(csi+1)*(eta+1)/8;
	dNdzeta[ 3] = -(1-csi)*(eta+1)/8;
	dNdzeta[ 4] = (1-csi)*(1-eta)/8;
	dNdzeta[ 5] = (csi+1)*(1-eta)/8;
	dNdzeta[ 6] = (csi+1)*(eta+1)/8;
	dNdzeta[ 7] = (1-csi)*(eta+1)/8;

	return dNdzeta;
}


int Hexahedron8::getNodeAmount() const
{
	return 8;
}


std::vector<fem::Point3D>
Hexahedron8::getLocalCoordinates()
{
	this->coordinates[0] = Point3D(	-1,	-1,	-1	);
	this->coordinates[1] = Point3D(	1,	-1,	-1	);
	this->coordinates[2] = Point3D(	1,	1,	-1	);
	this->coordinates[3] = Point3D(	-1,	1,	-1	);

	this->coordinates[4] = Point3D(	-1,	-1,	1	);
	this->coordinates[5] = Point3D(	1,	-1,	1	);
	this->coordinates[6] = Point3D(	1,	1,	1	);
	this->coordinates[7] = Point3D(	-1,	1,	1	);

	return this->coordinates;
}


}	//namespace fem
