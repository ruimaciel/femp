#ifndef FEMP_QUADRANGLE_FAMILY_HPP
#define FEMP_QUADRANGLE_FAMILY_HPP


#include "BaseElement.h++"


namespace fem
{

template <typename Scalar>
struct QuadrangleFamily
	: public BaseElement<Scalar>
{
	QuadrangleFamily();

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
QuadrangleFamily<Scalar>::family() const
{
	return BaseElement<Scalar>::EF_QUADRILATERAL;
}


template <typename Scalar>
QuadrangleFamily<Scalar>::QuadrangleFamily()
	: BaseElement<Scalar>()
{
	generateQuadratureData();
};


template<typename Scalar>
void QuadrangleFamily<Scalar>::generateQuadratureData()
{
	using namespace boost;
	std::vector<tuple<fem::Point, Scalar> > ips;
	
	for(int d = 1; d < 6; d++)
	{
		ips.clear();
		Scalar x[d], w[d];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		this->template gauleg(x,w,d);	// this causes an error with gcc4.7 http://gcc.gnu.org/gcc-4.7/porting_to.html

		// and now generate a list with those points
		for(int i = 0; i < d; i++)
		{
			for(int j = 0; j < d; j++)
			{
				ips.push_back(tuple<fem::Point,Scalar>(fem::Point(x[i],x[j],0), w[i]*w[j]));
			}
		}
		this->ipwpl[d] = ips;
	}
}

}

#endif
