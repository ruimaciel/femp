#include "Quadrangle8.h++"


#include <libfemp/FemException.h++>


namespace fem
{


Quadrangle8::Quadrangle8()
{
	this->stiffness_degree = 2;
	this->domain_degree = 2;

	this->coordinates.resize(8);
}


std::vector<double>
Quadrangle8::getN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();

	std::vector<double> N(this->getNodeAmount());

	N[0] = (csi-1)*(1-eta)*(eta+csi+1)/4;
	N[1] = (csi+1)*(eta-1)*(eta-csi+1)/4;
	N[2] = (csi+1)*(eta+1)*(eta+csi-1)/4;
	N[3] = (1-csi)*(eta+1)*(eta-csi-1)/4;
	N[4] = (1-csi*csi)*(1-eta)/2;
	N[5] = (csi+1)*(1-eta*eta)/2;
	N[6] = (1-csi*csi)*(eta+1)/2;
	N[7] = (1-csi)*(1-eta*eta)/2;
	
	return N;
}


std::vector<double>
Quadrangle8::getdNdcsi(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = (1-eta)*(eta+csi+1)/4+(csi-1)*(1-eta)/4;
	dNdcsi[1] = (eta-1)*(eta-csi+1)/4-(csi+1)*(eta-1)/4;
	dNdcsi[2] = (eta+1)*(eta+csi-1)/4+(csi+1)*(eta+1)/4;
	dNdcsi[3] = -(eta+1)*(eta-csi-1)/4-(1-csi)*(eta+1)/4;
	dNdcsi[4] = -csi*(1-eta);
	dNdcsi[5] = (1-eta*eta)/2;
	dNdcsi[6] = -csi*(eta+1);
	dNdcsi[7] = -(1-eta*eta)/2;

	return dNdcsi;
}


std::vector<double>
Quadrangle8::getdNdeta(const Point &p)
{
	double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = (csi-1)*(1-eta)/4-(csi-1)*(eta+csi+1)/4;
	dNdeta[1] = (csi+1)*(eta-csi+1)/4+(csi+1)*(eta-1)/4;
	dNdeta[2] = (csi+1)*(eta+csi-1)/4+(csi+1)*(eta+1)/4;
	dNdeta[3] = (1-csi)*(eta-csi-1)/4+(1-csi)*(eta+1)/4;
	dNdeta[4] = -(1-csi*csi)/2;
	dNdeta[5] = -(csi+1)*eta;
	dNdeta[6] = (1-csi*csi)/2;
	dNdeta[7] = -(1-csi)*eta;
	
	return dNdeta;
}


std::vector<double>
Quadrangle8::getdNdzeta(const Point &)
{
	std::vector<double> dNdzeta(this->getNodeAmount());

	dNdzeta[0] = 0;
	dNdzeta[1] = 0;
	dNdzeta[2] = 0;
	dNdzeta[3] = 0;
	dNdzeta[4] = 0;
	dNdzeta[5] = 0;
	dNdzeta[6] = 0;
	dNdzeta[7] = 0;

	return dNdzeta;
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


}	// namespace fem

