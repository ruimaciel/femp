#include "Hexahedron8.h++"


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
}


std::vector<double>
Hexahedron8::getN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();
	const double zeta = p.z();

	std::vector<double> N(this->node_number());

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
Hexahedron8::getdNdcsi(const Point &p)
{
	//double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdcsi(this->node_number());

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
Hexahedron8::getdNdeta(const Point &p)
{
	double csi = p.x();
	//double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdeta(this->node_number());

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
Hexahedron8::getdNdzeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();
	//double zeta = p.z();

	std::vector<double> dNdzeta(this->node_number());

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


std::vector<fem::Point> & 
Hexahedron8::setCoordinates()
{
	this->coordinates[0] = Point(	-1,	-1,	-1	);
	this->coordinates[1] = Point(	1,	-1,	-1	);
	this->coordinates[2] = Point(	1,	1,	-1	);
	this->coordinates[3] = Point(	-1,	1,	-1	);

	this->coordinates[4] = Point(	-1,	-1,	1	);
	this->coordinates[5] = Point(	1,	-1,	1	);
	this->coordinates[6] = Point(	1,	1,	1	);
	this->coordinates[7] = Point(	-1,	1,	1	);

	return this->coordinates;
}


}	//namespace fem
