#ifndef QUADRANGLE_FAMILY_HPP
#define QUADRANGLE_FAMILY_HPP


#include "BaseElement.h++"


namespace fem
{

template <typename T>
struct QuadrangleFamily
	: public BaseElement<T>
{
	QuadrangleFamily();

	enum BaseElement<T>::ElementFamily family() const;


protected:
	void generateQuadratureData();
};


template<typename T>
enum BaseElement<T>::ElementFamily
QuadrangleFamily<T>::family() const
{
	return BaseElement<T>::EF_QUADRILATERAL;
}


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
	std::vector<tuple<fem::point, T> > ips;
	
	for(int d = 1; d < 6; d++)
	{
		ips.clear();
		T x[d], w[d];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		this->template gauleg(x,w,d);	// this causes an error with gcc4.7 http://gcc.gnu.org/gcc-4.7/porting_to.html

		// and now generate a list with those points
		for(int i = 0; i < d; i++)
		{
			for(int j = 0; j < d; j++)
			{
				ips.push_back(tuple<fem::point,T>(fem::point(x[i],x[j],0), w[i]*w[j]));
			}
		}
		this->ipwpl[d] = ips;
	}
}

}

#endif
