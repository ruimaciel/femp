#include "Triangle6.h++"


#include <libfemp/FemException.h++>


namespace fem
{


Triangle6::Triangle6()
{
	this->stiffness_degree = 1;
	this->domain_degree = 2;

	this->coordinates.resize(6);

	this->N.resize(6);
	this->dNdcsi.resize(6);
	this->dNdeta.resize(6);
	this->dNdzeta.resize(6);
}


std::vector<double> &
Triangle6::setN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();

	this->N[0] = (2*(1-eta-csi)-1)*(1-eta-csi);
	this->N[1] = csi*(2*csi-1);
	this->N[2] = eta*(2*eta-1);
	this->N[3] = 4*csi*(1-eta-csi);
	this->N[4] = 4*csi*eta;
	this->N[5] = 4*(1-eta-csi)*eta;
	
	return this->N;
}


std::vector<double> &
Triangle6::setdNdcsi(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	this->dNdcsi[0] = 1.0-4*(1-eta-csi);
	this->dNdcsi[1] = 4*csi-1;
	this->dNdcsi[2] = 0;
	this->dNdcsi[3] = 4*(1-eta-csi)-4*csi;
	this->dNdcsi[4] = 4*eta;
	this->dNdcsi[5] = -4*eta;

	return this->dNdcsi;
}


std::vector<double> &
Triangle6::setdNdeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	this->dNdeta[0] = 1-4*(1-eta-csi);
	this->dNdeta[1] = 0;
	this->dNdeta[2] = 4*eta-1;
	this->dNdeta[3] = -4*csi;
	this->dNdeta[4] = 4*csi;
	this->dNdeta[5] = 4*(1-eta-csi)-4*eta;
	
	return this->dNdeta;
}


std::vector<double> &
Triangle6::setdNdzeta(const Point &)
{
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;
	this->dNdzeta[3] = 0;
	this->dNdzeta[4] = 0;
	this->dNdzeta[5] = 0;

	return this->dNdzeta;
}


std::vector<fem::Point> &
Triangle6::setCoordinates()
{
	//TODO finish
	this->coordinates[0] = Point(	0,	0,	0	);
	this->coordinates[1] = Point(	1,	0,	0	);
	this->coordinates[2] = Point(	0,	1,	0	);
	this->coordinates[3] = Point(	0.5f,	0,	0	);
	this->coordinates[4] = Point(	0.5f,	0.5f,	0	);
	this->coordinates[5] = Point(	0,	0.5f,	0	);

	return this->coordinates;
}


void
Triangle6::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 6)
	{
		throw FemException("wrong number of nodes");
	}

	this->nodes = nodes;
}


}	//namespace fem

