#include "VPStateModel.h++"

#include <map>
#include <list>
#include <algorithm>
#include <iostream>

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
	: ViewportState()
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
VPStateModel::initialize(BaseViewport *viewport)
{
	mylog.setPrefix("VPStateModel::initialize()");
	mylog.message("initializing");

	assert(viewport != NULL);

	this->m_no_displacements.setModel(viewport->project->model);
}



void
VPStateModel::populateScenegraph(BaseViewport *viewport)
{
	mylog.setPrefix("void VPStateModel::populateScenegraph(fem::Model *viewport->project->model)");
	mylog.message("populating");

	assert(viewport != NULL);

	scenegraph.clear();

	SceneGraphComponent * component;

	// add the nodes to the scenegraph
	for(std::map<size_t, fem::Node>::iterator i = viewport->project->model.node_list.begin(); i != viewport->project->model.node_list.end(); i++)
	{
		component =  new SGC::Node(i->first, i->second, &this->m_no_displacements);
		if(component)
			this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, component);
	}

	for( std::map<fem::node_restriction_ref_t, fem::NodeRestrictions>::iterator i = viewport->project->model.node_restrictions_list.begin(); i != viewport->project->model.node_restrictions_list.end(); i++)
	{
		//TODO rewrite the SGC::NodeRestrictions class
		component = new SGC::NodeRestrictions(i->first, i->first, i->second, &this->m_no_displacements);
		if(component) 
			this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODE_RESTRICTIONS, component);
	}

	// add the elements to the scene graph
	//for( std::vector<fem::Element>::iterator i = viewport->project->model.element_list.begin(); i != viewport->project->model.element_list.end(); i++)
	for( std::vector<fem::Element>::size_type n = 0; n < viewport->project->model.element_list.size(); n++)
	{
		component = this->m_factory(n, viewport->project->model.element_list[n]);
		if(component) 
			this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, component);
	}

	// set the visibility of the rendering groups
	this->scenegraph.rendering_groups[2].render = false;	// hide wireframe surfaces

	// generate the scene graph
	this->scenegraph.generateSceneGraph();
}


void 
VPStateModel::setSelection(Selection)
{
	std::cout << "VPStateModel::setSelection(Selection)" << std::endl;
}


void
VPStateModel::paintGL(BaseViewport *viewport)
{
	assert(viewport != NULL);

	mylog.setPrefix("VPStateModel::paintGL()");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewport->viewport_data.camera.reposition();

	//TODO finish implementing this
	this->scenegraph.paint(viewport->viewport_data, viewport->colors);
}


void
VPStateModel::mousePressEvent(BaseViewport *viewport, QMouseEvent *event)
{
	viewport->viewport_data.lastPos = event->pos();
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


