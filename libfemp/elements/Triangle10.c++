#include "Triangle10.h++"


#include <libfemp/FemException.h++>


namespace fem
{


Triangle10::Triangle10()
{
	this->stiffness_degree = 1;
	this->domain_degree = 1;

	this->coordinates.resize(10);

	this->N.resize(10);
	this->dNdcsi.resize(10);
	this->dNdeta.resize(10);
	this->dNdzeta.resize(10);
}


std::vector<double> & 
Triangle10::setN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();

	this->N[0] = 4.5*(-eta-csi+1.0/3)*(-eta-csi+2.0/3)*(-eta-csi+1);
	this->N[1] = 4.5*(csi-2.0/3)*(csi-1.0/3)*csi;
	this->N[2] = 4.5*(eta-2.0/3)*(eta-1.0/3)*eta;
	this->N[3] = 13.5*csi*(-eta-csi+2.0/3)*(-eta-csi+1);
	this->N[4] = 13.5*(csi-1.0/3)*csi*(-eta-csi+1);
	this->N[5] = 13.5*(csi-1.0/3)*csi*eta;
	this->N[6] = 13.5*csi*(eta-1.0/3)*eta;
	this->N[7] = 13.5*(-eta-csi+1)*(eta-1.0/3)*eta;
	this->N[8] = 13.5*(-eta-csi+2.0/3)*(-eta-csi+1)*eta;
	this->N[9] = 27*csi*(-eta-csi+1)*eta;

	return this->N;
}


std::vector<double> & 
Triangle10::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & 
Triangle10::setdNdcsi(const double &csi, const double &eta, const double &)
{
	//TODO test this
	// this->dNdcsi
	this->N[0] = -(27*eta*eta+(54*csi-36)*eta+27*csi*csi-36*csi+11)/2.0;
	this->N[1] = (27*csi*csi-18*csi+2)/2.0;
	this->N[2] = 0;
	this->N[3] = (27*eta*eta+(108*csi-45)*eta+81*csi*csi-90*csi+18)/2.0;
	this->N[4] = -((54*csi-9)*eta+81*csi*csi-72*csi+9)/2.0;
	this->N[5] = (54*csi-9)*eta/2.0;
	this->N[6] = (27*eta*eta-9*eta)/2.0;
	this->N[7] = -(27*eta*eta-9*eta)/2.0;
	this->N[8] = (54*eta*eta+(54*csi-45)*eta)/2.0;
	this->N[9] = (27-54*csi)*eta-27*eta*eta;

	return this->dNdcsi;
}


std::vector<double> & 
Triangle10::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & 
Triangle10::setdNdeta(const double &csi, const double &eta, const double &)
{
	//TODO test this
	// this->dNdeta
	this->N[0] = -(27*eta*eta+(54*csi-36)*eta+27*csi*csi-36*csi+11)/2.0;
	this->N[1] = 0;
	this->N[2] = (27*eta*eta-18*eta+2)/2.0;
	this->N[3] = (54*csi*eta+54*csi*csi-45*csi)/2.0;
	this->N[4] = -(27*csi*csi-9*csi)/2.0;
	this->N[5] = (27*csi*csi-9*csi)/2.0;
	this->N[6] = (54*csi*eta-9*csi)/2.0;
	this->N[7] = -(81*eta*eta+(54*csi-72)*eta-9*csi+9)/2.0;
	this->N[8] = (81*eta*eta+(108*csi-90)*eta+27*csi*csi-45*csi+18)/2.0;
	this->N[9] = -54*csi*eta-27*csi*csi+27*csi;

	return this->dNdeta;
}


std::vector<double> & 
Triangle10::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


std::vector<double> & 
Triangle10::setdNdzeta(const double &, const double &, const double &)
{
	//TODO finish this
	// this->dNdzeta
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;
	this->dNdzeta[3] = 0;
	this->dNdzeta[4] = 0;
	this->dNdzeta[5] = 0;
	this->dNdzeta[6] = 0;
	this->dNdzeta[7] = 0;
	this->dNdzeta[8] = 0;
	this->dNdzeta[9] = 0;

	return this->dNdzeta;
}


std::vector<fem::Point> & 
Triangle10::setCoordinates()
{
	this->coordinates[0] = Point(	0,	0,	0	);
	this->coordinates[1] = Point(	1,	0,	0	);
	this->coordinates[2] = Point(	0,	1,	0	);
	this->coordinates[3] = Point(	0.5,	0,	0	);
	this->coordinates[4] = Point(	0.5,	0.5,	0	);
	this->coordinates[5] = Point(	0,	0.5,	0	);

	return this->coordinates;
}


void
Triangle10::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 10)
	{
		throw FemException("wrong number of nodes");
	}

	this->nodes = nodes;
}


}	// namespace fem
