#ifndef FEMP_PROJECT_HPP
#define FEMP_PROJECT_HPP

#include <libfemp/AnalysisResult.h++>
#include <libfemp/Model.h++>

#include <ProjectVisitor/ProjectVisitor.h++>

#include <vector>

/**
This class is intended to describe a FEM project in it's entirely, which includes:
- a FEM model
- a series of analysis results
**/
namespace fem {

class Project {
public:
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

    /**
     * Implements a Visitor design pattern
     */
    void accept(ProjectVisitor& visitor);

protected:
    Model m_model; // the FEM model

public:
    std::vector<AnalysisResult> result; // a list with all analysis
};

} // namespace fem

#endif
