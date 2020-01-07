#include "MoveNodesVisitor.h++"

#include <assert.h>

#include <libfemp/AnalysisResult.h++>
#include <libfemp/Node.h++>

MoveNodesVisitor::MoveNodesVisitor(Selection selection, fem::Point3D const& translation)
    : m_selection(selection)
{
    m_translation = translation;
}

void MoveNodesVisitor::visit(fem::Model& model, std::vector<fem::AnalysisResult>&)
{
    for (auto node : m_selection.getNodeReferences()) {
        model.getNode(node) += m_translation;
    }
}
