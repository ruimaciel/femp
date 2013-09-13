#ifndef HEXAHEDRON8_HPP
#define HEXAHEDRON8_HPP

#include <vector>

#include "HexahedronFamily.h++"
#include "../point.h++"



namespace fem
{

template <typename T>
struct Hexahedron8
	: public HexahedronFamily<T>
{
public:
	Hexahedron8();
	~Hexahedron8()	{};

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
        enum BaseElement<T>::Error set(std::vector<size_t> &nodes);

        /** 
        return the number of nodes that an element of this particular type has
        @return the number of nodes
        **/
        int node_number() const	{ return 8; };
};


template<typename T>
Hexahedron8<T>::Hexahedron8()
	: HexahedronFamily<T>()
{
	this->type = BaseElement<T>::FE_HEXAHEDRON8;
	this->stiffness_degree = 2;
	this->domain_degree = 1;

	this->coordinates.resize(8);

	this->N.resize(8);
	this->dNdcsi.resize(8);
	this->dNdeta.resize(8);
	this->dNdzeta.resize(8);
}


template<typename T>
std::vector<T> & 
Hexahedron8<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron8<T>::setN(const T &csi, const T &eta, const T &zeta)
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
std::vector<T> & 
Hexahedron8<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron8<T>::setdNdcsi(const T &, const T &eta, const T &zeta)
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
std::vector<T> & 
Hexahedron8<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron8<T>::setdNdeta(const T &csi, const T &, const T &zeta)
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
std::vector<T> & 
Hexahedron8<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron8<T>::setdNdzeta(const T &csi, const T &eta, const T &)
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
std::vector<fem::point> & 
Hexahedron8<T>::setCoordinates()
{
	this->coordinates[0] = point(	-1,	-1,	-1	);
	this->coordinates[1] = point(	1,	-1,	-1	);
	this->coordinates[2] = point(	1,	1,	-1	);
	this->coordinates[3] = point(	-1,	1,	-1	);

	this->coordinates[4] = point(	-1,	-1,	1	);
	this->coordinates[5] = point(	1,	-1,	1	);
	this->coordinates[6] = point(	1,	1,	1	);
	this->coordinates[7] = point(	-1,	1,	1	);

	return this->coordinates;
}


template<typename T>
enum BaseElement<T>::Error 
Hexahedron8<T>::set(std::vector<size_t> &nodes)
{
	assert(nodes.size() == 8);
	this->nodes = nodes;
	return BaseElement<T>::ERR_OK;
}


}

#endif
