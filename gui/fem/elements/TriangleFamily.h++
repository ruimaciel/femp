#ifndef TRIANGLE_FAMILY_HPP
#define TRIANGLE_FAMILY_HPP


#include "BaseElement.h++"


namespace fem
{

template <typename T>
struct TriangleFamily
	: public BaseElement<T>
{
	TriangleFamily();

	protected:
		void generateQuadratureData();
};


template<typename T>
TriangleFamily<T>::TriangleFamily()
	: BaseElement<T>()
{
	generateQuadratureData();
}



template<typename T>
void TriangleFamily<T>::generateQuadratureData()
{
	using namespace boost;
	std::vector<tuple<fem::point, T> > ips;

	// triangle family, level 1
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::point,T>(fem::point(1.0/3,1.0/3,1.0/3), 0.5));
		this->ipwpl[1] = ips;
	}

	// triangle family, level 2: 3 points, degree 2
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::point,T>(fem::point(	2.0/3,	1.0/6,	1.0/6), 1.0/6));
		ips.push_back(tuple<fem::point,T>(fem::point(	1.0/6,	2.0/3,	1.0/6), 1.0/6));
		ips.push_back(tuple<fem::point,T>(fem::point(	1.0/6,	1.0/6,	2.0/3), 1.0/6));
		this->ipwpl[2] = ips;
	}

	// triangle family, level 3: 6 points, degree 4
	{
		//TODO needs testing
		ips.clear();
		T g1=(8-sqrt(10.0)+sqrt(38.0-44.0*sqrt(2.0/5)))/18;
		T g2=(8-sqrt(10.0)-sqrt(38.0-44.0*sqrt(2.0/5)))/18;

		ips.push_back(tuple<fem::point,T>(fem::point(1-2*g1, g1, g1), (620+sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::point,T>(fem::point(g1, 1-2*g1, g1), (620+sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::point,T>(fem::point(g1, g1, 1-2*g1), (620+sqrt(213125-53320*sqrt(10)))/(2*3720)) );

		ips.push_back(tuple<fem::point,T>(fem::point(1-2*g2, g2, g2), (620-sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::point,T>(fem::point(g2, 1-2*g2, g2), (620-sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::point,T>(fem::point(g2, g2, 1-2*g2), (620-sqrt(213125-53320*sqrt(10)))/(2*3720)) );

		this->ipwpl[3] = ips;
	}

	// triangle family, level 4: 7  points, degree 5
	{
		//TODO needs testing
		ips.clear();
	
		T g1=(6.0-sqrt(15))/21; 
		T g2=(6.0+sqrt(15))/21;

		ips.push_back(tuple<fem::point,T>(fem::point(1.0-2*g1, g1, g1), (155.0-sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::point,T>(fem::point(g1, 1.0-2*g1, g1), (155.0-sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::point,T>(fem::point(g1, g1, 1.0-2*g1), (155.0-sqrt(15))/(2*1200)));

		ips.push_back(tuple<fem::point,T>(fem::point(1.0-2*g2, g2, g2), (155.0+sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::point,T>(fem::point(g2, 1.0-2*g2, g2), (155.0+sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::point,T>(fem::point(g2, g2, 1.0-2*g2), (155.0+sqrt(15))/(2*1200)));

		ips.push_back(tuple<fem::point,T>(fem::point(1.0/3, 1.0/3, 1.0/3), 9.0/(2*40)));

		this->ipwpl[4] = ips;
	}
}

}

#endif
