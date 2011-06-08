#ifndef QUADRANGLE_FAMILY_HPP
#define QUADRANGLE_FAMILY_HPP


#include "BaseElement.h++"
#include "../point.h++"


namespace fem
{

template <typename T>
struct QuadrangleFamily
	: public BaseElement<T>
{
	QuadrangleFamily();

	protected:
		void generateQuadratureData();
};


template <typename T>
QuadrangleFamily<T>::QuadrangleFamily()
	: BaseElement<T>()
{
	generateQuadratureData();
};


template<typename T>
void QuadrangleFamily<T>::generateQuadratureData()
{
	using namespace boost;
	std::vector<tuple<point, double> > ips;
	
	for(int d = 1; d < 6; d++)
	{
		ips.clear();
		T x[d], w[d];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		gauleg(x,w,d);

		// and now generate a list with those points
		for(int i = 0; i < d; i++)
		{
			for(int j = 0; j < d; j++)
			{
				ips.push_back(tuple<point,T>(point(x[i],x[j],0), w[i]*w[j]));
			}
		}
		this->ipwpl[d] = ips;
	}
}

}

#endif
