#ifndef SCENE_GRAPH_COMPONENT_NODE_RESTRICTION_HPP
#define SCENE_GRAPH_COMPONENT_NODE_RESTRICTION_HPP

#include "Operations/OperationsVisitor.h++"
#include "SceneGraphComponent.h++"

#include "../ViewportData.h++"
#include <options/Options.h++>

#include <libfemp/NodeRestrictions.h++>

class DisplacementsRepresentationPolicy;

namespace SGC {

class NodeRestrictions
    : public SceneGraphComponent {
public:
    NodeRestrictions(const fem::node_ref_t& node_reference, const fem::node_restriction_ref_t& node_restrictions_reference, fem::NodeRestrictions& node_restrictions, DisplacementsRepresentationPolicy* displacements);
    ~NodeRestrictions();

    /**
     * Renders this node
     */
    void paintGL(ViewportData& data, ViewportColors& colors);

    /**
     * Visitor pattern method
     */
    void accept(Operation::OperationsVisitor& visitor);

protected:
    void renderNodeRestriction();

protected:
    fem::node_ref_t m_node_reference;
    fem::node_restriction_ref_t m_node_restrictions_reference;
    fem::NodeRestrictions* m_node_restrictions;
    DisplacementsRepresentationPolicy* m_displacements;
};

} // namespace SGC

#endif
