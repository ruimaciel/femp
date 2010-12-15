#include "SGCNode.h++"

#include <GL/gl.h>
#include <GL/glu.h>

#include "../Logs.h++"	// declare the global message loggers


SGCNode::SGCNode(size_t reference_node_label, fem::Node &reference_node, std::map<size_t, fem::NodeRestrictions> &reference_node_restrictions_map)
	: SceneGraphComponent()
{
	this->node_label = reference_node_label;
	this->setReferenceNode(reference_node);
	node_restrictions_map = &reference_node_restrictions_map;
}


SGCNode::~SGCNode()
{
}


void SGCNode::setReferenceNode(fem::Node &referenced_node)
{
	this->node = &referenced_node;

	mylog.setPrefix("SGCNode::setReferenceNode()");
	mylog.message("yet to be implemented");

	//TODO adjust boundary to this surface
}


void SGCNode::paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors)
{
	glPushMatrix();
	glTranslated(node->data[0],node->data[1],node->data[2]);
	
	glScalef(data.node_scale/(data.aspect_ratio*pow(2,data.zoom)), data.node_scale/(data.aspect_ratio*pow(2,data.zoom)), data.node_scale/(data.aspect_ratio*pow(2,data.zoom)));

	//TODO find a better rendering for the nodes
	glBegin(GL_LINES);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3i(0,0,0);
		glVertex3i(2,0,0);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3i(0,0,0);
		glVertex3i(0,2,0);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3i(0,0,0);
		glVertex3i(0,0,2);
	glEnd();

	//TODO paint selected node in a different color
	// paint the nodal sphere
	/*
	if(document->model_selection.isNodeSelected(label))
		glColor3f(1.0f,0,0);
	else
	*/
	if(this->selected)
		glColor3fv(colors.selected);
	else
		glColor3fv(colors.node);

	//TODO replace this with a display list

	GLUquadric *p;
	p = gluNewQuadric();
	gluSphere(p,1,8,8);

	// paint restrictions, if there are any
	if(node_restrictions_map->find(node_label) != node_restrictions_map->end())
	{
		if((*node_restrictions_map)[node_label].dx())
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
		if((*node_restrictions_map)[node_label].dy())
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
		if( (*node_restrictions_map)[node_label].dz())
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
	}

	// end 
	glPopMatrix();
}


void SGCNode::accept(OperationsVisitor &v)
{
	v.visit(*this);
}
