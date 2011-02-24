#ifndef TETRAHEDRON_FAMILY_HPP
#define TETRAHEDRON_FAMILY_HPP


#include "BaseElement.h++"


namespace fem
{

template <typename T>
struct TetrahedronFamily
	: public BaseElement<T>
{
	TetrahedronFamily();

	protected:
		void generateQuadratureData();
};


template<typename T>
TetrahedronFamily<T>::TetrahedronFamily()
	: BaseElement<T>()
{
	generateQuadratureData();
}



template<typename T>
void TetrahedronFamily<T>::generateQuadratureData()
{
	//TODO test this
	using namespace boost;

	std::vector<boost::tuple<fem::point, T> > ips;	//TODO remove ips as a temporary

	// Tetrahedron family, degree 1
	{
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(0.25,0.25,0.25), 1.0/6.0));
		this->ipwpl[1] = ips;
	}

	// Tetrahedron family, degree 2
	{
		ips.clear();

		ips.push_back(tuple<fem::point,double>(fem::point(0.58541019662496845446,0.13819660112501051518,0.13819660112501051518),1.0/(6*4)));
		ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.58541019662496845446,0.13819660112501051518),1.0/(6*4)));
		ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.13819660112501051518,0.58541019662496845446),1.0/(6*4)));
		ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.13819660112501051518,0.13819660112501051518),1.0/(6*4)));

		this->ipwpl[2] = ips;
	}

	// Tetrahedron family, degree 3
	{
		ips.clear();

		double g[2];
		double w[2];

		g[0]=(55-3*sqrt(17)+sqrt(1022-134*sqrt(17)))/196;
		g[1]=(55-3*sqrt(17)-sqrt(1022-134*sqrt(17)))/196;

		w[0]= (1.0/8 + sqrt((1715161837-406006699*sqrt(17))/23101)/3120)/6.0;
		w[1]= (1.0/8 - sqrt((1715161837-406006699*sqrt(17))/23101)/3120) /6.0;

		// 1 to 4
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[0], g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], 1-3*g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], 1-3*g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], g[0]), w[0] ));

		// 5 to 8
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[1], g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], 1-3*g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], 1-3*g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], g[1]), w[1] ));

		this->ipwpl[3] = ips;
	}

	// Tetrahedron family, degree 4
	{
		ips.clear();
		double g[3];
		double w[2];
		g[0]=0.09273525031089122640232391373703060;
		g[1]=0.31088591926330060979734573376345783;
		g[2]=0.45449629587435035050811947372066056;

		w[0] = (-1+6*g[1]*(2+g[1]*(-7+8*g[1]))+14*g[2]-60*g[1]*(3+4*g[1]* (-3+4*g[1]))*g[2]+4*(-7+30*g[1]*(3+4*g[1]*(-3+4*g[1])))*g[2]*g[2])/ (120*(g[0]-g[1])*(g[1]*(-3+8*g[1])+6*g[2]+8*g[1]*(-3+4*g[1])*g[2]-4* (3+4*g[1]*(-3+4*g[1]))*g[2]*g[2]+8*g[0]*g[0]*(1+12*g[1]* (-1+2*g[1])+4*g[2]-8*g[2]*g[2])+g[0]*(-3-96*g[1]*g[1]+24*g[2]*(-1+2*g[2])+ g[1]*(44+32*(1-2*g[2])*g[2]))));
		w[1] = (-1-20*(1+12*g[0]*(2*g[0]-1))*w[0]+20*g[2]*(2*g[2]-1)*(4*w[0]-1))/ (20*(1+12*g[1]*(2*g[1]-1)+4*g[2]-8*g[2]*g[2]));

		// 1 to 4
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[0], g[0], g[0]), w[0]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], 1-3*g[0], g[0]), w[0]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], 1-3*g[0]), w[0]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], g[0]), w[0]/6.0 ));
		// 5 to 8
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[1], g[1], g[1]), w[1]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], 1-3*g[1], g[1]), w[1]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], 1-3*g[1]), w[1]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], g[1]), w[1]/6.0 ));
		// 9 to 14
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/2-g[2], 1.0/2-g[2], g[2]), (1.0/6.0 - 2*(w[0]+w[1])/3)/6.0  ));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/2-g[2], g[2], 1.0/2-g[2]), (1.0/6.0 - 2*(w[0]+w[1])/3)/6.0  ));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/2-g[2], g[2], g[2]), (1.0/6.0 - 2*(w[0]+w[1])/3)/6.0  ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], 1.0/2-g[2], 1.0/2-g[2]), (1.0/6.0 - 2*(w[0]+w[1])/3)/6.0  ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], 1.0/2-g[2], g[2]), (1.0/6.0 - 2*(w[0]+w[1])/3)/6.0  ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], g[2], 1.0/2-g[2]), (1.0/6.0 - 2*(w[0]+w[1])/3)/6.0  ));
		this->ipwpl[4] = ips;
	}

	// Tetrahedron family, degree 5
	{
		ips.clear();
		double g[3];
		double w[2];

		g[0]=(7-sqrt(15))/34; 	g[1]=7/17-g[0]; 	g[2]=(10-2*sqrt(15))/40;
		w[0]=(2665+14*sqrt(15))/(37800);	w[1]=(2665-14*sqrt(15))/(37800);

		// 1 to 4
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[0], g[0], g[0]), w[0]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], 1-3*g[0], g[0]), w[0]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], 1-3*g[0]), w[0]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], g[0]), w[0]/6.0 ));

		// 5 to 8
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[1], g[1], g[1]), w[1]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], 1-3*g[1], g[1]), w[1]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], 1-3*g[1]), w[1]/6.0 ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], g[1] ), w[1]/6.0 ));

		// 9 to 14
		ips.push_back(tuple<fem::point,double>(fem::point(0.5-g[2], 0.5 - g[2], g[2] ), 10.0/(6.0*189)) );
		ips.push_back(tuple<fem::point,double>(fem::point(0.5-g[2], g[2], 0.5-g[2] ), 10.0/(6*189)) );
		ips.push_back(tuple<fem::point,double>(fem::point(0.5-g[2], g[2], g[2] ), 10.0/(6*189)));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], 0.5-g[2], 0.5-g[2] ), 10.0/(6*189)));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], 0.5-g[2], g[2] ), 10.0/(6*189)));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], g[2], 0.5-g[2] ), 10.0/(6*189)));

		// 15
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/4, 1.0/4, 1.0/4 ), 16.0/(6*135)));

		this->ipwpl[5] = ips;
	}
}

}

#endif
