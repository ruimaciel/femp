#include "MoveNodesVisitor.h++"

#include <assert.h>

#include <libfemp/Node.h++>
#include <libfemp/AnalysisResult.h++>


MoveNodesVisitor::MoveNodesVisitor(Selection const &selection, fem::Point3D const &translation)
	: m_selection(selection)
{
	m_translation = translation;
}


void
MoveNodesVisitor::visit(fem::Model &model, std::vector<fem::AnalysisResult> &)
{
	for(auto node: m_selection.getNodeReferences())
	{
		model.getNode(node) += m_translation;
	}
}


