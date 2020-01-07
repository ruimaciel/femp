#include "SetDomainLoadsVisitor.h++"

#include <libfemp/AnalysisResult.h++>
#include <libfemp/Element.h++>
#include <libfemp/Node.h++>

SetDomainLoadsVisitor::SetDomainLoadsVisitor(Selection selection, fem::LoadPattern& load_pattern, fem::Point3D const& force)
    : m_selection(selection)
    , m_load_pattern(load_pattern)
    , m_force(force)
{
}

void SetDomainLoadsVisitor::visit(fem::Model&, std::vector<fem::AnalysisResult>&)
{
    for (fem::element_ref_t const& eref : m_selection.getElementReferences()) {
        m_load_pattern.addDomainLoad(eref, m_force);
    }
}
