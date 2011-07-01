#include "SGCNode.h++"

#include <GL/gl.h>
#include <GL/glu.h>

#include "../Logs.h++"	// declare the global message loggers


SGCNode::SGCNode(size_t reference_node_label, fem::Project &project)
	: SceneGraphComponent()
{
	this->node_label = reference_node_label;
	this->node = &project.model.node_list[reference_node_label];
}


SGCNode::~SGCNode()
{
}


void SGCNode::paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result, float &scale,  ViewportColors &colors)
{
	glPushMatrix();
	fem::point u;
	if(result != NULL)
		u =  result->displacements[this->node_label];

	glTranslated(node->data[0] + scale*u.data[0],node->data[1] + scale*u.data[1], node->data[2] + scale*u.data[2]);
	
	glScalef(data.node_scale/(data.aspect_ratio*pow(2,data.zoom)), data.node_scale/(data.aspect_ratio*pow(2,data.zoom)), data.node_scale/(data.aspect_ratio*pow(2,data.zoom)));

	//TODO paint selected node in a different color
	// paint the nodal sphere
	if(this->selected)
		glColor3fv(colors.selected);
	else
		glColor3fv(colors.node);

	//TODO replace this with a display list

	GLUquadric *p;
	p = gluNewQuadric();
	gluSphere(p,1,8,8);

	// end 
	glPopMatrix();
}


void SGCNode::accept(OperationsVisitor &v)
{
	v.visit(*this);
}
