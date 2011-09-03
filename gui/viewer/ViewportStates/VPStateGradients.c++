#include "VPStateGradients.h++"

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
#include "../SceneGraphComponents/SGCNodeRestrictions.h++"


VPStateGradients::VPStateGradients()
	: ViewportState<BaseViewport>()
{ 
	//TODO test only. remove.
	this->m_gradient_representation.setMaximumGradientValue(1);
	this->m_gradient_representation.setMinimumGradientValue(-1);
	this->m_gradient_representation.renderConstant(1);

	this->m_factory.setElementRepresentationPolicy(&m_gradient_representation);
	this->m_factory.setDisplacementsPolicy(&m_displacements);
}


VPStateGradients::~VPStateGradients()
{
	mylog.setPrefix("VPStateGradients::~VPStateGradients()");
	mylog.message("destructor called");
}


void
VPStateGradients::initialize(BaseViewport *mv)
{
	mylog.setPrefix("VPStateGradients::initialize()");
	mylog.message("initializing");
	// build the displaced_nodes from the analysis
	assert(mv != NULL);

	this->setDisplacementsScale(1.0);	//TODO tweak this value 

	this->m_gradient_representation.setModel(mv->project->model);
	this->m_displacements.setModel(mv->project->model);
}


void
VPStateGradients::populateScenegraph(BaseViewport *viewport)
{
	mylog.setPrefix("void VPStateGradients::populateScenegraph(fem::Model *viewport->project->model)");
	mylog.message("populating");

	assert(viewport != NULL);

	SceneGraphComponent * component;

	// add the nodes to the scenegraph
	for(std::map<size_t, fem::Node>::iterator i = viewport->project->model.node_list.begin(); i != viewport->project->model.node_list.end(); i++)
	{
		component =  new SGCNode(i->first, i->second, &this->m_displacements);
		if(component)
			this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, component);
	}

	/**
	for( std::map<size_t, fem::NodeRestrictions>::iterator i = viewport->project->model.node_restrictions_list.begin(); i != viewport->project->model.node_restrictions_list.end(); i++)
	{
		this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODE_RESTRICTIONS, new SGCNodeRestrictions(viewport->project->model.node_list[i->first], i->second) );
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
VPStateGradients::setAnalysisResult(fem::AnalysisResult<double> &new_result)
{
	this->m_gradient_representation.setAnalysisResult(new_result);
	this->m_displacements.setAnalysisResult(new_result);
}


void
VPStateGradients::setDisplacementsScale(float new_scale)
{
	mylog.setPrefix("VPStateGradients::setDisplacementsScale()");
	mylog.message("set scale");
	this->m_displacements.setDisplacementsScale(new_scale);
}


void
VPStateGradients::paintGL(BaseViewport *viewport)
{
	assert(viewport != NULL);

	mylog.setPrefix("VPStateGradients::paintGL()");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewport->viewport_data.camera.reposition();

	this->scenegraph.paint(viewport->viewport_data,  viewport->colors);

}


void
VPStateGradients::mousePressEvent(BaseViewport *viewport, QMouseEvent *event)
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
VPStateGradients::keyPressEvent ( BaseViewport *viewport, QKeyEvent * event )
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


void
VPStateGradients::renderStrains11()
{
	qWarning("void VPStateGradients::renderStrains11()");
	this->m_gradient_representation.renderStrains11();
}


void
VPStateGradients::renderStrains22()
{
	qWarning("void VPStateGradients::renderStrains22()");
	//TODO test only. change this
	//this->m_gradient_representation.renderNeutral();
	this->m_gradient_representation.renderConstant(-0.5);
}


void
VPStateGradients::selectModelObjects(const fem::point &,const fem::point &)
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
