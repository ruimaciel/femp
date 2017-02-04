#include "SetNodeRestraintsVisitor.h++"

#include <assert.h>

#include <libfemp/Node.h++>
#include <libfemp/Element.h++>
#include <libfemp/AnalysisResult.h++>


SetNodeRestraintsVisitor::SetNodeRestraintsVisitor(Selection const &selection, fem::NodeRestrictions const &restrictions)
	: m_selection(selection)
{
	m_restrictions = restrictions;
}


void 
SetNodeRestraintsVisitor::visit(fem::Model &model, std::vector<fem::AnalysisResult<double> > &)
{
	if(m_restrictions.free())
	{
		for(auto node: m_selection.getNodeReferences())
		{
			model.popNodeRestrictions(node);
		}
	}
	else
	{
		for(auto node: m_selection.getNodeReferences())
		{
			model.pushNodeRestrictions(node, m_restrictions);
		}
	}
}


