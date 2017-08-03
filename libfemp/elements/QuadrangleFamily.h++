#ifndef FEMP_QUADRANGLE_FAMILY_HPP
#define FEMP_QUADRANGLE_FAMILY_HPP


#include "BaseElement.h++"


namespace fem
{

template <typename T>
struct QuadrangleFamily
	: public BaseElement<T>
{
	QuadrangleFamily();

	enum BaseElement<T>::ElementFamily family() const;

	/**
	 * Returns the total number of degrees of freedom
	 **/
	virtual unsigned int getDofAmount() const	{ return 3*this->node_number(); }

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
	std::vector<tuple<fem::Point, T> > ips;
	
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
				ips.push_back(tuple<fem::Point,T>(fem::Point(x[i],x[j],0), w[i]*w[j]));
			}
		}
		this->ipwpl[d] = ips;
	}
}

}

#endif
