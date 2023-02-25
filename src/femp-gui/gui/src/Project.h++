#ifndef FEMP_PROJECT_HPP
#define FEMP_PROJECT_HPP

// gui includes
#include <ProjectVisitor/ProjectVisitor.h++>

// domain includes
#include <domain/Model.h++>

// libfemp includes
#include <libfemp/AnalysisResult.h++>
#include <libfemp/Model.h++>

// stl includes
#include <vector>

/**
This class is intended to describe a FEM project in it's entirely, which
includes:
- a FEM model
- a series of analysis results
**/
namespace fem {

class Project {
	public:
	Project();
	~Project();

	/**
	 * clears the project
	 */
	void clear();

	/**
	 * Adds the result of a new analysis process to the result list
	 */
	void pushAnalysisResult(fem::AnalysisResult& new_result);

	/**
	 * returns a reference to the Project's model
	 */
	Model& getModel();
	std::shared_ptr<gui::Model> getDomainModel();

	std::vector<AnalysisResult>& getAnalysisResults();	// a list with all analysis

	/**
	 * Implements a Visitor design pattern
	 */
	void accept(ProjectVisitor& visitor);

	protected:
	Model m_model;	// the FEM model
	std::shared_ptr<gui::Model> m_domainModel;
	std::vector<AnalysisResult> m_analysisResults;	// a list with all analysis
};

}  // namespace fem

#endif
