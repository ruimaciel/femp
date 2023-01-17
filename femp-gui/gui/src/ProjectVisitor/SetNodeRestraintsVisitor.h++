#ifndef PROJECTVISITOR_SETNODERESTRAINTVISITOR_HPP
#define PROJECTVISITOR_SETNODERESTRAINTVISITOR_HPP

#include "ProjectVisitor.h++"

// services includes
#include <selection/Selection.h++>

// libfemp includes
#include <libfemp/AnalysisResult.h++>
#include <libfemp/Model.h++>
#include <libfemp/NodeRestrictions.h++>

// stl includes
#include <array>

/**
 * Sets node restraints in a specific set of nodes
 */
class SetNodeRestraintsVisitor : public ProjectVisitor {
	public:
	SetNodeRestraintsVisitor(Selection selection, fem::NodeRestrictions const& restrictions);

	void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result) override;

	protected:
	fem::NodeRestrictions m_restrictions;
	Selection m_selection;
};

#endif
