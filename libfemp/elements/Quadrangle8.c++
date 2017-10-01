#include "Quadrangle8.h++"


#include <libfemp/FemException.h++>


namespace fem
{


Quadrangle8::Quadrangle8()
{
	this->stiffness_degree = 2;
	this->domain_degree = 2;

	this->coordinates.resize(8);

	this->N.resize(8);
	this->dNdcsi.resize(8);
	this->dNdeta.resize(8);
	this->dNdzeta.resize(8);
}


std::vector<double> & Quadrangle8::setN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();

	this->N[0] = (csi-1)*(1-eta)*(eta+csi+1)/4;
	this->N[1] = (csi+1)*(eta-1)*(eta-csi+1)/4;
	this->N[2] = (csi+1)*(eta+1)*(eta+csi-1)/4;
	this->N[3] = (1-csi)*(eta+1)*(eta-csi-1)/4;
	this->N[4] = (1-csi*csi)*(1-eta)/2;
	this->N[5] = (csi+1)*(1-eta*eta)/2;
	this->N[6] = (1-csi*csi)*(eta+1)/2;
	this->N[7] = (1-csi)*(1-eta*eta)/2;
	
	return this->N;
}


std::vector<double> & Quadrangle8::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & Quadrangle8::setdNdcsi(const double &csi, const double &eta, const double &)
{
	//TODO test this
	// this->dNdcsi
	this->dNdcsi[0] = (1-eta)*(eta+csi+1)/4+(csi-1)*(1-eta)/4;
	this->dNdcsi[1] = (eta-1)*(eta-csi+1)/4-(csi+1)*(eta-1)/4;
	this->dNdcsi[2] = (eta+1)*(eta+csi-1)/4+(csi+1)*(eta+1)/4;
	this->dNdcsi[3] = -(eta+1)*(eta-csi-1)/4-(1-csi)*(eta+1)/4;
	this->dNdcsi[4] = -csi*(1-eta);
	this->dNdcsi[5] = (1-eta*eta)/2;
	this->dNdcsi[6] = -csi*(eta+1);
	this->dNdcsi[7] = -(1-eta*eta)/2;

	return this->dNdcsi;
}


std::vector<double> & Quadrangle8::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & Quadrangle8::setdNdeta(const double &csi, const double &eta, const double &)
{
	//TODO test this
	// this->dNdeta
	this->dNdeta[0] = (csi-1)*(1-eta)/4-(csi-1)*(eta+csi+1)/4;
	this->dNdeta[1] = (csi+1)*(eta-csi+1)/4+(csi+1)*(eta-1)/4;
	this->dNdeta[2] = (csi+1)*(eta+csi-1)/4+(csi+1)*(eta+1)/4;
	this->dNdeta[3] = (1-csi)*(eta-csi-1)/4+(1-csi)*(eta+1)/4;
	this->dNdeta[4] = -(1-csi*csi)/2;
	this->dNdeta[5] = -(csi+1)*eta;
	this->dNdeta[6] = (1-csi*csi)/2;
	this->dNdeta[7] = -(1-csi)*eta;
	
	return this->dNdeta;
}


std::vector<double> & Quadrangle8::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & Quadrangle8::setdNdzeta(const double &, const double &, const double &)
{
	//TODO test this
	// this->dNdzeta
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;
	this->dNdzeta[3] = 0;
	this->dNdzeta[4] = 0;
	this->dNdzeta[5] = 0;
	this->dNdzeta[6] = 0;
	this->dNdzeta[7] = 0;

	return this->dNdzeta;
}


std::vector<fem::Point> & Quadrangle8::setCoordinates()
{
	this->coordinates[0] = Point(	-0.5,	-0.5,	0	);
	this->coordinates[1] = Point(	0.5,	-0.5,	0	);
	this->coordinates[2] = Point(	0.5,	0.5,	0	);
	this->coordinates[3] = Point(	-0.5,	0.5,	0	);
	this->coordinates[4] = Point(	0,	-0.5,	0	);
	this->coordinates[5] = Point(	0.5,	0,	0	);
	this->coordinates[6] = Point(	0,	0.5,	0	);
	this->coordinates[7] = Point(	-0.5,	0,	0	);

	return this->coordinates;
}


void
Quadrangle8::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 8)
	{
		throw FemException("wrong number of nodes");
	}
	this->nodes = nodes;
}


}	// namespace fem

