#ifndef FEMP_QUADRANGLE9_HPP
#define FEMP_QUADRANGLE9_HPP

#include <vector>

#include "QuadrangleFamily.h++"
#include "../Point.h++"



namespace fem
{

template <typename Scalar>
struct Quadrangle9
	: public QuadrangleFamily<Scalar>
{
	public:
		Quadrangle9();
		~Quadrangle9()	{};

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
        int node_number() const	{ return 9; };
};


template<typename Scalar>
Quadrangle9<Scalar>::Quadrangle9()
{
	this->stiffness_degree = 1;
	this->domain_degree = 2;

	this->coordinates.resize(9);

	this->N.resize(9);
	this->dNdcsi.resize(9);
	this->dNdeta.resize(9);
	this->dNdzeta.resize(9);
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle9<Scalar>::setN(const Scalar &csi, const Scalar &eta, const Scalar &)
{
	//TODO test this
	this->N[0] = (csi-1)*csi*(eta-1)*eta/4;
	this->N[1] = csi*(csi+1)*(eta-1)*eta/4;
	this->N[2] = csi*(csi+1)*eta*(eta+1)/4;
	this->N[3] = (csi-1)*csi*eta*(eta+1)/4;
	this->N[4] = (1-csi)*(csi+1)*(eta-1)*eta/2;
	this->N[5] = csi*(csi+1)*(1-eta)*(eta+1)/2;
	this->N[6] = (1-csi)*(csi+1)*eta*(eta+1)/2;
	this->N[7] = (csi-1)*csi*(1-eta)*(eta+1)/2;
	this->N[8] = (1-csi)*(csi+1)*(1-eta)*(eta+1);
	return this->N;
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle9<Scalar>::setN(const Point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle9<Scalar>::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle9<Scalar>::setdNdcsi(const Scalar &csi, const Scalar &eta, const Scalar &)
{
	//TODO test this
	// this->dNdcsi
	this->dNdcsi[0] = csi*(eta-1)*eta/4+(csi-1)*(eta-1)*eta/4;
	this->dNdcsi[1] = (csi+1)*(eta-1)*eta/4+csi*(eta-1)*eta/4;
	this->dNdcsi[2] = (csi+1)*eta*(eta+1)/4+csi*eta*(eta+1)/4;
	this->dNdcsi[3] = csi*eta*(eta+1)/4+(csi-1)*eta*(eta+1)/4;
	this->dNdcsi[4] = (1-csi)*(eta-1)*eta/2-(csi+1)*(eta-1)*eta/2;
	this->dNdcsi[5] = (csi+1)*(1-eta)*(eta+1)/2+csi*(1-eta)*(eta+1)/2;
	this->dNdcsi[6] = (1-csi)*eta*(eta+1)/2-(csi+1)*eta*(eta+1)/2;
	this->dNdcsi[7] = csi*(1-eta)*(eta+1)/2+(csi-1)*(1-eta)*(eta+1)/2;
	this->dNdcsi[8] = (1-csi)*(1-eta)*(eta+1)-(csi+1)*(1-eta)*(eta+1);
	
	return this->dNdcsi;
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle9<Scalar>::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle9<Scalar>::setdNdeta(const Scalar &csi, const Scalar &eta, const Scalar &)
{
	//TODO test this
	// this->dNdeta
	this->dNdeta[0] = (csi-1)*csi*eta/4+(csi-1)*csi*(eta-1)/4;
	this->dNdeta[1] = csi*(csi+1)*eta/4+csi*(csi+1)*(eta-1)/4;
	this->dNdeta[2] = csi*(csi+1)*(eta+1)/4+csi*(csi+1)*eta/4;
	this->dNdeta[3] = (csi-1)*csi*(eta+1)/4+(csi-1)*csi*eta/4;
	this->dNdeta[4] = (1-csi)*(csi+1)*eta/2+(1-csi)*(csi+1)*(eta-1)/2;
	this->dNdeta[5] = csi*(csi+1)*(1-eta)/2-csi*(csi+1)*(eta+1)/2;
	this->dNdeta[6] = (1-csi)*(csi+1)*(eta+1)/2+(1-csi)*(csi+1)*eta/2;
	this->dNdeta[7] = (csi-1)*csi*(1-eta)/2-(csi-1)*csi*(eta+1)/2;
	this->dNdeta[8] = (1-csi)*(csi+1)*(1-eta)-(1-csi)*(csi+1)*(eta+1);
	
	return this->dNdeta;
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle9<Scalar>::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle9<Scalar>::setdNdzeta(const Scalar &, const Scalar &, const Scalar &)
{
	//TODO test this
	// this->dNdzeta
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;
	this->dNdzeta[3] = 0;
	this->dNdzeta[4] = 0;
	this->dNdzeta[5] = 0;
	this->dNdzeta[6] = 0;
	this->dNdzeta[7] = 0;
	this->dNdzeta[8] = 0;

	return this->dNdzeta;
}

template<typename Scalar>
std::vector<fem::Point> & Quadrangle9<Scalar>::setCoordinates()
{
	this->coordinates[0] = Point(	-0.5,	-0.5,	0	);
	this->coordinates[1] = Point(	0.5,	-0.5,	0	);
	this->coordinates[2] = Point(	0.5,	0.5,	0	);
	this->coordinates[3] = Point(	-0.5,	0.5,	0	);
	this->coordinates[4] = Point(	0,	-0.5,	0	);
	this->coordinates[5] = Point(	0.5,	0,	0	);
	this->coordinates[6] = Point(	0,	0.5,	0	);
	this->coordinates[7] = Point(	-0.5,	0,	0	);
	this->coordinates[8] = Point(	0,	0,	0	);

	return this->coordinates;
}


template<typename Scalar>
void
Quadrangle9<Scalar>::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 9)
	{
		throw FemException("wrong number of nodes");
	}

	this->nodes = nodes;
}


}

#endif
