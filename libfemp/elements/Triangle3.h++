#ifndef FEMP_TRIANGLE3_HPP
#define FEMP_TRIANGLE3_HPP

#include <vector>

#include "TriangleFamily.h++"
#include "../Point.h++"



namespace fem
{

template <typename Scalar>
struct Triangle3
	: public TriangleFamily<Scalar>
{
public:
	Triangle3();
	~Triangle3()	{};

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
	int node_number() const	{ return 3; };
};


template<typename Scalar>
Triangle3<Scalar>::Triangle3()
{
	this->stiffness_degree = 1;
	this->domain_degree = 1;

	this->coordinates.resize(3);

	this->N.resize(3);
	this->dNdcsi.resize(3);
	this->dNdeta.resize(3);
	this->dNdzeta.resize(3);
}


template<typename Scalar>
std::vector<Scalar> & 
Triangle3<Scalar>::setN(const Point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & 
Triangle3<Scalar>::setN(const Scalar &csi, const Scalar &eta, const Scalar &)
{
	this->N[0] = 1-csi-eta;
	this->N[1] = csi;
	this->N[2] = eta;
	
	return this->N;
}


template<typename Scalar>
std::vector<Scalar> & 
Triangle3<Scalar>::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & 
Triangle3<Scalar>::setdNdcsi(const Scalar &, const Scalar &, const Scalar &)
{
	// this->dNdcsi
	this->dNdcsi[0] = -1;
	this->dNdcsi[1] = 1;
	this->dNdcsi[2] = 0;

	return this->dNdcsi;
}


template<typename Scalar>
std::vector<Scalar> & 
Triangle3<Scalar>::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & 
Triangle3<Scalar>::setdNdeta(const Scalar &, const Scalar &, const Scalar &)
{
	// this->dNdeta
	this->dNdeta[0] = -1;
	this->dNdeta[1] = 0;
	this->dNdeta[2] = 1;
	
	return this->dNdeta;
}


template<typename Scalar>
std::vector<Scalar> & 
Triangle3<Scalar>::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & 
Triangle3<Scalar>::setdNdzeta(const Scalar &, const Scalar &, const Scalar &)
{
	// this->dNdzeta
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;

	return this->dNdzeta;
}


template<typename Scalar>
std::vector<fem::Point> & 
Triangle3<Scalar>::setCoordinates()
{
	this->coordinates[0] = Point(	0,	0,	0	);
	this->coordinates[1] = Point(	1,	0,	0	);
	this->coordinates[2] = Point(	0,	1,	0	);

	return this->coordinates;
}


template<typename Scalar>
void
Triangle3<Scalar>::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 3)
	{
		throw FemException("wrong number of nodes");
	}

	this->nodes = nodes;
}


}

#endif
