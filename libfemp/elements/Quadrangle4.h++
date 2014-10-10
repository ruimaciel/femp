#ifndef QUADRANGLE4_HPP
#define QUADRANGLE4_HPP

#include <vector>

#include "QuadrangleFamily.h++"
#include "../point.h++"



namespace fem
{

template <typename T>
struct Quadrangle4
	: public QuadrangleFamily<T>
{
	public:
		Quadrangle4();
		~Quadrangle4()	{};

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
        int node_number() const	{ return 4; };

};


template<typename T>
Quadrangle4<T>::Quadrangle4()
{
	this->stiffness_degree = 1;
	this->domain_degree = 1;

	this->coordinates.resize(4);

	this->N.resize(4);
	this->dNdcsi.resize(4);
	this->dNdeta.resize(4);
	this->dNdzeta.resize(4);
}


template<typename T>
std::vector<T> & Quadrangle4<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Quadrangle4<T>::setN(const T &csi, const T &eta, const T &)
{
	this->N[0] = (1-csi)*(1-eta)/4;
	this->N[1] = (1+csi)*(1-eta)/4;
	this->N[2] = (1+csi)*(1+eta)/4;
	this->N[3] = (1-csi)*(1+eta)/4;
	
	return this->N;
}


template<typename T>
std::vector<T> & Quadrangle4<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Quadrangle4<T>::setdNdcsi(const T &, const T &eta, const T &)
{
	// this->dNdcsi
	this->dNdcsi[0] = (eta-1)/4;
	this->dNdcsi[1] = (1-eta)/4;
	this->dNdcsi[2] = (1+eta)/4;
	this->dNdcsi[3] = (-1-eta)/4;

	return this->dNdcsi;
}


template<typename T>
std::vector<T> & Quadrangle4<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Quadrangle4<T>::setdNdeta(const T &csi, const T &, const T &)
{
	// this->dNdeta
	this->dNdeta[0] = (csi-1)/4;
	this->dNdeta[1] = (-1-csi)/4;
	this->dNdeta[2] = (1+csi)/4;
	this->dNdeta[3] = (1-csi)/4;
	
	return this->dNdeta;
}


template<typename T>
std::vector<T> & Quadrangle4<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Quadrangle4<T>::setdNdzeta(const T &, const T &, const T &)
{
	// this->dNdzeta
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;
	this->dNdzeta[3] = 0;

	return this->dNdzeta;
}


template<typename T>
std::vector<fem::point> & Quadrangle4<T>::setCoordinates()
{
	this->coordinates[0] = point(	-0.5,	-0.5,	0	);
	this->coordinates[1] = point(	0.5,	-0.5,	0	);
	this->coordinates[2] = point(	0.5,	0.5,	0	);
	this->coordinates[3] = point(	-0.5,	0.5,	0	);

	return this->coordinates;
}


template<typename T>
void
Quadrangle4<T>::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 4)
	{
		throw FemException("wrong number of nodes");
	}
	this->nodes = nodes;
}


}

#endif
