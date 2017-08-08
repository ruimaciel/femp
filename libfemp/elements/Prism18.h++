#ifndef FEMP_PRISM18_HPP
#define FEMP_PRISM18_HPP

#include <vector>

#include "PrismFamily.h++"
#include "../Point.h++"




namespace fem
{

template <typename Scalar>
struct Prism18
	: public PrismFamily<Scalar>
{
public:
	Prism18();
	~Prism18()	{};

	std::vector<fem::Point> & setCoordinates();

	std::vector<Scalar> & setN(const Point & p);
	std::vector<Scalar> & setN(const Scalar &csi, const Scalar &eta, const Scalar &zeta = 0);

	std::vector<Scalar> & setdNdcsi(const Point &p);
	std::vector<Scalar> & setdNdcsi(const Scalar &csi, const Scalar &eta, const Scalar &zeta = 0);

	std::vector<Scalar> & setdNdeta(const Point &p);
	std::vector<Scalar> & setdNdeta(const Scalar &csi, const Scalar &eta, const Scalar &zeta = 0);

	std::vector<Scalar> & setdNdzeta(const Point &p);
	std::vector<Scalar> & setdNdzeta(const Scalar &csi, const Scalar &eta, const Scalar &zeta = 0);

public: // merging with fem::Element
        void set(std::vector<size_t> &nodes);

        /** 
        return the number of nodes that an element of this particular type has
        @return the number of nodes
        **/
        int node_number() const	{ return 18; };
};


template<typename Scalar>
Prism18<Scalar>::Prism18()
{
	this->type = BaseElement<Scalar>::FE_PRISM18;
	this->stiffness_degree = 5;
	this->domain_degree = 2;

	this->coordinates.resize(18);

	this->N.resize(18);
	this->dNdcsi.resize(18);
	this->dNdeta.resize(18);
	this->dNdzeta.resize(18);
}


template<typename Scalar>
std::vector<Scalar> & Prism18<Scalar>::setN(const Point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Prism18<Scalar>::setN(const Scalar &csi, const Scalar &eta, const Scalar &zeta)
{
	this->N[0] = ((-1 + csi + eta)*(-1 + 2*csi + 2*eta)*(-1 + zeta)* zeta)/2.;
	this->N[1] = (csi*(-1 + 2*csi)*(-1 + zeta)*zeta)/2.;
	this->N[2] =  (eta*(-1 + 2*eta)*(-1 + zeta)*zeta)/2.;
	this->N[3] =  ((-1 + csi + eta)*(-1 + 2*csi + 2*eta)*zeta*(1 + zeta))/2.;
	this->N[4] =  (csi*(-1 + 2*csi)*zeta*(1 + zeta))/2.;
	this->N[5] =  (eta*(-1 + 2*eta)*zeta*(1 + zeta))/2.;
	this->N[6] =  -2*csi*(-1 + csi + eta)*(-1 + zeta)*zeta;
	this->N[7] =  -2*eta*(-1 + csi + eta)*(-1 + zeta)*zeta;
	this->N[8] =  -((-1 + csi + eta)*(-1 + 2*csi + 2*eta)*(-1 + zeta*zeta));
	this->N[9] =  2*csi*eta*(-1 + zeta)*zeta;
	this->N[10] =  -(csi*(-1 + 2*csi)*(-1 + zeta*zeta));
	this->N[11] =  -(eta*(-1 + 2*eta)*(-1 + zeta*zeta));
	this->N[12] =  -2*csi*(-1 + csi + eta)*zeta*(1 + zeta);
	this->N[13] =  -2*eta*(-1 + csi + eta)*zeta*(1 + zeta);
	this->N[14] =  2*csi*eta*zeta*(1 + zeta);
	this->N[15] =  4*csi*(-1 + csi + eta)*(-1 + zeta*zeta);
	this->N[16] =  4*eta*(-1 + csi + eta)*(-1 + zeta*zeta);
	this->N[17] =  -4*csi*eta*(-1 + zeta*zeta);
	
	return this->N;
}


template<typename Scalar>
std::vector<Scalar> & Prism18<Scalar>::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Prism18<Scalar>::setdNdcsi(const Scalar &csi, const Scalar &eta, const Scalar &zeta)
{
	//TODO test this
	// this->dNdcsi

	this->dNdcsi[0] = (2*eta+2*csi-1)*(zeta-1)*zeta/2+(eta+csi-1)*(zeta-1)*zeta;
	this->dNdcsi[1] = (2*csi-1)*(zeta-1)*zeta/2+csi*(zeta-1)*zeta;
	this->dNdcsi[2] = 0;
	this->dNdcsi[3] = (2*eta+2*csi-1)*zeta*(zeta+1)/2+(eta+csi-1)*zeta*(zeta+1);
	this->dNdcsi[4] =  (2*csi-1)*zeta*(zeta+1)/2+csi*zeta*(zeta+1);
	this->dNdcsi[5] = 0;
	this->dNdcsi[6] = -2*(eta+csi-1)*(zeta-1)*zeta-2*csi*(zeta-1)*zeta;
	this->dNdcsi[7] = -2*eta*(zeta-1)*zeta;
	this->dNdcsi[8] = -(2*eta+2*csi-1)*(zeta*zeta-1)-2*(eta+csi-1)*(zeta*zeta-1);
	this->dNdcsi[9] = 2*eta*(zeta-1)*zeta;
	this->dNdcsi[10] =  -(2*csi-1)*(zeta*zeta-1)-2*csi*(zeta*zeta-1);
	this->dNdcsi[11] = 0;
	this->dNdcsi[12] = -2*(eta+csi-1)*zeta*(zeta+1)-2*csi*zeta*(zeta+1);
	this->dNdcsi[13] = -2*eta*zeta*(zeta+1);
	this->dNdcsi[14] = 2*eta*zeta*(zeta+1);
	this->dNdcsi[15] = 4*(eta+csi-1)*(zeta*zeta-1)+4*csi*(zeta*zeta-1);
	this->dNdcsi[16] = 4*eta*(zeta*zeta-1);
	this->dNdcsi[17] = -4*eta*(zeta*zeta-1);


	return this->dNdcsi;
}


template<typename Scalar>
std::vector<Scalar> & Prism18<Scalar>::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Prism18<Scalar>::setdNdeta(const Scalar &csi, const Scalar &eta, const Scalar &zeta)
{
	//TODO test this
	// this->dNdeta

	this->dNdeta[0] = (2*eta+2*csi-1)*(zeta-1)*zeta/2+(eta+csi-1)*(zeta-1)*zeta;
	this->dNdeta[1] = 0;
	this->dNdeta[2] = (2*eta-1)*(zeta-1)*zeta/2+eta*(zeta-1)*zeta;
	this->dNdeta[3] = (2*eta+2*csi-1)*zeta*(zeta+1)/2+(eta+csi-1)*zeta*(zeta+1);
	this->dNdeta[4] = 0;
	this->dNdeta[5] =  (2*eta-1)*zeta*(zeta+1)/2+eta*zeta*(zeta+1);
	this->dNdeta[6] = -2*csi*(zeta-1)*zeta;
	this->dNdeta[7] = -2*(eta+csi-1)*(zeta-1)*zeta-2*eta*(zeta-1)*zeta;
	this->dNdeta[8] = -(2*eta+2*csi-1)*(zeta*zeta-1)-2*(eta+csi-1)*(zeta*zeta-1);
	this->dNdeta[9] = 2*csi*(zeta-1)*zeta;
	this->dNdeta[10] = 0;
	this->dNdeta[11] =  -(2*eta-1)*(zeta*zeta-1)-2*eta*(zeta*zeta-1);
	this->dNdeta[12] = -2*csi*zeta*(zeta+1);
	this->dNdeta[13] = -2*(eta+csi-1)*zeta*(zeta+1)-2*eta*zeta*(zeta+1);
	this->dNdeta[14] = 2*csi*zeta*(zeta+1);
	this->dNdeta[15] = 4*csi*(zeta*zeta-1);
	this->dNdeta[16] = 4*(eta+csi-1)*(zeta*zeta-1)+4*eta*(zeta*zeta-1);
	this->dNdeta[17] =  -4*csi*(zeta*zeta-1);
	
	return this->dNdeta;
}


template<typename Scalar>
std::vector<Scalar> & Prism18<Scalar>::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Prism18<Scalar>::setdNdzeta(const Scalar &csi, const Scalar &eta, const Scalar &zeta)
{
	//TODO test this

	this->dNdzeta[0] = (eta+csi-1)*(2*eta+2*csi-1)*zeta/2+(eta+csi-1)*(2*eta+2*csi-1)*(zeta-1)/2;
	this->dNdzeta[1] = csi*(2*csi-1)*zeta/2+csi*(2*csi-1)*(zeta-1)/2;
	this->dNdzeta[2] = eta*(2*eta-1)*zeta/2+eta*(2*eta-1)*(zeta-1)/2;
	this->dNdzeta[3] =  (eta+csi-1)*(2*eta+2*csi-1)*(zeta+1)/2+(eta+csi-1)*(2*eta+2*csi-1)*zeta/2;
	this->dNdzeta[4] = csi*(2*csi-1)*(zeta+1)/2+csi*(2*csi-1)*zeta/2;
	this->dNdzeta[5] = eta*(2*eta-1)*(zeta+1)/2+eta*(2*eta-1)*zeta/2;
	this->dNdzeta[6] =  -2*csi*(eta+csi-1)*zeta-2*csi*(eta+csi-1)*(zeta-1);
	this->dNdzeta[7] = -2*eta*(eta+csi-1)*zeta-2*eta*(eta+csi-1)*(zeta-1);
	this->dNdzeta[8] = -2*(eta+csi-1)*(2*eta+2*csi-1)*zeta;
	this->dNdzeta[9] = 2*csi*eta*zeta+2*csi*eta*(zeta-1);
	this->dNdzeta[10] = -2*csi*(2*csi-1)*zeta;
	this->dNdzeta[11] =  -2*eta*(2*eta-1)*zeta;
	this->dNdzeta[12] = -2*csi*(eta+csi-1)*(zeta+1)-2*csi*(eta+csi-1)*zeta;
	this->dNdzeta[13] = -2*eta*(eta+csi-1)*(zeta+1)-2*eta*(eta+csi-1)*zeta;
	this->dNdzeta[14] = 2*csi*eta*(zeta+1)+2*csi*eta*zeta;
	this->dNdzeta[15] = 8*csi*(eta+csi-1)*zeta;
	this->dNdzeta[16] =  8*eta*(eta+csi-1)*zeta;
	this->dNdzeta[17] = -8*csi*eta*zeta;

	return this->dNdzeta;
}

template<typename Scalar>
std::vector<fem::Point> & Prism18<Scalar>::setCoordinates()
{
	this->coordinates[0] = Point(	0,	0,	-1	);
	this->coordinates[1] = Point(	1,	0,	-1	);
	this->coordinates[2] = Point(	0,	1,	-1	);
	this->coordinates[3] = Point(	0,	0,	1	);
	this->coordinates[4] = Point(	1,	0,	1	);
	this->coordinates[5] = Point(	0,	1,	1	);

	this->coordinates[6] = Point(	0.5,	0,	-1	);
	this->coordinates[7] = Point(	0,	0.5,	-1	);
	this->coordinates[8] = Point(	0,	0,	0	);
	this->coordinates[9] = Point(	0.5,	0.5,	-1	);
	this->coordinates[10] = Point(	1,	0,	0	);
	this->coordinates[11] = Point(	0,	1,	0	);
	this->coordinates[12] = Point(	0.5,	0,	1	);
	this->coordinates[13] = Point(	0,	0.5,	1	);
	this->coordinates[14] = Point(	0.5,	0.5,	1	);

	this->coordinates[15] = Point(	0.5,	0,	0	);
	this->coordinates[16] = Point(	0,	0.5,	0	);
	this->coordinates[17] = Point(	0.5,	0.5,	0	);

	return this->coordinates;
}


template<typename Scalar>
void
Prism18<Scalar>::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 18)
	{
		throw FemException("wrong number of nodes");
	}
	this->nodes = nodes;
}


}


#endif
