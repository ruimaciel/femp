#ifndef PROJECTVISITOR_MOVENODESVISITOR_HPP
#define PROJECTVISITOR_MOVENODESVISITOR_HPP

#include "ProjectVisitor.h++"

// services includes
#include <selection/Selection.h++>

// libfemp includes
#include <libfemp/AnalysisResult.h++>
#include <libfemp/Model.h++>
#include <libfemp/Point3D.h++>

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
