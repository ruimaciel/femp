#ifndef TETRAHEDRON10_HPP
#define TETRAHEDRON10_HPP

#include <vector>
#include <boost/tuple/tuple.hpp>

#include "TetrahedronFamily.h++"
#include "../point.h++"




namespace fem
{

template <typename T>
struct Tetrahedron10
	: public TetrahedronFamily<T>
{
	public:
		Tetrahedron10();
		~Tetrahedron10()	{};

		std::vector<fem::point> & setCoordinates();

		std::vector<T> & setN(const point & p);
		std::vector<T> & setN(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdcsi(const point &p);
		std::vector<T> & setdNdcsi(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdeta(const point &p);
		std::vector<T> & setdNdeta(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdzeta(const point &p);
		std::vector<T> & setdNdzeta(const T &csi, const T &eta, const T &zeta = 0);

};


template<typename T>
Tetrahedron10<T>::Tetrahedron10()
{
	this->stiffness_degree = 2;
	this->domain_degree = 2;

	this->coordinates.resize(10);
	this->N.resize(10);
	this->dNdcsi.resize(10);
	this->dNdeta.resize(10);
	this->dNdzeta.resize(10);
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setN(const T &csi, const T &eta, const T &zeta)
{
	//TODO finish this
	this->N[0] = 2*(-zeta-eta-csi+0.5)*(-zeta-eta-csi+1);
	this->N[1] = 2*(csi-0.5)*csi;
	this->N[2] = 2*(eta-0.5)*eta;
	this->N[3] = 2*(zeta-0.5)*zeta;
	this->N[4] = 4*csi*(-zeta-eta-csi+1);
	this->N[5] = 4*csi*eta;
	this->N[6] = 4*eta*(-zeta-eta-csi+1);
	this->N[7] = 4*(-zeta-eta-csi+1)*zeta;
	this->N[8] = 4*eta*zeta;
	this->N[9] = 4*csi*zeta;
	
	return this->N;
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdcsi(const T &csi, const T &eta, const T &zeta)
{
	//TODO finish this
	// this->dNdcsi
	this->dNdcsi[0] = -2*(-zeta-eta-csi+1)-2*(-zeta-eta-csi+0.5);
	this->dNdcsi[1] = 2*csi+2*(csi-0.5);
	this->dNdcsi[2] = 0;
	this->dNdcsi[3] = 0;
	this->dNdcsi[4] = 4*(-zeta-eta-csi+1)-4*csi;
	this->dNdcsi[5] = 4*eta;
	this->dNdcsi[6] = -4*eta;
	this->dNdcsi[7] = -4*zeta;
	this->dNdcsi[8] = 0;
	this->dNdcsi[9] = 4*zeta;

	return this->dNdcsi;
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdeta(const T &csi, const T &eta, const T &zeta)
{
	//TODO test this
	// this->dNdeta
	this->dNdeta[0] = -2*(-zeta-eta-csi+1)-2*(-zeta-eta-csi+0.5);
	this->dNdeta[1] = 0;
	this->dNdeta[2] = 2*eta+2*(eta-0.5);
	this->dNdeta[3] = 0;
	this->dNdeta[4] = -4*csi;
	this->dNdeta[5] = 4*csi;
	this->dNdeta[6] = 4*(-zeta-eta-csi+1)-4*eta;
	this->dNdeta[7] = -4*zeta;
	this->dNdeta[8] = 4*zeta;
	this->dNdeta[9] = 0;
	
	return this->dNdeta;
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdzeta(const T &csi, const T &eta, const T &zeta)
{
	//TODO test this
	// this->dNdzeta
	this->dNdzeta[0] = -2*(-zeta-eta-csi+1)-2*(-zeta-eta-csi+0.5);
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;
	this->dNdzeta[3] = 2*zeta+2*(zeta-0.5);
	this->dNdzeta[4] = -4*csi;
	this->dNdzeta[5] = 0;
	this->dNdzeta[6] = -4*eta;
	this->dNdzeta[7] = 4*(-zeta-eta-csi+1)-4*zeta;
	this->dNdzeta[8] = 4*eta;
	this->dNdzeta[9] = 4*csi;

	return this->dNdzeta;
}


template<typename T>
std::vector<fem::point> & Tetrahedron10<T>::setCoordinates()
{
	this->coordinates[0] = point(	0,	0,	0	);
	this->coordinates[1] = point(	1,	0,	0	);
	this->coordinates[2] = point(	0,	1,	0	);
	this->coordinates[3] = point(	0,	0,	1	);

	this->coordinates[4] = point(	0.5,	0,	0	);
	this->coordinates[5] = point(	0.5,	0.5,	0	);
	this->coordinates[6] = point(	0,	0.5,	0	);
	this->coordinates[7] = point(	0,	0,	0.5	);
	this->coordinates[8] = point(	0,	0.5,	0.5	);
	this->coordinates[9] = point(	0.5,	0.5,	0.5	);

	return this->coordinates;
}


}

#endif
