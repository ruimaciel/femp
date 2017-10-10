#include "Prism6.h++"


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

	this->N.resize(6);
	this->dNdcsi.resize(6);
	this->dNdeta.resize(6);
	this->dNdzeta.resize(6);
}


std::vector<double>
Prism6::getN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();
	const double zeta = p.z();

	this->N[0] = (-eta-csi+1)*(1-zeta)/2;
	this->N[1] = csi*(1-zeta)/2;
	this->N[2] = eta*(1-zeta)/2;
	this->N[3] = (-eta-csi+1)*(zeta+1)/2;
	this->N[4] = csi*(zeta+1)/2;
	this->N[5] = eta*(zeta+1)/2;
	
	return this->N;
}


std::vector<double>
Prism6::getdNdcsi(const Point &p)
{
	// double csi = p.x();
	// double eta = p.y();
	double zeta = p.z();

	this->dNdcsi[0] = -(1-zeta)/2;
	this->dNdcsi[1] = (1-zeta)/2;
	this->dNdcsi[2] = 0;
	this->dNdcsi[3] = -(zeta+1)/2;
	this->dNdcsi[4] = (zeta+1)/2;
	this->dNdcsi[5] = 0;

	return this->dNdcsi;
}


std::vector<double>
Prism6::getdNdeta(const Point &p)
{
	// double csi = p.x();
	// double eta = p.y();
	double zeta = p.z();

	this->dNdeta[0] = -(1-zeta)/2;
	this->dNdeta[1] = 0;
	this->dNdeta[2] = (1-zeta)/2;
	this->dNdeta[3] = -(zeta+1)/2;
	this->dNdeta[4] = 0;
	this->dNdeta[5] = (zeta+1)/2;
	
	return this->dNdeta;
}


std::vector<double>
Prism6::getdNdzeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();
	// double zeta = p.z();

	this->dNdzeta[0] = -(-eta-csi+1)/2;
	this->dNdzeta[1] = -csi/2;
	this->dNdzeta[2] = -eta/2;
	this->dNdzeta[3] = (-eta-csi+1)/2;
	this->dNdzeta[4] = csi/2;
	this->dNdzeta[5] = eta/2;

	return this->dNdzeta;
}

std::vector<fem::Point> & Prism6::setCoordinates()
{
	this->coordinates[0] = Point(	0,	0,	-1	);
	this->coordinates[1] = Point(	1,	0,	-1	);
	this->coordinates[2] = Point(	0,	1,	-1	);
	this->coordinates[3] = Point(	0,	0,	1	);
	this->coordinates[4] = Point(	1,	0,	1	);
	this->coordinates[5] = Point(	0,	1,	1	);

	return this->coordinates;
}


void
Prism6::get(std::vector<size_t> &nodes)
{
	if(nodes.size() == 6)
	{
		throw FemException("wrong number of nodes");
	}
	this->nodes = nodes;
}


}	// namespace fem

