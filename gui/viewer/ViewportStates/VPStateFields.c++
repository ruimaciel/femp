#include "VPStateFields.h++"

#include <map>
#include <list>
#include <algorithm>

#include <assert.h>

#include <GL/gl.h>
#include <GL/glu.h>	// for gluQuadric()

#include "Logs.h++"	// declare the global message loggers

#include "../../fem/Model.h++"
#include "../../fem/Surface.h++"

#include "../BaseViewport.h++"

#include "ui/DialogScale.h++"

#include "../SceneGraph.h++"
#include "../SceneGraphComponents/SGCNode.h++"
#include "../SceneGraphComponents/SGCFieldSurface.h++"
#include "../SceneGraphComponents/SGCDisplacementOriginalSurface.h++"
#include "../SceneGraphComponents/FieldSurface/surfaces.h++"


VPStateFields::VPStateFields()
	: ViewportState<BaseViewport>()
{ 
	original_nodes = NULL;
}


VPStateFields::~VPStateFields()
{
	mylog.setPrefix("VPStateFields::~VPStateFields()");
	mylog.message("destructor called");
}


void VPStateFields::initialize(BaseViewport *viewport)
{
	original_nodes = &viewport->project->model.node_list;

	// build the displaced_nodes from the analysis

	this->setDisplacementScale(1.0);	//TODO tweak this value 
}


void VPStateFields::populateScenegraph(BaseViewport *viewport)
{
	// add the nodes to the scenegraph
	for(std::map<size_t, fem::Node>::iterator i = displaced_nodes.begin(); i != displaced_nodes.end(); i++)
	{
		this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, new SGCNode(i->first, i->second, viewport->project->model.node_restrictions_list) );
	}

	// add the surfaces to the scenegraph
	for(std::list<fem::Surface>::iterator i = viewport->project->model.surface_list.begin(); i != viewport->project->model.surface_list.end(); i++)
	{
		if(i->external())
		{
			switch(i->getType())
			{
				case fem::Element::FE_TRIANGLE3:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCFieldSurface<SurfaceTriangle3>(*i, displaced_nodes, *display_options->result) );
					break;

				case fem::Element::FE_TRIANGLE6:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCFieldSurface<SurfaceTriangle6>(*i, displaced_nodes, *display_options->result) );
					break;

				case fem::Element::FE_QUADRANGLE4:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCFieldSurface<SurfaceQuad4>(*i, displaced_nodes, *display_options->result) );
					break;

				case fem::Element::FE_QUADRANGLE8:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCFieldSurface<SurfaceQuad8>(*i, displaced_nodes, *display_options->result) );
					break;

				case fem::Element::FE_QUADRANGLE9:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCFieldSurface<SurfaceQuad9>(*i, displaced_nodes, *display_options->result) );
					break;

				default:
					mylog.message("unknown surface type");
					break;
			}
		}
	}

	// add the transparent surfaces to the scenegraph
	for(std::list<fem::Surface>::iterator i = viewport->project->model.surface_list.begin(); i != viewport->project->model.surface_list.end(); i++)
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


void VPStateFields::paintGL(BaseViewport *viewport)
{
	assert(viewport != NULL);

	mylog.setPrefix("VPStateFields::paintGL()");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewport->viewport_data.camera.reposition();

	//mylog.message("painting");

	this->scenegraph.paint(viewport->viewport_data, viewport->project->model, viewport->colors);

}


void VPStateFields::mousePressEvent(BaseViewport *viewport, QMouseEvent *event)
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


void VPStateFields::keyPressEvent ( BaseViewport *viewport, QKeyEvent * event )
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


void VPStateFields::setDisplacementScale(float new_scale)
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

