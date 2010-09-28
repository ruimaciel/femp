#ifndef TRIANGLE3_HPP
#define TRIANGLE3_HPP

#include <vector>
#include <boost/tuple/tuple.hpp>

#include "BaseElement.h++"
#include "../point.h++"




namespace fem
{

template <typename T>
struct Triangle3
	: public BaseElement<T>
{
	public:
		Triangle3();
		~Triangle3()	{};

		std::vector<T> & setN(const point & p);
		std::vector<T> & setN(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdcsi(const point &p);
		std::vector<T> & setdNdcsi(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdeta(const point &p);
		std::vector<T> & setdNdeta(const T &csi, const T &eta, const T &zeta = 0);

		std::vector<T> & setdNdzeta(const point &p);
		std::vector<T> & setdNdzeta(const T &csi, const T &eta, const T &zeta = 0);

	protected:
		/*
		Generates the lists of integration points/weights for this type of element
		*/
		void generateQuadratureData();
};


template<typename T>
Triangle3<T>::Triangle3()
{
	this->N.resize(3);
	this->dNdcsi.resize(3);
	this->dNdeta.resize(3);
	this->dNdzeta.resize(3);
}


template<typename T>
std::vector<T> & Triangle3<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Triangle3<T>::setN(const T &csi, const T &eta, const T &)
{
	this->N[0] = 1-csi-eta;
	this->N[1] = csi;
	this->N[2] = eta;
	
	return this->N;
}


template<typename T>
std::vector<T> & Triangle3<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Triangle3<T>::setdNdcsi(const T &, const T &, const T &)
{
	// this->dNdcsi
	this->dNdcsi[0] = -1;
	this->dNdcsi[1] = 1;
	this->dNdcsi[2] = 0;

	return this->dNdcsi;
}


template<typename T>
std::vector<T> & Triangle3<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Triangle3<T>::setdNdeta(const T &, const T &, const T &)
{
	// this->dNdeta
	this->dNdeta[0] = -1;
	this->dNdeta[1] = 0;
	this->dNdeta[2] = 1;
	
	return this->dNdeta;
}


template<typename T>
std::vector<T> & Triangle3<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Triangle3<T>::setdNdzeta(const T &, const T &, const T &)
{
	// this->dNdzeta
	this->dNdzeta[0] = 0;
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;

	return this->dNdzeta;
}


template<typename T>
void Triangle3<T>::generateQuadratureData()
{
	using namespace boost;
	std::vector<tuple<fem::point, double> > ips;

	// triangle family, level 1
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3,1.0/3,1.0/3), 1.0));
		this->ipwpl[1] = ips;
	}

	// triangle family, level 2: 3 points, degree 2
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(	2.0/3,	1.0/6,	1.0/6), 1.0/3));
		ips.push_back(tuple<fem::point,double>(fem::point(	1.0/6,	2.0/3,	1.0/6), 1.0/3));
		ips.push_back(tuple<fem::point,double>(fem::point(	1.0/6,	1.0/6,	2.0/3), 1.0/3));
		this->ipwpl[2] = ips;
	}

	// triangle family, level 3: 6 points, degree 4
	{
		//TODO needs testing
		ips.clear();
		double g1=(8-sqrt(10.0)+sqrt(38.0-44.0*sqrt(2.0/5)))/18;
		double g2=(8-sqrt(10.0)-sqrt(38.0-44.0*sqrt(2.0/5)))/18;

		ips.push_back(tuple<fem::point,double>(fem::point(1-2*g1, g1, g1), (620+sqrt(213125-53320*sqrt(10)))/3720) );
		ips.push_back(tuple<fem::point,double>(fem::point(g1, 1-2*g1, g1), (620+sqrt(213125-53320*sqrt(10)))/3720) );
		ips.push_back(tuple<fem::point,double>(fem::point(g1, g1, 1-2*g1), (620+sqrt(213125-53320*sqrt(10)))/3720) );

		ips.push_back(tuple<fem::point,double>(fem::point(1-2*g2, g2, g2), (620-sqrt(213125-53320*sqrt(10)))/3720) );
		ips.push_back(tuple<fem::point,double>(fem::point(g2, 1-2*g2, g2), (620-sqrt(213125-53320*sqrt(10)))/3720) );
		ips.push_back(tuple<fem::point,double>(fem::point(g2, g2, 1-2*g2), (620-sqrt(213125-53320*sqrt(10)))/3720) );

		this->ipwpl[3] = ips;
	}

	// triangle family, level 4: 7  points, degree 5
	{
		//TODO needs testing
		ips.clear();
	
		double g1=(6.0-sqrt(15))/21; 
		double g2=(6.0+sqrt(15))/21;

		ips.push_back(tuple<fem::point,double>(fem::point(1.0-2*g1, g1, g1), (155.0-sqrt(15))/1200));
		ips.push_back(tuple<fem::point,double>(fem::point(g1, 1.0-2*g1, g1), (155.0-sqrt(15))/1200));
		ips.push_back(tuple<fem::point,double>(fem::point(g1, g1, 1.0-2*g1), (155.0-sqrt(15))/1200));

		ips.push_back(tuple<fem::point,double>(fem::point(1.0-2*g2, g2, g2), (155.0+sqrt(15))/1200));
		ips.push_back(tuple<fem::point,double>(fem::point(g2, 1.0-2*g2, g2), (155.0+sqrt(15))/1200));
		ips.push_back(tuple<fem::point,double>(fem::point(g2, g2, 1.0-2*g2), (155.0+sqrt(15))/1200));

		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3), 9.0/40));

		this->ipwpl[4] = ips;
	}

	//TODO add 5th degree
}


}

#endif
