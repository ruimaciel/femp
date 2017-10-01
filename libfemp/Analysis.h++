#ifndef FEMP_ANALYSIS_HPP
#define FEMP_ANALYSIS_HPP

#include <iostream> //TODO remove this: debug purposes only
#include <map>

#include <boost/tuple/tuple.hpp>

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <Eigen/LU>

#include <libla/Operations.h++>
#include <libla/ProgressIndicatorStrategy.h++>

#include <libfemp/Model.h++>
#include <libfemp/Element.h++>
#include <libfemp/LoadPattern.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/elements/BaseElement.h++>
#include <libfemp/elements/all.h++> // remove individual elements after elements are refactored
#include <libfemp/ElementResults/ElementResults.h++>
#include <libfemp/ElementResults/ElementResultsFactory.h++>


namespace fem
{

template<typename Scalar>
class Analysis
{
public:
	// list of supported elements
	// area elements, used to integrate surface loads
	Triangle3	tri3;
	Triangle6	tri6;
	Quadrangle4 	quad4;
	Quadrangle8 	quad8;
	Quadrangle9 	quad9;

	// volume elements
	Tetrahedron4	tetra4;
	Tetrahedron10	tetra10;
	Hexahedron8 	hexa8;
	Hexahedron20 	hexa20;
	Hexahedron27 	hexa27;
	Prism6		prism6;
	Prism15		prism15;
	Prism18		prism18;

public:
	enum Error {	
		ERR_OK = 0,	// no error
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

public:
	/** sets up a FEM equation according to the info contained in the instance of this class
	The struct FemEquation objects must already be resized to handle the model and initialized
	@param model	a reference to a fem::Model object
	@param lp	the load pattern
	@param result	a pointer to a AnalysisResult object, where the run results will be stored
	@return an error
	**/
	enum Error buildEquation(Model &Model, const LoadPattern &lp, AnalysisResult &result, ProgressIndicatorStrategy &progress);


	/** runs the analysis
	@param model	a reference to a fem::Model object
	@param lp	the load pattern
	@param result	a pointer to a AnalysisResult object, where the run results will be stored
	@return an error
	**/
	virtual enum Error run(Model &model, LoadPattern &lp, AnalysisResult *result, ProgressIndicatorStrategy &progress) = 0;


	/**
	 * generates the global stiffness matrix
	 * @param model the model
	 * @param result where the result
	 * @param progress 
	 **/
	enum Error generateGlobalStiffnessMatrix(Model &model, AnalysisResult &result, ProgressIndicatorStrategy &progress);


	/**
	 * generates the global domain force vector contribution defined by a load pattern
	 * @param model the model
	 * @param lp the load pattern
	 * @param result
	 * @param progress
	 **/
	enum Error generateGlobalDomainForceVector(Model &model, const LoadPattern &lp, AnalysisResult &result, ProgressIndicatorStrategy &progress);


	/**
	 * generates the global surface force vector contribution defined by a load pattern
	 * @param model the model
	 * @param lp the load pattern
	 * @param result
	 * @param progress
	 **/
	enum Error generateGlobalSurfaceForceVector(Model &model, const LoadPattern &lp, AnalysisResult &result, ProgressIndicatorStrategy &progress);


	/**
	 * generates the global point force vector contribution defined by a load pattern
	 * @param model the model
	 * @param lp the load pattern
	 * @param result
	 * @param progress
	 **/
	enum Error generateGlobalPointForceVector(Model &model, const LoadPattern &lp, AnalysisResult &result, ProgressIndicatorStrategy &progress);


	/**
	Returns a map of all nodes which had any relative displacement
	**/
	std::map<size_t, Node> displacements_map(AnalysisResult &result);


	/**
	Generates AnalysisResult::displacements, a map between a reference to a fem::Node object and a vector with it's displacements 
	**/
	void generateDisplacementsMap(Model &model, AnalysisResult &result);


	/**
	Calculates a set of recovered values in every node of each individual element
	**/
	enum Error recoverValues(Model &model, AnalysisResult &result);


	/**
	Calculates a set of recovered values in every node of each individual element
	**/
	enum Error calculateStrainEnergy(Model &model, AnalysisResult &result);


protected:

	/**
	Builds the location matrix, a map between the node number and a 3-tuple holding the degree of freedom reference numbers for each degree of freedom, and resizes the temp FemEquation object
	@param model	the reference of a fem::Model object
	@param result	a fem::AnalysisResult object, where the information will be stored
	**/
	void make_location_matrix(Model &model, AnalysisResult &result);


	/**
	Adds the elementary stiffness matrix and nodal force vector to the global counterparts following the location matrix
	@param k_elem	elementary stiffness matrix
	@param f_elem	elementary nodal force vector
	@param lm	location matrix
	@param f	FemEquation
	@param element	reference to the element
	**/
	void add_elementary_stiffness_to_global(const Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> &k_elem, std::map<size_t, boost::tuple<size_t, size_t, size_t> > &lm,  Element &element, AnalysisResult &result);

};



} // namespace femp

#endif
