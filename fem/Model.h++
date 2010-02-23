#ifndef FEM_HPP
#define FEM_HPP

#include <QString>

#include <map>
#include <vector>

#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/tuple/tuple.hpp>

#include "Node.h++"
#include "Element.h++"
#include "Material.h++"
#include "NodeRestrictions.h++"
#include "LoadPattern.h++"
#include "FemEquation.h++"


namespace fem
{

class Model {
	private:
		int default_material;	// used when adding elements

	public:
		enum Error {	ERR_OK = 0,	// no error
				ERR_NO_ELEMENTS,
				ERR_UNSUPPORTED_ELEMENT,
				ERR_NODE_NUMBER,
				ERR_ELEMENT_NODE_REFERENCE,	// an invalid node reference has been made
				ERR_NODE_RESTRICTIONS_NODE_REFERENCE,	// an invalid node reference has been made
				ERR_INVALID_MATERIAL_REFERENCE,
				ERR_INVALID_NODE_REFERENCE
				};

		std::map<size_t, Node> 	node_list;
		std::vector<Element> 	element_list;
		std::vector<Material> 	material_list;
		std::map<size_t, NodeRestrictions>	node_restrictions_list;	// the node restrictions aren't stored in the Node class in order to save up memory
		std::vector<LoadPattern>	load_pattern_list;

	public:
		Model();
		~Model();

		// clears the entire model
		void clear();

		// sets a node
		void setNode(size_t pos, double x, double y, double z);
		void setDefaultMaterial(int material)	{ default_material = material; }
		void pushElement(fem::Element);
		void pushElement(fem::Element::Type type, std::vector<size_t> nodes);

		/** Specifies new node restrictions affecting a node
		@param node	a reference for a node contained in node_list
		@param nr	the new node restrictions definition
		@return	ERR_NONE if all went well, some other error if something went bad
		**/
		enum Error pushNodeRestrictions(size_t node, fem::NodeRestrictions nr);

		/** push a new load pattern into the load pattern stack
		@param lp	the newly added load pattern
		@return	ERR_NONE if all went well, some other error if something went bad
		**/
		enum Error pushLoadPattern(fem::LoadPattern lp);


		/** sets up a FEM equation according to the info contained in the instance of this class
		The struct FemEquation objects must already be resized to handle the model and initialized
		@param f	a struct FemEquation object that will be used to store the FEM equation
		@param lp	the load pattern
		@return an error
		**/
		enum Error build_fem_equation(struct FemEquation &f, const LoadPattern &lp);


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
		enum Error run(const LoadPattern &lp);


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
		given an element and a position in local coordinates, it generates a list with the nodal weights for the shape function for each interpolation point in local coordinates
		@param type	the element type
		@param point	local coordinates
		@return a boost::tuple consisting of three vector<double> storing each node's interpolation weights
		**/
		boost::tuple<std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double> >	sf(const Element::Type type, const fem::point &point);


		/**
		Performs a sanity check on the model
		@retur ERR_OK if all is well, other error code if something bad happened
		**/
		enum Model::Error sanity_check();

	private:
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
		boost::tuple<std::map<size_t, boost::tuple<size_t,size_t,size_t> >, size_t>  make_location_matrix();



		void add_k_elem_to_kg(const boost::numeric::ublas::symmetric_matrix<double, boost::numeric::ublas::upper> &k_elem, FemEquation &f, std::map<size_t, boost::tuple<size_t, size_t, size_t> > &lm,  Element &element);
};

}

#endif
