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

	this->N.resize(8);
	this->dNdcsi.resize(8);
	this->dNdeta.resize(8);
	this->dNdzeta.resize(8);
}


std::vector<double> & 
Hexahedron8::setN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();
	const double zeta = p.z();

	this->N[0] = (1-csi)*(1-eta)*(1-zeta)/8;
	this->N[1] = (csi+1)*(1-eta)*(1-zeta)/8;
	this->N[2] = (csi+1)*(eta+1)*(1-zeta)/8;
	this->N[3] = (1-csi)*(eta+1)*(1-zeta)/8;
	this->N[4] = (1-csi)*(1-eta)*(zeta+1)/8;
	this->N[5] = (csi+1)*(1-eta)*(zeta+1)/8;
	this->N[6] = (csi+1)*(eta+1)*(zeta+1)/8;
	this->N[7] = (1-csi)*(eta+1)*(zeta+1)/8;
	
	return this->N;
}


std::vector<double> & 
Hexahedron8::setdNdcsi(const Point &p)
{
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	this->dNdcsi[ 0] = -(1-eta)*(1-zeta)/8;
	this->dNdcsi[ 1] = (1-eta)*(1-zeta)/8;
	this->dNdcsi[ 2] = (eta+1)*(1-zeta)/8;
	this->dNdcsi[ 3] = -(eta+1)*(1-zeta)/8;
	this->dNdcsi[ 4] = -(1-eta)*(zeta+1)/8;
	this->dNdcsi[ 5] = (1-eta)*(zeta+1)/8;
	this->dNdcsi[ 6] = (eta+1)*(zeta+1)/8;
	this->dNdcsi[ 7] = -(eta+1)*(zeta+1)/8;

	return this->dNdcsi;
}


std::vector<double> & 
Hexahedron8::setdNdeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	this->dNdeta[ 0] = -(1-csi)*(1-zeta)/8;
	this->dNdeta[ 1] = -(csi+1)*(1-zeta)/8;
	this->dNdeta[ 2] = (csi+1)*(1-zeta)/8;
	this->dNdeta[ 3] = (1-csi)*(1-zeta)/8;
	this->dNdeta[ 4] = -(1-csi)*(zeta+1)/8;
	this->dNdeta[ 5] = -(csi+1)*(zeta+1)/8;
	this->dNdeta[ 6] = (csi+1)*(zeta+1)/8;
	this->dNdeta[ 7] = (1-csi)*(zeta+1)/8;
	
	return this->dNdeta;
}


std::vector<double> & 
Hexahedron8::setdNdzeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	this->dNdzeta[ 0] = -(1-csi)*(1-eta)/8;
	this->dNdzeta[ 1] = -(csi+1)*(1-eta)/8;
	this->dNdzeta[ 2] = -(csi+1)*(eta+1)/8;
	this->dNdzeta[ 3] = -(1-csi)*(eta+1)/8;
	this->dNdzeta[ 4] = (1-csi)*(1-eta)/8;
	this->dNdzeta[ 5] = (csi+1)*(1-eta)/8;
	this->dNdzeta[ 6] = (csi+1)*(eta+1)/8;
	this->dNdzeta[ 7] = (1-csi)*(eta+1)/8;

	return this->dNdzeta;
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


void
Hexahedron8::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 8)
	{
		throw FemException("wrong number of nodes");
	}

	this->nodes = nodes;
}


}	//namespace fem
