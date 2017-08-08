#ifndef FEMP_FEMP_QUADRANGLE4_HPP
#define FEMP_FEMP_QUADRANGLE4_HPP

#include <vector>

#include "QuadrangleFamily.h++"
#include "../Point.h++"



namespace fem
{

template <typename Scalar>
struct Quadrangle4
	: public QuadrangleFamily<Scalar>
{
	public:
		Quadrangle4();
		~Quadrangle4()	{};

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
        int node_number() const	{ return 4; };

};


template<typename Scalar>
Quadrangle4<Scalar>::Quadrangle4()
{
	this->stiffness_degree = 1;
	this->domain_degree = 1;

	this->coordinates.resize(4);

	this->N.resize(4);
	this->dNdcsi.resize(4);
	this->dNdeta.resize(4);
	this->dNdzeta.resize(4);
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle4<Scalar>::setN(const Point &p)
{
	const Scalar csi = p.x();
	const Scalar eta = p.y();

	this->N[0] = (1-csi)*(1-eta)/4;
	this->N[1] = (1+csi)*(1-eta)/4;
	this->N[2] = (1+csi)*(1+eta)/4;
	this->N[3] = (1-csi)*(1+eta)/4;
	
	return this->N;
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle4<Scalar>::setdNdcsi(const Point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle4<Scalar>::setdNdcsi(const Scalar &, const Scalar &eta, const Scalar &)
{
	// this->dNdcsi
	this->dNdcsi[0] = (eta-1)/4;
	this->dNdcsi[1] = (1-eta)/4;
	this->dNdcsi[2] = (1+eta)/4;
	this->dNdcsi[3] = (-1-eta)/4;

	return this->dNdcsi;
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle4<Scalar>::setdNdeta(const Point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle4<Scalar>::setdNdeta(const Scalar &csi, const Scalar &, const Scalar &)
{
	// this->dNdeta
	this->dNdeta[0] = (csi-1)/4;
	this->dNdeta[1] = (-1-csi)/4;
	this->dNdeta[2] = (1+csi)/4;
	this->dNdeta[3] = (1-csi)/4;
	
	return this->dNdeta;
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle4<Scalar>::setdNdzeta(const Point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename Scalar>
std::vector<Scalar> & Quadrangle4<Scalar>::setdNdzeta(const Scalar &, const Scalar &, const Scalar &)
{
	// this->dNdzeta
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;
	this->dNdzeta[3] = 0;

	return this->dNdzeta;
}


template<typename Scalar>
std::vector<fem::Point> & Quadrangle4<Scalar>::setCoordinates()
{
	this->coordinates[0] = Point(	-0.5,	-0.5,	0	);
	this->coordinates[1] = Point(	0.5,	-0.5,	0	);
	this->coordinates[2] = Point(	0.5,	0.5,	0	);
	this->coordinates[3] = Point(	-0.5,	0.5,	0	);

	return this->coordinates;
}


template<typename Scalar>
void
Quadrangle4<Scalar>::set(std::vector<size_t> &nodes)
{
	if(nodes.size() == 4)
	{
		throw FemException("wrong number of nodes");
	}
	this->nodes = nodes;
}


}

#endif
