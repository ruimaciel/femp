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

#include "../BaseViewport.h++"

#include "../SceneGraph.h++"
#include "../SceneGraphComponents/SGCNode.h++"
#include "../SceneGraphComponents/SGCNodeRestrictions.h++"


VPStateModel::VPStateModel()
	: ViewportState<BaseViewport>()
{ 
	this->m_factory.setElementRepresentationPolicy(m_element_representation_factory.opaque());
	this->m_factory.setDisplacementsPolicy(&m_no_displacements);
}


VPStateModel::~VPStateModel()
{
	mylog.setPrefix("VPStateModel::~VPStateModel()");
	mylog.message("destructor called");
}


void
VPStateModel::initialize(BaseViewport *mv)
{
	mylog.setPrefix("VPStateModel::initialize()");
	mylog.message("initializing");

	assert(mv != NULL);

	this->m_no_displacements.setModel(mv->project->model);
}



void
VPStateModel::populateScenegraph(BaseViewport *mv)
{
	mylog.setPrefix("void VPStateModel::populateScenegraph(fem::Model *mv->project->model)");
	mylog.message("populating");

	assert(mv != NULL);

	SceneGraphComponent * component;

	// add the nodes to the scenegraph
	for(std::map<size_t, fem::Node>::iterator i = mv->project->model.node_list.begin(); i != mv->project->model.node_list.end(); i++)
	{
		component =  new SGCNode(i->first, i->second, &this->m_no_displacements);
		if(component)
			this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, component);
	}

	for( std::map<size_t, fem::NodeRestrictions>::iterator i = mv->project->model.node_restrictions_list.begin(); i != mv->project->model.node_restrictions_list.end(); i++)
	{
		//TODO rewrite the SGCNodeRestrictions class
		component =  new SGCNodeRestrictions(mv->project->model.node_list[i->first], i->second);
		if(component) 
			this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODE_RESTRICTIONS, component);
	}

	// add the elements to the scene graph
	for( std::vector<fem::Element>::iterator i = mv->project->model.element_list.begin(); i != mv->project->model.element_list.end(); i++)
	{
		component = this->m_factory(*i);
		if(component) 
			this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, component);
	}

	// set the visibility of the rendering groups
	this->scenegraph.rendering_groups[2].render = false;	// hide wireframe surfaces

	// generate the scene graph
	this->scenegraph.generateSceneGraph();
}


void
VPStateModel::paintGL(BaseViewport *mv)
{
	assert(mv != NULL);

	mylog.setPrefix("VPStateModel::paintGL()");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mv->viewport_data.camera.reposition();

	//TODO finish implementing this
	this->scenegraph.paint(mv->viewport_data, mv->colors);
}


void
VPStateModel::mousePressEvent(BaseViewport *mv, QMouseEvent *event)
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
	}
}


void
VPStateModel::selectModelObjects(const fem::point &,const fem::point &)
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
