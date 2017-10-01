#include "Hexahedron20.h++"


#include <libfemp/FemException.h++>


namespace fem
{


Hexahedron20::Hexahedron20()
	: HexahedronFamily()
{
	this->type = BaseElement::FE_HEXAHEDRON20;
	this->stiffness_degree = 3;
	this->domain_degree = 2;

	this->coordinates.resize(20);

	this->N.resize(20);
	this->dNdcsi.resize(20);
	this->dNdeta.resize(20);
	this->dNdzeta.resize(20);
}


std::vector<double> & 
Hexahedron20::setN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();
	const double zeta = p.z();

	this->N[ 0] = (1-csi)*(1-eta)*(1-zeta)*(-zeta-eta-csi-2)/8;
	this->N[ 1] = (csi+1)*(1-eta)*(1-zeta)*(-zeta-eta+csi-2)/8;
	this->N[ 2] = (csi+1)*(eta+1)*(1-zeta)*(-zeta+eta+csi-2)/8;
	this->N[ 3] = (1-csi)*(eta+1)*(1-zeta)*(-zeta+eta-csi-2)/8;
	this->N[ 4] = (1-csi)*(1-eta)*(zeta+1)*(zeta-eta-csi-2)/8;
	this->N[ 5] = (csi+1)*(1-eta)*(zeta+1)*(zeta-eta+csi-2)/8;
	this->N[ 6] = (csi+1)*(eta+1)*(zeta+1)*(zeta+eta+csi-2)/8;
	this->N[ 7] = (1-csi)*(eta+1)*(zeta+1)*(zeta+eta-csi-2)/8;
	this->N[ 8] = (1-csi*csi)*(1-eta)*(1-zeta)/4;
	this->N[ 9] = (1-csi)*(1-eta*eta)*(1-zeta)/4;
	this->N[10] = (1-csi)*(1-eta)*(1-zeta*zeta)/4;
	this->N[11] = (csi+1)*(1-eta*eta)*(1-zeta)/4;
	this->N[12] = (csi+1)*(1-eta)*(1-zeta*zeta)/4;
	this->N[13] = (1-csi*csi)*(eta+1)*(1-zeta)/4;
	this->N[14] = (csi+1)*(eta+1)*(1-zeta*zeta)/4;
	this->N[15] = (1-csi)*(eta+1)*(1-zeta*zeta)/4;
	this->N[16] = (1-csi*csi)*(1-eta)*(zeta+1)/4;
	this->N[17] = (1-csi)*(1-eta*eta)*(zeta+1)/4;
	this->N[18] = (csi+1)*(1-eta*eta)*(zeta+1)/4;
	this->N[19] = (1-csi*csi)*(eta+1)*(zeta+1)/4;

	return this->N;
}


std::vector<double> & 
Hexahedron20::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & 
Hexahedron20::setdNdcsi(const double &csi, const double &eta, const double &zeta)
{
	// this->dNdcsi
	this->dNdcsi[ 0] = (eta-1)*(zeta-1)*(zeta+eta+2*csi+1)/8;
	this->dNdcsi[ 1] = -(eta-1)*(zeta-1)*(zeta+eta-2*csi+1)/8;
	this->dNdcsi[ 2] = (eta+1)*(zeta-1)*(zeta-eta-2*csi+1)/8;
	this->dNdcsi[ 3] = -(eta+1)*(zeta-1)*(zeta-eta+2*csi+1)/8;
	this->dNdcsi[ 4] = (eta-1)*(zeta+1)*(zeta-eta-2*csi-1)/8;
	this->dNdcsi[ 5] = -(eta-1)*(zeta+1)*(zeta-eta+2*csi-1)/8;
	this->dNdcsi[ 6] = (eta+1)*(zeta+1)*(zeta+eta+2*csi-1)/8;
	this->dNdcsi[ 7] = -(eta+1)*(zeta+1)*(zeta+eta-2*csi-1)/8;
	this->dNdcsi[ 8] = -csi*(1-eta)*(1-zeta)/2;
	this->dNdcsi[ 9] = -(1-eta*eta)*(1-zeta)/4;
	this->dNdcsi[10] = -(1-eta)*(1-zeta*zeta)/4;
	this->dNdcsi[11] = (1-eta*eta)*(1-zeta)/4;
	this->dNdcsi[12] = (1-eta)*(1-zeta*zeta)/4;
	this->dNdcsi[13] = -csi*(eta+1)*(1-zeta)/2;
	this->dNdcsi[14] = (eta+1)*(1-zeta*zeta)/4;
	this->dNdcsi[15] = -(eta+1)*(1-zeta*zeta)/4;
	this->dNdcsi[16] = -csi*(1-eta)*(zeta+1)/2;
	this->dNdcsi[17] = -(1-eta*eta)*(zeta+1)/4;
	this->dNdcsi[18] = (1-eta*eta)*(zeta+1)/4;
	this->dNdcsi[19] = -csi*(eta+1)*(zeta+1)/2;

	return this->dNdcsi;
}


