#ifndef FEMP_ANALYSIS_HPP
#define FEMP_ANALYSIS_HPP

// Eigen includes
#include <Eigen/Core>
#include <Eigen/LU>
#include <Eigen/Sparse>

// boost includes
#include <boost/tuple/tuple.hpp>

// la includes
#include <la/Operations.h++>
#include <la/ProgressIndicatorStrategy.h++>

// libfemp includes
#include <libfemp/AnalysisResult.h++>
#include <libfemp/Element.h++>
#include <libfemp/ElementResults/ElementResults.h++>
#include <libfemp/ElementResults/ElementResultsFactory.h++>
#include <libfemp/elements/all.h++>	 // remove individual elements after elements are refactored
#include <libfemp/elements/BaseElement.h++>
#include <libfemp/LoadPattern.h++>
#include <libfemp/Model.h++>

// std includes
#include <iostream>	 //TODO remove this: debug purposes only
#include <map>

namespace fem {

/**
 *TODO: these are placeholder member variables to help transition to new
 *quadrature rules
 */
struct QuadratureRulesOptions {
	int stiffness_degree;  // Quadrature rule degree to integrate stiffness
						   // matrices
	int domain_degree;	   // Quadrature rule degree to integrate domain loads
};

template <typename Scalar>
class Analysis {
	public:
	QuadratureRulesOptions tri3;
	QuadratureRulesOptions tri6;
	QuadratureRulesOptions quad4;
	QuadratureRulesOptions quad8;
	QuadratureRulesOptions quad9;

	QuadratureRulesOptions tetra4;
	QuadratureRulesOptions tetra10;
	QuadratureRulesOptions hexa8;
	QuadratureRulesOptions hexa20;
	QuadratureRulesOptions hexa27;

	QuadratureRulesOptions prism6;
	QuadratureRulesOptions prism15;
	QuadratureRulesOptions prism18;

	public:
	enum Error {
		ERR_OK = 0,	 // no error
		ERR_NO_ELEMENTS,
		ERR_UNSUPPORTED_ELEMENT,
		ERR_NODE_NUMBER,
		ERR_ELEMENT_NODE_REFERENCE,			   // an invalid node reference has been made
		ERR_NODE_RESTRICTIONS_NODE_REFERENCE,  // an invalid node reference has been
											   // made
		ERR_INVALID_MATERIAL_REFERENCE,
		ERR_INVALID_NODE_REFERENCE,
		ERR_SINGULAR_MATRIX,
		ERR_NEGATIVE_DETERMINANT
	};

	public:
	/**
	 * Sets up a FEM equation according to the info contained in the
	 * instance of this class.
	 * The struct FemEquation objects must already be resized to handle the
	 * model and initialized.
	 * @param model	a reference to a fem::Model object
	 * @param lp	the load pattern
	 * @param result	a pointer to a AnalysisResult object, where the run results
	 * will be stored
	 * @return an error
	 */
	enum Error buildEquation(Model& Model, const LoadPattern& lp, AnalysisResult& result, ProgressIndicatorStrategy& progress);

	/**
	 * Runs the analysis
	 * @param model	a reference to a fem::Model object
	 * @param lp	the load pattern
	 * @param result	a pointer to a AnalysisResult object, where the run results
	 * will be stored
	 * @return an error
	 */
	virtual enum Error run(Model& model, LoadPattern& lp, AnalysisResult& result, ProgressIndicatorStrategy& progress) = 0;

	/**
	 * Generates the global stiffness matrix
	 * @param model the model
	 * @param result where the result
	 * @param progress
	 */
	enum Error generateGlobalStiffnessMatrix(Model& model, AnalysisResult& result, ProgressIndicatorStrategy& progress);

	/**
	 * Generates the global domain force vector contribution defined by a load
	 * pattern
	 * @param model the model
	 * @param lp the load pattern
	 * @param result
	 * @param progress
	 */
	enum Error generateGlobalDomainForceVector(Model& model, const LoadPattern& lp, AnalysisResult& result, ProgressIndicatorStrategy& progress);

	/**
	 * Generates the global surface force vector contribution defined by a
	 * load pattern.
	 * @param model the model
	 * @param lp the load pattern
	 * @param result
	 * @param progress
	 */
	enum Error generateGlobalSurfaceForceVector(Model& model, const LoadPattern& lp, AnalysisResult& result, ProgressIndicatorStrategy& progress);

	/**
	 * Generates the global point force vector contribution defined by a
	 * load pattern.
	 * @param model the model
	 * @param lp the load pattern
	 * @param result
	 * @param progress
	 */
	enum Error generateGlobalPointForceVector(Model& model, const LoadPattern& lp, AnalysisResult& result, ProgressIndicatorStrategy& progress);

	/**
	 * Returns a map of all nodes which had any relative displacement
	 */
	std::map<size_t, Node> displacementsMap(AnalysisResult& result);

	/**
	 * Generates AnalysisResult::displacements, a map between a reference to a
	 * fem::Node object and a vector with it's displacements
	 */
	void generateDisplacementsMap(Model& model, AnalysisResult& result);

	/**
	 * Calculates a set of recovered values in every node of each individual
	 * element
	 */
	enum Error recoverValues(Model& model, AnalysisResult& result);

	/**
	 * Calculates a set of recovered values in every node of each individual
	 * element
	 */
	enum Error calculateStrainEnergy(Model& model, AnalysisResult& result);

	protected:
	/**
	 * Builds the location matrix, a map between the node number and a
	 * 3-tuple holding the degree of freedom reference numbers for each
	 * degree of freedom, and resizes the temp FemEquation object.
	 * @param model	the reference of a fem::Model object
	 * @param result	a fem::AnalysisResult object, where the information will be
	 * stored
	 */
	void makeLocationMatrix(Model& model, AnalysisResult& result);

	/**
	 * Adds the elementary stiffness matrix and nodal force vector to the global
	 * counterparts following the location matrix
	 * @param k_elem	elementary stiffness matrix
	 * @param f_elem	elementary nodal force vector
	 * @param lm	location matrix
	 * @param f	FemEquation
	 * @param element	reference to the element
	 */
	void addElementaryStiffnessToGlobal(const Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>& k_elem,
										std::map<size_t, boost::tuple<size_t, size_t, size_t>>& lm, Element& element, AnalysisResult& result);
};

}  // namespace fem

#endif
