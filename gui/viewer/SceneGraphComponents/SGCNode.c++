#include "SGCNode.h++"

#include <GL/gl.h>
#include <GL/glu.h>

#include <assert.h>


namespace SGC
{


Node::Node(size_t reference_node_label, fem::Node &node, DisplacementsRepresentationPolicy *displacements)
	: SceneGraphComponent()
{
	assert(displacements != NULL);

	this->node_label = reference_node_label;
	this->m_node = &node;
	this->m_displacements = displacements;
}


Node::~Node()
{
}


void Node::paintGL(ViewportData &data, ViewportColors &colors)
{
	glPushMatrix();
	fem::point u = (*m_displacements)[this->node_label];

	//glTranslated(this->m_node->data[0], this->m_node->data[1], this->m_node->data[2]);
	glTranslated(u.data[0], u.data[1], u.data[2]);
	
	//glScalef(data.node_scale/(data.aspect_ratio*pow(2,data.zoom)), data.node_scale/(data.aspect_ratio*pow(2,data.zoom)), data.node_scale/(data.aspect_ratio*pow(2,data.zoom)));
	float radius = data.node_radius*(data.node_scale/(data.aspect_ratio*pow(2,data.zoom)));

	//TODO paint selected node in a different color
	// paint the nodal sphere
	if(this->selected)
		glColor3fv(colors.selected);
	else
		glColor3fv(colors.node);

	//TODO replace this with a display list

	GLUquadric *p;
	p = gluNewQuadric();
	gluSphere(p,radius,8,8);

	// end 
	glPopMatrix();
}


void Node::accept(Operation::OperationsVisitor &visitor)
{
	visitor.visit(*this);
}


}	// namespace SGC


