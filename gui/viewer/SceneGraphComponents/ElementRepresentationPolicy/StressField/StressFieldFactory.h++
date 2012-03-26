#ifndef STRESS_FIELD_FACTORY_H
#define STRESS_FIELD_FACTORY_H

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <Eigen/LU>

#include "StressFieldRepresentation.h++"
#include "../../../../fem/Model.h++"
#include "../../../../fem/Element.h++"
#include "../../../../fem/AnalysisResult.h++"

#include "../../../../fem/elements/BaseElement.h++"
#include "../../../../fem/elements/Tetrahedron4.h++"
#include "../../../../fem/elements/Tetrahedron10.h++"
#include "../../../../fem/elements/Hexahedron8.h++"
#include "../../../../fem/elements/Hexahedron20.h++"
#include "../../../../fem/elements/Hexahedron27.h++"
#include "../../../../fem/elements/Prism6.h++"
#include "../../../../fem/elements/Prism15.h++"
#include "../../../../fem/elements/Prism18.h++"


namespace StressFieldRepresentation
{

/** 
Builder pattern to generate policies for the representation of each element
**/
class StressFieldFactory
{
protected:
	float *m_diameter;
	fem::Model *m_model;
	fem::AnalysisResult<double> *m_result;
	float m_max, m_min;	// maximum and minimum value from any stress

	// temp values for dsyevj3
	double A[3][3];
	double eig_vec[3][3];
	double eig_val[3];

	// temp variables for operator()
	Eigen::Matrix3d 	Dg, invDg;
	Eigen::Vector3d 	dNdcsi;


	fem::Tetrahedron4<double>       m_tetrahedron4;
	fem::Tetrahedron10<double>      m_tetrahedron10;
	fem::Hexahedron8<double>        m_hexahedron8;
	fem::Hexahedron20<double>       m_hexahedron20;
	fem::Hexahedron27<double>       m_hexahedron27;
	fem::Prism6<double>     	m_prism6;
	fem::Prism15<double>    	m_prism15;
	fem::Prism18<double>    	m_prism18;

public:
	StressFieldFactory(float &diameter, fem::Model &model, fem::AnalysisResult<double> &result);

	/**
	The factory functor
	**/
	StressFieldRepresentation operator() (fem::Element const &element) ;

	/**
	Returns the maximum and minimum principal stress
	**/
	float max() const;
	float min() const;

protected:
	/** 
	Taken from: 
	http://www.mpi-hd.mpg.de/personalhomes/globes/3x3/

	Article:
	Efficient numerical diagonalization of hermitian 3x3 matrices
	http://arxiv.org/abs/physics/0610206
	**/
	int dsyevj3(double A[3][3], double Q[3][3], double w[3]) const;
};

}

#endif

