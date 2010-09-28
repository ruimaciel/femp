#ifndef TETRAHEDRON10_HPP
#define TETRAHEDRON10_HPP

#include <vector>
#include <boost/tuple/tuple.hpp>

#include "BaseElement.h++"
#include "../point.h++"




namespace fem
{

template <typename T>
struct Tetrahedron10
	: public BaseElement<T>
{
	public:
		Tetrahedron10();
		~Tetrahedron10()	{};

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
Tetrahedron10<T>::Tetrahedron10()
{
	this->N.resize(10);
	this->dNdcsi.resize(10);
	this->dNdeta.resize(10);
	this->dNdzeta.resize(10);
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setN(const point &p)
{
	return this->setN(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setN(const T &csi, const T &eta, const T &zeta)
{
	//TODO finish this
	this->N[0] = 2*(-zeta-eta-csi+0.5)*(-zeta-eta-csi+1);
	this->N[1] = 2*(csi-0.5)*csi;
	this->N[2] = 2*(eta-0.5)*eta;
	this->N[3] = 2*(zeta-0.5)*zeta;
	this->N[4] = 4*csi*(-zeta-eta-csi+1);
	this->N[5] = 4*csi*eta;
	this->N[6] = 4*eta*(-zeta-eta-csi+1);
	this->N[7] = 4*(-zeta-eta-csi+1)*zeta;
	this->N[8] = 4*eta*zeta;
	this->N[9] = 4*csi*zeta;
	
	return this->N;
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdcsi(const point &p)
{
	return this->setdNdcsi(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdcsi(const T &csi, const T &eta, const T &zeta)
{
	//TODO finish this
	// this->dNdcsi
	this->dNdcsi[0] = -2*(-zeta-eta-csi+1)-2*(-zeta-eta-csi+0.5);
	this->dNdcsi[1] = 2*csi+2*(csi-0.5);
	this->dNdcsi[2] = 0;
	this->dNdcsi[3] = 0;
	this->dNdcsi[4] = 4*(-zeta-eta-csi+1)-4*csi;
	this->dNdcsi[5] = 4*eta;
	this->dNdcsi[6] = -4*eta;
	this->dNdcsi[7] = -4*zeta;
	this->dNdcsi[8] = 0;
	this->dNdcsi[9] = 4*zeta;

	return this->dNdcsi;
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdeta(const point &p)
{
	return this->setdNdeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdeta(const T &csi, const T &eta, const T &zeta)
{
	//TODO test this
	// this->dNdeta
	this->dNdeta[0] = -2*(-zeta-eta-csi+1)-2*(-zeta-eta-csi+0.5);
	this->dNdeta[1] = 0;
	this->dNdeta[2] = 2*eta+2*(eta-0.5);
	this->dNdeta[3] = 0;
	this->dNdeta[4] = -4*csi;
	this->dNdeta[5] = 4*csi;
	this->dNdeta[6] = 4*(-zeta-eta-csi+1)-4*eta;
	this->dNdeta[7] = -4*zeta;
	this->dNdeta[8] = 4*zeta;
	this->dNdeta[9] = 0;
	
	return this->dNdeta;
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdzeta(const point &p)
{
	return this->setdNdzeta(p.data[0], p.data[1], p.data[2]);
}


template<typename T>
std::vector<T> & Tetrahedron10<T>::setdNdzeta(const T &csi, const T &eta, const T &zeta)
{
	//TODO test this
	// this->dNdzeta
	this->dNdzeta[0] = -2*(-zeta-eta-csi+1)-2*(-zeta-eta-csi+0.5);
	this->dNdzeta[1] = 0;
	this->dNdzeta[2] = 0;
	this->dNdzeta[3] = 2*zeta+2*(zeta-0.5);
	this->dNdzeta[4] = -4*csi;
	this->dNdzeta[5] = 0;
	this->dNdzeta[6] = -4*eta;
	this->dNdzeta[7] = 4*(-zeta-eta-csi+1)-4*zeta;
	this->dNdzeta[8] = 4*eta;
	this->dNdzeta[9] = 4*csi;

	return this->dNdzeta;
}


template<typename T>
void Tetrahedron10<T>::generateQuadratureData()
{
	//TODO test this
	using namespace boost;

	std::vector<boost::tuple<fem::point, T> > ips;

	// Tetrahedron family, degree 1
	{
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(0.25,0.25,0.25), 1.0/6.0));
		this->ipwpl[1] = ips;
	}

	// Tetrahedron family, degree 2
	{
		ips.clear();

		ips.push_back(tuple<fem::point,double>(fem::point(0.58541019662496845446,0.13819660112501051518,0.13819660112501051518),1.0/(6*4)));
		ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.58541019662496845446,0.13819660112501051518),1.0/(6*4)));
		ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.13819660112501051518,0.58541019662496845446),1.0/(6*4)));
		ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.13819660112501051518,0.13819660112501051518),1.0/(6*4)));

		this->ipwpl[2] = ips;
	}

