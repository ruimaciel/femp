#ifndef FEM_HPP
#define FEM_HPP

#include <QString>

#include <map>
#include <vector>

#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>

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
				ERR_INVALID_NODE_REFERENCE
				};

		std::map<size_t, Node> 	node_list;
		std::vector<Element> 	element_list;
		std::vector<Material> 	material_list;
		std::map<size_t, NodeRestrictions>	node_restrictions_list;
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
		returns the jacobian matrix of a given element
		*/
		inline boost::numeric::ublas::matrix<double> J(double csi,double eta,double zeta, const Element &element);

		/*
		return the inverse of a 3 by 3 matrix
		*/
		inline boost::numeric::ublas::matrix<double> invert3by3(const boost::numeric::ublas::matrix<double> &M, double det);

		/*
		return the determinant of a 3 by 3 matrix
		*/
		double det3by3(const boost::numeric::ublas::matrix<double> &M);

		/* 
		same as above but takes a fem::point as a source of [csi,eta,zeta] coordinates
		@param p	local coordinates
		@param element	the element in question
		*/
		inline boost::numeric::ublas::matrix<double> J(fem::point p, const Element &element);


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


		//TODO perform sanity checks on data structure
};


}

#endif
