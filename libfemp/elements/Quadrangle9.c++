#include "Quadrangle9.h++"


#include <libfemp/FemException.h++>


namespace fem
{


Quadrangle9::Quadrangle9()
{
	this->stiffness_degree = 1;
	this->domain_degree = 2;

	this->coordinates.resize(9);

	this->N.resize(9);
	this->dNdcsi.resize(9);
	this->dNdeta.resize(9);
	this->dNdzeta.resize(9);
}


std::vector<double>
Quadrangle9::getN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();

	this->N[0] = (csi-1)*csi*(eta-1)*eta/4;
	this->N[1] = csi*(csi+1)*(eta-1)*eta/4;
	this->N[2] = csi*(csi+1)*eta*(eta+1)/4;
	this->N[3] = (csi-1)*csi*eta*(eta+1)/4;
	this->N[4] = (1-csi)*(csi+1)*(eta-1)*eta/2;
	this->N[5] = csi*(csi+1)*(1-eta)*(eta+1)/2;
	this->N[6] = (1-csi)*(csi+1)*eta*(eta+1)/2;
	this->N[7] = (csi-1)*csi*(1-eta)*(eta+1)/2;
	this->N[8] = (1-csi)*(csi+1)*(1-eta)*(eta+1);

	return this->N;
}


std::vector<double>
Quadrangle9::getdNdcsi(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	this->dNdcsi[0] = csi*(eta-1)*eta/4+(csi-1)*(eta-1)*eta/4;
	this->dNdcsi[1] = (csi+1)*(eta-1)*eta/4+csi*(eta-1)*eta/4;
	this->dNdcsi[2] = (csi+1)*eta*(eta+1)/4+csi*eta*(eta+1)/4;
	this->dNdcsi[3] = csi*eta*(eta+1)/4+(csi-1)*eta*(eta+1)/4;
	this->dNdcsi[4] = (1-csi)*(eta-1)*eta/2-(csi+1)*(eta-1)*eta/2;
	this->dNdcsi[5] = (csi+1)*(1-eta)*(eta+1)/2+csi*(1-eta)*(eta+1)/2;
	this->dNdcsi[6] = (1-csi)*eta*(eta+1)/2-(csi+1)*eta*(eta+1)/2;
	this->dNdcsi[7] = csi*(1-eta)*(eta+1)/2+(csi-1)*(1-eta)*(eta+1)/2;
	this->dNdcsi[8] = (1-csi)*(1-eta)*(eta+1)-(csi+1)*(1-eta)*(eta+1);
	
	return this->dNdcsi;
}


std::vector<double>
Quadrangle9::getdNdeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	this->dNdeta[0] = (csi-1)*csi*eta/4+(csi-1)*csi*(eta-1)/4;
	this->dNdeta[1] = csi*(csi+1)*eta/4+csi*(csi+1)*(eta-1)/4;
	this->dNdeta[2] = csi*(csi+1)*(eta+1)/4+csi*(csi+1)*eta/4;
	this->dNdeta[3] = (csi-1)*csi*(eta+1)/4+(csi-1)*csi*eta/4;
	this->dNdeta[4] = (1-csi)*(csi+1)*eta/2+(1-csi)*(csi+1)*(eta-1)/2;
	this->dNdeta[5] = csi*(csi+1)*(1-eta)/2-csi*(csi+1)*(eta+1)/2;
	this->dNdeta[6] = (1-csi)*(csi+1)*(eta+1)/2+(1-csi)*(csi+1)*eta/2;
	this->dNdeta[7] = (csi-1)*csi*(1-eta)/2-(csi-1)*csi*(eta+1)/2;
	this->dNdeta[8] = (1-csi)*(csi+1)*(1-eta)-(1-csi)*(csi+1)*(eta+1);
	
	return this->dNdeta;
}


std::vector<double>
Quadrangle9::getdNdzeta(const Point &)
{
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;
	this->dNdzeta[3] = 0;
	this->dNdzeta[4] = 0;
	this->dNdzeta[5] = 0;
	this->dNdzeta[6] = 0;
	this->dNdzeta[7] = 0;
	this->dNdzeta[8] = 0;

	return this->dNdzeta;
}

std::vector<fem::Point> &
Quadrangle9::setCoordinates()
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


void
Quadrangle9::get(std::vector<size_t> &nodes)
{
	if(nodes.size() == 9)
	{
		throw FemException("wrong number of nodes");
	}

	this->nodes = nodes;
}


}	// namespace fem