	// Tetrahedron family, degree 3
	{
		ips.clear();
		/*
		ips.push_back(tuple<fem::point,double>(fem::point(0, 0, 0), 1.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		*/

		/*
		   If [j<=0,info={{g1,g1,g1,g1},w1}; info[[1,i]]=1-3*g1];
		   If [j> 0,info={{g2,g2,g2,g2},w2}; info[[1,j]]=1-3*g2]];
		 */

		double g[2];
		double w[2];

		g[0]=(55-3*sqrt(17)+sqrt(1022-134*sqrt(17)))/196;
		g[1]=(55-3*sqrt(17)-sqrt(1022-134*sqrt(17)))/196;

		w[0]= (1.0/8 + sqrt((1715161837-406006699*sqrt(17))/23101)/3120)/6.0;
		w[1]= (1.0/8 - sqrt((1715161837-406006699*sqrt(17))/23101)/3120) /6.0;

		// 1 to 4
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[0], g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], 1-3*g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], 1-3*g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], g[0]), w[0] ));

		// 5 to 8
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[1], g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], 1-3*g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], 1-3*g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], g[1]), w[1] ));

		this->ipwpl[3] = ips;
	}

	// Tetrahedron family, degree 4
	{
		ips.clear();
		double g[3];
		double w[2];
		g[0]=0.09273525031089122640232391373703060;
		g[1]=0.31088591926330060979734573376345783;
		g[2]=0.45449629587435035050811947372066056;

		w[0] = (-1+6*g[1]*(2+g[1]*(-7+8*g[1]))+14*g[2]-60*g[1]*(3+4*g[1]* (-3+4*g[1]))*g[2]+4*(-7+30*g[1]*(3+4*g[1]*(-3+4*g[1])))*g[2]*g[2])/ (120*(g[0]-g[1])*(g[1]*(-3+8*g[1])+6*g[2]+8*g[1]*(-3+4*g[1])*g[2]-4* (3+4*g[1]*(-3+4*g[1]))*g[2]*g[2]+8*g[0]*g[0]*(1+12*g[1]* (-1+2*g[1])+4*g[2]-8*g[2]*g[2])+g[0]*(-3-96*g[1]*g[1]+24*g[2]*(-1+2*g[2])+ g[1]*(44+32*(1-2*g[2])*g[2]))));
		w[1] = (-1-20*(1+12*g[0]*(2*g[0]-1))*w[0]+20*g[2]*(2*g[2]-1)*(4*w[0]-1))/ (20*(1+12*g[1]*(2*g[1]-1)+4*g[2]-8*g[2]*g[2]));

		// 1 to 4
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[0], g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], 1-3*g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], 1-3*g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], g[0]), w[0] ));
		// 5 to 8
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[1], g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], 1-3*g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], 1-3*g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], g[1]), w[1] ));
		// 9 to 14
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/2-g[2], 1.0/2-g[2], g[3]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/2-g[2], g[3], 1.0/2-g[2]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/2-g[2], g[3], g[3]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[3], 1.0/2-g[2], 1.0/2-g[2]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[3], 1.0/2-g[2], g[3]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[3], g[3], 1.0/2-g[2]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		this->ipwpl[4] = ips;
	}

	// Tetrahedron family, degree 5
	{
		ips.clear();
		double g[3];
		double w[2];

		g[0]=(7-sqrt(15))/34; 	g[1]=7/17-g[0]; 	g[2]=(10-2*sqrt(15))/40;
		w[0]=(2665+14*sqrt(15))/37800;	w[1]=(2665-14*sqrt(15))/37800;

		// 1 to 4
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[0], g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], 1-3*g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], 1-3*g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], g[0]), w[0] ));

		// 5 to 8
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[1], g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], 1-3*g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], 1-3*g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], g[1] ), w[1] ));

		// 9 to 14
		ips.push_back(tuple<fem::point,double>(fem::point(0.5-g[2], 0.5 - g[2], g[2] ), 10.0/189));
		ips.push_back(tuple<fem::point,double>(fem::point(0.5-g[2], g[2], 0.5-g[2] ), 10.0/189));
		ips.push_back(tuple<fem::point,double>(fem::point(0.5-g[2], g[2], g[2] ), 10.0/189));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], 0.5-g[2], 0.5-g[2] ), 10.0/189));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], 0.5-g[2], g[2] ), 10.0/189));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], g[2], 0.5-g[2] ), 10.0/189));

		// 15
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/4, 1.0/4, 1.0/4 ), 16.0/135));

		this->ipwpl[5] = ips;
	}
}

}

#endif
