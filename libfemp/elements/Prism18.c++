#include "Prism18.h++"


#include <libfemp/FemException.h++>


namespace fem
{


Prism18::Prism18()
	: PrismFamily()
{
	this->type = BaseElement::FE_PRISM18;
	this->stiffness_degree = 5;
	this->domain_degree = 2;

	this->coordinates.resize(18);

	this->N.resize(18);
	this->dNdcsi.resize(18);
	this->dNdeta.resize(18);
	this->dNdzeta.resize(18);
}


std::vector<double>
Prism18::getN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();
	const double zeta = p.z();

	this->N[0] = ((-1 + csi + eta)*(-1 + 2*csi + 2*eta)*(-1 + zeta)* zeta)/2.;
	this->N[1] = (csi*(-1 + 2*csi)*(-1 + zeta)*zeta)/2.;
	this->N[2] =  (eta*(-1 + 2*eta)*(-1 + zeta)*zeta)/2.;
	this->N[3] =  ((-1 + csi + eta)*(-1 + 2*csi + 2*eta)*zeta*(1 + zeta))/2.;
	this->N[4] =  (csi*(-1 + 2*csi)*zeta*(1 + zeta))/2.;
	this->N[5] =  (eta*(-1 + 2*eta)*zeta*(1 + zeta))/2.;
	this->N[6] =  -2*csi*(-1 + csi + eta)*(-1 + zeta)*zeta;
	this->N[7] =  -2*eta*(-1 + csi + eta)*(-1 + zeta)*zeta;
	this->N[8] =  -((-1 + csi + eta)*(-1 + 2*csi + 2*eta)*(-1 + zeta*zeta));
	this->N[9] =  2*csi*eta*(-1 + zeta)*zeta;
	this->N[10] =  -(csi*(-1 + 2*csi)*(-1 + zeta*zeta));
	this->N[11] =  -(eta*(-1 + 2*eta)*(-1 + zeta*zeta));
	this->N[12] =  -2*csi*(-1 + csi + eta)*zeta*(1 + zeta);
	this->N[13] =  -2*eta*(-1 + csi + eta)*zeta*(1 + zeta);
	this->N[14] =  2*csi*eta*zeta*(1 + zeta);
	this->N[15] =  4*csi*(-1 + csi + eta)*(-1 + zeta*zeta);
	this->N[16] =  4*eta*(-1 + csi + eta)*(-1 + zeta*zeta);
	this->N[17] =  -4*csi*eta*(-1 + zeta*zeta);
	
	return this->N;
}


std::vector<double>
Prism18::getdNdcsi(const Point &p)
{
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	this->dNdcsi[0] = (2*eta+2*csi-1)*(zeta-1)*zeta/2+(eta+csi-1)*(zeta-1)*zeta;
	this->dNdcsi[1] = (2*csi-1)*(zeta-1)*zeta/2+csi*(zeta-1)*zeta;
	this->dNdcsi[2] = 0;
	this->dNdcsi[3] = (2*eta+2*csi-1)*zeta*(zeta+1)/2+(eta+csi-1)*zeta*(zeta+1);
	this->dNdcsi[4] =  (2*csi-1)*zeta*(zeta+1)/2+csi*zeta*(zeta+1);
	this->dNdcsi[5] = 0;
	this->dNdcsi[6] = -2*(eta+csi-1)*(zeta-1)*zeta-2*csi*(zeta-1)*zeta;
	this->dNdcsi[7] = -2*eta*(zeta-1)*zeta;
	this->dNdcsi[8] = -(2*eta+2*csi-1)*(zeta*zeta-1)-2*(eta+csi-1)*(zeta*zeta-1);
	this->dNdcsi[9] = 2*eta*(zeta-1)*zeta;
	this->dNdcsi[10] =  -(2*csi-1)*(zeta*zeta-1)-2*csi*(zeta*zeta-1);
	this->dNdcsi[11] = 0;
	this->dNdcsi[12] = -2*(eta+csi-1)*zeta*(zeta+1)-2*csi*zeta*(zeta+1);
	this->dNdcsi[13] = -2*eta*zeta*(zeta+1);
	this->dNdcsi[14] = 2*eta*zeta*(zeta+1);
	this->dNdcsi[15] = 4*(eta+csi-1)*(zeta*zeta-1)+4*csi*(zeta*zeta-1);
	this->dNdcsi[16] = 4*eta*(zeta*zeta-1);
	this->dNdcsi[17] = -4*eta*(zeta*zeta-1);


	return this->dNdcsi;
}


