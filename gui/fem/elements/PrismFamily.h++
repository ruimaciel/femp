#ifndef PRISM_FAMILY_HPP
#define PRISM_FAMILY_HPP

#include <iostream>

#include "BaseElement.h++"
#include "../point.h++"


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

	using namespace boost;
	std::vector<tuple<point, double> > ips;

	// Prism family, level 1 (tri degree 1 * line Gauss degree 1)
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<point,double>(point(1.0/3,1.0/3, 0), 0.5*1*2));
		this->ipwpl[1] = ips;
	}

	// triangle family, level 2: (tri degree 2 * line gauss degree 2)
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<point,double>(point(	2.0/3,	1.0/6,	-1.0/sqrt(3) ), 0.5*(1.0/3)*1));
		ips.push_back(tuple<point,double>(point(	1.0/6,	2.0/3,	-1.0/sqrt(3) ), 0.5*(1.0/3)*1));
		ips.push_back(tuple<point,double>(point(	1.0/6,	1.0/6,	-1.0/sqrt(3) ), 0.5*(1.0/3)*1));

		ips.push_back(tuple<point,double>(point(	2.0/3,	1.0/6,	1.0/sqrt(3) ), 0.5*(1.0/3)*1));
		ips.push_back(tuple<point,double>(point(	1.0/6,	2.0/3,	1.0/sqrt(3) ), 0.5*(1.0/3)*1));
		ips.push_back(tuple<point,double>(point(	1.0/6,	1.0/6,	1.0/sqrt(3) ), 0.5*(1.0/3)*1));

		this->ipwpl[2] = ips;
	}

	// triangle family, level 3: ( tri degree 4 (6 points) * line Gauss degree 5)
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
			ips.push_back(tuple<point,double>(point(1-2*g1, g1,	x[i]), 0.5*(620+sqrt(213125-53320*sqrt(10)))*w[i]/(3720)) );
			ips.push_back(tuple<point,double>(point(g1, 1-2*g1,	x[i]), 0.5*(620+sqrt(213125-53320*sqrt(10)))*w[i]/(3720)) );
			ips.push_back(tuple<point,double>(point(g1, g1,	x[i]), 0.5*(620+sqrt(213125-53320*sqrt(10)))*w[i]/(3720)) );

			ips.push_back(tuple<point,double>(point(1-2*g2, g2, 	x[i]), 0.5*(620-sqrt(213125-53320*sqrt(10)))*w[i]/(3720)) );
			ips.push_back(tuple<point,double>(point(g2, 1-2*g2, 	x[i]), 0.5*(620-sqrt(213125-53320*sqrt(10)))*w[i]/(3720)) );
			ips.push_back(tuple<point,double>(point(g2, g2, 	x[i]), 0.5*(620-sqrt(213125-53320*sqrt(10)))*w[i]/(3720)) );
		}

		this->ipwpl[3] = ips;
	}

	// triangle family, level 4: (tri degree 5 (7  points) * line gauss degree 5)
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
			ips.push_back(tuple<point,double>(point(1.0-2*g1, g1,	x[i]), (155.0-sqrt(15))*w[i]/(2*1200)));
			ips.push_back(tuple<point,double>(point(g1, 1.0-2*g1, x[i]), (155.0-sqrt(15))*w[i]/(2*1200)));
			ips.push_back(tuple<point,double>(point(g1, g1, 	x[i]), (155.0-sqrt(15))*w[i]/(2*1200)));

			ips.push_back(tuple<point,double>(point(1.0-2*g2, g2, x[i]), (155.0+sqrt(15))*w[i]/(2*1200)));
			ips.push_back(tuple<point,double>(point(g2, 1.0-2*g2, x[i]), (155.0+sqrt(15))*w[i]/(2*1200)));
			ips.push_back(tuple<point,double>(point(g2, g2, 	x[i]), (155.0+sqrt(15))*w[i]/(2*1200)));

			ips.push_back(tuple<point,double>(point(1.0/3, 1.0/3, x[i]), 9.0*w[i]/(2*40)));
		}

		this->ipwpl[4] = ips;
	}

	// triangle family, level 5: (tri degree 6 (12  points) * line gauss degree 7)
	{
		T x[4], w[4];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		gauleg(x,w,4);

		//TODO needs testing
		ips.clear();
	
		for(int i = 0; i < 4; i++)
		{
			/*
			ips.push_back(tuple<point,double>(point(1.0-2*g1, g1,	x[i]), (155.0-sqrt(15))*w[i]/(2*1200)));
			ips.push_back(tuple<point,double>(point(g1, 1.0-2*g1, x[i]), (155.0-sqrt(15))*w[i]/(2*1200)));
			ips.push_back(tuple<point,double>(point(g1, g1, 	x[i]), (155.0-sqrt(15))*w[i]/(2*1200)));

			ips.push_back(tuple<point,double>(point(1.0-2*g2, g2, x[i]), (155.0+sqrt(15))*w[i]/(2*1200)));
			ips.push_back(tuple<point,double>(point(g2, 1.0-2*g2, x[i]), (155.0+sqrt(15))*w[i]/(2*1200)));
			ips.push_back(tuple<point,double>(point(g2, g2, 	x[i]), (155.0+sqrt(15))*w[i]/(2*1200)));

			ips.push_back(tuple<point,double>(point(1.0/3, 1.0/3, x[i]), 9.0*w[i]/(2*40)));
			*/
			ips.push_back(tuple<point,double>(point(0.873821971016996, 0.063089014491502, x[i]), 0.5*w[i]*0.050844906370207));
			ips.push_back(tuple<point,double>(point(0.063089014491502, 0.873821971016996, x[i]), 0.5*w[i]*0.050844906370207));
			ips.push_back(tuple<point,double>(point(0.063089014491502, 0.063089014491502, x[i]), 0.5*w[i]*0.050844906370207));
			ips.push_back(tuple<point,double>(point(0.501426509658179, 0.249286745170910, x[i]), 0.5*w[i]*0.116786275726379));
			ips.push_back(tuple<point,double>(point(0.249286745170910, 0.501426509658179, x[i]), 0.5*w[i]*0.116786275726379));
			ips.push_back(tuple<point,double>(point(0.249286745170910, 0.249286745170910, x[i]), 0.5*w[i]*0.116786275726379));
			ips.push_back(tuple<point,double>(point(0.636502499121399, 0.310352451033785, x[i]), 0.5*w[i]*0.082851075618374));
			ips.push_back(tuple<point,double>(point(0.310352451033785, 0.636502499121399, x[i]), 0.5*w[i]*0.082851075618374));
			ips.push_back(tuple<point,double>(point(0.636502499121399, 0.053145049844816, x[i]), 0.5*w[i]*0.082851075618374));
			ips.push_back(tuple<point,double>(point(0.053145049844816, 0.636502499121399, x[i]), 0.5*w[i]*0.082851075618374));
			ips.push_back(tuple<point,double>(point(0.310352451033785, 0.053145049844816, x[i]), 0.5*w[i]*0.082851075618374));
			ips.push_back(tuple<point,double>(point(0.053145049844816, 0.310352451033785, x[i]), 0.5*w[i]*0.082851075618374));
		}

		this->ipwpl[5] = ips;
	}
}

}



#endif
