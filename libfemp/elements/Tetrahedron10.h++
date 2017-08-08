#ifndef FEMP_TETRAHEDRON10_HPP
#define FEMP_TETRAHEDRON10_HPP

#include <vector>

#include "TetrahedronFamily.h++"
#include "../Point.h++"




namespace fem
{

template <typename Scalar>
struct Tetrahedron10
	: public TetrahedronFamily<Scalar>
{
public:
	Tetrahedron10();
	~Tetrahedron10()	{};

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
        int node_number() const	{ return 10; };
};


template<typename Scalar>
Tetrahedron10<Scalar>::Tetrahedron10()
{
	this->type = BaseElement<Scalar>::FE_TETRAHEDRON10;
	this->stiffness_degree = 2;
	this->domain_degree = 2;

	this->coordinates.resize(10);
	this->N.resize(10);
	this->dNdcsi.resize(10);
	this->dNdeta.resize(10);
	this->dNdzeta.resize(10);
}


template<typename Scalar>
std::vector<Scalar> & Tetrahedron10<Scalar>::setN(const Point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Tetrahedron10<Scalar>::setN(const Scalar &csi, const Scalar &eta, const Scalar &zeta)
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


template<typename Scalar>
std::vector<Scalar> & Tetrahedron10<Scalar>::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Tetrahedron10<Scalar>::setdNdcsi(const Scalar &csi, const Scalar &eta, const Scalar &zeta)
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


template<typename Scalar>
std::vector<Scalar> & Tetrahedron10<Scalar>::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Tetrahedron10<Scalar>::setdNdeta(const Scalar &csi, const Scalar &eta, const Scalar &zeta)
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


template<typename Scalar>
std::vector<Scalar> & Tetrahedron10<Scalar>::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Tetrahedron10<Scalar>::setdNdzeta(const Scalar &csi, const Scalar &eta, const Scalar &zeta)
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


template<typename Scalar>
std::vector<fem::Point> & Tetrahedron10<Scalar>::setCoordinates()
{
	this->coordinates[0] = Point(	0,	0,	0	);
	this->coordinates[1] = Point(	1,	0,	0	);
	this->coordinates[2] = Point(	0,	1,	0	);
	this->coordinates[3] = Point(	0,	0,	1	);

	this->coordinates[4] = Point(	0.5,	0,	0	);
	this->coordinates[5] = Point(	0.5,	0.5,	0	);
	this->coordinates[6] = Point(	0,	0.5,	0	);
	this->coordinates[7] = Point(	0,	0,	0.5	);
	this->coordinates[8] = Point(	0,	0.5,	0.5	);
	this->coordinates[9] = Point(	0.5,	0.5,	0.5	);

	return this->coordinates;
}


template<typename Scalar>
void
Tetrahedron10<Scalar>::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 10)
	{
		throw FemException("wrong number of nodes");
	}
	this->nodes = nodes;
}


}

#endif
