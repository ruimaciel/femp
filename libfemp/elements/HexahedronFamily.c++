#include "HexahedronFamily.h++"



#include <libfemp/FemException.h++>

namespace fem
{


HexahedronFamily::HexahedronFamily()
	: BaseElement()
{
	generateQuadratureData();
}


enum BaseElement::ElementFamily
HexahedronFamily::family() const
{
	return BaseElement::EF_HEXAHEDRON;
}


std::vector<boost::tuple<fem::Point3D, double> > 
HexahedronFamily::getStiffnessQuadratureRule()
{ 
	return this->ipwpl[stiffness_degree];
}


std::vector<boost::tuple<fem::Point3D, double> > 
HexahedronFamily::getDomainQuadratureRule()
{ 
	return this->ipwpl[domain_degree];
}


void
HexahedronFamily::generateQuadratureData()
{
	for(int d = 1; d <= 5; d++)
	{
		double x[d], w[d];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		this->gauleg(x,w,d);

		// and now generate a list with those points
		for(int i = 0; i < d; i++)
		{
			for(int j = 0; j < d; j++)
			{
				for(int k = 0; k < d; k++)
				{
					this->ipwpl[d].push_back(boost::tuple<fem::Point3D,double>(fem::Point3D(x[i],x[j],x[k]), w[i]*w[j]*w[k]));
				}
			}
		}
	}
}


}	// namespace fem

