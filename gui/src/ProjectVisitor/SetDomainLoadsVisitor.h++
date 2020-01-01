#ifndef SET_DOMAIN_LOADS_VISITOR_HPP
#define SET_DOMAIN_LOADS_VISITOR_HPP

#include <array>

#include "ProjectVisitor.h++"
#include <selection/Selection.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/LoadPattern.h++>
#include <libfemp/Model.h++>

/**
 * Sets the domain loads in a selection of elements
 */
class SetDomainLoadsVisitor
    : public ProjectVisitor {
public:
    SetDomainLoadsVisitor(Selection const& selection, fem::LoadPattern& load_pattern, fem::Point3D const& force);

    void visit(fem::Model& model, std::vector<fem::AnalysisResult>&);

protected:
    Selection const& m_selection;
    fem::LoadPattern& m_load_pattern;
    fem::Point3D const& m_force;
};

#endif
