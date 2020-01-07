#include "SetNodeRestraintsVisitor.h++"

#include <assert.h>

#include <libfemp/AnalysisResult.h++>
#include <libfemp/Element.h++>
#include <libfemp/Node.h++>

SetNodeRestraintsVisitor::SetNodeRestraintsVisitor(Selection selection, fem::NodeRestrictions const& restrictions)
    : m_selection(selection)
{
    m_restrictions = restrictions;
}

void SetNodeRestraintsVisitor::visit(fem::Model& model, std::vector<fem::AnalysisResult>&)
{
    if (m_restrictions.free()) {
        for (auto node : m_selection.getNodeReferences()) {
            model.popNodeRestrictions(node);
        }
    } else {
        for (auto node : m_selection.getNodeReferences()) {
            model.pushNodeRestrictions(node, m_restrictions);
        }
    }
}
