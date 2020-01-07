#include "SGCNode.h++"

#include <GL/gl.h>
#include <GL/glu.h>

#include <assert.h>

#include "DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"

namespace SGC {

Node::Node(size_t reference_node_label, fem::Node& node, DisplacementsRepresentationPolicy* displacements)
    : SceneGraphComponent()
{
    assert(displacements != nullptr);

    this->node_label = reference_node_label;
    this->m_node = node;
    this->m_displacements = displacements;
}

Node::~Node()
{
}

void Node::paintGL(ViewportData& data, ViewportColors& colors)
{
    glPushMatrix();
    fem::Point3D u = (*m_displacements)[this->node_label];

    glTranslated(u.data[0], u.data[1], u.data[2]);

    float radius = data.node_radius * (data.node_scale / (data.aspect_ratio * pow(2, data.zoom)));

    // paint the nodal sphere
    if (this->selected)
        glColor3fv(colors.selected.data());
    else
        glColor3fv(colors.node.data());

    GLUquadric* p;
    p = gluNewQuadric();
    gluSphere(p, radius, 8, 8);

    // end
    glPopMatrix();
}

const fem::node_ref_t&
Node::reference() const
{
    return node_label;
}

const fem::Point3D&
Node::pos() const
{
    return m_node;
}

void Node::accept(Operation::OperationsVisitor& visitor)
{
    visitor.visit(*this);
}

} // namespace SGC
