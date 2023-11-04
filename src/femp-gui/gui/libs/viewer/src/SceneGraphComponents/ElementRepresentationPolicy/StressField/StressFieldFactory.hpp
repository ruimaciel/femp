#ifndef STRESS_FIELD_FACTORY_H
#define STRESS_FIELD_FACTORY_H

#include <Eigen/Core>
#include <Eigen/LU>
#include <Eigen/Sparse>
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Element.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/elements/BaseElement.hpp>
#include <libfemp/elements/Hexahedron20.hpp>
#include <libfemp/elements/Hexahedron27.hpp>
#include <libfemp/elements/Hexahedron8.hpp>
#include <libfemp/elements/Prism15.hpp>
#include <libfemp/elements/Prism18.hpp>
#include <libfemp/elements/Prism6.hpp>
#include <libfemp/elements/Tetrahedron10.hpp>
#include <libfemp/elements/Tetrahedron4.hpp>

#include "StressFieldRepresentation.hpp"

namespace StressFieldRepresentation {

/**
 * Builder pattern to generate policies for the representation of each element
 **/
class StressFieldFactory {
	protected:
	float* m_diameter;
	fem::Model* m_model;
	fem::AnalysisResult* m_result;
	float m_max, m_min;	 // maximum and minimum value from any stress

	// temp values for dsyevj3
	double A[3][3];	 // temporary variable
	double eig_vec[3][3];
	double eig_val[3];

	// helper objects, which are only used because fem::Element was poorly
	// conceived and there is no time to rewrite it
	fem::Tetrahedron4 m_tetrahedron4;
	fem::Tetrahedron10 m_tetrahedron10;
	fem::Hexahedron8 m_hexahedron8;
	fem::Hexahedron20 m_hexahedron20;
	fem::Hexahedron27 m_hexahedron27;
	fem::Prism6 m_prism6;
	fem::Prism15 m_prism15;
	fem::Prism18 m_prism18;

	public:
	StressFieldFactory(float& diameter, fem::Model& model, fem::AnalysisResult& result);

	/**
	 * The factory functor
	 **/
	StressFieldRepresentation operator()(fem::Element const& element);

	/**
	 * Returns the maximum and minimum value for the principal stress
	 **/
	float max() const;
	float min() const;

	protected:
	/**
	 * Taken from:
	 * http://www.mpi-hd.mpg.de/personalhomes/globes/3x3/
	 *
	 * Article:
	 * Efficient numerical diagonalization of hermitian 3x3 matrices
	 * http://arxiv.org/abs/physics/0610206
	 **/
	int dsyevj3(double A[3][3], double Q[3][3], double w[3]) const;
};

}  // namespace StressFieldRepresentation

#endif
