#include "ConcentricLoad.h++"

#include <iostream>

#include "../Point.h++"


namespace fem
{


ConcentricLoad::ConcentricLoad()
{
	this->element = nullptr;
	this->m_magnitude = 1.0f;
	this->m_center = fem::Point(0,0,0);
}


void 
ConcentricLoad::setLoadMagnitude(float const &magnitude)
{
	this->m_magnitude = magnitude;
}


void 
ConcentricLoad::setConvergencePoint(fem::Point const &center)
{
	this->m_center = center;
}


void 
ConcentricLoad::operator() (fem::SurfaceLoad &surface_load, fem::Model &model)
{
	fem::Point f;
	fem::Point dPdcsi, dPdeta;

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
			std::cerr << "ConcentricLoad(): invalid surface load type" << std::endl;
			element = nullptr;
			return;
			break;
	}

	/**
	for each node that defines the surface, define a normal vector and
	set the force accordingly
	**/
	element->setCoordinates();	// sets the values for the local coordinates that mark each node
	for(unsigned int i = 0; i < surface_load.nodes.size(); i++)
	{
		f = model.node_list[surface_load.nodes[i]] - m_center;
		f.normalize();
		f *= m_magnitude;

		// set the force
		surface_load.surface_forces[i] = f;
	}
}


}	// namespace fem