std::vector<double> & 
Hexahedron20::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & 
Hexahedron20::setdNdeta(const double &csi, const double &eta, const double &zeta)
{
	// this->dNdeta
	this->dNdeta[ 0] = (csi-1)*(zeta-1)*(zeta+2*eta+csi+1)/8;
	this->dNdeta[ 1] = (csi+1)*(1-zeta)*(zeta+2*eta-csi+1)/8;
	this->dNdeta[ 2] = (csi+1)*(zeta-1)*(zeta-2*eta-csi+1)/8;
	this->dNdeta[ 3] = (csi-1)*(1-zeta)*(zeta-2*eta+csi+1)/8;
	this->dNdeta[ 4] = (csi-1)*(zeta+1)*(zeta-2*eta-csi-1)/8;
	this->dNdeta[ 5] = -(csi+1)*(zeta+1)*(zeta-2*eta+csi-1)/8;
	this->dNdeta[ 6] = (csi+1)*(zeta+1)*(zeta+2*eta+csi-1)/8;
	this->dNdeta[ 7] = (1-csi)*(zeta+1)*(zeta+2*eta-csi-1)/8;
	this->dNdeta[ 8] = (1-csi*csi)*(zeta-1)/4;
	this->dNdeta[ 9] = (1-csi)*eta*(zeta-1)/2;
	this->dNdeta[10] = (csi-1)*(1-zeta*zeta)/4;
	this->dNdeta[11] = (csi+1)*eta*(zeta-1)/2;
	this->dNdeta[12] = (csi+1)*(zeta*zeta-1)/4;
	this->dNdeta[13] = (1-csi*csi)*(1-zeta)/4;
	this->dNdeta[14] = (csi+1)*(1-zeta*zeta)/4;
	this->dNdeta[15] = (1-csi)*(1-zeta*zeta)/4;
	this->dNdeta[16] = (csi*csi-1)*(zeta+1)/4;
	this->dNdeta[17] = (csi-1)*eta*(zeta+1)/2;
	this->dNdeta[18] = -(csi+1)*eta*(zeta+1)/2;
	this->dNdeta[19] = (1-csi*csi)*(zeta+1)/4;
	
	return this->dNdeta;
}


std::vector<double> & 
Hexahedron20::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & 
Hexahedron20::setdNdzeta(const double &csi, const double &eta, const double &zeta)
{
	// this->dNdzeta
	this->dNdzeta[ 0] = (csi-1)*(eta-1)*(2*zeta+eta+csi+1)/8;
	this->dNdzeta[ 1] = -(csi+1)*(eta-1)*(2*zeta+eta-csi+1)/8;
	this->dNdzeta[ 2] = (csi+1)*(eta+1)*(2*zeta-eta-csi+1)/8;
	this->dNdzeta[ 3] = -(csi-1)*(eta+1)*(2*zeta-eta+csi+1)/8;
	this->dNdzeta[ 4] = (csi-1)*(eta-1)*(2*zeta-eta-csi-1)/8;
	this->dNdzeta[ 5] = -(csi+1)*(eta-1)*(2*zeta-eta+csi-1)/8;
	this->dNdzeta[ 6] = (csi+1)*(eta+1)*(2*zeta+eta+csi-1)/8;
	this->dNdzeta[ 7] = -(csi-1)*(eta+1)*(2*zeta+eta-csi-1)/8;
	this->dNdzeta[ 8] = -(1-csi*csi)*(1-eta)/4;
	this->dNdzeta[ 9] = -(1-csi)*(1-eta*eta)/4;
	this->dNdzeta[10] = -(1-csi)*(1-eta)*zeta/2;
	this->dNdzeta[11] = -(csi+1)*(1-eta*eta)/4;
	this->dNdzeta[12] = -(csi+1)*(1-eta)*zeta/2;
	this->dNdzeta[13] = -(1-csi*csi)*(eta+1)/4;
	this->dNdzeta[14] = -(csi+1)*(eta+1)*zeta/2;
	this->dNdzeta[15] = -(1-csi)*(eta+1)*zeta/2;
	this->dNdzeta[16] = (1-csi*csi)*(1-eta)/4;
	this->dNdzeta[17] = (1-csi)*(1-eta*eta)/4;
	this->dNdzeta[18] = (csi+1)*(1-eta*eta)/4;
	this->dNdzeta[19] = (1-csi*csi)*(eta+1)/4;

	return this->dNdzeta;
}


std::vector<fem::Point> & 
Hexahedron20::setCoordinates()
{
	this->coordinates[0] = Point(	-1,	-1,	-1	);
	this->coordinates[1] = Point(	1,	-1,	-1	);
	this->coordinates[2] = Point(	1,	1,	-1	);
	this->coordinates[3] = Point(	-1,	1,	-1	);

	this->coordinates[4] = Point(	-1,	-1,	1	);
	this->coordinates[5] = Point(	1,	-1,	1	);
	this->coordinates[6] = Point(	1,	1,	1	);
	this->coordinates[7] = Point(	-1,	1,	1	);

	this->coordinates[8] = Point(	0,	-1,	-1	);
	this->coordinates[9] = Point(	-1,	0,	-1	);
	this->coordinates[10] = Point(	-1,	-1,	0	);
	this->coordinates[11] = Point(	1,	0,	-1	);
	this->coordinates[12] = Point(	1,	-1,	0	);
	this->coordinates[13] = Point(	0,	1,	-1	);
	this->coordinates[14] = Point(	1,	1,	0	);
	this->coordinates[15] = Point(	-1,	1,	0	);
	this->coordinates[16] = Point(	0,	-1,	1	);
	this->coordinates[17] = Point(	-1,	0,	1	);
	this->coordinates[18] = Point(	1,	0,	1	);
	this->coordinates[19] = Point(	0,	1,	1	);

	return this->coordinates;
}


void
Hexahedron20::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 20)
	{
		throw FemException("wrong number of nodes");
	}

	this->nodes = nodes;
}


}	// namespace fem

