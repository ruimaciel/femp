#ifndef HEXAHEDRON8_HPP
#define HEXAHEDRON8_HPP

#include <vector>
#include <boost/tuple/tuple.hpp>

#include "BaseElement.h++"
#include "../point.h++"




namespace fem
{

template <typename T>
struct Hexahedron8
	: public BaseElement<T>
{
	public:
		Hexahedron8();
		~Hexahedron8()	{};

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
		void generateQuadratureData();
};


template<typename T>
Hexahedron8<T>::Hexahedron8()
{
	this->N.resize(8);
	this->dNdcsi.resize(8);
	this->dNdeta.resize(8);
	this->dNdzeta.resize(8);
}


template<typename T>
std::vector<T> & Hexahedron8<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Hexahedron8<T>::setN(const T &csi, const T &eta, const T &zeta)
{
	this->N[0] = (1-csi)*(1-eta)*(1-zeta)/8;
	this->N[1] = (csi+1)*(1-eta)*(1-zeta)/8;
	this->N[2] = (csi+1)*(eta+1)*(1-zeta)/8;
	this->N[3] = (1-csi)*(eta+1)*(1-zeta)/8;
	this->N[4] = (1-csi)*(1-eta)*(zeta+1)/8;
	this->N[5] = (csi+1)*(1-eta)*(zeta+1)/8;
	this->N[6] = (csi+1)*(eta+1)*(zeta+1)/8;
	this->N[7] = (1-csi)*(eta+1)*(zeta+1)/8;
	
	return this->N;
}


template<typename T>
std::vector<T> & Hexahedron8<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Hexahedron8<T>::setdNdcsi(const T &, const T &eta, const T &zeta)
{
	// this->dNdcsi
	this->dNdcsi[ 0] = -(1-eta)*(1-zeta)/8;
	this->dNdcsi[ 1] = (1-eta)*(1-zeta)/8;
	this->dNdcsi[ 2] = (eta+1)*(1-zeta)/8;
	this->dNdcsi[ 3] = -(eta+1)*(1-zeta)/8;
	this->dNdcsi[ 4] = -(1-eta)*(zeta+1)/8;
	this->dNdcsi[ 5] = (1-eta)*(zeta+1)/8;
	this->dNdcsi[ 6] = (eta+1)*(zeta+1)/8;
	this->dNdcsi[ 7] = -(eta+1)*(zeta+1)/8;

	return this->dNdcsi;
}


template<typename T>
std::vector<T> & Hexahedron8<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Hexahedron8<T>::setdNdeta(const T &csi, const T &, const T &zeta)
{
	// this->dNdeta
	this->dNdeta[ 0] = -(1-csi)*(1-zeta)/8;
	this->dNdeta[ 1] = -(csi+1)*(1-zeta)/8;
	this->dNdeta[ 2] = (csi+1)*(1-zeta)/8;
	this->dNdeta[ 3] = (1-csi)*(1-zeta)/8;
	this->dNdeta[ 4] = -(1-csi)*(zeta+1)/8;
	this->dNdeta[ 5] = -(csi+1)*(zeta+1)/8;
	this->dNdeta[ 6] = (csi+1)*(zeta+1)/8;
	this->dNdeta[ 7] = (1-csi)*(zeta+1)/8;
	
	return this->dNdeta;
}


template<typename T>
std::vector<T> & Hexahedron8<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Hexahedron8<T>::setdNdzeta(const T &csi, const T &eta, const T &)
{
	// this->dNdzeta
	this->dNdzeta[ 0] = -(1-csi)*(1-eta)/8;
	this->dNdzeta[ 1] = -(csi+1)*(1-eta)/8;
	this->dNdzeta[ 2] = -(csi+1)*(eta+1)/8;
	this->dNdzeta[ 3] = -(1-csi)*(eta+1)/8;
	this->dNdzeta[ 4] = (1-csi)*(1-eta)/8;
	this->dNdzeta[ 5] = (csi+1)*(1-eta)/8;
	this->dNdzeta[ 6] = (csi+1)*(eta+1)/8;
	this->dNdzeta[ 7] = (1-csi)*(eta+1)/8;

	return this->dNdzeta;
}


template<typename T>
void Hexahedron8<T>::generateQuadratureData()
{
	std::vector<boost::tuple<fem::point, T> > ips;

	for(int d = 1; d < 5; d++)
	{
		this->ipwpl.clear();
		T x[d], w[d];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		gauleg(x,w,d);

		// and now generate a list with those points
		for(int i = 0; i < d; i++)
		{
			for(int j = 0; j < d; j++)
			{
				for(int k = 0; k < d; k++)
				{
					ips.push_back(boost::tuple<fem::point,T>(fem::point(x[i],x[j],x[k]), w[i]*w[j]*w[k]));
				}
			}
		}
		this->ipwpl[d] = ips;
	}
}


}

#endif
