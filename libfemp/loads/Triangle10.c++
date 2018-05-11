#include "Triangle10.h++"


#include <memory>

#include <libfemp/quadrature_rules/Tetrahedron.h++>
#include <libfemp/FemException.h++>


namespace fem
{


Triangle10::Triangle10()
{
	this->stiffness_degree = 1;
	this->domain_degree = 1;

	this->coordinates.resize(10);


	// specify new quadrature rule
	using namespace quadrature;
	m_stiffness_quadrature_rule = std::unique_ptr<quadrature::Triangle6>( new quadrature::Triangle6() );

	m_domain_quadrature_rule = std::unique_ptr<quadrature::Triangle6>( new quadrature::Triangle6() );

}


std::vector<double>
Triangle10::getN(const Point3D &p)
{
	const double csi = p.x();
	const double eta = p.y();

	std::vector<double> N(this->getNodeAmount());

	N[0] = 4.5*(-eta-csi+1.0/3)*(-eta-csi+2.0/3)*(-eta-csi+1);
	N[1] = 4.5*(csi-2.0/3)*(csi-1.0/3)*csi;
	N[2] = 4.5*(eta-2.0/3)*(eta-1.0/3)*eta;
	N[3] = 13.5*csi*(-eta-csi+2.0/3)*(-eta-csi+1);
	N[4] = 13.5*(csi-1.0/3)*csi*(-eta-csi+1);
	N[5] = 13.5*(csi-1.0/3)*csi*eta;
	N[6] = 13.5*csi*(eta-1.0/3)*eta;
	N[7] = 13.5*(-eta-csi+1)*(eta-1.0/3)*eta;
	N[8] = 13.5*(-eta-csi+2.0/3)*(-eta-csi+1)*eta;
	N[9] = 27*csi*(-eta-csi+1)*eta;

	return N;
}


std::vector<double>
Triangle10::getdNdcsi(const Point3D &p)
{
	double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdcsi(this->getNodeAmount());

	dNdcsi[0] = -(27*eta*eta+(54*csi-36)*eta+27*csi*csi-36*csi+11)/2.0;
	dNdcsi[1] = (27*csi*csi-18*csi+2)/2.0;
	dNdcsi[2] = 0;
	dNdcsi[3] = (27*eta*eta+(108*csi-45)*eta+81*csi*csi-90*csi+18)/2.0;
	dNdcsi[4] = -((54*csi-9)*eta+81*csi*csi-72*csi+9)/2.0;
	dNdcsi[5] = (54*csi-9)*eta/2.0;
	dNdcsi[6] = (27*eta*eta-9*eta)/2.0;
	dNdcsi[7] = -(27*eta*eta-9*eta)/2.0;
	dNdcsi[8] = (54*eta*eta+(54*csi-45)*eta)/2.0;
	dNdcsi[9] = (27-54*csi)*eta-27*eta*eta;

	return dNdcsi;
}


std::vector<double>
Triangle10::getdNdeta(const Point3D &p)
{
	double csi = p.x();
	double eta = p.y();

	std::vector<double> dNdeta(this->getNodeAmount());

	dNdeta[0] = -(27*eta*eta+(54*csi-36)*eta+27*csi*csi-36*csi+11)/2.0;
	dNdeta[1] = 0;
	dNdeta[2] = (27*eta*eta-18*eta+2)/2.0;
	dNdeta[3] = (54*csi*eta+54*csi*csi-45*csi)/2.0;
	dNdeta[4] = -(27*csi*csi-9*csi)/2.0;
	dNdeta[5] = (27*csi*csi-9*csi)/2.0;
	dNdeta[6] = (54*csi*eta-9*csi)/2.0;
	dNdeta[7] = -(81*eta*eta+(54*csi-72)*eta-9*csi+9)/2.0;
	dNdeta[8] = (81*eta*eta+(108*csi-90)*eta+27*csi*csi-45*csi+18)/2.0;
	dNdeta[9] = -54*csi*eta-27*csi*csi+27*csi;

	return dNdeta;
}


std::vector<double>
Triangle10::getdNdzeta(const Point3D &)
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
	dNdzeta[8] = 0;
	dNdzeta[9] = 0;

	return dNdzeta;
}


std::vector<fem::Point3D>
Triangle10::getLocalCoordinates()
{
	this->coordinates[0] = Point3D(	0,	0,	0	);
	this->coordinates[1] = Point3D(	1,	0,	0	);
	this->coordinates[2] = Point3D(	0,	1,	0	);
	this->coordinates[3] = Point3D(	0.5,	0,	0	);
	this->coordinates[4] = Point3D(	0.5,	0.5,	0	);
	this->coordinates[5] = Point3D(	0,	0.5,	0	);

	return this->coordinates;
}


}	// namespace fem

