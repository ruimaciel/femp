#ifndef PROJECTVISITOR_SETNODERESTRAINTVISITOR_HPP
#define PROJECTVISITOR_SETNODERESTRAINTVISITOR_HPP

#include "ProjectVisitor.hpp"

// services includes
#include <selection/Selection.hpp>

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/NodeRestrictions.hpp>

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
