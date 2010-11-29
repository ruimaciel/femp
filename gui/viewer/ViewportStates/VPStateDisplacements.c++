#include "VPStateDisplacements.h++"

#include <map>
#include <list>
#include <algorithm>

#include <GL/gl.h>
#include <GL/glu.h>	// for gluQuadric()

#include "Logs.h++"	// declare the global message loggers

#include "../fem/Model.h++"
#include "../fem/Surface.h++"

#include "../ModelViewport.h++"


VPStateDisplacements::VPStateDisplacements()
	: ViewportState()
{ 
	original_nodes = NULL;
}


VPStateDisplacements::~VPStateDisplacements()
{
	mylog.setPrefix("VPStateDisplacements::~VPStateDisplacements()");
	mylog.message("destructor called");
}


void VPStateDisplacements::initialize(ModelViewport *mv)
{
	original_nodes = &mv->model->node_list;

	// build the displaced_nodes from the analysis

	this->setDisplacementScale(1.0);	//TODO tweak this value 
}


void VPStateDisplacements::populateScenegraph(ModelViewport *mv)
{
	mylog.setPrefix("void VPStateDisplacements::populateScenegraph(fem::Model *mv->model)");
	mylog.message("populating");

	//TODO generate the scenegraph

	// add the nodes to the scenegraph
	for(std::map<size_t, fem::Node>::iterator i = mv->model->node_list.begin(); i != mv->model->node_list.end(); i++)
	{
		this->scenegraph.addPrimitiveComponent(i->second);
	}

	// add the surfaces to the scenegraph
	for(std::list<fem::Surface>::iterator i = mv->model->surface_list.begin(); i != mv->model->surface_list.end(); i++)
	{
		if(i->external())
		{
			this->scenegraph.addPrimitiveComponent(*i);
		}
	}

	// generate the scene graph
	this->scenegraph.generateSceneGraph();
}


void VPStateDisplacements::paintGL(ModelViewport *mv)
{
	mylog.setPrefix("VPStateDisplacements::paintGL()");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mv->viewport_data.camera.reposition();

	// std::cout << "pos: " << mv->viewport_data.camera.pos << "\trot: " << mv->viewport_data.camera.rotation << "\tzoom: " << mv->viewport_data.zoom << std::endl;
	//mylog.message("painting");

	this->scenegraph.paint(mv);

}


void VPStateDisplacements::mousePressEvent(ModelViewport *mv, QMouseEvent *event)
{
	mv->viewport_data.lastPos = event->pos();
	// process left clicks
	if(event->buttons() & Qt::LeftButton)
	{
		fem::point near, far;
		QPoint pos = event->pos();
		GLdouble modelview[16];
		GLdouble projection[16];
		GLint viewport[4];

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, projection);
		glGetIntegerv(GL_VIEWPORT, viewport);
		gluUnProject(pos.x(), viewport[3]-pos.y(), 0, modelview, projection, viewport, &near.data[0], &near.data[1], &near.data[2]);
		gluUnProject(pos.x(), viewport[3]-pos.y(), 1, modelview, projection, viewport, &far.data[0], &far.data[1], &far.data[2]);

		// push the line
		// selectModelObjects(near, far); 	//TODO finish this

	}
}



void VPStateDisplacements::setDisplacementScale(float new_scale)
{
	assert(original_nodes != NULL);

	displaced_nodes.clear();

	for(std::map<size_t, fem::Node>::iterator i = original_nodes->begin(); i != original_nodes->end(); i++)
	{
		//TODO finish this
		//displaced_nodes[i->first] = new_scale*i->second;
		displaced_nodes[i->first] = i->second;
	}
}


void VPStateDisplacements::selectModelObjects(const fem::point &near,const fem::point &far)
{
	//TODO finish implementing this

	// test nodes
	float a, b, c;
	float x2x1, y2y1, z2z1; // helper temp variables to avoid remultiplying
	std::map<size_t,float> distance_map;

	//for(std::map<size_t,fem::Node>::iterator i = document->model.node_list.begin(); i != document->model.node_list.end(); i++)
	for(std::list<SceneGraphComponent *>::iterator i = this->scenegraph.primitive_components.begin(); i != this->scenegraph.primitive_components.end(); i++)
	{

		if(b*b - 4*a*c > 0)
		{
			(*i)->selected = true;
		}
	}
	// select the nearest hit
	// document->selectNode(std::min_element(distance_map.begin(), distance_map.end(), distance_map.value_comp())->first);
}
