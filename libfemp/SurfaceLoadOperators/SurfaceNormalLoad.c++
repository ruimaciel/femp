#include "SurfaceNormalLoad.h++"

#include <iostream>

#include "../Point3D.h++"


namespace fem
{


SurfaceNormalLoad::SurfaceNormalLoad()
{
	this->m_magnitude = 1.0f;
	this->element = nullptr;
}


void
SurfaceNormalLoad::setLoadMagnitude(float const &magnitude)
{
	this->m_magnitude = magnitude;
}


void
SurfaceNormalLoad::operator() (fem::SurfaceLoad &surface_load, fem::Model &model)
{
	fem::Point3D f;
	fem::Point3D dPdcsi, dPdeta;

	// set the element
	switch(surface_load.type)
	{
		case Element::FE_TRIANGLE3:
			element = &m_tri3;
			surface_load.surface_forces.resize(3);
			break;

		case Element::FE_TRIANGLE6:
			element = &m_tri6;
			surface_load.surface_forces.resize(6);
			break;

		case Element::FE_QUADRANGLE4:
			element = &m_quad4;
			surface_load.surface_forces.resize(4);
			break;

		case Element::FE_QUADRANGLE8:
			element = &m_quad8;
			surface_load.surface_forces.resize(8);
			break;

		case Element::FE_QUADRANGLE9:
			element = &m_quad9;
			surface_load.surface_forces.resize(9);
			break;

		default:	// if this part was reached then something is broken
			std::cerr << "SurfaceNormalLoad(): invalid surface load type" << std::endl;
			element = nullptr;
			return;
			break;
	}

	/**
	for each node that defines the surface, define a normal vector and
	set the force accordingly
	**/
	using namespace std;
	auto coordinates = element->getLocalCoordinates();
	for(unsigned int i = 0; i < surface_load.nodes.size(); i++)
	{
		cout << "node " << i << " at " << coordinates[i] << "\n";

		auto dNdcsi = element->getdNdcsi(coordinates[i]);
		auto dNdeta = element->getdNdeta(coordinates[i]);
		dPdcsi.zero();
		dPdeta.zero();

		for(unsigned int n = 0; n < surface_load.nodes.size(); n++)
		{
			fem::Point3D &p = model.node_list[ surface_load.nodes[n]];
			cout << "Point : " << p << "\n";
			dPdcsi += dNdcsi[n]*p;
			dPdeta += dNdeta[n]*p;
		}

		f = cross_product(dPdcsi, dPdeta);
		cout << "cross( " << dPdcsi << "," << dPdeta << ")\n";

		f.normalize();
		f *= m_magnitude;

		// set the force
		surface_load.surface_forces[i] = f;

		cout << "force: " << f << endl;
	}
}


}	// namespace fem


