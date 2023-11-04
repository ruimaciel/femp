#ifndef PROJECTVISITOR_SETDOMAINLOADSVISITOR_HPP
#define PROJECTVISITOR_SETDOMAINLOADSVISITOR_HPP

#include "ProjectVisitor.hpp"

// services includes
#include <selection/Selection.hpp>

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/LoadPattern.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/Point3D.hpp>

// stl includes
#include <array>

/**
 * Sets the domain loads in a selection of elements
 */
class SetDomainLoadsVisitor : public ProjectVisitor {
	public:
	SetDomainLoadsVisitor(Selection selection, fem::LoadPattern& load_pattern, fem::Point3D const& force);

	void visit(fem::Model& model, std::vector<fem::AnalysisResult>&) override;

	protected:
	Selection m_selection;
	fem::LoadPattern& m_load_pattern;
	fem::Point3D const& m_force;
};

#endif
