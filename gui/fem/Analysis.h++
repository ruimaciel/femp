#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP

#include <boost/tuple/tuple.hpp>

#include "../lalib/Matrix.h++"
#include "../lalib/Vector.h++"
#include <Eigen/Core>
#include <Eigen/Sparse>

#include <map>

#include "Model.h++"
#include "Element.h++"
#include "LoadPattern.h++"

#include "ProcessedModel.h++"

#include "elements/Triangle3.h++"
#include "elements/Triangle6.h++"
#include "elements/Triangle10.h++"
#include "elements/Quadrangle4.h++"
#include "elements/Quadrangle8.h++"
#include "elements/Quadrangle9.h++"
#include "elements/Tetrahedron4.h++"
#include "elements/Tetrahedron10.h++"
#include "elements/Hexahedron8.h++"
#include "elements/Hexahedron20.h++"
#include "elements/Hexahedron27.h++"
#include "elements/Prism6.h++"
#include "elements/Prism15.h++"
#include "elements/Prism18.h++"


namespace fem
{

class Analysis
{
	private:
		Triangle3<double>	tri3;
		Triangle6<double>	tri6;
		Triangle10<double>	tri10;
		Quadrangle4<double> 	quad4;
		Quadrangle8<double> 	quad8;
		Quadrangle9<double> 	quad9;
		Tetrahedron4<double>	tetra4;
		Tetrahedron10<double>	tetra10;
		Hexahedron8<double> 	hexa8;
		Hexahedron20<double> 	hexa20;
		Hexahedron27<double> 	hexa27;
		Prism6<double>		prism6;
		Prism15<double>		prism15;
		Prism18<double>		prism18;

	public:
		enum Error {	ERR_OK = 0,	// no error
			ERR_NO_ELEMENTS,
			ERR_UNSUPPORTED_ELEMENT,
			ERR_NODE_NUMBER,
			ERR_ELEMENT_NODE_REFERENCE,	// an invalid node reference has been made
			ERR_NODE_RESTRICTIONS_NODE_REFERENCE,	// an invalid node reference has been made
			ERR_INVALID_MATERIAL_REFERENCE,
			ERR_INVALID_NODE_REFERENCE,
			ERR_SINGULAR_MATRIX,
			ERR_NEGATIVE_DETERMINANT
		};

	protected:
		std::map<enum Element::ElementFamily, std::map<int, std::vector<boost::tuple<fem::point, double> > > > ipwpl;	// integration points/weights pair list
		std::map<enum Element::Type, int> degree;	// stiffness matrix integration point degree for a particular element
		std::map<enum Element::Type, int> ddegree;	// domain load integration point degree for a particular element

			// location matrix: <node, <DoF number, DoF number, DoF number> >, if DoF == 0 then this isn't a DoF
		std::map<size_t, boost::tuple<size_t,size_t,size_t> > lm;

			// the FEM equation
		// FemEquation f;
		/*
		Eigen::DynamicSparseMatrix<double,Eigen::RowMajor> k;
		Eigen::Matrix<double,Eigen::Dynamic,1> f;
		Eigen::Matrix<double,Eigen::Dynamic,1> d;
		*/
		lalib::Matrix<float,lalib::SparseDOK> K;
		lalib::Vector<float> f;
		lalib::Vector<float> d;


	public:
		Analysis();
		Analysis(const Analysis &);
		~Analysis();


		/** sets up a FEM equation according to the info contained in the instance of this class
		The struct FemEquation objects must already be resized to handle the model and initialized
		@param model	a reference to a fem::Model object
		@param lp	the load pattern
		@param verbose	true to output progress messages
		@return an error
		**/
		enum Error build_fem_equation(Model &model, const LoadPattern &lp, bool verbose);


		/** runs the analysis
		@param model	a reference to a fem::Model object
		@param lp	the load pattern
		@return an error
		**/
		virtual enum Error run(Model &model, LoadPattern &lp, ProcessedModel &p) = 0;


		/**
		Set a new integration degree for a specific element: stiffness matrix integration
		@param type	element type
		@param d	desired degree
		**/
		void setDegree(Element::Type &type, int &d);

		/**
		Set a new integration degree for a specific element: domain loads integration
		@param type	element type
		@param d	desired degree
		**/
		void setDDegree(Element::Type &type, int &d);


		void output_fem_equation(std::ostream &out);
		void output_displacements(std::ostream &out);

		/**
		Returns a map of all nodes which had any relative displacement
		**/
		std::map<size_t, Node> displacements_map();

	protected:
		/**
		Set the default values for the intended integration degrees for all supported elements
		**/
		void setDefaultIntegrationDegrees();


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
		Pre-builds all lists of integration point/weight pairs for all supported elements
		**/
		void build_integration_points();


		/**
		Builds the location matrix, a map between the node number and a 3-tuple holding the degree of freedom reference numbers for each degree of freedom, and resizes the temp FemEquation object
		**/
		void make_location_matrix(Model &model);


		/**
		Adds the elementary stiffness matrix and nodal force vector to the global counterparts following the location matrix
		@param k_elem	elementary stiffness matrix
		@param f_elem	elementary nodal force vector
		@param lm	location matrix
		@param f	FemEquation
		@param element	reference to the element
		**/
		void add_elementary_stiffness_to_global(const Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> &k_elem, std::map<size_t, boost::tuple<size_t, size_t, size_t> > &lm,  Element &element);


		const std::vector<double> & getN( const Element::Type &type, const point & p);
		const std::vector<double> & getdNdcsi( const Element::Type &type, const point & p);
		const std::vector<double> & getdNdeta( const Element::Type &type, const point & p);
		const std::vector<double> & getdNdzeta( const Element::Type &type, const point & p);


};

}

#endif
