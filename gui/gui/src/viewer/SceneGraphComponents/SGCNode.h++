#ifndef SCENE_GRAPH_COMPONENT_NODE_HPP
#define SCENE_GRAPH_COMPONENT_NODE_HPP

#include "Operations/OperationsVisitor.h++"
#include "SceneGraphComponent.h++"

#include <libfemp/Node.h++>
#include <libfemp/NodeRestrictions.h++>

class DisplacementsRepresentationPolicy;

namespace SGC {

/**
 * Scene graph component which renders a node
 */
class Node
    : public SceneGraphComponent
{
protected:
    fem::node_ref_t node_label;
    fem::Node m_node;
    DisplacementsRepresentationPolicy* m_displacements;

public:
    Node(size_t, fem::Node& node, DisplacementsRepresentationPolicy* displacements);
    ~Node();

    /**
     * Renders this node
     */
    void paintGL(ViewportData& data, ViewportColors& colors);

    fem::node_ref_t const& reference() const;

    fem::Point3D const& pos() const;

    /**
     * Visitor pattern method
     */
    void accept(Operation::OperationsVisitor& visitor);
};

} // namespace SGC

#endif
