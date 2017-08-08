#ifndef FEMP_PRISM6_HPP
#define FEMP_PRISM6_HPP

#include <vector>

#include "PrismFamily.h++"
#include "../Point.h++"




namespace fem
{

template <typename Scalar>
struct Prism6
	: public PrismFamily<Scalar>
{
public:
	Prism6();
	~Prism6()	{};

	std::vector<fem::Point> & setCoordinates();

	std::vector<Scalar> & setN(const Point & p);

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
        int node_number() const	{ return 16; };
};


template<typename Scalar>
Prism6<Scalar>::Prism6()
	: PrismFamily<Scalar>()
{
	this->type = BaseElement<Scalar>::FE_PRISM6;
	this->stiffness_degree = 2;
	this->domain_degree = 2;

	this->coordinates.resize(6);

	this->N.resize(6);
	this->dNdcsi.resize(6);
	this->dNdeta.resize(6);
	this->dNdzeta.resize(6);
}


template<typename Scalar>
std::vector<Scalar> & Prism6<Scalar>::setN(const Point &p)
{
	const Scalar csi = p.x();
	const Scalar eta = p.y();
	const Scalar zeta = p.z();

	this->N[0] = (-eta-csi+1)*(1-zeta)/2;
	this->N[1] = csi*(1-zeta)/2;
	this->N[2] = eta*(1-zeta)/2;
	this->N[3] = (-eta-csi+1)*(zeta+1)/2;
	this->N[4] = csi*(zeta+1)/2;
	this->N[5] = eta*(zeta+1)/2;
	
	return this->N;
}


template<typename Scalar>
std::vector<Scalar> & Prism6<Scalar>::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Prism6<Scalar>::setdNdcsi(const Scalar &, const Scalar &, const Scalar &zeta)
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


template<typename Scalar>
std::vector<Scalar> & Prism6<Scalar>::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Prism6<Scalar>::setdNdeta(const Scalar &, const Scalar &, const Scalar &zeta)
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


template<typename Scalar>
std::vector<Scalar> & Prism6<Scalar>::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Prism6<Scalar>::setdNdzeta(const Scalar &csi, const Scalar &eta, const Scalar &)
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

template<typename Scalar>
std::vector<fem::Point> & Prism6<Scalar>::setCoordinates()
{
	this->coordinates[0] = Point(	0,	0,	-1	);
	this->coordinates[1] = Point(	1,	0,	-1	);
	this->coordinates[2] = Point(	0,	1,	-1	);
	this->coordinates[3] = Point(	0,	0,	1	);
	this->coordinates[4] = Point(	1,	0,	1	);
	this->coordinates[5] = Point(	0,	1,	1	);

	return this->coordinates;
}


template<typename Scalar>
void
Prism6<Scalar>::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 6)
	{
		throw FemException("wrong number of nodes");
	}
	this->nodes = nodes;
}

}

#endif
