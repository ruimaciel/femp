#ifndef PRISM6_HPP
#define PRISM6_HPP

#include <vector>

#include "PrismFamily.h++"
#include "../point.h++"




namespace fem
{

template <typename T>
struct Prism6
	: public PrismFamily<T>
{
	public:
		Prism6();
		~Prism6()	{};

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
Prism6<T>::Prism6()
{
	this->stiffness_degree = 2;
	this->domain_degree = 2;

	this->coordinates.resize(6);

	this->N.resize(6);
	this->dNdcsi.resize(6);
	this->dNdeta.resize(6);
	this->dNdzeta.resize(6);
}


template<typename T>
std::vector<T> & Prism6<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism6<T>::setN(const T &csi, const T &eta, const T &zeta)
{
	//TODO finish this
	this->N[0] = (-eta-csi+1)*(1-zeta)/2;
	this->N[1] = csi*(1-zeta)/2;
	this->N[2] = eta*(1-zeta)/2;
	this->N[3] = (-eta-csi+1)*(zeta+1)/2;
	this->N[4] = csi*(zeta+1)/2;
	this->N[5] = eta*(zeta+1)/2;
	
	return this->N;
}


template<typename T>
std::vector<T> & Prism6<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism6<T>::setdNdcsi(const T &, const T &, const T &zeta)
{
	//TODO finish this
	// this->dNdcsi
	this->dNdcsi[0] = -(1-zeta)/2;
	this->dNdcsi[1] = (1-zeta)/2;
	this->dNdcsi[2] = 0;
	this->dNdcsi[3] = -(zeta+1)/2;
	this->dNdcsi[4] = (zeta+1)/2;
	this->dNdcsi[5] = 0;

	return this->dNdcsi;
}


template<typename T>
std::vector<T> & Prism6<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism6<T>::setdNdeta(const T &, const T &, const T &zeta)
{
	//TODO finish this
	// this->dNdeta
	this->dNdeta[0] = -(1-zeta)/2;
	this->dNdeta[1] = 0;
	this->dNdeta[2] = (1-zeta)/2;
	this->dNdeta[3] = -(zeta+1)/2;
	this->dNdeta[4] = 0;
	this->dNdeta[5] = (zeta+1)/2;
	
	return this->dNdeta;
}


template<typename T>
std::vector<T> & Prism6<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism6<T>::setdNdzeta(const T &csi, const T &eta, const T &)
{
	//TODO finish this
	// this->dNdzeta
	this->dNdzeta[0] = -(-eta-csi+1)/2;
	this->dNdzeta[1] = -csi/2;
	this->dNdzeta[2] = -eta/2;
	this->dNdzeta[3] = (-eta-csi+1)/2;
	this->dNdzeta[4] = csi/2;
	this->dNdzeta[5] = eta/2;

	return this->dNdzeta;
}

template<typename T>
std::vector<fem::point> & Prism6<T>::setCoordinates()
{
	this->coordinates[0] = point(	0,	0,	-1	);
	this->coordinates[1] = point(	1,	0,	-1	);
	this->coordinates[2] = point(	0,	1,	-1	);
	this->coordinates[3] = point(	0,	0,	1	);
	this->coordinates[4] = point(	1,	0,	1	);
	this->coordinates[5] = point(	0,	1,	1	);

	return this->coordinates;
}


}

#endif
