#include "SetNodeRestraintsVisitor.h++"

#include <assert.h>

#include <libfemp/Node.h++>
#include <libfemp/Element.h++>
#include <libfemp/AnalysisResult.h++>


SetNodeRestraintsVisitor::SetNodeRestraintsVisitor(Selection const &selection, fem::NodeRestrictions const &restrictions)
{
	m_restrictions = restrictions;
	m_selection = &selection;
}


void 
SetNodeRestraintsVisitor::visit(fem::Model &model, std::vector<fem::AnalysisResult<double> > &)
{
	assert(m_selection != NULL);

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
}


