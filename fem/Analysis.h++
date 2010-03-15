#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP

#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/tuple/tuple.hpp>

#include "Model.h++"
#include "FemEquation.h++"
#include "LoadPattern.h++"


namespace fem
{

class Analysis
{
	public:
		enum Error {	ERR_OK = 0,	// no error
			ERR_NO_ELEMENTS,
			ERR_UNSUPPORTED_ELEMENT,
			ERR_NODE_NUMBER,
			ERR_ELEMENT_NODE_REFERENCE,	// an invalid node reference has been made
			ERR_NODE_RESTRICTIONS_NODE_REFERENCE,	// an invalid node reference has been made
			ERR_INVALID_MATERIAL_REFERENCE,
			ERR_INVALID_NODE_REFERENCE,

			ERR_SINGULAR_MATRIX
		};

	public:
		Analysis();
		Analysis(const Analysis &);
		~Analysis();


		/** sets up a FEM equation according to the info contained in the instance of this class
		The struct FemEquation objects must already be resized to handle the model and initialized
		@param f	a struct FemEquation object that will be used to store the FEM equation
		@param lp	the load pattern
		@return an error
		**/
		enum Error build_fem_equation(Model &model, struct FemEquation &f, const LoadPattern &lp);


		/*
		return the inverse of a 3 by 3 matrix
		*/
		inline boost::numeric::ublas::matrix<double> invert3by3(const boost::numeric::ublas::matrix<double> &M, double det);


		/*
		return the determinant of a 3 by 3 matrix
		*/
		double det3by3(const boost::numeric::ublas::matrix<double> &M);


		/** runs the analysis based on a given load pattern
		@param lp	the load pattern
		@return 
		**/
		enum Error run(Model &model, const LoadPattern &lp);


		/** 
		given an element and a position in local coordinates, it generates a list with the nodal weights for the shape function for each interpolation point in local coordinates
		@param type	the element type
		@param point	local coordinates
		@return a boost::tuple consisting of three vector<double> storing each node's interpolation weights
		**/
		boost::tuple<std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double> >	sf(const Element::Type type, const fem::point &point);


	private:
		/**
		  Gauss-Legendre integration function, gauleg, from "Numerical Recipes in C"
		  (Cambridge Univ. Press) by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and
		  B.P. Flannery
		@param x	array of doubles, stores the abcissa of the integration point
		@param w	array of doubles, stores the weights of the integration points
		@param n	the number of Gauss points
		*/
		void gauleg(double x[], double w[], int n);


		/**
		Given an element type and the desired degree, returns a list Gauss quadrature integration points
		@param type	element type
		@param degree	integration degree
		@return a list of integration points and the respective integration weights
		**/
		std::vector<boost::tuple<fem::point, double> > integration_points(const Element::Type &type, const int &degree = 0); 

		/**
		Builds the location matrix, a map between the node number and a 3-tuple holding the degree of freedom reference numbers for each degree of freedom
		@return a 2-tuple consisting of a map between the node reference number and it's corresponding degree of freedom references and a number of the total number of dof 
		**/
		boost::tuple<std::map<size_t, boost::tuple<size_t,size_t,size_t> >, size_t>  make_location_matrix(Model &model);


		/**
		Adds the elementary stiffness matrix and nodal force vector to the global counterparts following the location matrix
		@param k_elem	elementary stiffness matrix
		@param f_elem	elementary nodal force vector
		@param lm	location matrix
		@param f	FemEquation
		@param element	reference to the element
		**/
		void add_elementary_to_global(const boost::numeric::ublas::symmetric_matrix<double, boost::numeric::ublas::upper> &k_elem, const boost::numeric::ublas::mapped_vector<double> &f_elem, FemEquation &f, std::map<size_t, boost::tuple<size_t, size_t, size_t> > &lm,  Element &element);
};

}

#endif
