#include "VPStateDisplacements.h++"

#include <map>
#include <list>
#include <algorithm>
#include <iostream>

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
#include "../SceneGraphComponents/SGCNodeRestrictions.h++"


VPStateDisplacements::VPStateDisplacements()
	: ViewportState<BaseViewport>()
{ 
	this->m_factory.setElementRepresentationPolicy(m_element_representation_factory.opaque());
	this->m_factory.setDisplacementsPolicy(&m_displacements);
}


VPStateDisplacements::~VPStateDisplacements()
{
	mylog.setPrefix("VPStateDisplacements::~VPStateDisplacements()");
	mylog.message("destructor called");
}


void
VPStateDisplacements::initialize(BaseViewport *mv)
{
	mylog.setPrefix("VPStateDisplacements::initialize()");
	mylog.message("initializing");
	// build the displaced_nodes from the analysis
	assert(mv != NULL);

	this->setDisplacementsScale(1.0);	//TODO tweak this value 
	this->m_displacements.setModel(mv->project->model);
}


void
VPStateDisplacements::populateScenegraph(BaseViewport *viewport)
{
	mylog.setPrefix("void VPStateDisplacements::populateScenegraph(fem::Model *viewport->project->model)");
	mylog.message("populating");

	assert(viewport != NULL);

	SceneGraphComponent * component;

	// add the nodes to the scenegraph
	for(std::map<size_t, fem::Node>::iterator i = viewport->project->model.node_list.begin(); i != viewport->project->model.node_list.end(); i++)
	{
		component =  new SGC::Node(i->first, i->second, &this->m_displacements);
		if(component)
			this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, component);
	}

	/**
	for( std::map<size_t, fem::NodeRestrictions>::iterator i = viewport->project->model.node_restrictions_list.begin(); i != viewport->project->model.node_restrictions_list.end(); i++)
	{
		this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODE_RESTRICTIONS, new SGC::NodeRestrictions(viewport->project->model.node_list[i->first], i->second) );
	}
	**/

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


void
VPStateDisplacements::setAnalysisResult(fem::AnalysisResult<double> &new_result)
{
	this->m_displacements.setAnalysisResult(new_result);
}


void
VPStateDisplacements::setDisplacementsScale(float new_scale)
{
	mylog.setPrefix("VPStateDisplacements::setDisplacementsScale()");
	mylog.message("set scale");
	this->m_displacements.setDisplacementsScale(new_scale);
}


void 
VPStateDisplacements::setSelection(Selection)
{
	std::cout << "VPStateDisplacements::setSelection(Selection)" << std::endl;
}


void
VPStateDisplacements::paintGL(BaseViewport *viewport)
{
	assert(viewport != NULL);

	mylog.setPrefix("VPStateDisplacements::paintGL()");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewport->viewport_data.camera.reposition();

	this->scenegraph.paint(viewport->viewport_data,  viewport->colors);

}


void
VPStateDisplacements::mousePressEvent(BaseViewport *viewport, QMouseEvent *event)
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


void
VPStateDisplacements::keyPressEvent ( BaseViewport *viewport, QKeyEvent * event )
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


