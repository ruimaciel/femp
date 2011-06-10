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
#include "../SceneGraphComponents/SGCModelSurface.h++"
#include "../SceneGraphComponents/OpaqueSurface/SurfaceTriangle3.h++"
#include "../SceneGraphComponents/OpaqueSurface/SurfaceTriangle6.h++"
#include "../SceneGraphComponents/OpaqueSurface/SurfaceQuad4.h++"
#include "../SceneGraphComponents/OpaqueSurface/SurfaceQuad8.h++"
#include "../SceneGraphComponents/OpaqueSurface/SurfaceQuad9.h++"
#include "../SceneGraphComponents/WireframeSurface/surfaces.h++"



VPStateModel::VPStateModel()
	: ViewportState<BaseViewport>()
{ 
}


VPStateModel::~VPStateModel()
{
	mylog.setPrefix("VPStateModel::~VPStateModel()");
	mylog.message("destructor called");
}


void VPStateModel::initialize(BaseViewport *)
{
	mylog.setPrefix("VPStateModel::initialize()");
	mylog.message("yet to be implemented");
}


void VPStateModel::populateScenegraph(BaseViewport *mv)
{
	mylog.setPrefix("void VPStateModel::populateScenegraph(fem::Model *mv->project->model)");
	mylog.message("populating");

	//TODO generate the scenegraph

	// add the nodes to the scenegraph
	for(std::map<size_t, fem::Node>::iterator i = mv->project->model.node_list.begin(); i != mv->project->model.node_list.end(); i++)
	{
		//TODO set rendering groups
		this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, new SGCNode(i->first, i->second, mv->project->model.node_restrictions_list) );
	}

	for( std::map<size_t, fem::NodeRestrictions>::iterator i = mv->project->model.node_restrictions_list.begin(); i != mv->project->model.node_restrictions_list.end(); i++)
	{
		this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODE_RESTRICTIONS, new SGCNodeRestrictions(mv->project->model.node_list[i->first], i->second) );
	}

	// add the surfaces to the scenegraph
	for(std::list<fem::Surface>::iterator i = mv->project->model.surface_list.begin(); i != mv->project->model.surface_list.end(); i++)
	{
		if(i->external())
		{
			switch(i->getType())
			{
				case fem::Element::FE_TRIANGLE3:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCModelSurface<SurfaceTriangle3>(*i, mv->project->model.node_list) );
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_WIREFRAME, new SGCModelSurface<WireframeSurfaceTriangle3>(*i, mv->project->model.node_list) );
					break;

				case fem::Element::FE_TRIANGLE6:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCModelSurface<SurfaceTriangle6>(*i, mv->project->model.node_list) );
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_WIREFRAME, new SGCModelSurface<WireframeSurfaceTriangle6>(*i, mv->project->model.node_list) );
					break;

				case fem::Element::FE_QUADRANGLE4:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCModelSurface<SurfaceQuad4>(*i, mv->project->model.node_list) );
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_WIREFRAME, new SGCModelSurface<WireframeSurfaceQuad4>(*i, mv->project->model.node_list) );
					break;

				case fem::Element::FE_QUADRANGLE8:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCModelSurface<SurfaceQuad8>(*i, mv->project->model.node_list) );
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_WIREFRAME, new SGCModelSurface<WireframeSurfaceQuad8>(*i, mv->project->model.node_list) );
					break;

				case fem::Element::FE_QUADRANGLE9:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCModelSurface<SurfaceQuad9>(*i, mv->project->model.node_list) );
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_WIREFRAME, new SGCModelSurface<WireframeSurfaceQuad9>(*i, mv->project->model.node_list) );
					break;

				default:
					mylog.message("unknown surface type");
					break;
			}
		}
	}

	// set the visibility of the rendering groups
	this->scenegraph.rendering_groups[2].render = false;	// hide wireframe surfaces

	// generate the scene graph
	this->scenegraph.generateSceneGraph();
}


void VPStateModel::paintGL(BaseViewport *mv)
{
	mylog.setPrefix("VPStateModel::paintGL()");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mv->viewport_data.camera.reposition();


	//TODO finish implementing this
	this->scenegraph.paint(mv->viewport_data, *mv->project, mv->colors);
}


void VPStateModel::mousePressEvent(BaseViewport *mv, QMouseEvent *event)
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
