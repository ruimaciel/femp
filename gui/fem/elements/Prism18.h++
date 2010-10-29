#ifndef PRISM18_HPP
#define PRISM18_HPP

#include <vector>
#include <boost/tuple/tuple.hpp>

#include "PrismFamily.h++"
#include "../point.h++"




namespace fem
{

template <typename T>
struct Prism18
	: public PrismFamily<T>
{
	public:
		Prism18();
		~Prism18()	{};

		std::vector<T> & setN(const point & p);
		std::vector<T> & setN(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdcsi(const point &p);
		std::vector<T> & setdNdcsi(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdeta(const point &p);
		std::vector<T> & setdNdeta(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdzeta(const point &p);
		std::vector<T> & setdNdzeta(const T &csi, const T &eta, const T &zeta = 0);

	protected:
		/*
		Generates the lists of integration points/weights for this type of element
		*/
		// void generateQuadratureData();
};


template<typename T>
Prism18<T>::Prism18()
{
	this->N.resize(18);
	this->dNdcsi.resize(18);
	this->dNdeta.resize(18);
	this->dNdzeta.resize(18);
}


template<typename T>
std::vector<T> & Prism18<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism18<T>::setN(const T &csi, const T &eta, const T &zeta)
{
	//TODO test this

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


template<typename T>
std::vector<T> & Prism18<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism18<T>::setdNdcsi(const T &csi, const T &eta, const T &zeta)
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


template<typename T>
std::vector<T> & Prism18<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism18<T>::setdNdeta(const T &csi, const T &eta, const T &zeta)
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


template<typename T>
std::vector<T> & Prism18<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism18<T>::setdNdzeta(const T &csi, const T &eta, const T &zeta)
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

}

#endif
