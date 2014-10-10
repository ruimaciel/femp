#ifndef STRAIN11_GRADIENT_FIELD_POLICY_H
#define STRAIN11_GRADIENT_FIELD_POLICY_H

#include "GradientFieldPolicy.h++"

#include <Eigen/Core>	// for the Dg matrix
#include <Eigen/LU>	// for the computeInverse() method

#include <libfemp/elements/BaseElement.h++>
#include <libfemp/elements/Tetrahedron4.h++>
#include <libfemp/elements/Tetrahedron10.h++>
#include <libfemp/elements/Hexahedron8.h++>
#include <libfemp/elements/Hexahedron20.h++>
#include <libfemp/elements/Hexahedron27.h++>
#include <libfemp/elements/Prism6.h++>
#include <libfemp/elements/Prism15.h++>
#include <libfemp/elements/Prism18.h++>


/**
Strain11 gradient field policy
**/
class Strain11GradientFieldPolicy
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
	Strain11GradientFieldPolicy();

protected:
	float val(fem::element_ref_t const &ref, gradient_index_t const &p) const;
	float maxVal(fem::ResultsRanges<double> const &) const;
	float minVal(fem::ResultsRanges<double> const &) const;

};


#endif

