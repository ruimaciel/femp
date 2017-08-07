#ifndef FEMP_HEXAHEDRON_FAMILY_HPP
#define FEMP_HEXAHEDRON_FAMILY_HPP


#include "BaseElement.h++"


namespace fem
{

template <typename Scalar>
struct HexahedronFamily
	: public BaseElement<Scalar>
{
	HexahedronFamily();

	enum BaseElement<Scalar>::ElementFamily family() const;

	/**
	 * Returns the total number of degrees of freedom
	 **/
	virtual unsigned int getDofAmount() const	{ return 3*this->node_number(); }

protected:
	void generateQuadratureData();
};


template<typename Scalar>
enum BaseElement<Scalar>::ElementFamily
HexahedronFamily<Scalar>::family() const
{
	return BaseElement<Scalar>::EF_HEXAHEDRON;
}



template<typename Scalar>
HexahedronFamily<Scalar>::HexahedronFamily()
	: BaseElement<Scalar>()
{
	generateQuadratureData();
}


template<typename Scalar>
void HexahedronFamily<Scalar>::generateQuadratureData()
{
	for(int d = 1; d <= 5; d++)
	{
		Scalar x[d], w[d];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		this->template gauleg(x,w,d);

		// and now generate a list with those points
		for(int i = 0; i < d; i++)
		{
			for(int j = 0; j < d; j++)
			{
				for(int k = 0; k < d; k++)
				{
					this->ipwpl[d].push_back(boost::tuple<fem::Point,Scalar>(fem::Point(x[i],x[j],x[k]), w[i]*w[j]*w[k]));
				}
			}
		}
	}
}

}

#endif
