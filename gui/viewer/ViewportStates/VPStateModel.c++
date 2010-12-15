#include "VPStateModel.h++"

#include <map>
#include <list>
#include <algorithm>

#include <GL/gl.h>
#include <GL/glu.h>	// for gluQuadric()

#include "../Logs.h++"	// declare the global message loggers

#include "../../fem/Model.h++"
#include "../../fem/NodeRestrictions.h++"
#include "../../fem/Surface.h++"

#include "../ModelViewport.h++"

#include "../SceneGraphComponents/SGCNode.h++"
#include "../SceneGraphComponents/SGCSurface.h++"


VPStateModel::VPStateModel()
	: ViewportState()
{ 
}


VPStateModel::~VPStateModel()
{
	mylog.setPrefix("VPStateModel::~VPStateModel()");
	mylog.message("destructor called");
}


void VPStateModel::initialize(ModelViewport *mv)
{
	mylog.setPrefix("VPStateModel::initialize()");
	mylog.message("yet to be implemented");
}


void VPStateModel::populateScenegraph(ModelViewport *mv)
{
	mylog.setPrefix("void VPStateModel::populateScenegraph(fem::Model *mv->model)");
	mylog.message("populating");

	//TODO generate the scenegraph

	// add the nodes to the scenegraph
	for(std::map<size_t, fem::Node>::iterator i = mv->model->node_list.begin(); i != mv->model->node_list.end(); i++)
	{
		this->scenegraph.addPrimitiveComponent(new SGCNode(i->first, i->second, mv->model->node_restrictions_list) );
	}

	// add the surfaces to the scenegraph
	for(std::list<fem::Surface>::iterator i = mv->model->surface_list.begin(); i != mv->model->surface_list.end(); i++)
	{
		if(i->external())
		{
			this->scenegraph.addPrimitiveComponent(new SGCSurface(*i) );
		}
	}

	// generate the scene graph
	this->scenegraph.generateSceneGraph();
}


void VPStateModel::paintGL(ModelViewport *mv)
{
	mylog.setPrefix("VPStateModel::paintGL()");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mv->viewport_data.camera.reposition();

	std::cout << "pos: " << mv->viewport_data.camera.pos << "\trot: " << mv->viewport_data.camera.rotation << "\tzoom: " << mv->viewport_data.zoom << std::endl;
	
	//mylog.message("painting");


	//TODO finish implementing this
	//this->scenegraph.paintGL(mv->viewport_data, mv->model, mv->colors);
	this->scenegraph.paint(mv);

	//this->crudePaintHack(mv->model, mv->viewport_data, mv->colors);

}


void VPStateModel::mousePressEvent(ModelViewport *mv, QMouseEvent *event)
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


void VPStateModel::selectModelObjects(const fem::point &near,const fem::point &far)
{
	//TODO finish this
	// test nodes
	/*
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
	*/
	// select the nearest hit
	// document->selectNode(std::min_element(distance_map.begin(), distance_map.end(), distance_map.value_comp())->first);
}
