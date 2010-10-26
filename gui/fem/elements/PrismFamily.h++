#ifndef PRISM_FAMILY_HPP
#define PRISM_FAMILY_HPP

#include <iostream>

#include "BaseElement.h++"


namespace fem
{

template <typename T>
struct PrismFamily
	: public BaseElement<T>
{
	PrismFamily();

	protected:
		void generateQuadratureData();
};


template<typename T>
PrismFamily<T>::PrismFamily()
	: BaseElement<T>()
{
	generateQuadratureData();
}


template<typename T>
void PrismFamily<T>::generateQuadratureData()
{
	//TODO test implement this
	std::cout << "PrismFamily" << std::endl;

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
