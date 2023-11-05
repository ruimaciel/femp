#ifndef FEMP_PROJECTVISITOR_SETDOMAINLOADSVISITOR_HPP
#define FEMP_PROJECTVISITOR_SETDOMAINLOADSVISITOR_HPP

#include "ProjectVisitor.hpp"

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Element.hpp>
#include <libfemp/LoadPattern.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/Point3D.hpp>

// stl includes
#include <set>
#include <vector>

/**
 * Sets the domain loads in a selection of elements
 */
class SetDomainLoadsVisitor : public ProjectVisitor {
	public:
	SetDomainLoadsVisitor(std::set<fem::element_ref_t> selected_elements, fem::LoadPattern& load_pattern, fem::Point3D const& force);

	void visit(fem::Model& model, std::vector<fem::AnalysisResult>&) override;

	protected:
	std::set<fem::element_ref_t> m_selected_elements;
	fem::LoadPattern& m_load_pattern;
	fem::Point3D const& m_force;
};

#endif
