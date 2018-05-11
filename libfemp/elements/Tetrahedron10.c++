#include "Tetrahedron10.h++"

#include <memory>

#include <libfemp/quadrature_rules/Tetrahedron.h++>
#include <libfemp/FemException.h++>


namespace fem
{


Tetrahedron10::Tetrahedron10()
	: TetrahedronFamily()
{
	this->type = BaseElement::FE_TETRAHEDRON10;
	this->stiffness_degree = 2;
	this->domain_degree = 2;

	this->coordinates.resize(10);


	// specify new quadrature rule
	using namespace quadrature;
	m_stiffness_quadrature_rule = std::unique_ptr<Tetrahedron4>( new Tetrahedron4() );

	m_domain_quadrature_rule = std::unique_ptr<Tetrahedron14>( new Tetrahedron14() );

}


std::vector<double>
Tetrahedron10::getN(const Point3D &p)
{
	const double csi = p.x();
	const double eta = p.y();
	const double zeta = p.z();

	std::vector<double> N(this->getNodeAmount());

	N[0] = 2*(-zeta-eta-csi+0.5)*(-zeta-eta-csi+1);
	N[1] = 2*(csi-0.5)*csi;
	N[2] = 2*(eta-0.5)*eta;
	N[3] = 2*(zeta-0.5)*zeta;
	N[4] = 4*csi*(-zeta-eta-csi+1);
	N[5] = 4*csi*eta;
	N[6] = 4*eta*(-zeta-eta-csi+1);
	N[7] = 4*(-zeta-eta-csi+1)*zeta;
	N[8] = 4*eta*zeta;
	N[9] = 4*csi*zeta;

	return N;
}


std::vector<double>
Tetrahedron10::getdNdcsi(const Point3D &p)
{
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = -2*(-zeta-eta-csi+1)-2*(-zeta-eta-csi+0.5);
	dNdcsi[1] = 2*csi+2*(csi-0.5);
	dNdcsi[2] = 0;
	dNdcsi[3] = 0;
	dNdcsi[4] = 4*(-zeta-eta-csi+1)-4*csi;
	dNdcsi[5] = 4*eta;
	dNdcsi[6] = -4*eta;
	dNdcsi[7] = -4*zeta;
	dNdcsi[8] = 0;
	dNdcsi[9] = 4*zeta;

	return dNdcsi;
}


std::vector<double>
Tetrahedron10::getdNdeta(const Point3D &p)
{
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = -2*(-zeta-eta-csi+1)-2*(-zeta-eta-csi+0.5);
	dNdeta[1] = 0;
	dNdeta[2] = 2*eta+2*(eta-0.5);
	dNdeta[3] = 0;
	dNdeta[4] = -4*csi;
	dNdeta[5] = 4*csi;
	dNdeta[6] = 4*(-zeta-eta-csi+1)-4*eta;
	dNdeta[7] = -4*zeta;
	dNdeta[8] = 4*zeta;
	dNdeta[9] = 0;

	return dNdeta;
}


std::vector<double>
Tetrahedron10::getdNdzeta(const Point3D &p)
{
	double csi = p.x();
	double eta = p.y();
	double zeta = p.z();

	std::vector<double> dNdzeta(this->getNodeAmount());

	dNdzeta[0] = -2*(-zeta-eta-csi+1)-2*(-zeta-eta-csi+0.5);
	dNdzeta[1] = 0;
	dNdzeta[2] = 0;
	dNdzeta[3] = 2*zeta+2*(zeta-0.5);
	dNdzeta[4] = -4*csi;
	dNdzeta[5] = 0;
	dNdzeta[6] = -4*eta;
	dNdzeta[7] = 4*(-zeta-eta-csi+1)-4*zeta;
	dNdzeta[8] = 4*eta;
	dNdzeta[9] = 4*csi;

	return dNdzeta;
}


std::vector<fem::Point3D>
Tetrahedron10::getLocalCoordinates()
{
	this->coordinates[0] = Point3D(	0,	0,	0	);
	this->coordinates[1] = Point3D(	1,	0,	0	);
	this->coordinates[2] = Point3D(	0,	1,	0	);
	this->coordinates[3] = Point3D(	0,	0,	1	);

	this->coordinates[4] = Point3D(	0.5,	0,	0	);
	this->coordinates[5] = Point3D(	0.5,	0.5,	0	);
	this->coordinates[6] = Point3D(	0,	0.5,	0	);
	this->coordinates[7] = Point3D(	0,	0,	0.5	);
	this->coordinates[8] = Point3D(	0,	0.5,	0.5	);
	this->coordinates[9] = Point3D(	0.5,	0.5,	0.5	);

	return this->coordinates;
}


}	// namespace fem

