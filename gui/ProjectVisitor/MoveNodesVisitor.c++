#include "MoveNodesVisitor.h++"

#include <assert.h>

#include <libfemp/Node.h++>
#include <libfemp/AnalysisResult.h++>


MoveNodesVisitor::MoveNodesVisitor(Selection const &selection, fem::point const &translation)
{
	m_selection = &selection;
	m_translation = translation;
}


void 
MoveNodesVisitor::visit(fem::Model &model, std::vector<fem::AnalysisResult<double> > &)
{
	assert(m_selection != NULL);

	for(auto node: m_selection->m_nodes_selected)
	{
		model.getNode(node) += m_translation;
	}
}


