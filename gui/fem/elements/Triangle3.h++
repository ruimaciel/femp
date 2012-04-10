#ifndef TRIANGLE3_HPP
#define TRIANGLE3_HPP

#include <vector>

#include "TriangleFamily.h++"
#include "../point.h++"



namespace fem
{

template <typename T>
struct Triangle3
	: public TriangleFamily<T>
{
public:
	Triangle3();
	~Triangle3()	{};

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
Triangle3<T>::setN(const point &p)
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
Triangle3<T>::setdNdcsi(const point &p)
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
Triangle3<T>::setdNdeta(const point &p)
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
Triangle3<T>::setdNdzeta(const point &p)
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
std::vector<fem::point> & 
Triangle3<T>::setCoordinates()
{
	//TODO finish
	return this->coordinates;
}


template<typename T>
enum BaseElement<T>::Error 
Triangle3<T>::set(std::vector<size_t> &nodes)
{
	assert(nodes.size() == 3);
	this->nodes = nodes;
	return BaseElement<T>::ERR_OK;
}


}

#endif
