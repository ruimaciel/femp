#include "TriangleFamily.h++"


#include <libfemp/FemException.h++>


namespace fem
{


TriangleFamily::TriangleFamily()
{
	generateQuadratureData();
}


enum BaseElement::ElementFamily
TriangleFamily::family() const
{
	return BaseElement::EF_TRIANGLE;
}


std::vector<boost::tuple<fem::Point3D, double> >
TriangleFamily::getStiffnessQuadratureRule()
{
	return this->ipwpl[stiffness_degree];
}


std::vector<boost::tuple<fem::Point3D, double> >
TriangleFamily::getDomainQuadratureRule()
{
	return this->ipwpl[domain_degree];
}


void
TriangleFamily::generateQuadratureData()
{
	using namespace boost;
	std::vector<tuple<fem::Point3D, double> > ips;

	// triangle family, level 1
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(1.0/3,1.0/3,1.0/3), 0.5));
		this->ipwpl[1] = ips;
	}

	// triangle family, level 2: 3 points, degree 2
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(	2.0/3,	1.0/6,	1.0/6), 1.0/6));
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(	1.0/6,	2.0/3,	1.0/6), 1.0/6));
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(	1.0/6,	1.0/6,	2.0/3), 1.0/6));
		this->ipwpl[2] = ips;
	}

	// triangle family, level 3: 6 points, degree 4
	{
		//TODO needs testing
		ips.clear();
		double g1=(8-sqrt(10.0)+sqrt(38.0-44.0*sqrt(2.0/5)))/18;
		double g2=(8-sqrt(10.0)-sqrt(38.0-44.0*sqrt(2.0/5)))/18;

		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(1-2*g1, g1, g1), (620+sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(g1, 1-2*g1, g1), (620+sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(g1, g1, 1-2*g1), (620+sqrt(213125-53320*sqrt(10)))/(2*3720)) );

		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(1-2*g2, g2, g2), (620-sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(g2, 1-2*g2, g2), (620-sqrt(213125-53320*sqrt(10)))/(2*3720)) );
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(g2, g2, 1-2*g2), (620-sqrt(213125-53320*sqrt(10)))/(2*3720)) );

		this->ipwpl[3] = ips;
	}

	// triangle family, level 4: 7  points, degree 5
	{
		//TODO needs testing
		ips.clear();
	
		double g1=(6.0-sqrt(15))/21; 
		double g2=(6.0+sqrt(15))/21;

		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(1.0-2*g1, g1, g1), (155.0-sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(g1, 1.0-2*g1, g1), (155.0-sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(g1, g1, 1.0-2*g1), (155.0-sqrt(15))/(2*1200)));

		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(1.0-2*g2, g2, g2), (155.0+sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(g2, 1.0-2*g2, g2), (155.0+sqrt(15))/(2*1200)));
		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(g2, g2, 1.0-2*g2), (155.0+sqrt(15))/(2*1200)));

		ips.push_back(tuple<fem::Point3D,double>(fem::Point3D(1.0/3, 1.0/3, 1.0/3), 9.0/(2*40)));

		this->ipwpl[4] = ips;
	}
}

}

