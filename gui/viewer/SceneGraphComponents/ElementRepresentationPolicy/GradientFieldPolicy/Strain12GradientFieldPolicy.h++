#ifndef STRAIN12_GRADIENT_FIELD_POLICY_H
#define STRAIN12_GRADIENT_FIELD_POLICY_H

#include "GradientFieldPolicy.h++"

#include <Eigen/Core>	// for the Dg matrix
#include <Eigen/LU>	// for the computeInverse() method

#include "../../../../fem/elements/BaseElement.h++"
#include "../../../../fem/elements/Tetrahedron4.h++"
#include "../../../../fem/elements/Tetrahedron10.h++"
#include "../../../../fem/elements/Hexahedron8.h++"
#include "../../../../fem/elements/Hexahedron20.h++"
#include "../../../../fem/elements/Hexahedron27.h++"
#include "../../../../fem/elements/Prism6.h++"
#include "../../../../fem/elements/Prism15.h++"
#include "../../../../fem/elements/Prism18.h++"


/**
Strain12 gradient field policy
**/
class Strain12GradientFieldPolicy
	: public GradientFieldPolicy
{
protected:
	// list of supported elements
	//TODO fem::PrismFamily has problems with template float
	fem::Tetrahedron4<double>	m_tetrahedron4;
	fem::Tetrahedron10<double>	m_tetrahedron10;
	fem::Hexahedron8<double>	m_hexahedron8;
	fem::Hexahedron20<double>	m_hexahedron20;
	fem::Hexahedron27<double>	m_hexahedron27;
	fem::Prism6<double>	m_prism6;
	fem::Prism15<double>	m_prism15;
	fem::Prism18<double>	m_prism18;

	Eigen::Matrix3d Dg, invDg;
	Eigen::Vector3d dNdcsi;

public:
	Strain12GradientFieldPolicy();

	void calculateGradientValues (fem::Element &element);
};


#endif
