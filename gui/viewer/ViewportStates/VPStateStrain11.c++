#include "VPStateStrain11.h++"

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

#include "Strain11.h++"


VPStateStrain11::VPStateStrain11()
	: ViewportState<BaseViewport>()
{ 
	field = NULL;	

	field = new Strain11;
}


VPStateStrain11::~VPStateStrain11()
{
}


void VPStateStrain11::initialize(BaseViewport *)
{
	// build the displaced_nodes from the analysis

	this->setDisplacementsScale(1.0);	//TODO tweak this value 
}


void VPStateStrain11::populateScenegraph(BaseViewport *viewport)
{
	//TODO generate the scenegraph

	// add the nodes to the scenegraph
	for(size_t n = 0; n < viewport->project->model.node_list.size(); n++)
	{
		this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, new SGCNode(n, *viewport->project) );
	}

	// add the surfaces to the scenegraph
	/*
	for(std::list<fem::Surface>::iterator i = viewport->project->model.surface_list.begin(); i != viewport->project->model.surface_list.end(); i++)
	{
		if(i->external())
		{
			switch(i->getType())
			{
				case fem::Element::FE_TRIANGLE3:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCFieldSurface<FieldSurfaceTriangle3>(*i, field) );
					break;

				case fem::Element::FE_TRIANGLE6:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCFieldSurface<FieldSurfaceTriangle6>(*i, field) );
					break;

				case fem::Element::FE_QUADRANGLE4:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCFieldSurface<FieldSurfaceQuad4>(*i, field) );
					break;

				case fem::Element::FE_QUADRANGLE8:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCFieldSurface<FieldSurfaceQuad8>(*i, field) );
					break;

				case fem::Element::FE_QUADRANGLE9:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, new SGCFieldSurface<FieldSurfaceQuad9>(*i, field) );
					break;

				default:
					mylog.message("unknown surface type");
					break;
			}
		}
	}
	*/

	// add the transparent surfaces to the scenegraph
	/*
	for(std::list<fem::Surface>::iterator i = viewport->project->model.surface_list.begin(); i != viewport->project->model.surface_list.end(); i++)
	{
		if(i->external())
		{
			switch(i->getType())
			{
				case fem::Element::FE_TRIANGLE3:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_GHOST_SURFACES, new SGCDisplacementOriginalSurface<SurfaceTriangle3>(*i) );
					break;

				case fem::Element::FE_TRIANGLE6:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_GHOST_SURFACES, new SGCDisplacementOriginalSurface<SurfaceTriangle6>(*i) );
					break;

				case fem::Element::FE_QUADRANGLE4:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_GHOST_SURFACES, new SGCDisplacementOriginalSurface<SurfaceQuad4>(*i) );
					break;

				case fem::Element::FE_QUADRANGLE8:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_GHOST_SURFACES, new SGCDisplacementOriginalSurface<SurfaceQuad8>(*i) );
					break;

				case fem::Element::FE_QUADRANGLE9:
					this->scenegraph.addPrimitiveComponent(SceneGraph::RG_GHOST_SURFACES, new SGCDisplacementOriginalSurface<SurfaceQuad9>(*i) );
					break;

				default:
					mylog.message("unknown surface type");
					break;
			}
		}
	}
	*/
	// generate the scene graph
	this->scenegraph.generateSceneGraph();
}


void VPStateStrain11::paintGL(BaseViewport *viewport)
{
	assert(viewport != NULL);
	assert(this->result != NULL);

	mylog.setPrefix("VPStateStrain11::paintGL()");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewport->viewport_data.camera.reposition();

	//mylog.message("painting");

	this->scenegraph.paint(viewport->viewport_data, *viewport->project, this->result, this->scale, viewport->colors);

}


void VPStateStrain11::mousePressEvent(BaseViewport *viewport, QMouseEvent *event)
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


void VPStateStrain11::keyPressEvent ( BaseViewport *viewport, QKeyEvent * event )
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
						this->setDisplacementsScale(ds.scale());

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


void VPStateStrain11::setField(FieldComponent *field)
{
	assert(field != NULL);
	//TODO finish this
	if(this->field != NULL)
		delete this->field;
	this->field = field;
}


void VPStateStrain11::selectModelObjects(const fem::point &,const fem::point &)
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
