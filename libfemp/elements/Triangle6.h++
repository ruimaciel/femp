#ifndef FEMP_TRIANGLE6_HPP
#define FEMP_TRIANGLE6_HPP

#include <vector>

#include "TriangleFamily.h++"
#include "../Point.h++"



namespace fem
{

template <typename Scalar>
struct Triangle6
	: public TriangleFamily<Scalar>
{
	public:
		Triangle6();
		~Triangle6()	{};

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
	int node_number() const	{ return 6; };
};


template<typename Scalar>
Triangle6<Scalar>::Triangle6()
{
	this->stiffness_degree = 1;
	this->domain_degree = 2;

	this->coordinates.resize(6);

	this->N.resize(6);
	this->dNdcsi.resize(6);
	this->dNdeta.resize(6);
	this->dNdzeta.resize(6);
}


template<typename Scalar>
std::vector<Scalar> & Triangle6<Scalar>::setN(const Point &p)
{
	const Scalar csi = p.x();
	const Scalar eta = p.y();

	this->N[0] = (2*(1-eta-csi)-1)*(1-eta-csi);
	this->N[1] = csi*(2*csi-1);
	this->N[2] = eta*(2*eta-1);
	this->N[3] = 4*csi*(1-eta-csi);
	this->N[4] = 4*csi*eta;
	this->N[5] = 4*(1-eta-csi)*eta;
	
	return this->N;
}


template<typename Scalar>
std::vector<Scalar> & Triangle6<Scalar>::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Triangle6<Scalar>::setdNdcsi(const Scalar &csi, const Scalar &eta, const Scalar &)
{
	//TODO test this
	// this->dNdcsi
	this->dNdcsi[0] = 1.0-4*(1-eta-csi);
	this->dNdcsi[1] = 4*csi-1;
	this->dNdcsi[2] = 0;
	this->dNdcsi[3] = 4*(1-eta-csi)-4*csi;
	this->dNdcsi[4] = 4*eta;
	this->dNdcsi[5] = -4*eta;

	return this->dNdcsi;
}


template<typename Scalar>
std::vector<Scalar> & Triangle6<Scalar>::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Triangle6<Scalar>::setdNdeta(const Scalar &csi, const Scalar &eta, const Scalar &)
{
	//TODO test this
	// this->dNdeta
	this->dNdeta[0] = 1-4*(1-eta-csi);
	this->dNdeta[1] = 0;
	this->dNdeta[2] = 4*eta-1;
	this->dNdeta[3] = -4*csi;
	this->dNdeta[4] = 4*csi;
	this->dNdeta[5] = 4*(1-eta-csi)-4*eta;
	
	return this->dNdeta;
}


template<typename Scalar>
std::vector<Scalar> & Triangle6<Scalar>::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Triangle6<Scalar>::setdNdzeta(const Scalar &, const Scalar &, const Scalar &)
{
	//TODO test this
	// this->dNdzeta
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;
	this->dNdzeta[3] = 0;
	this->dNdzeta[4] = 0;
	this->dNdzeta[5] = 0;

	return this->dNdzeta;
}


template<typename Scalar>
std::vector<fem::Point> & Triangle6<Scalar>::setCoordinates()
{
	//TODO finish
	this->coordinates[0] = Point(	0,	0,	0	);
	this->coordinates[1] = Point(	1,	0,	0	);
	this->coordinates[2] = Point(	0,	1,	0	);
	this->coordinates[3] = Point(	0.5f,	0,	0	);
	this->coordinates[4] = Point(	0.5f,	0.5f,	0	);
	this->coordinates[5] = Point(	0,	0.5f,	0	);

	return this->coordinates;
}


template<typename Scalar>
void
Triangle6<Scalar>::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 6)
	{
		throw FemException("wrong number of nodes");
	}

	this->nodes = nodes;
}


}

#endif
