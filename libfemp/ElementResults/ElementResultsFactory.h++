#ifndef FEMP_ELEMENTRESULTSFACTORY_HPP
#define FEMP_ELEMENTRESULTSFACTORY_HPP

#include <cmath>	// sqrt
#include <iostream>	// cout

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <Eigen/LU>

#include <libfemp/Element.h++>
#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/FemException.h++>
#include "ElementResults.h++"

#include <libfemp/elements/BaseElement.h++>
#include <libfemp/elements/Tetrahedron4.h++>
#include <libfemp/elements/Tetrahedron10.h++>
#include <libfemp/elements/Hexahedron8.h++>
#include <libfemp/elements/Hexahedron20.h++>
#include <libfemp/elements/Hexahedron27.h++>
#include <libfemp/elements/Prism6.h++>
#include <libfemp/elements/Prism15.h++>
#include <libfemp/elements/Prism18.h++>


namespace fem
{

/**
Factory pattern which creates ElementResults objects based on a given element
**/
class ElementResultsFactory
{
protected:
	Model *m_model;
	AnalysisResult 	*m_analysis_result;

	fem::Tetrahedron4<double>       m_tetrahedron4;
	fem::Tetrahedron10<double>      m_tetrahedron10;
	fem::Hexahedron8<double>        m_hexahedron8;
	fem::Hexahedron20<double>       m_hexahedron20;
	fem::Hexahedron27<double>       m_hexahedron27;
	fem::Prism6<double>     m_prism6;
	fem::Prism15<double>    m_prism15;
	fem::Prism18<double>    m_prism18;

	Eigen::Matrix3d 	Dg, invDg;
	Eigen::Vector3d 	dNdcsi;


public:
	ElementResultsFactory(Model &, AnalysisResult &);

	/**
	Factory method that produces pointers to ElementResults objects from a given fem::Element object
	**/
	ElementResults *operator() (const fem::Element &);

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


}	// namespace fem

#endif 
