#ifndef TRIANGLE10_HPP
#define TRIANGLE10_HPP

#include <vector>

#include "BaseElement.h++"
#include "../point.h++"




namespace fem
{

template <typename T>
struct Triangle10
	: public BaseElement<T>
{
	public:
		Triangle10();
		~Triangle10()	{};

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
Triangle10<T>::Triangle10()
{
	this->N.resize(10);
	this->dNdcsi.resize(10);
	this->dNdeta.resize(10);
	this->dNdzeta.resize(10);
}


template<typename T>
std::vector<T> & Triangle10<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Triangle10<T>::setN(const T &csi, const T &eta, const T &zeta)
{
	//TODO test this
	this->N[0] = 4.5*(-eta-csi+1.0/3)*(-eta-csi+2.0/3)*(-eta-csi+1);
	this->N[1] = 4.5*(csi-2.0/3)*(csi-1.0/3)*csi;
	this->N[2] = 4.5*(eta-2.0/3)*(eta-1.0/3)*eta;
	this->N[3] = 13.5*csi*(-eta-csi+2.0/3)*(-eta-csi+1);
	this->N[4] = 13.5*(csi-1.0/3)*csi*(-eta-csi+1);
	this->N[5] = 13.5*(csi-1.0/3)*csi*eta;
	this->N[6] = 13.5*csi*(eta-1.0/3)*eta;
	this->N[7] = 13.5*(-eta-csi+1)*(eta-1.0/3)*eta;
	this->N[8] = 13.5*(-eta-csi+2.0/3)*(-eta-csi+1)*eta;
	this->N[9] = 27*csi*(-eta-csi+1)*eta;

	return this->N;
}


template<typename T>
std::vector<T> & Triangle10<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Triangle10<T>::setdNdcsi(const T &csi, const T &eta, const T &)
{
	//TODO test this
	// this->dNdcsi
	this->N[0] = -(27*eta*eta+(54*csi-36)*eta+27*csi*csi-36*csi+11)/2.0;
	this->N[1] = (27*csi*csi-18*csi+2)/2.0;
	this->N[2] = 0;
	this->N[3] = (27*eta*eta+(108*csi-45)*eta+81*csi*csi-90*csi+18)/2.0;
	this->N[4] = -((54*csi-9)*eta+81*csi*csi-72*csi+9)/2.0;
	this->N[5] = (54*csi-9)*eta/2.0;
	this->N[6] = (27*eta*eta-9*eta)/2.0;
	this->N[7] = -(27*eta*eta-9*eta)/2.0;
	this->N[8] = (54*eta*eta+(54*csi-45)*eta)/2.0;
	this->N[9] = (27-54*csi)*eta-27*eta*eta;

	return this->dNdcsi;
}


template<typename T>
std::vector<T> & Triangle10<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Triangle10<T>::setdNdeta(const T &csi, const T &eta, const T &)
{
	//TODO test this
	// this->dNdeta
	this->N[0] = -(27*eta*eta+(54*csi-36)*eta+27*csi*csi-36*csi+11)/2.0;
	this->N[1] = 0;
	this->N[2] = (27*eta*eta-18*eta+2)/2.0;
	this->N[3] = (54*csi*eta+54*csi*csi-45*csi)/2.0;
	this->N[4] = -(27*csi*csi-9*csi)/2.0;
	this->N[5] = (27*csi*csi-9*csi)/2.0;
	this->N[6] = (54*csi*eta-9*csi)/2.0;
	this->N[7] = -(81*eta*eta+(54*csi-72)*eta-9*csi+9)/2.0;
	this->N[8] = (81*eta*eta+(108*csi-90)*eta+27*csi*csi-45*csi+18)/2.0;
	this->N[9] = -54*csi*eta-27*csi*csi+27*csi;

	return this->dNdeta;
}


template<typename T>
std::vector<T> & Triangle10<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Triangle10<T>::setdNdzeta(const T &, const T &, const T &)
{
	//TODO finish this
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
	this->dNdzeta[9] = 0;

	return this->dNdzeta;
}


template<typename T>
void Triangle10<T>::generateQuadratureData()
{
	using namespace boost;
	std::vector<tuple<fem::point, double> > ips;

	// triangle family, level 1
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3,1.0/3,1.0/3), 0.5));
		this->ipwpl[1] = ips;
	}

	// triangle family, level 2: 3 points, degree 2
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(	2.0/3,	1.0/6,	1.0/6), 1.0/6));
		ips.push_back(tuple<fem::point,double>(fem::point(	1.0/6,	2.0/3,	1.0/6), 1.0/6));
		ips.push_back(tuple<fem::point,double>(fem::point(	1.0/6,	1.0/6,	2.0/3), 1.0/6));
		this->ipwpl[2] = ips;
	}

	// triangle family, level 3: 6 points, degree 4
	{
		//TODO needs testing
		ips.clear();
		double g1=(8-sqrt(10.0)+sqrt(38.0-44.0*sqrt(2.0/5)))/18;
		double g2=(8-sqrt(10.0)-sqrt(38.0-44.0*sqrt(2.0/5)))/18;

		ips.push_back(tuple<fem::point,double>(fem::point(1-2*g1, g1, g1), (620+sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::point,double>(fem::point(g1, 1-2*g1, g1), (620+sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::point,double>(fem::point(g1, g1, 1-2*g1), (620+sqrt(213125-53320*sqrt(10)))/(2*3720)) );

		ips.push_back(tuple<fem::point,double>(fem::point(1-2*g2, g2, g2), (620-sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::point,double>(fem::point(g2, 1-2*g2, g2), (620-sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::point,double>(fem::point(g2, g2, 1-2*g2), (620-sqrt(213125-53320*sqrt(10)))/(2*3720)) );

		this->ipwpl[3] = ips;
	}

	// triangle family, level 4: 7  points, degree 5
	{
		//TODO needs testing
		ips.clear();
	
		double g1=(6.0-sqrt(15))/21; 
		double g2=(6.0+sqrt(15))/21;

		ips.push_back(tuple<fem::point,double>(fem::point(1.0-2*g1, g1, g1), (155.0-sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::point,double>(fem::point(g1, 1.0-2*g1, g1), (155.0-sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::point,double>(fem::point(g1, g1, 1.0-2*g1), (155.0-sqrt(15))/(2*1200)));

		ips.push_back(tuple<fem::point,double>(fem::point(1.0-2*g2, g2, g2), (155.0+sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::point,double>(fem::point(g2, 1.0-2*g2, g2), (155.0+sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::point,double>(fem::point(g2, g2, 1.0-2*g2), (155.0+sqrt(15))/(2*1200)));

		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3), 9.0/(2*40) ));

		this->ipwpl[4] = ips;
	}

	//TODO add 5th degree
}

}

#endif