std::vector<double>
Prism18::getdNdeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	this->dNdeta[0] = (2*eta+2*csi-1)*(zeta-1)*zeta/2+(eta+csi-1)*(zeta-1)*zeta;
	this->dNdeta[1] = 0;
	this->dNdeta[2] = (2*eta-1)*(zeta-1)*zeta/2+eta*(zeta-1)*zeta;
	this->dNdeta[3] = (2*eta+2*csi-1)*zeta*(zeta+1)/2+(eta+csi-1)*zeta*(zeta+1);
	this->dNdeta[4] = 0;
	this->dNdeta[5] =  (2*eta-1)*zeta*(zeta+1)/2+eta*zeta*(zeta+1);
	this->dNdeta[6] = -2*csi*(zeta-1)*zeta;
	this->dNdeta[7] = -2*(eta+csi-1)*(zeta-1)*zeta-2*eta*(zeta-1)*zeta;
	this->dNdeta[8] = -(2*eta+2*csi-1)*(zeta*zeta-1)-2*(eta+csi-1)*(zeta*zeta-1);
	this->dNdeta[9] = 2*csi*(zeta-1)*zeta;
	this->dNdeta[10] = 0;
	this->dNdeta[11] =  -(2*eta-1)*(zeta*zeta-1)-2*eta*(zeta*zeta-1);
	this->dNdeta[12] = -2*csi*zeta*(zeta+1);
	this->dNdeta[13] = -2*(eta+csi-1)*zeta*(zeta+1)-2*eta*zeta*(zeta+1);
	this->dNdeta[14] = 2*csi*zeta*(zeta+1);
	this->dNdeta[15] = 4*csi*(zeta*zeta-1);
	this->dNdeta[16] = 4*(eta+csi-1)*(zeta*zeta-1)+4*eta*(zeta*zeta-1);
	this->dNdeta[17] =  -4*csi*(zeta*zeta-1);
	
	return this->dNdeta;
}


std::vector<double>
Prism18::getdNdzeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	this->dNdzeta[0] = (eta+csi-1)*(2*eta+2*csi-1)*zeta/2+(eta+csi-1)*(2*eta+2*csi-1)*(zeta-1)/2;
	this->dNdzeta[1] = csi*(2*csi-1)*zeta/2+csi*(2*csi-1)*(zeta-1)/2;
	this->dNdzeta[2] = eta*(2*eta-1)*zeta/2+eta*(2*eta-1)*(zeta-1)/2;
	this->dNdzeta[3] =  (eta+csi-1)*(2*eta+2*csi-1)*(zeta+1)/2+(eta+csi-1)*(2*eta+2*csi-1)*zeta/2;
	this->dNdzeta[4] = csi*(2*csi-1)*(zeta+1)/2+csi*(2*csi-1)*zeta/2;
	this->dNdzeta[5] = eta*(2*eta-1)*(zeta+1)/2+eta*(2*eta-1)*zeta/2;
	this->dNdzeta[6] =  -2*csi*(eta+csi-1)*zeta-2*csi*(eta+csi-1)*(zeta-1);
	this->dNdzeta[7] = -2*eta*(eta+csi-1)*zeta-2*eta*(eta+csi-1)*(zeta-1);
	this->dNdzeta[8] = -2*(eta+csi-1)*(2*eta+2*csi-1)*zeta;
	this->dNdzeta[9] = 2*csi*eta*zeta+2*csi*eta*(zeta-1);
	this->dNdzeta[10] = -2*csi*(2*csi-1)*zeta;
	this->dNdzeta[11] =  -2*eta*(2*eta-1)*zeta;
	this->dNdzeta[12] = -2*csi*(eta+csi-1)*(zeta+1)-2*csi*(eta+csi-1)*zeta;
	this->dNdzeta[13] = -2*eta*(eta+csi-1)*(zeta+1)-2*eta*(eta+csi-1)*zeta;
	this->dNdzeta[14] = 2*csi*eta*(zeta+1)+2*csi*eta*zeta;
	this->dNdzeta[15] = 8*csi*(eta+csi-1)*zeta;
	this->dNdzeta[16] =  8*eta*(eta+csi-1)*zeta;
	this->dNdzeta[17] = -8*csi*eta*zeta;

	return this->dNdzeta;
}

std::vector<fem::Point> & Prism18::setCoordinates()
{
	this->coordinates[0] = Point(	0,	0,	-1	);
	this->coordinates[1] = Point(	1,	0,	-1	);
	this->coordinates[2] = Point(	0,	1,	-1	);
	this->coordinates[3] = Point(	0,	0,	1	);
	this->coordinates[4] = Point(	1,	0,	1	);
	this->coordinates[5] = Point(	0,	1,	1	);

	this->coordinates[6] = Point(	0.5,	0,	-1	);
	this->coordinates[7] = Point(	0,	0.5,	-1	);
	this->coordinates[8] = Point(	0,	0,	0	);
	this->coordinates[9] = Point(	0.5,	0.5,	-1	);
	this->coordinates[10] = Point(	1,	0,	0	);
	this->coordinates[11] = Point(	0,	1,	0	);
	this->coordinates[12] = Point(	0.5,	0,	1	);
	this->coordinates[13] = Point(	0,	0.5,	1	);
	this->coordinates[14] = Point(	0.5,	0.5,	1	);

	this->coordinates[15] = Point(	0.5,	0,	0	);
	this->coordinates[16] = Point(	0,	0.5,	0	);
	this->coordinates[17] = Point(	0.5,	0.5,	0	);

	return this->coordinates;
}


void
Prism18::get(std::vector<size_t> &nodes)
{
	if(nodes.size() == 18)
	{
		throw FemException("wrong number of nodes");
	}
	this->nodes = nodes;
}



}	// namespace fem

