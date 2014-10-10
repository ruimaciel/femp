#include "SetDomainLoadsVisitor.h++"

#include <libfemp/Node.h++>
#include <libfemp/Element.h++>
#include <libfemp/AnalysisResult.h++>


SetDomainLoadsVisitor::SetDomainLoadsVisitor(Selection const &selection, fem::LoadPattern &load_pattern, fem::point const &force)
	: m_selection(selection), m_load_pattern(load_pattern), m_force(force)
{
}


void 
SetDomainLoadsVisitor::visit(fem::Model &model, std::vector<fem::AnalysisResult<double> > &)
{
	for(fem::element_ref_t const &eref: m_selection.m_elements_selected)
	{
		m_load_pattern.addDomainLoad(eref, m_force);
	}

	/*
	if(m_restrictions.free())
	{
		for(auto node: m_selection->m_nodes_selected)
		{
			model.popNodeRestrictions(node);
		}
	}
	else
	{
		for(auto node: m_selection->m_nodes_selected)
		{
			model.pushNodeRestrictions(node, m_restrictions);
		}
	}
	*/
}


