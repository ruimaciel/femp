#ifndef FEMP_PRISM15_HPP
#define FEMP_PRISM15_HPP

#include <vector>

#include "PrismFamily.h++"
#include "../point.h++"




namespace fem
{

template <typename T>
struct Prism15
	: public PrismFamily<T>
{
	public:
		Prism15();
		~Prism15()	{};

		std::vector<fem::point> & setCoordinates();

		std::vector<T> & setN(const point & p);
		std::vector<T> & setN(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdcsi(const point &p);
		std::vector<T> & setdNdcsi(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdeta(const point &p);
		std::vector<T> & setdNdeta(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdzeta(const point &p);
		std::vector<T> & setdNdzeta(const T &csi, const T &eta, const T &zeta = 0);

public: // merging with fem::Element
	void set(std::vector<size_t> &nodes);

        /** 
        return the number of nodes that an element of this particular type has
        @return the number of nodes
        **/
        int node_number() const	{ return 15; };
};


template<typename T>
Prism15<T>::Prism15()
{
	this->type = BaseElement<T>::FE_PRISM15;
	this->stiffness_degree = 5;
	this->domain_degree = 2;

	this->coordinates.resize(15);

	this->N.resize(15);
	this->dNdcsi.resize(15);
	this->dNdeta.resize(15);
	this->dNdzeta.resize(15);
}


template<typename T>
std::vector<T> & Prism15<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism15<T>::setN(const T &csi, const T &eta, const T &zeta)
{
	//TODO test this

	this->N[0] = -((-1 + csi + eta)*(-1 + zeta)*(2*(csi + eta) + zeta))/2.0;
	this->N[1] =  (csi*(-1 + zeta)*(2 - 2*csi + zeta))/2.0;
	this->N[2] =  (eta*(-1 + zeta)*(2 - 2*eta + zeta))/2.0;
	this->N[3] =  -((-1 + csi + eta)*(1 + zeta)*(-2*(csi + eta) + zeta))/2.0;
	this->N[4] =  (csi*(1 + zeta)*(-2 + 2*csi + zeta))/2.0;
	this->N[5] =  (eta*(1 + zeta)*(-2 + 2*eta + zeta))/2.0;
	this->N[6] =  2*csi*(-1 + csi + eta)*(-1 + zeta);
	this->N[7] = 2*eta*(-1 + csi + eta)*(-1 + zeta);
	this->N[8] =  (-1 + csi + eta)*(-1 + zeta*zeta);
	this->N[9] = -2*csi*eta*(-1 + zeta);
	this->N[10] =  csi - csi*zeta*zeta;
	this->N[11] = eta - eta*zeta*zeta;
	this->N[12] =  -2*csi*(-1 + csi + eta)*(1 + zeta);
	this->N[13] = -2*eta*(-1 + csi + eta)*(1 + zeta);
	this->N[14] =  2*csi*eta*(1 + zeta);
	
	return this->N;
}


template<typename T>
std::vector<T> & Prism15<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism15<T>::setdNdcsi(const T &csi, const T &eta, const T &zeta)
{
	//TODO test this
	// this->dNdcsi

	this->dNdcsi[0] = -(zeta-1)*(zeta+2*(eta+csi))/2-(eta+csi-1)*(zeta-1);
	this->dNdcsi[1] = (zeta-1)*(zeta-2*csi+2)/2-csi*(zeta-1);
	this->dNdcsi[2] = 0;
	this->dNdcsi[3] = (eta+csi-1)*(zeta+1)-(zeta+1)*(zeta-2*(eta+csi))/2;
	this->dNdcsi[4] = (zeta+1)*(zeta+2*csi-2)/2+csi*(zeta+1);
	this->dNdcsi[5] = 0;
	this->dNdcsi[6] =  2*(eta+csi-1)*(zeta-1)+2*csi*(zeta-1);
	this->dNdcsi[7] = 2*eta*(zeta-1);
	this->dNdcsi[8] = zeta*zeta-1;
	this->dNdcsi[9] = -2*eta*(zeta-1);
	this->dNdcsi[10] = 1-zeta*zeta;
	this->dNdcsi[11] = 0;
	this->dNdcsi[12] = -2*(eta+csi-1)*(zeta+1)-2*csi*(zeta+1);
	this->dNdcsi[13] = -2*eta*(zeta+1);
	this->dNdcsi[14] = 2*eta*(zeta+1);

	return this->dNdcsi;
}


template<typename T>
std::vector<T> & Prism15<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism15<T>::setdNdeta(const T &csi, const T &eta, const T &zeta)
{
	//TODO test this
	// this->dNdeta

	this->dNdeta[0] = -(zeta-1)*(zeta+2*(eta+csi))/2-(eta+csi-1)*(zeta-1);
	this->dNdeta[1] = 0;
	this->dNdeta[2] = (zeta-1)*(zeta-2*eta+2)/2-eta*(zeta-1);
	this->dNdeta[3] = (eta+csi-1)*(zeta+1)-(zeta+1)*(zeta-2*(eta+csi))/2;
	this->dNdeta[4] = 0;
	this->dNdeta[5] = (zeta+1)*(zeta+2*eta-2)/2+eta*(zeta+1);
	this->dNdeta[6] =  2*csi*(zeta-1);
	this->dNdeta[7] = 2*(eta+csi-1)*(zeta-1)+2*eta*(zeta-1);
	this->dNdeta[8] = zeta*zeta-1;
	this->dNdeta[9] = -2*csi*(zeta-1);
	this->dNdeta[10] = 0;
	this->dNdeta[11] = 1-zeta*zeta;
	this->dNdeta[12] = -2*csi*(zeta+1);
	this->dNdeta[13] = -2*(eta+csi-1)*(zeta+1)-2*eta*(zeta+1);
	this->dNdeta[14] = 2*csi*(zeta+1);
	
	return this->dNdeta;
}


template<typename T>
std::vector<T> & Prism15<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism15<T>::setdNdzeta(const T &csi, const T &eta, const T &zeta)
{
	//TODO test this
	// this->dNdzeta

	this->dNdzeta[0] = -(eta+csi-1)*(zeta+2*(eta+csi))/2-(eta+csi-1)*(zeta-1)/2;
	this->dNdzeta[1] = csi*(zeta-2*csi+2)/2+csi*(zeta-1)/2;
	this->dNdzeta[2] = eta*(zeta-2*eta+2)/2+eta*(zeta-1)/2;
	this->dNdzeta[3] = -(eta+csi-1)*(zeta-2*(eta+csi))/2-(eta+csi-1)*(zeta+1)/2;
	this->dNdzeta[4] =  csi*(zeta+2*csi-2)/2+csi*(zeta+1)/2;
	this->dNdzeta[5] = eta*(zeta+2*eta-2)/2+eta*(zeta+1)/2;
	this->dNdzeta[6] = 2*csi*(eta+csi-1);
	this->dNdzeta[7] = 2*eta*(eta+csi-1);
	this->dNdzeta[8] = 2*(eta+csi-1)*zeta;
	this->dNdzeta[9] = -2*csi*eta;
	this->dNdzeta[10] = -2*csi*zeta;
	this->dNdzeta[11] = -2*eta*zeta;
	this->dNdzeta[12] = -2*csi*(eta+csi-1);
	this->dNdzeta[13] =  -2*eta*(eta+csi-1);
	this->dNdzeta[14] = 2*csi*eta;

	return this->dNdzeta;
}

template<typename T>
std::vector<fem::point> & Prism15<T>::setCoordinates()
{
	this->coordinates[0] = point(	0,	0,	-1	);
	this->coordinates[1] = point(	1,	0,	-1	);
	this->coordinates[2] = point(	0,	1,	-1	);
	this->coordinates[3] = point(	0,	0,	1	);
	this->coordinates[4] = point(	1,	0,	1	);
	this->coordinates[5] = point(	0,	1,	1	);

	this->coordinates[6] = point(	0.5,	0,	-1	);
	this->coordinates[7] = point(	0,	0.5,	-1	);
	this->coordinates[8] = point(	0,	0,	0	);
	this->coordinates[9] = point(	0.5,	0.5,	-1	);
	this->coordinates[10] = point(	1,	0,	0	);
	this->coordinates[11] = point(	0,	1,	0	);
	this->coordinates[12] = point(	0.5,	0,	1	);
	this->coordinates[13] = point(	0,	0.5,	1	);
	this->coordinates[14] = point(	0.5,	0.5,	1	);

	return this->coordinates;
}


template<typename T>
void
Prism15<T>::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 15)
	{
		throw FemException("wrong number of nodes");
	}
	this->nodes = nodes;
}

}

#endif
