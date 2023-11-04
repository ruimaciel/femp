#ifndef PROJECTVISITOR_MOVENODESVISITOR_HPP
#define PROJECTVISITOR_MOVENODESVISITOR_HPP

#include "ProjectVisitor.hpp"

// services includes
#include <selection/Selection.hpp>

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/Point3D.hpp>

// stl includes
#include <array>

/**
 * Performs a translation on a specific set of nodes
 */
class MoveNodesVisitor : public ProjectVisitor {
	public:
	MoveNodesVisitor(Selection selection, fem::Point3D const& translation);

	void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result) override;

	protected:
	fem::Point3D m_translation;
	Selection m_selection;
};

#endif
