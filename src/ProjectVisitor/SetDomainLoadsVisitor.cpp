#include "SetDomainLoadsVisitor.hpp"

// libfemp includes
#include <libfemp/Node.hpp>

SetDomainLoadsVisitor::SetDomainLoadsVisitor(std::set<fem::element_ref_t> selected_elements, fem::LoadPattern& load_pattern, fem::Point3D const& force)
	: m_selected_elements{selected_elements}, m_load_pattern(load_pattern), m_force(force) {}

void SetDomainLoadsVisitor::visit(fem::Model&, std::vector<fem::AnalysisResult>&) {
	for (fem::element_ref_t const& eref : m_selected_elements) {
		m_load_pattern.addDomainLoad(eref, m_force);
	}
}
