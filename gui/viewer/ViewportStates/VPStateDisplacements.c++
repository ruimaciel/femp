#include "VPStateDisplacements.h++"

#include <map>
#include <list>
#include <algorithm>

#include <assert.h>

#include <GL/gl.h>
#include <GL/glu.h>	// for gluQuadric()

#include "Logs.h++"	// declare the global message loggers

#include "../../fem/Model.h++"
#include "../../fem/Surface.h++"

#include "../DisplacementsViewport.h++"

#include "ui/DialogScale.h++"

#include "../SceneGraph.h++"
#include "../SceneGraphComponents/SGCNode.h++"
#include "../SceneGraphComponents/SGCDisplacementSurface.h++"
#include "../SceneGraphComponents/SGCDisplacementOriginalSurface.h++"
#include "../SceneGraphComponents/OpaqueSurface/surfaces.h++"


VPStateDisplacements::VPStateDisplacements()
	: ViewportState<DisplacementsViewport>()
{ 
	original_nodes = NULL;
}


VPStateDisplacements::~VPStateDisplacements()
{
	mylog.setPrefix("VPStateDisplacements::~VPStateDisplacements()");
	mylog.message("destructor called");
}


void VPStateDisplacements::initialize(DisplacementsViewport *viewport)
{
	original_nodes = &viewport->model->node_list;

	// build the displaced_nodes from the analysis

	this->setDisplacementScale(1.0);	//TODO tweak this value 
}


void VPStateDisplacements::populateScenegraph(DisplacementsViewport *viewport)
{
	mylog.setPrefix("void VPStateDisplacements::populateScenegraph(fem::Model *viewport->model)");

	//TODO generate the scenegraph

	// add the nodes to the scenegraph
	//for(std::map<size_t, fem::Node>::iterator i = viewport->model->node_list.begin(); i != viewport->model->node_list.end(); i++)
	for(std::map<size_t, fem::Node>::iterator i = displaced_nodes.begin(); i != displaced_nodes.end(); i++)
	{
		this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, new SGCNode(i->first, i->second, viewport->model->node_restrictions_list) );
	}

	// add the surfaces to the scenegraph
	for(std::list<fem::Surface>::iterator i = viewport->model->surface_list.begin(); i != viewport->model->surface_list.end(); i++)
	{
		if(i->external())
		{
			switch(i->getType())
			{
				case fem::Element::FE_TRIANGLE3:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCDisplacementSurface<SurfaceTriangle3>(*i, displaced_nodes) );
					break;

				case fem::Element::FE_TRIANGLE6:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCDisplacementSurface<SurfaceTriangle6>(*i, displaced_nodes) );
					break;

				case fem::Element::FE_QUADRANGLE4:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCDisplacementSurface<SurfaceQuad4>(*i, displaced_nodes) );
					break;

				case fem::Element::FE_QUADRANGLE8:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCDisplacementSurface<SurfaceQuad8>(*i, displaced_nodes) );
					break;

				case fem::Element::FE_QUADRANGLE9:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCDisplacementSurface<SurfaceQuad9>(*i, displaced_nodes) );
					break;

				default:
					mylog.message("unknown surface type");
					break;
			}
		}
	}

	// add the transparent surfaces to the scenegraph
	for(std::list<fem::Surface>::iterator i = viewport->model->surface_list.begin(); i != viewport->model->surface_list.end(); i++)
	{
		if(i->external())
		{
			switch(i->getType())
			{
				case fem::Element::FE_TRIANGLE3:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_GHOST_SURFACES, new SGCDisplacementOriginalSurface<SurfaceTriangle3>(*i, *original_nodes) );
					break;

				case fem::Element::FE_TRIANGLE6:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_GHOST_SURFACES, new SGCDisplacementOriginalSurface<SurfaceTriangle6>(*i, *original_nodes) );
					break;

				case fem::Element::FE_QUADRANGLE4:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_GHOST_SURFACES, new SGCDisplacementOriginalSurface<SurfaceQuad4>(*i, *original_nodes) );
					break;

				case fem::Element::FE_QUADRANGLE8:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_GHOST_SURFACES, new SGCDisplacementOriginalSurface<SurfaceQuad8>(*i, *original_nodes) );
					break;

				case fem::Element::FE_QUADRANGLE9:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_GHOST_SURFACES, new SGCDisplacementOriginalSurface<SurfaceQuad9>(*i, *original_nodes) );
					break;

				default:
					mylog.message("unknown surface type");
					break;
			}
		}
	}
	// generate the scene graph
	this->scenegraph.generateSceneGraph();
}


void VPStateDisplacements::paintGL(DisplacementsViewport *viewport)
{
	assert(viewport != NULL);

	mylog.setPrefix("VPStateDisplacements::paintGL()");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewport->viewport_data.camera.reposition();

	//mylog.message("painting");

	this->scenegraph.paint(viewport->viewport_data, *viewport->model, viewport->colors);

}


void VPStateDisplacements::mousePressEvent(DisplacementsViewport *viewport, QMouseEvent *event)
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

		// push the line
		// selectModelObjects(near, far); 	//TODO finish this

	}
}


void VPStateDisplacements::keyPressEvent ( DisplacementsViewport *viewport, QKeyEvent * event )
{
	qWarning("keypressed");
	switch( event->key() )
	{
		case Qt::Key_S:	// change the displacements scale
			{
				DialogScale ds(1.0f, viewport);
				switch(ds.exec())
				{
					case QDialog::Accepted:
						this->setDisplacementScale(ds.scale());

						//update the scene
						viewport->updateGL();
						break;

					default:
						break;
				}
			}
			break;

		default:
			break;
	}
}


void VPStateDisplacements::setDisplacementScale(float new_scale)
{
	assert(original_nodes != NULL);

	displaced_nodes.clear();

	for(std::map<size_t, fem::Node>::iterator i = original_nodes->begin(); i != original_nodes->end(); i++)
	{
		//TODO finish this
		displaced_nodes[i->first] = i->second;
		if(displacements.find(i->first) != displacements.end())
		{
			displaced_nodes[i->first] += new_scale*displacements[i->first];
		}
	}
}


void VPStateDisplacements::selectModelObjects(const fem::point &near,const fem::point &far)
{
	//TODO finish implementing this

	/*
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
	*/
}
