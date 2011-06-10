#include "SGCNodeRestrictions.h++"

#include <GL/gl.h>
#include <GL/glu.h>


SGCNodeRestrictions::SGCNodeRestrictions(fem::Node &node, fem::NodeRestrictions &node_restrictions)
	: SceneGraphComponent()
{
	m_node= &node;
	m_node_restrictions = &node_restrictions;
}


SGCNodeRestrictions::~SGCNodeRestrictions()
{
}


void SGCNodeRestrictions::paintGL(ViewportData &data, fem::Project &, ViewportColors &colors)
{
	glPushMatrix();
	glTranslated(m_node->data[0],m_node->data[1],m_node->data[2]);

	glScalef(data.node_scale/(data.aspect_ratio*pow(2,data.zoom)), data.node_scale/(data.aspect_ratio*pow(2,data.zoom)), data.node_scale/(data.aspect_ratio*pow(2,data.zoom)));

	// paint restrictions, if there are any
	glColor3fv(colors.restraints);
	if(m_node_restrictions->dx())
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(1.4142f, 0, 1.4142f);
		glVertex3i(0,0,0);
		glVertex3i(-2,2,2);
		glVertex3i(-2,-2,2);

		glNormal3f(1.4142f,-1.4142f, 0);
		glVertex3i(0,0,0);
		glVertex3i(-2,-2, 2);
		glVertex3i(-2,-2,-2);

		glNormal3f(1.4142f, 0, -1.4142f);
		glVertex3i(0,0,0);
		glVertex3i(-2,-2,-2);
		glVertex3i(-2, 2,-2);

		glNormal3f(1.4142f, 1.4142f, 0);
		glVertex3i(0,0,0);
		glVertex3i(-2, 2,-2);
		glVertex3i(-2, 2, 2);

		// backface
		glNormal3f(-1,0,0);
		glVertex3i(-2, 2, 2);
		glVertex3i(-2, 2,-2);
		glVertex3i(-2,-2,-2);
		glVertex3i(-2,-2,-2);
		glVertex3i(-2,-2, 2);
		glVertex3i(-2, 2, 2);
		glEnd();
	}
	if(m_node_restrictions->dy())
	{
		// render the pyramid
		glBegin(GL_TRIANGLES);
		glNormal3i( 2, 0, 2);
		glVertex3i( 0, 0, 0);
		glVertex3i( 2,-2,-2);
		glVertex3i( 2, 2,-2);

		glNormal3i( 0,-2, 2);
		glVertex3i(0,0,0);
		glVertex3i(-2,-2,-2);
		glVertex3i( 2,-2,-2);

		glNormal3i(-2, 0, 2);
		glVertex3i(0,0,0);
		glVertex3i(-2, 2,-2);
		glVertex3i(-2,-2,-2);

		glNormal3i( 0, 2, 2);
		glVertex3i(0,0,0);
		glVertex3i( 2, 2,-2);
		glVertex3i(-2, 2,-2);

		// backface
		glNormal3f( 0,0,-1);
		glVertex3i( 2, 2,-2);
		glVertex3i(-2,-2,-2);
		glVertex3i(-2, 2,-2);
		glVertex3i(-2,-2,-2);
		glVertex3i( 2, 2,-2);
		glVertex3i( 2,-2,-2);
		glEnd();
	}
	if( m_node_restrictions->dz())
	{
		glRotatef(-90,1,0,0);
		// render the pyramid
		glBegin(GL_TRIANGLES);
		glNormal3i( 2, 0, 2);
		glVertex3i( 0, 0, 0);
		glVertex3i( 2,-2,-2);
		glVertex3i( 2, 2,-2);

		glNormal3i( 0,-2, 2);
		glVertex3i(0,0,0);
		glVertex3i(-2,-2,-2);
		glVertex3i( 2,-2,-2);

		glNormal3i(-2, 0, 2);
		glVertex3i(0,0,0);
		glVertex3i(-2, 2,-2);
		glVertex3i(-2,-2,-2);

		glNormal3i( 0, 2, 2);
		glVertex3i(0,0,0);
		glVertex3i( 2, 2,-2);
		glVertex3i(-2, 2,-2);

		// backface
		glNormal3f( 0,0,-1);
		glVertex3i( 2, 2,-2);
		glVertex3i(-2,-2,-2);
		glVertex3i(-2, 2,-2);
		glVertex3i(-2,-2,-2);
		glVertex3i( 2, 2,-2);
		glVertex3i( 2,-2,-2);
		glEnd();
	}

	// end 
	glPopMatrix();
}


void SGCNodeRestrictions::accept(OperationsVisitor &v)
{
	v.visit(*this);
}
