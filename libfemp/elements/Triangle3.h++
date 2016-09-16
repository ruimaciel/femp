#ifndef FEMP_TRIANGLE3_HPP
#define FEMP_TRIANGLE3_HPP

#include <vector>

#include "TriangleFamily.h++"
#include "../Point.h++"



namespace fem
{

template <typename T>
struct Triangle3
	: public TriangleFamily<T>
{
public:
	Triangle3();
	~Triangle3()	{};

	std::vector<fem::Point> & setCoordinates();

	std::vector<T> & setN(const Point & p);
	std::vector<T> & setN(const T &csi, const T &eta, const T &zeta = 0);

	std::vector<T> & setdNdcsi(const Point &p);
	std::vector<T> & setdNdcsi(const T &csi, const T &eta, const T &zeta = 0);

	std::vector<T> & setdNdeta(const Point &p);
	std::vector<T> & setdNdeta(const T &csi, const T &eta, const T &zeta = 0);

	std::vector<T> & setdNdzeta(const Point &p);
	std::vector<T> & setdNdzeta(const T &csi, const T &eta, const T &zeta = 0);

public: // merging with fem::Element
	void set(std::vector<size_t> &nodes);

	/** 
	return the number of nodes that an element of this particular type has
	@return the number of nodes
	**/
	int node_number() const	{ return 3; };
};


template<typename T>
Triangle3<T>::Triangle3()
{
	this->stiffness_degree = 1;
	this->domain_degree = 1;

	this->coordinates.resize(3);

	this->N.resize(3);
	this->dNdcsi.resize(3);
	this->dNdeta.resize(3);
	this->dNdzeta.resize(3);
}


template<typename T>
std::vector<T> & 
Triangle3<T>::setN(const Point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Triangle3<T>::setN(const T &csi, const T &eta, const T &)
{
	this->N[0] = 1-csi-eta;
	this->N[1] = csi;
	this->N[2] = eta;
	
	return this->N;
}


template<typename T>
std::vector<T> & 
Triangle3<T>::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Triangle3<T>::setdNdcsi(const T &, const T &, const T &)
{
	// this->dNdcsi
	this->dNdcsi[0] = -1;
	this->dNdcsi[1] = 1;
	this->dNdcsi[2] = 0;

	return this->dNdcsi;
}


template<typename T>
std::vector<T> & 
Triangle3<T>::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Triangle3<T>::setdNdeta(const T &, const T &, const T &)
{
	// this->dNdeta
	this->dNdeta[0] = -1;
	this->dNdeta[1] = 0;
	this->dNdeta[2] = 1;
	
	return this->dNdeta;
}


template<typename T>
std::vector<T> & 
Triangle3<T>::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & 
Triangle3<T>::setdNdzeta(const T &, const T &, const T &)
{
	// this->dNdzeta
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;

	return this->dNdzeta;
}


template<typename T>
std::vector<fem::Point> & 
Triangle3<T>::setCoordinates()
{
	this->coordinates[0] = Point(	0,	0,	0	);
	this->coordinates[1] = Point(	1,	0,	0	);
	this->coordinates[2] = Point(	0,	1,	0	);

	return this->coordinates;
}


template<typename T>
void
Triangle3<T>::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 3)
	{
		throw FemException("wrong number of nodes");
	}

	this->nodes = nodes;
}


}

#endif
