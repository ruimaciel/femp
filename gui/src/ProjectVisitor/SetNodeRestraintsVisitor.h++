#ifndef SET_NODE_RESTRAINT_VISITOR_HPP
#define SET_NODE_RESTRAINT_VISITOR_HPP

#include <array>

#include "ProjectVisitor.h++"
#include <selection/Selection.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/Model.h++>
#include <libfemp/NodeRestrictions.h++>

/**
 * Sets node restraints in a specific set of nodes
 */
class SetNodeRestraintsVisitor
    : public ProjectVisitor {
public:
    SetNodeRestraintsVisitor(Selection selection, fem::NodeRestrictions const& restrictions);

    void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result);

protected:
    fem::NodeRestrictions m_restrictions;
    Selection m_selection;
};

#endif
