#include "Triangle3.h++"


#include <libfemp/FemException.h++>


namespace fem
{


Triangle3::Triangle3()
{
	this->stiffness_degree = 1;
	this->domain_degree = 1;

	this->coordinates.resize(3);

	this->N.resize(3);
	this->dNdcsi.resize(3);
	this->dNdeta.resize(3);
	this->dNdzeta.resize(3);
}


std::vector<double> & 
Triangle3::setN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();

	this->N[0] = 1-csi-eta;
	this->N[1] = csi;
	this->N[2] = eta;
	
	return this->N;
}


std::vector<double> & 
Triangle3::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & 
Triangle3::setdNdcsi(const double &, const double &, const double &)
{
	// this->dNdcsi
	this->dNdcsi[0] = -1;
	this->dNdcsi[1] = 1;
	this->dNdcsi[2] = 0;

	return this->dNdcsi;
}


std::vector<double> & 
Triangle3::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & 
Triangle3::setdNdeta(const double &, const double &, const double &)
{
	// this->dNdeta
	this->dNdeta[0] = -1;
	this->dNdeta[1] = 0;
	this->dNdeta[2] = 1;
	
	return this->dNdeta;
}


std::vector<double> & 
Triangle3::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & 
Triangle3::setdNdzeta(const double &, const double &, const double &)
{
	// this->dNdzeta
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;

	return this->dNdzeta;
}


std::vector<fem::Point> & 
Triangle3::setCoordinates()
{
	this->coordinates[0] = Point(	0,	0,	0	);
	this->coordinates[1] = Point(	1,	0,	0	);
	this->coordinates[2] = Point(	0,	1,	0	);

	return this->coordinates;
}


void
Triangle3::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 3)
	{
		throw FemException("wrong number of nodes");
	}

	this->nodes = nodes;
}


}	// namespace fem

