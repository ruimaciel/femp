#ifndef HEXAHEDRON27_HPP
#define HEXAHEDRON27_HPP

#include <vector>

#include "HexahedronFamily.h++"
#include "../point.h++"




namespace fem
{

template <typename T>
struct Hexahedron27
	: public HexahedronFamily<T>
{
public:
	Hexahedron27();
	~Hexahedron27()	{};

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
        int node_number() const	{ return 27; };
};


template<typename T>
Hexahedron27<T>::Hexahedron27()
	: HexahedronFamily<T>()
{
	this->type = BaseElement<T>::FE_HEXAHEDRON27;
	this->stiffness_degree = 3;
	this->domain_degree = 2;

	this->coordinates.resize(27);

	this->N.resize(27);
	this->dNdcsi.resize(27);
	this->dNdeta.resize(27);
	this->dNdzeta.resize(27);
}


template<typename T>
std::vector<T> & 
Hexahedron27<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron27<T>::setN(const T &csi, const T &eta, const T &zeta)
{
	this->N[ 0] = (csi-1)*csi*(eta-1)*eta*(zeta-1)*zeta/8;
	this->N[ 1] = csi*(csi+1)*(eta-1)*eta*(zeta-1)*zeta/8;
	this->N[ 2] = csi*(csi+1)*eta*(eta+1)*(zeta-1)*zeta/8;
	this->N[ 3] = (csi-1)*csi*eta*(eta+1)*(zeta-1)*zeta/8;
	this->N[ 4] = (csi-1)*csi*(eta-1)*eta*zeta*(zeta+1)/8;
	this->N[ 5] = csi*(csi+1)*(eta-1)*eta*zeta*(zeta+1)/8;
	this->N[ 6] = csi*(csi+1)*eta*(eta+1)*zeta*(zeta+1)/8;
	this->N[ 7] = (csi-1)*csi*eta*(eta+1)*zeta*(zeta+1)/8;
	this->N[ 8] = -(csi-1)*(csi+1)*(eta-1)*eta*(zeta-1)*zeta/4;
	this->N[ 9] = -(csi-1)*csi*(eta-1)*(eta+1)*(zeta-1)*zeta/4;
	this->N[10] = -(csi-1)*csi*(eta-1)*eta*(zeta-1)*(zeta+1)/4;
	this->N[11] = -csi*(csi+1)*(eta-1)*(eta+1)*(zeta-1)*zeta/4;
	this->N[12] = -csi*(csi+1)*(eta-1)*eta*(zeta-1)*(zeta+1)/4;
	this->N[13] = -(csi-1)*(csi+1)*eta*(eta+1)*(zeta-1)*zeta/4;
	this->N[14] = -csi*(csi+1)*eta*(eta+1)*(zeta-1)*(zeta+1)/4;
	this->N[15] = -(csi-1)*csi*eta*(eta+1)*(zeta-1)*(zeta+1)/4;
	this->N[16] = -(csi-1)*(csi+1)*(eta-1)*eta*zeta*(zeta+1)/4;
	this->N[17] = -(csi-1)*csi*(eta-1)*(eta+1)*zeta*(zeta+1)/4;
	this->N[18] = -csi*(csi+1)*(eta-1)*(eta+1)*zeta*(zeta+1)/4;
	this->N[19] = -(csi-1)*(csi+1)*eta*(eta+1)*zeta*(zeta+1)/4;
	this->N[20] = (csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta-1)*zeta/2;
	this->N[21] = (csi-1)*(csi+1)*(eta-1)*eta*(zeta-1)*(zeta+1)/2;
	this->N[22] = (csi-1)*csi*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2;
	this->N[23] = csi*(csi+1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2;
	this->N[24] = (csi-1)*(csi+1)*eta*(eta+1)*(zeta-1)*(zeta+1)/2;
	this->N[25] = (csi-1)*(csi+1)*(eta-1)*(eta+1)*zeta*(zeta+1)/2;
	this->N[26] = -(csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1);
	
	return this->N;
}


template<typename T>
std::vector<T> & 
Hexahedron27<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron27<T>::setdNdcsi(const T &csi, const T &eta, const T &zeta)
{
	// this->dNdcsi
	this->dNdcsi[ 0] = csi*(eta-1)*eta*(zeta-1)*zeta/8+(csi-1)*(eta-1)*eta*(zeta-1)*zeta/8;
	this->dNdcsi[ 1] = (csi+1)*(eta-1)*eta*(zeta-1)*zeta/8+csi*(eta-1)*eta*(zeta-1)*zeta/8;
	this->dNdcsi[ 2] = (csi+1)*eta*(eta+1)*(zeta-1)*zeta/8+csi*eta*(eta+1)*(zeta-1)*zeta/8;
	this->dNdcsi[ 3] = csi*eta*(eta+1)*(zeta-1)*zeta/8+(csi-1)*eta*(eta+1)*(zeta-1)*zeta/8;
	this->dNdcsi[ 4] = csi*(eta-1)*eta*zeta*(zeta+1)/8+(csi-1)*(eta-1)*eta*zeta*(zeta+1)/8;
	this->dNdcsi[ 5] = (csi+1)*(eta-1)*eta*zeta*(zeta+1)/8+csi*(eta-1)*eta*zeta*(zeta+1)/8;
	this->dNdcsi[ 6] = (csi+1)*eta*(eta+1)*zeta*(zeta+1)/8+csi*eta*(eta+1)*zeta*(zeta+1)/8;
	this->dNdcsi[ 7] = csi*eta*(eta+1)*zeta*(zeta+1)/8+(csi-1)*eta*(eta+1)*zeta*(zeta+1)/8;
	this->dNdcsi[ 8] = -(csi+1)*(eta-1)*eta*(zeta-1)*zeta/4-(csi-1)*(eta-1)*eta*(zeta-1)*zeta/4;
	this->dNdcsi[ 9] = -csi*(eta-1)*(eta+1)*(zeta-1)*zeta/4-(csi-1)*(eta-1)*(eta+1)*(zeta-1)*zeta/4;
	this->dNdcsi[10] = -csi*(eta-1)*eta*(zeta-1)*(zeta+1)/4-(csi-1)*(eta-1)*eta*(zeta-1)*(zeta+1)/4;
	this->dNdcsi[11] = -(csi+1)*(eta-1)*(eta+1)*(zeta-1)*zeta/4-csi*(eta-1)*(eta+1)*(zeta-1)*zeta/4;
	this->dNdcsi[12] = -(csi+1)*(eta-1)*eta*(zeta-1)*(zeta+1)/4-csi*(eta-1)*eta*(zeta-1)*(zeta+1)/4;
	this->dNdcsi[13] = -(csi+1)*eta*(eta+1)*(zeta-1)*zeta/4-(csi-1)*eta*(eta+1)*(zeta-1)*zeta/4;
	this->dNdcsi[14] = -(csi+1)*eta*(eta+1)*(zeta-1)*(zeta+1)/4-csi*eta*(eta+1)*(zeta-1)*(zeta+1)/4;
	this->dNdcsi[15] = -csi*eta*(eta+1)*(zeta-1)*(zeta+1)/4-(csi-1)*eta*(eta+1)*(zeta-1)*(zeta+1)/4;
	this->dNdcsi[16] = -(csi+1)*(eta-1)*eta*zeta*(zeta+1)/4-(csi-1)*(eta-1)*eta*zeta*(zeta+1)/4;
	this->dNdcsi[17] = -csi*(eta-1)*(eta+1)*zeta*(zeta+1)/4-(csi-1)*(eta-1)*(eta+1)*zeta*(zeta+1)/4;
	this->dNdcsi[18] = -(csi+1)*(eta-1)*(eta+1)*zeta*(zeta+1)/4-csi*(eta-1)*(eta+1)*zeta*(zeta+1)/4;
	this->dNdcsi[19] = -(csi+1)*eta*(eta+1)*zeta*(zeta+1)/4-(csi-1)*eta*(eta+1)*zeta*(zeta+1)/4;
	this->dNdcsi[20] = (csi+1)*(eta-1)*(eta+1)*(zeta-1)*zeta/2+(csi-1)*(eta-1)*(eta+1)*(zeta-1)*zeta/2;
	this->dNdcsi[21] = (csi+1)*(eta-1)*eta*(zeta-1)*(zeta+1)/2+(csi-1)*(eta-1)*eta*(zeta-1)*(zeta+1)/2;
	this->dNdcsi[22] = csi*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2+(csi-1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2;
	this->dNdcsi[23] = (csi+1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2+csi*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2;
	this->dNdcsi[24] = (csi+1)*eta*(eta+1)*(zeta-1)*(zeta+1)/2+(csi-1)*eta*(eta+1)*(zeta-1)*(zeta+1)/2;
	this->dNdcsi[25] = (csi+1)*(eta-1)*(eta+1)*zeta*(zeta+1)/2+(csi-1)*(eta-1)*(eta+1)*zeta*(zeta+1)/2;
	this->dNdcsi[26] = -(csi+1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)-(csi-1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1);

	return this->dNdcsi;
}


template<typename T>
std::vector<T> & 
Hexahedron27<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron27<T>::setdNdeta(const T &csi, const T &eta, const T &zeta)
{
	// this->dNdeta
	this->dNdeta[ 0] = (csi-1)*csi*eta*(zeta-1)*zeta/8+(csi-1)*csi*(eta-1)*(zeta-1)*zeta/8;
	this->dNdeta[ 1] = csi*(csi+1)*eta*(zeta-1)*zeta/8+csi*(csi+1)*(eta-1)*(zeta-1)*zeta/8;
	this->dNdeta[ 2] =  csi*(csi+1)*(eta+1)*(zeta-1)*zeta/8+csi*(csi+1)*eta*(zeta-1)*zeta/8;
	this->dNdeta[ 3] = (csi-1)*csi*(eta+1)*(zeta-1)*zeta/8+(csi-1)*csi*eta*(zeta-1)*zeta/8;
	this->dNdeta[ 4] =  (csi-1)*csi*eta*zeta*(zeta+1)/8+(csi-1)*csi*(eta-1)*zeta*(zeta+1)/8;
	this->dNdeta[ 5] = csi*(csi+1)*eta*zeta*(zeta+1)/8+csi*(csi+1)*(eta-1)*zeta*(zeta+1)/8;
	this->dNdeta[ 6] =  csi*(csi+1)*(eta+1)*zeta*(zeta+1)/8+csi*(csi+1)*eta*zeta*(zeta+1)/8;
	this->dNdeta[ 7] = (csi-1)*csi*(eta+1)*zeta*(zeta+1)/8+(csi-1)*csi*eta*zeta*(zeta+1)/8;
	this->dNdeta[ 8] =  -(csi-1)*(csi+1)*eta*(zeta-1)*zeta/4-(csi-1)*(csi+1)*(eta-1)*(zeta-1)*zeta/4;
	this->dNdeta[ 9] = -(csi-1)*csi*(eta+1)*(zeta-1)*zeta/4-(csi-1)*csi*(eta-1)*(zeta-1)*zeta/4;
	this->dNdeta[10] =  -(csi-1)*csi*eta*(zeta-1)*(zeta+1)/4-(csi-1)*csi*(eta-1)*(zeta-1)*(zeta+1)/4;
	this->dNdeta[11] = -csi*(csi+1)*(eta+1)*(zeta-1)*zeta/4-csi*(csi+1)*(eta-1)*(zeta-1)*zeta/4;
	this->dNdeta[12] =  -csi*(csi+1)*eta*(zeta-1)*(zeta+1)/4-csi*(csi+1)*(eta-1)*(zeta-1)*(zeta+1)/4;
	this->dNdeta[13] = -(csi-1)*(csi+1)*(eta+1)*(zeta-1)*zeta/4-(csi-1)*(csi+1)*eta*(zeta-1)*zeta/4;
	this->dNdeta[14] =  -csi*(csi+1)*(eta+1)*(zeta-1)*(zeta+1)/4-csi*(csi+1)*eta*(zeta-1)*(zeta+1)/4;
	this->dNdeta[15] = -(csi-1)*csi*(eta+1)*(zeta-1)*(zeta+1)/4-(csi-1)*csi*eta*(zeta-1)*(zeta+1)/4;
	this->dNdeta[16] =  -(csi-1)*(csi+1)*eta*zeta*(zeta+1)/4-(csi-1)*(csi+1)*(eta-1)*zeta*(zeta+1)/4;
	this->dNdeta[17] = -(csi-1)*csi*(eta+1)*zeta*(zeta+1)/4-(csi-1)*csi*(eta-1)*zeta*(zeta+1)/4;
	this->dNdeta[18] =  -csi*(csi+1)*(eta+1)*zeta*(zeta+1)/4-csi*(csi+1)*(eta-1)*zeta*(zeta+1)/4;
	this->dNdeta[19] = -(csi-1)*(csi+1)*(eta+1)*zeta*(zeta+1)/4-(csi-1)*(csi+1)*eta*zeta*(zeta+1)/4;
	this->dNdeta[20] =  (csi-1)*(csi+1)*(eta+1)*(zeta-1)*zeta/2+(csi-1)*(csi+1)*(eta-1)*(zeta-1)*zeta/2;
	this->dNdeta[21] =  (csi-1)*(csi+1)*eta*(zeta-1)*(zeta+1)/2+(csi-1)*(csi+1)*(eta-1)*(zeta-1)*(zeta+1)/2;
	this->dNdeta[22] =  (csi-1)*csi*(eta+1)*(zeta-1)*(zeta+1)/2+(csi-1)*csi*(eta-1)*(zeta-1)*(zeta+1)/2;
	this->dNdeta[23] =  csi*(csi+1)*(eta+1)*(zeta-1)*(zeta+1)/2+csi*(csi+1)*(eta-1)*(zeta-1)*(zeta+1)/2;
	this->dNdeta[24] =  (csi-1)*(csi+1)*(eta+1)*(zeta-1)*(zeta+1)/2+(csi-1)*(csi+1)*eta*(zeta-1)*(zeta+1)/2;
	this->dNdeta[25] =  (csi-1)*(csi+1)*(eta+1)*zeta*(zeta+1)/2+(csi-1)*(csi+1)*(eta-1)*zeta*(zeta+1)/2;
	this->dNdeta[26] =  -(csi-1)*(csi+1)*(eta+1)*(zeta-1)*(zeta+1)-(csi-1)*(csi+1)*(eta-1)*(zeta-1)*(zeta+1);
	
	return this->dNdeta;
}


template<typename T>
std::vector<T> & 
Hexahedron27<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Hexahedron27<T>::setdNdzeta(const T &csi, const T &eta, const T &zeta)
{
	// this->dNdzeta
	this->dNdzeta[ 0] = (csi-1)*csi*(eta-1)*eta*zeta/8+(csi-1)*csi*(eta-1)*eta*(zeta-1)/8;
	this->dNdzeta[ 1] = csi*(csi+1)*(eta-1)*eta*zeta/8+csi*(csi+1)*(eta-1)*eta*(zeta-1)/8;
	this->dNdzeta[ 2] =  csi*(csi+1)*eta*(eta+1)*zeta/8+csi*(csi+1)*eta*(eta+1)*(zeta-1)/8;
	this->dNdzeta[ 3] = (csi-1)*csi*eta*(eta+1)*zeta/8+(csi-1)*csi*eta*(eta+1)*(zeta-1)/8;
	this->dNdzeta[ 4] =  (csi-1)*csi*(eta-1)*eta*(zeta+1)/8+(csi-1)*csi*(eta-1)*eta*zeta/8;
	this->dNdzeta[ 5] = csi*(csi+1)*(eta-1)*eta*(zeta+1)/8+csi*(csi+1)*(eta-1)*eta*zeta/8;
	this->dNdzeta[ 6] =  csi*(csi+1)*eta*(eta+1)*(zeta+1)/8+csi*(csi+1)*eta*(eta+1)*zeta/8;
	this->dNdzeta[ 7] = (csi-1)*csi*eta*(eta+1)*(zeta+1)/8+(csi-1)*csi*eta*(eta+1)*zeta/8;
	this->dNdzeta[ 8] =  -(csi-1)*(csi+1)*(eta-1)*eta*zeta/4-(csi-1)*(csi+1)*(eta-1)*eta*(zeta-1)/4;
	this->dNdzeta[ 9] = -(csi-1)*csi*(eta-1)*(eta+1)*zeta/4-(csi-1)*csi*(eta-1)*(eta+1)*(zeta-1)/4;
	this->dNdzeta[10] =  -(csi-1)*csi*(eta-1)*eta*(zeta+1)/4-(csi-1)*csi*(eta-1)*eta*(zeta-1)/4;
	this->dNdzeta[11] = -csi*(csi+1)*(eta-1)*(eta+1)*zeta/4-csi*(csi+1)*(eta-1)*(eta+1)*(zeta-1)/4;
	this->dNdzeta[12] =  -csi*(csi+1)*(eta-1)*eta*(zeta+1)/4-csi*(csi+1)*(eta-1)*eta*(zeta-1)/4;
	this->dNdzeta[13] = -(csi-1)*(csi+1)*eta*(eta+1)*zeta/4-(csi-1)*(csi+1)*eta*(eta+1)*(zeta-1)/4;
	this->dNdzeta[14] =  -csi*(csi+1)*eta*(eta+1)*(zeta+1)/4-csi*(csi+1)*eta*(eta+1)*(zeta-1)/4;
	this->dNdzeta[15] = -(csi-1)*csi*eta*(eta+1)*(zeta+1)/4-(csi-1)*csi*eta*(eta+1)*(zeta-1)/4;
	this->dNdzeta[16] =  -(csi-1)*(csi+1)*(eta-1)*eta*(zeta+1)/4-(csi-1)*(csi+1)*(eta-1)*eta*zeta/4;
	this->dNdzeta[17] = -(csi-1)*csi*(eta-1)*(eta+1)*(zeta+1)/4-(csi-1)*csi*(eta-1)*(eta+1)*zeta/4;
	this->dNdzeta[18] =  -csi*(csi+1)*(eta-1)*(eta+1)*(zeta+1)/4-csi*(csi+1)*(eta-1)*(eta+1)*zeta/4;
	this->dNdzeta[19] = -(csi-1)*(csi+1)*eta*(eta+1)*(zeta+1)/4-(csi-1)*(csi+1)*eta*(eta+1)*zeta/4;
	this->dNdzeta[20] =  (csi-1)*(csi+1)*(eta-1)*(eta+1)*zeta/2+(csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta-1)/2;
	this->dNdzeta[21] =  (csi-1)*(csi+1)*(eta-1)*eta*(zeta+1)/2+(csi-1)*(csi+1)*(eta-1)*eta*(zeta-1)/2;
	this->dNdzeta[22] = (csi-1)*csi*(eta-1)*(eta+1)*(zeta+1)/2+(csi-1)*csi*(eta-1)*(eta+1)*(zeta-1)/2;
	this->dNdzeta[23] =  csi*(csi+1)*(eta-1)*(eta+1)*(zeta+1)/2+csi*(csi+1)*(eta-1)*(eta+1)*(zeta-1)/2;
	this->dNdzeta[24] = (csi-1)*(csi+1)*eta*(eta+1)*(zeta+1)/2+(csi-1)*(csi+1)*eta*(eta+1)*(zeta-1)/2;
	this->dNdzeta[25] =  (csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta+1)/2+(csi-1)*(csi+1)*(eta-1)*(eta+1)*zeta/2;
	this->dNdzeta[26] =  -(csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta+1)-(csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta-1);

	return this->dNdzeta;
}


template<typename T>
std::vector<fem::point> & 
Hexahedron27<T>::setCoordinates()
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

	this->coordinates[20] = point(	0,	0,	1	);
	this->coordinates[21] = point(	0,	-1,	0	);
	this->coordinates[22] = point(	-1,	0,	0	);
	this->coordinates[23] = point(	1,	0,	0	);
	this->coordinates[24] = point(	0,	1,	0	);
	this->coordinates[25] = point(	0,	0,	1	);
	this->coordinates[26] = point(	0,	0,	0	);

	return this->coordinates;
}


template<typename T>
enum BaseElement<T>::Error 
Hexahedron27<T>::set(std::vector<size_t> &nodes)
{
	assert(nodes.size() == 27);
	this->nodes = nodes;
	return BaseElement<T>::ERR_OK;
}


}

#endif
