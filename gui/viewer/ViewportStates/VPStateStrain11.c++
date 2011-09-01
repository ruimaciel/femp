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
	this->m_factory.setElementRepresentationPolicy(m_element_representation_factory.opaque());
	this->m_factory.setDisplacementsPolicy(&m_displacements);
}


VPStateStrain11::~VPStateStrain11()
{
}


void VPStateStrain11::initialize(BaseViewport *viewport)
{
	// build the displaced_nodes from the analysis

	assert(viewport != NULL);

	this->setDisplacementsScale(1.0);	//TODO tweak this value 
	this->m_displacements.setModel(viewport->project->model);
}


void VPStateStrain11::populateScenegraph(BaseViewport *viewport)
{
	assert(viewport != NULL);

	SceneGraphComponent * component;

	// add the nodes to the scenegraph
	for(std::map<size_t, fem::Node>::iterator i = viewport->project->model.node_list.begin(); i != viewport->project->model.node_list.end(); i++)
	{
		component =  new SGCNode(i->first, i->second, &this->m_displacements);
		if(component)
			this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, component);
	}

	//TODO render node restrictions

	// add the elements to the scenegraph
	for( std::vector<fem::Element>::iterator i = viewport->project->model.element_list.begin(); i != viewport->project->model.element_list.end(); i++)
	{
		component = this->m_factory(*i);
		if(component) 
			this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, component);
	}
	// generate the scene graph
	this->scenegraph.generateSceneGraph();
}


void VPStateStrain11::paintGL(BaseViewport *viewport)
{
	assert(viewport != NULL);

	mylog.setPrefix("VPStateStrain11::paintGL()");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewport->viewport_data.camera.reposition();

	this->scenegraph.paint(viewport->viewport_data,  viewport->colors);
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
