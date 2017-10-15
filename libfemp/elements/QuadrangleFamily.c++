#include "QuadrangleFamily.h++"


#include <libfemp/FemException.h++>


namespace fem
{


QuadrangleFamily::QuadrangleFamily()
	: BaseElement()
{
	generateQuadratureData();
};


enum BaseElement::ElementFamily
QuadrangleFamily::family() const
{
	return BaseElement::EF_QUADRILATERAL;
}


std::vector<boost::tuple<fem::Point, double> >
QuadrangleFamily::getStiffnessQuadratureRule()
{
	return this->ipwpl[stiffness_degree];
}


std::vector<boost::tuple<fem::Point, double> >
QuadrangleFamily::getDomainQuadratureRule()
{
	return this->ipwpl[domain_degree];
}


void
QuadrangleFamily::generateQuadratureData()
{
	using namespace boost;
	std::vector<tuple<fem::Point, double> > ips;
	
	for(int d = 1; d < 6; d++)
	{
		ips.clear();
		double x[d], w[d];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		this->gauleg(x,w,d);	// this causes an error with gcc4.7 http://gcc.gnu.org/gcc-4.7/porting_to.html

		// and now generate a list with those points
		for(int i = 0; i < d; i++)
		{
			for(int j = 0; j < d; j++)
			{
				ips.push_back(tuple<fem::Point,double>(fem::Point(x[i],x[j],0), w[i]*w[j]));
			}
		}
		this->ipwpl[d] = ips;
	}
}


}	// namespace fem

