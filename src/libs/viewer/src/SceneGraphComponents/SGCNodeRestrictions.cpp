#include "SGCNodeRestrictions.hpp"

#include <GL/gl.h>
#include <GL/glu.h>

#include "DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.hpp"

namespace SGC {

NodeRestrictions::NodeRestrictions(const fem::node_ref_t& node_reference, const fem::node_restriction_ref_t& node_restrictions_reference,
								   fem::NodeRestrictions& node_restrictions, DisplacementsRepresentationPolicy* displacements)
	: SceneGraphComponent()

{
	m_node_reference = node_reference;
	m_node_restrictions_reference = node_restrictions_reference;
	m_node_restrictions = &node_restrictions;
	m_displacements = displacements;
}

NodeRestrictions::~NodeRestrictions() {}

void NodeRestrictions::paintGL(ViewportData& data, ViewportColors& colors) {
	fem::Point3D u = (*m_displacements)[this->m_node_reference];
	glPushMatrix();
	glTranslated(u.data[0], u.data[1], u.data[2]);

	glScalef(data.node_scale / (data.aspect_ratio * pow(2, data.zoom)), data.node_scale / (data.aspect_ratio * pow(2, data.zoom)),
			 data.node_scale / (data.aspect_ratio * pow(2, data.zoom)));

	// paint restrictions, if there are any
	glColor3fv(colors.restraints.data());
	if (m_node_restrictions->dx()) {
		renderNodeRestriction();
	}
	if (m_node_restrictions->dy()) {
		glPushMatrix();
		glRotatef(-90, 0, 0, 1);
		renderNodeRestriction();
		glPopMatrix();
	}
	if (m_node_restrictions->dz()) {
		glPushMatrix();
		glRotatef(-90, 0, 1, 0);
		renderNodeRestriction();
		glPopMatrix();
	}

	// end
	glPopMatrix();
}

void NodeRestrictions::accept(Operation::OperationsVisitor& visitor) {
	visitor.visit(*this);
}

void NodeRestrictions::renderNodeRestriction() {
	glBegin(GL_TRIANGLES);
	glNormal3f(1.4142f, 0, 1.4142f);
	glVertex3i(0, 0, 0);
	glVertex3i(-2, 2, 2);
	glVertex3i(-2, -2, 2);

	glNormal3f(1.4142f, -1.4142f, 0);
	glVertex3i(0, 0, 0);
	glVertex3i(-2, -2, 2);
	glVertex3i(-2, -2, -2);

	glNormal3f(1.4142f, 0, -1.4142f);
	glVertex3i(0, 0, 0);
	glVertex3i(-2, -2, -2);
	glVertex3i(-2, 2, -2);

	glNormal3f(1.4142f, 1.4142f, 0);
	glVertex3i(0, 0, 0);
	glVertex3i(-2, 2, -2);
	glVertex3i(-2, 2, 2);

	// backface
	glNormal3f(-1, 0, 0);
	glVertex3i(-2, 2, 2);
	glVertex3i(-2, 2, -2);
	glVertex3i(-2, -2, -2);
	glVertex3i(-2, -2, -2);
	glVertex3i(-2, -2, 2);
	glVertex3i(-2, 2, 2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glNormal3f(1.4142f, 0, 1.4142f);
	glVertex3i(0, 0, 0);
	glVertex3i(2, -2, 2);
	glVertex3i(2, 2, 2);

	glNormal3f(1.4142f, -1.4142f, 0);
	glVertex3i(0, 0, 0);
	glVertex3i(2, -2, -2);
	glVertex3i(2, -2, 2);

	glNormal3f(1.4142f, 0, -1.4142f);
	glVertex3i(0, 0, 0);
	glVertex3i(2, 2, -2);
	glVertex3i(2, -2, -2);

	glNormal3f(1.4142f, 1.4142f, 0);
	glVertex3i(0, 0, 0);
	glVertex3i(2, 2, 2);
	glVertex3i(2, 2, -2);

	// backface
	glNormal3f(1, 0, 0);
	glVertex3i(2, -2, -2);
	glVertex3i(2, 2, -2);
	glVertex3i(2, 2, 2);
	glVertex3i(2, 2, 2);
	glVertex3i(2, -2, 2);
	glVertex3i(2, -2, -2);
	glEnd();
}

}  // namespace SGC
