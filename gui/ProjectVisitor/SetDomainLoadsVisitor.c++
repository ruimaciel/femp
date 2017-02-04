#include "SetDomainLoadsVisitor.h++"

#include <libfemp/Node.h++>
#include <libfemp/Element.h++>
#include <libfemp/AnalysisResult.h++>


SetDomainLoadsVisitor::SetDomainLoadsVisitor(Selection const &selection, fem::LoadPattern &load_pattern, fem::Point const &force)
	: m_selection(selection), m_load_pattern(load_pattern), m_force(force)
{
}


void 
SetDomainLoadsVisitor::visit(fem::Model &, std::vector<fem::AnalysisResult<double> > &)
{
	for(fem::element_ref_t const &eref: m_selection.getElementReferences())
	{
		m_load_pattern.addDomainLoad(eref, m_force);
	}
}


