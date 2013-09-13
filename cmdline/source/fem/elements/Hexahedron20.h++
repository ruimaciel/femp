#ifndef HEXAHEDRON20_HPP
#define HEXAHEDRON20_HPP

#include <vector>

#include "HexahedronFamily.h++"
#include "../point.h++"




namespace fem
{

template <typename T>
struct Hexahedron20
	: public HexahedronFamily<T>
{
public:
	Hexahedron20();
	~Hexahedron20()	{};

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
        int node_number() const	{ return 20; };
};


template<typename T>
Hexahedron20<T>::Hexahedron20()
	: HexahedronFamily<T>()
{
	this->type = BaseElement<T>::FE_HEXAHEDRON20;
	this->stiffness_degree = 3;
	this->domain_degree = 2;

	this->coordinates.resize(20);

	this->N.resize(20);
	this->dNdcsi.resize(20);
	this->dNdeta.resize(20);
	this->dNdzeta.resize(20);
}


template<typename T>
std::vector<T> & 
Hexahedron20<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron20<T>::setN(const T &csi, const T &eta, const T &zeta)
{
	this->N[ 0] = (1-csi)*(1-eta)*(1-zeta)*(-zeta-eta-csi-2)/8;
	this->N[ 1] = (csi+1)*(1-eta)*(1-zeta)*(-zeta-eta+csi-2)/8;
	this->N[ 2] = (csi+1)*(eta+1)*(1-zeta)*(-zeta+eta+csi-2)/8;
	this->N[ 3] = (1-csi)*(eta+1)*(1-zeta)*(-zeta+eta-csi-2)/8;
	this->N[ 4] = (1-csi)*(1-eta)*(zeta+1)*(zeta-eta-csi-2)/8;
	this->N[ 5] = (csi+1)*(1-eta)*(zeta+1)*(zeta-eta+csi-2)/8;
	this->N[ 6] = (csi+1)*(eta+1)*(zeta+1)*(zeta+eta+csi-2)/8;
	this->N[ 7] = (1-csi)*(eta+1)*(zeta+1)*(zeta+eta-csi-2)/8;
	this->N[ 8] = (1-csi*csi)*(1-eta)*(1-zeta)/4;
	this->N[ 9] = (1-csi)*(1-eta*eta)*(1-zeta)/4;
	this->N[10] = (1-csi)*(1-eta)*(1-zeta*zeta)/4;
	this->N[11] = (csi+1)*(1-eta*eta)*(1-zeta)/4;
	this->N[12] = (csi+1)*(1-eta)*(1-zeta*zeta)/4;
	this->N[13] = (1-csi*csi)*(eta+1)*(1-zeta)/4;
	this->N[14] = (csi+1)*(eta+1)*(1-zeta*zeta)/4;
	this->N[15] = (1-csi)*(eta+1)*(1-zeta*zeta)/4;
	this->N[16] = (1-csi*csi)*(1-eta)*(zeta+1)/4;
	this->N[17] = (1-csi)*(1-eta*eta)*(zeta+1)/4;
	this->N[18] = (csi+1)*(1-eta*eta)*(zeta+1)/4;
	this->N[19] = (1-csi*csi)*(eta+1)*(zeta+1)/4;

	return this->N;
}


template<typename T>
std::vector<T> & 
Hexahedron20<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron20<T>::setdNdcsi(const T &csi, const T &eta, const T &zeta)
{
	// this->dNdcsi
	this->dNdcsi[ 0] = (eta-1)*(zeta-1)*(zeta+eta+2*csi+1)/8;
	this->dNdcsi[ 1] = -(eta-1)*(zeta-1)*(zeta+eta-2*csi+1)/8;
	this->dNdcsi[ 2] = (eta+1)*(zeta-1)*(zeta-eta-2*csi+1)/8;
	this->dNdcsi[ 3] = -(eta+1)*(zeta-1)*(zeta-eta+2*csi+1)/8;
	this->dNdcsi[ 4] = (eta-1)*(zeta+1)*(zeta-eta-2*csi-1)/8;
	this->dNdcsi[ 5] = -(eta-1)*(zeta+1)*(zeta-eta+2*csi-1)/8;
	this->dNdcsi[ 6] = (eta+1)*(zeta+1)*(zeta+eta+2*csi-1)/8;
	this->dNdcsi[ 7] = -(eta+1)*(zeta+1)*(zeta+eta-2*csi-1)/8;
	this->dNdcsi[ 8] = -csi*(1-eta)*(1-zeta)/2;
	this->dNdcsi[ 9] = -(1-eta*eta)*(1-zeta)/4;
	this->dNdcsi[10] = -(1-eta)*(1-zeta*zeta)/4;
	this->dNdcsi[11] = (1-eta*eta)*(1-zeta)/4;
	this->dNdcsi[12] = (1-eta)*(1-zeta*zeta)/4;
	this->dNdcsi[13] = -csi*(eta+1)*(1-zeta)/2;
	this->dNdcsi[14] = (eta+1)*(1-zeta*zeta)/4;
	this->dNdcsi[15] = -(eta+1)*(1-zeta*zeta)/4;
	this->dNdcsi[16] = -csi*(1-eta)*(zeta+1)/2;
	this->dNdcsi[17] = -(1-eta*eta)*(zeta+1)/4;
	this->dNdcsi[18] = (1-eta*eta)*(zeta+1)/4;
	this->dNdcsi[19] = -csi*(eta+1)*(zeta+1)/2;

	return this->dNdcsi;
}


template<typename T>
std::vector<T> & 
Hexahedron20<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron20<T>::setdNdeta(const T &csi, const T &eta, const T &zeta)
{
	// this->dNdeta
	this->dNdeta[ 0] = (csi-1)*(zeta-1)*(zeta+2*eta+csi+1)/8;
	this->dNdeta[ 1] = (csi+1)*(1-zeta)*(zeta+2*eta-csi+1)/8;
	this->dNdeta[ 2] = (csi+1)*(zeta-1)*(zeta-2*eta-csi+1)/8;
	this->dNdeta[ 3] = (csi-1)*(1-zeta)*(zeta-2*eta+csi+1)/8;
	this->dNdeta[ 4] = (csi-1)*(zeta+1)*(zeta-2*eta-csi-1)/8;
	this->dNdeta[ 5] = -(csi+1)*(zeta+1)*(zeta-2*eta+csi-1)/8;
	this->dNdeta[ 6] = (csi+1)*(zeta+1)*(zeta+2*eta+csi-1)/8;
	this->dNdeta[ 7] = (1-csi)*(zeta+1)*(zeta+2*eta-csi-1)/8;
	this->dNdeta[ 8] = (1-csi*csi)*(zeta-1)/4;
	this->dNdeta[ 9] = (1-csi)*eta*(zeta-1)/2;
	this->dNdeta[10] = (csi-1)*(1-zeta*zeta)/4;
	this->dNdeta[11] = (csi+1)*eta*(zeta-1)/2;
	this->dNdeta[12] = (csi+1)*(zeta*zeta-1)/4;
	this->dNdeta[13] = (1-csi*csi)*(1-zeta)/4;
	this->dNdeta[14] = (csi+1)*(1-zeta*zeta)/4;
	this->dNdeta[15] = (1-csi)*(1-zeta*zeta)/4;
	this->dNdeta[16] = (csi*csi-1)*(zeta+1)/4;
	this->dNdeta[17] = (csi-1)*eta*(zeta+1)/2;
	this->dNdeta[18] = -(csi+1)*eta*(zeta+1)/2;
	this->dNdeta[19] = (1-csi*csi)*(zeta+1)/4;
	
	return this->dNdeta;
}


template<typename T>
std::vector<T> & 
Hexahedron20<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron20<T>::setdNdzeta(const T &csi, const T &eta, const T &zeta)
{
	// this->dNdzeta
	this->dNdzeta[ 0] = (csi-1)*(eta-1)*(2*zeta+eta+csi+1)/8;
	this->dNdzeta[ 1] = -(csi+1)*(eta-1)*(2*zeta+eta-csi+1)/8;
	this->dNdzeta[ 2] = (csi+1)*(eta+1)*(2*zeta-eta-csi+1)/8;
	this->dNdzeta[ 3] = -(csi-1)*(eta+1)*(2*zeta-eta+csi+1)/8;
	this->dNdzeta[ 4] = (csi-1)*(eta-1)*(2*zeta-eta-csi-1)/8;
	this->dNdzeta[ 5] = -(csi+1)*(eta-1)*(2*zeta-eta+csi-1)/8;
	this->dNdzeta[ 6] = (csi+1)*(eta+1)*(2*zeta+eta+csi-1)/8;
	this->dNdzeta[ 7] = -(csi-1)*(eta+1)*(2*zeta+eta-csi-1)/8;
	this->dNdzeta[ 8] = -(1-csi*csi)*(1-eta)/4;
	this->dNdzeta[ 9] = -(1-csi)*(1-eta*eta)/4;
	this->dNdzeta[10] = -(1-csi)*(1-eta)*zeta/2;
	this->dNdzeta[11] = -(csi+1)*(1-eta*eta)/4;
	this->dNdzeta[12] = -(csi+1)*(1-eta)*zeta/2;
	this->dNdzeta[13] = -(1-csi*csi)*(eta+1)/4;
	this->dNdzeta[14] = -(csi+1)*(eta+1)*zeta/2;
	this->dNdzeta[15] = -(1-csi)*(eta+1)*zeta/2;
	this->dNdzeta[16] = (1-csi*csi)*(1-eta)/4;
	this->dNdzeta[17] = (1-csi)*(1-eta*eta)/4;
	this->dNdzeta[18] = (csi+1)*(1-eta*eta)/4;
	this->dNdzeta[19] = (1-csi*csi)*(eta+1)/4;

	return this->dNdzeta;
}


template<typename T>
std::vector<fem::point> & 
Hexahedron20<T>::setCoordinates()
{
	this->coordinates[0] = point(	-1,	-1,	-1	);
	this->coordinates[1] = point(	1,	-1,	-1	);
	this->coordinates[2] = point(	1,	1,	-1	);
	this->coordinates[3] = point(	-1,	1,	-1	);

	this->coordinates[4] = point(	-1,	-1,	1	);
	this->coordinates[5] = point(	1,	-1,	1	);
	this->coordinates[6] = point(	1,	1,	1	);
	this->coordinates[7] = point(	-1,	1,	1	);

	this->coordinates[8] = point(	0,	-1,	-1	);
	this->coordinates[9] = point(	-1,	0,	-1	);
	this->coordinates[10] = point(	-1,	-1,	0	);
	this->coordinates[11] = point(	1,	0,	-1	);
	this->coordinates[12] = point(	1,	-1,	0	);
	this->coordinates[13] = point(	0,	1,	-1	);
	this->coordinates[14] = point(	1,	1,	0	);
	this->coordinates[15] = point(	-1,	1,	0	);
	this->coordinates[16] = point(	0,	-1,	1	);
	this->coordinates[17] = point(	-1,	0,	1	);
	this->coordinates[18] = point(	1,	0,	1	);
	this->coordinates[19] = point(	0,	1,	1	);

	return this->coordinates;
}


template<typename T>
enum BaseElement<T>::Error 
Hexahedron20<T>::set(std::vector<size_t> &nodes)
{
	assert(nodes.size() == 20);
	this->nodes = nodes;

	return BaseElement<T>::ERR_OK;
}


}

#endif
