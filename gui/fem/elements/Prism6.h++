#ifndef PRISM6_HPP
#define PRISM6_HPP

#include <vector>
#include <boost/tuple/tuple.hpp>

#include "BaseElement.h++"
#include "../point.h++"




namespace fem
{

template <typename T>
struct Prism6
	: public BaseElement<T>
{
	public:
		Prism6();
		~Prism6()	{};

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
Prism6<T>::Prism6()
{
	this->N.resize(6);
	this->dNdcsi.resize(6);
	this->dNdeta.resize(6);
	this->dNdzeta.resize(6);
}


template<typename T>
std::vector<T> & Prism6<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism6<T>::setN(const T &csi, const T &eta, const T &zeta)
{
	//TODO finish this
	this->N[0] = (-eta-csi+1)*(1-zeta)/2;
	this->N[1] = csi*(1-zeta)/2;
	this->N[2] = eta*(1-zeta)/2;
	this->N[3] = (-eta-csi+1)*(zeta+1)/2;
	this->N[4] = csi*(zeta+1)/2;
	this->N[5] = eta*(zeta+1)/2;
	
	return this->N;
}


template<typename T>
std::vector<T> & Prism6<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism6<T>::setdNdcsi(const T &, const T &, const T &zeta)
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


template<typename T>
std::vector<T> & Prism6<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism6<T>::setdNdeta(const T &, const T &, const T &zeta)
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


template<typename T>
std::vector<T> & Prism6<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Prism6<T>::setdNdzeta(const T &csi, const T &eta, const T &)
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

template<typename T>
void Prism6<T>::generateQuadratureData()
{
	//TODO finish implement this

	using namespace boost;
	std::vector<tuple<fem::point, double> > ips;

	// Prism family, level 1 (tri degree 1 * line Gauss degree 1)
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3,1.0/3, 0), 0.5*2));
		this->ipwpl[1] = ips;
	}

	// triangle family, level 2: (tri degree 2 * line gauss degree 2)
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(	2.0/3,	1.0/6,	-1.0/sqrt(3) ), 1.0/6));
		ips.push_back(tuple<fem::point,double>(fem::point(	1.0/6,	2.0/3,	-1.0/sqrt(3) ), 1.0/6));
		ips.push_back(tuple<fem::point,double>(fem::point(	1.0/6,	1.0/6,	-1.0/sqrt(3) ), 1.0/6));

		ips.push_back(tuple<fem::point,double>(fem::point(	2.0/3,	1.0/6,	1.0/sqrt(3) ), 1.0/6));
		ips.push_back(tuple<fem::point,double>(fem::point(	1.0/6,	2.0/3,	1.0/sqrt(3) ), 1.0/6));
		ips.push_back(tuple<fem::point,double>(fem::point(	1.0/6,	1.0/6,	1.0/sqrt(3) ), 1.0/6));

		this->ipwpl[2] = ips;
	}

	// triangle family, level 3: ( tri degree 4 * line Gauss degree 5)
	{
		T x[3], w[3];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		gauleg(x,w,3);

		//TODO needs testing
		ips.clear();
		double g1=(8-sqrt(10.0)+sqrt(38.0-44.0*sqrt(2.0/5)))/18;
		double g2=(8-sqrt(10.0)-sqrt(38.0-44.0*sqrt(2.0/5)))/18;

		for(int i = 0; i < 3; i++)
		{
			ips.push_back(tuple<fem::point,double>(fem::point(1-2*g1, g1,	x[i]), (620+sqrt(213125-53320*sqrt(10)))*w[i]/(2*3720)) );
			ips.push_back(tuple<fem::point,double>(fem::point(g1, 1-2*g1,	x[i]), (620+sqrt(213125-53320*sqrt(10)))*w[i]/(2*3720)) );
			ips.push_back(tuple<fem::point,double>(fem::point(g1, g1,	x[i]), (620+sqrt(213125-53320*sqrt(10)))*w[i]/(2*3720)) );

			ips.push_back(tuple<fem::point,double>(fem::point(1-2*g2, g2, 	x[i]), (620-sqrt(213125-53320*sqrt(10)))*w[i]/(2*3720)) );
			ips.push_back(tuple<fem::point,double>(fem::point(g2, 1-2*g2, 	x[i]), (620-sqrt(213125-53320*sqrt(10)))*w[i]/(2*3720)) );
			ips.push_back(tuple<fem::point,double>(fem::point(g2, g2, 	x[i]), (620-sqrt(213125-53320*sqrt(10)))*w[i]/(2*3720)) );
		}

		this->ipwpl[3] = ips;
	}

	// triangle family, level 4: 7  points, degree 5
	{
		T x[3], w[3];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		gauleg(x,w,3);

		//TODO needs testing
		ips.clear();
	
		double g1=(6.0-sqrt(15))/21; 
		double g2=(6.0+sqrt(15))/21;

		for(int i = 0; i < 3; i++)
		{
		ips.push_back(tuple<fem::point,double>(fem::point(1.0-2*g1, g1,	x[i]), (155.0-sqrt(15))*w[i]/(2*1200)));
		ips.push_back(tuple<fem::point,double>(fem::point(g1, 1.0-2*g1, x[i]), (155.0-sqrt(15))*w[i]/(2*1200)));
		ips.push_back(tuple<fem::point,double>(fem::point(g1, g1, 	x[i]), (155.0-sqrt(15))*w[i]/(2*1200)));

		ips.push_back(tuple<fem::point,double>(fem::point(1.0-2*g2, g2, x[i]), (155.0+sqrt(15))*w[i]/(2*1200)));
		ips.push_back(tuple<fem::point,double>(fem::point(g2, 1.0-2*g2, x[i]), (155.0+sqrt(15))*w[i]/(2*1200)));
		ips.push_back(tuple<fem::point,double>(fem::point(g2, g2, 	x[i]), (155.0+sqrt(15))*w[i]/(2*1200)));

		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, x[i]), 9.0*w[i]/(2*40)));
		}

		this->ipwpl[4] = ips;
	}
}

}

#endif
