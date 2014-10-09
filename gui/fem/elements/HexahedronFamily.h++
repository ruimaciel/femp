#ifndef HEXAHEDRON_FAMILY_HPP
#define HEXAHEDRON_FAMILY_HPP


#include "BaseElement.h++"


namespace fem
{

template <typename T>
struct HexahedronFamily
	: public BaseElement<T>
{
	HexahedronFamily();

	enum BaseElement<T>::ElementFamily family() const;


protected:
	void generateQuadratureData();
};


template<typename T>
enum BaseElement<T>::ElementFamily
HexahedronFamily<T>::family() const
{
	return BaseElement<T>::EF_HEXAHEDRON;
}



template<typename T>
HexahedronFamily<T>::HexahedronFamily()
	: BaseElement<T>()
{
	generateQuadratureData();
}


template<typename T>
void HexahedronFamily<T>::generateQuadratureData()
{
	for(int d = 1; d <= 5; d++)
	{
		T x[d], w[d];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		this->template gauleg(x,w,d);

		// and now generate a list with those points
		for(int i = 0; i < d; i++)
		{
			for(int j = 0; j < d; j++)
			{
				for(int k = 0; k < d; k++)
				{
					this->ipwpl[d].push_back(boost::tuple<fem::point,T>(fem::point(x[i],x[j],x[k]), w[i]*w[j]*w[k]));
				}
			}
		}
	}
}

}

#endif
