#include "Tetrahedron4.h++"


#include <libfemp/FemException.h++>


namespace fem
{


Tetrahedron4::Tetrahedron4()
	: TetrahedronFamily()
{
	this->type = BaseElement::FE_TETRAHEDRON4;
	this->stiffness_degree = 1;
	this->domain_degree = 1;

	this->coordinates.resize(4);
}


std::vector<double>
Tetrahedron4::getN(const Point &p)
{
	const double csi = p.x();
	const double eta = p.y();
	const double zeta = p.z();

	std::vector<double> N(this->getNodeAmount());

	N[0] = 1.0-zeta-eta-csi;
	N[1] = csi;
	N[2] = eta;
	N[3] = zeta;
	
	return N;
}


std::vector<double>
Tetrahedron4::getdNdcsi(const Point &)
{
	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = -1.0;
	dNdcsi[1] = 1;
	dNdcsi[2] = 0;
	dNdcsi[3] = 0;

	return dNdcsi;
}


std::vector<double>
Tetrahedron4::getdNdeta(const Point &)
{
	std::vector<double> dNdeta(this->getNodeAmount());
	
	dNdeta[0] = -1.0;
	dNdeta[1] = 0;
	dNdeta[2] = 1;
	dNdeta[3] = 0;
	
	return dNdeta;
}


std::vector<double>
Tetrahedron4::getdNdzeta(const Point &)
{
	std::vector<double> dNdzeta(this->getNodeAmount());

	dNdzeta[0] = -1.0;
	dNdzeta[1] = 0;
	dNdzeta[2] = 0;
	dNdzeta[3] = 1;

	return dNdzeta;
}


std::vector<fem::Point> & Tetrahedron4::setCoordinates()
{
	this->coordinates[0] = Point(	0,	0,	0	);
	this->coordinates[1] = Point(	1,	0,	0	);
	this->coordinates[2] = Point(	0,	1,	0	);
	this->coordinates[3] = Point(	0,	0,	1	);

	return this->coordinates;
}


}	// namespace fem

