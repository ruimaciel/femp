#include "Quadrangle4.h++"


#include <libfemp/FemException.h++>


namespace fem
{


Quadrangle4::Quadrangle4()
{
	this->stiffness_degree = 1;
	this->domain_degree = 1;

	this->coordinates.resize(4);

	this->N.resize(4);
	this->dNdcsi.resize(4);
	this->dNdeta.resize(4);
	this->dNdzeta.resize(4);
}


std::vector<double> &
Quadrangle4::setN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();

	this->N[0] = (1-csi)*(1-eta)/4;
	this->N[1] = (1+csi)*(1-eta)/4;
	this->N[2] = (1+csi)*(1+eta)/4;
	this->N[3] = (1-csi)*(1+eta)/4;
	
	return this->N;
}


std::vector<double> &
Quadrangle4::setdNdcsi(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	this->dNdcsi[0] = (eta-1)/4;
	this->dNdcsi[1] = (1-eta)/4;
	this->dNdcsi[2] = (1+eta)/4;
	this->dNdcsi[3] = (-1-eta)/4;

	return this->dNdcsi;
}


std::vector<double> &
Quadrangle4::setdNdeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	this->dNdeta[0] = (csi-1)/4;
	this->dNdeta[1] = (-1-csi)/4;
	this->dNdeta[2] = (1+csi)/4;
	this->dNdeta[3] = (1-csi)/4;
	
	return this->dNdeta;
}


std::vector<double> &
Quadrangle4::setdNdzeta(const Point &)
{
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;
	this->dNdzeta[3] = 0;

	return this->dNdzeta;
}


std::vector<fem::Point> &
Quadrangle4::setCoordinates()
{
	this->coordinates[0] = Point(	-0.5,	-0.5,	0	);
	this->coordinates[1] = Point(	0.5,	-0.5,	0	);
	this->coordinates[2] = Point(	0.5,	0.5,	0	);
	this->coordinates[3] = Point(	-0.5,	0.5,	0	);

	return this->coordinates;
}


void
Quadrangle4::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 4)
	{
		throw FemException("wrong number of nodes");
	}
	this->nodes = nodes;
}


}	// namespace fem

