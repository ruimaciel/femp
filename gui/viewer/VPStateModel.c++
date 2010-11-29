#include "VPStateModel.h++"

#include <map>
#include <list>
#include <algorithm>

#include <GL/gl.h>
#include <GL/glu.h>	// for gluQuadric()

#include "Logs.h++"	// declare the global message loggers

#include "../fem/Model.h++"
#include "../fem/Surface.h++"

#include "ModelViewport.h++"


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
		this->scenegraph.addPrimitiveComponent(i->second);
	}

	// add the surfaces to the scenegraph
	for(std::list<fem::Surface>::iterator i = mv->model->surface_list.begin(); i != mv->model->surface_list.end(); i++)
	{
		if(i->external())
		{
			this->scenegraph.addPrimitiveComponent(*i);
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


void VPStateModel::crudePaintHack(ModelViewport *mv)
{
	using namespace fem;

	mylog.setPrefix("void VPStateModel::crudePaintHack(fem::Model *mv->model)");
	mylog.message("painting");


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mv->viewport_data.camera.reposition();

	std::cout << "pos: " << mv->viewport_data.camera.pos << "\trot: " << mv->viewport_data.camera.rotation << "\tzoom: " << mv->viewport_data.zoom << std::endl;

	/*
	glBegin(GL_TRIANGLES);
	glColor3f(1,1,1);
	glVertex3f(0,0,0);
	glVertex3f(1,0,0);
	glVertex3f(0,1,0);
	glEnd();
	paintNode(mv->model,mv->colors,1,point(0,0,0));
	// */

	mylog.message("painting nodes");
	// paint nodes
	for( std::map<size_t, Node>::iterator node = mv->model->node_list.begin(); node != mv->model->node_list.end(); node++)
	{
		if(std::find(mv->viewport_data.selected_node_list.begin(), mv->viewport_data.selected_node_list.end(), node->first) == mv->viewport_data.selected_node_list.end())
			paintNode(mv->viewport_data,mv->colors.node,node->second);
		else
			paintNode(mv->viewport_data,mv->colors.selected,node->second);
	}

	mylog.message("painting surfaces");
	// paint external surfaces
	for( std::list<Surface>::iterator surface = mv->model->surface_list.begin(); surface != mv->model->surface_list.end(); surface++)
	{
		if(surface->external())
		{
			switch(surface->type)
			{
				case Element::FE_TRIANGLE3:
					glColor3fv(mv->colors.tetrahedron4);
					renderTriangle3(mv->model->node_list[surface->nodes[0]], mv->model->node_list[surface->nodes[1]], mv->model->node_list[surface->nodes[2]]);
					break;

				case Element::FE_TRIANGLE6:
					glColor3fv(mv->colors.tetrahedron4);
					renderTriangle6(mv->model->node_list[surface->nodes[0]], mv->model->node_list[surface->nodes[1]], mv->model->node_list[surface->nodes[2]], mv->model->node_list[surface->nodes[3]], mv->model->node_list[surface->nodes[4]], mv->model->node_list[surface->nodes[5]]);
					break;

				case Element::FE_QUADRANGLE4:
					glColor3fv(mv->colors.tetrahedron4);
					renderQuad4(mv->model->node_list[surface->nodes[0]], mv->model->node_list[surface->nodes[1]], mv->model->node_list[surface->nodes[2]], mv->model->node_list[surface->nodes[3]]);
					break;

				case Element::FE_QUADRANGLE8:
					glColor3fv(mv->colors.tetrahedron4);
					renderQuad8(mv->model->node_list[surface->nodes[0]], mv->model->node_list[surface->nodes[1]], mv->model->node_list[surface->nodes[2]], mv->model->node_list[surface->nodes[3]], mv->model->node_list[surface->nodes[4]],  mv->model->node_list[surface->nodes[5]],mv->model->node_list[surface->nodes[6]],  mv->model->node_list[surface->nodes[7]]);
					break;

				case Element::FE_QUADRANGLE9:
					glColor3fv(mv->colors.tetrahedron4);
					renderQuad9(mv->model->node_list[surface->nodes[0]], mv->model->node_list[surface->nodes[1]], mv->model->node_list[surface->nodes[2]], mv->model->node_list[surface->nodes[3]], mv->model->node_list[surface->nodes[4]], mv->model->node_list[surface->nodes[5]],mv->model->node_list[surface->nodes[6]],  mv->model->node_list[surface->nodes[7]], mv->model->node_list[surface->nodes[8]] );
					break;

				default:
					mylog.message("unknown surface");
					break;
			}
		}
	}
}


inline void VPStateModel::renderLine3(const fem::point &p1, const fem::point &p2, const fem::point &p3, int partitions)
{
	glBegin(GL_LINE_STRIP); 
	for(int i = 0; i <= partitions; i++) 
	{ 
		float x = i/(float)partitions; 
		glVertex3dv( (2.0*p3*(x-0.5)*x-4.0*p2*(x-1)*x+2.0*p1*(x-1)*(x-0.5)).data); 
	} 
	glEnd();
}


inline void VPStateModel::renderQuad4(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, int partitions)
{
	// defining temporary structures for points and normal vectors
	fem::point p_upper_row[partitions+1];
	fem::point *pu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;
	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = p3*x*y+p4*(1-x)*y+p2*x*(1-y)+p1*(1-x)*(1-y);

		// and now set the normal vector
		dndx = p3*y-p4*y+p2*(1-y)-p1*(1-y);
		dndy = p3*x-p2*x+p4*(1-x)-p1*(1-x);
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	// the rest of the loop
	for (int j = 1; j <= partitions; j++)  
	{ 
		y = (double)j/partitions;
		// and now let's render
		glBegin(GL_TRIANGLE_STRIP);  
		for (int i = 0; i <= partitions; i++)  
		{ 
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = p3*x*y+p4*(1-x)*y+p2*x*(1-y)+p1*(1-x)*(1-y);

			// and now set the normal vector
			dndx = p3*y-p4*y+p2*(1-y)-p1*(1-y);
			dndy = p3*x-p2*x+p4*(1-x)-p1*(1-x);

			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glVertex3dv(pu[i].data);
			glNormal3dv(nl[i].data);
			glVertex3dv(pl[i].data);
		} 
		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;
		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;

		glEnd(); 
	} 
}

inline void VPStateModel::renderQuad8(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, int partitions)
{
/*
	^ y
	|
	4 -- 7 -- 3
	|         |
	8         6
	|         |
	1 -- 5 -- 2 --> x
*/
	// defining temporary structures for points and normal vectors
	fem::point p_upper_row[partitions+1];
	fem::point *pu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;
	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		//p_lower_row[i] = 16.0*p6*(1-x)*x*(1-y)*y - 8.0*p4*(0.5-x)*x*(1-y)*y + 8.0*p8*(0.5-x)*(1-x)*(1-y)*y - 8.0*p3*(1-x)*x*(0.5-y)*y + 4.0*p3*(0.5-x)*x*(0.5-y)*y - 4.0*p7*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*p5*(1-x)*x*(0.5-y)*(1-y) - 4.0*p2*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*p1*(0.5-x)*(1-x)*(0.5-y)*(1-y);
		p_lower_row[i] = 2.0*p3*x*y*(y+x-3/2.0) + 2.0*p4*(1-x)*y*(y-x-1/2.0) + 4.0*p6*x*(1-y)*y + 4.0*p8*(1-x)*(1-y)*y + 4.0*p7*(1-x)*x*y + 2.0*p2*x*(1-y)*(-y+x-1/2.0) + 2.0*p1*(1-x)*(1-y)*(-y-x+1/2.0) + 4.0*p5*(1-x)*x*(1-y);

		// and now set the normal vector
		// dndx = 8.0*p4*x*(1-y)*y-16.0*p6*x*(1-y)*y+16.0*p6*(1-x)*(1-y)*y-8.0*p8*(1-x)*(1-y)*y-8.0*p4*(0.5-x)*(1-y)*y-8.0*p8*(0.5-x)*(1-y)*y-4.0*p3*x*(0.5-y)*y+8.0*p3*x*(0.5-y)*y-8.0*p3*(1-x)*(0.5-y)*y +4.0*p7*(1-x)*(0.5-y)*y+4.0*p3*(0.5-x)*(0.5-y)*y+4.0*p7*(0.5-x)*(0.5-y)*y+4.0*p2*x*(0.5-y)*(1-y)-8.0*p5*x*(0.5-y)*(1-y)+8.0*p5*(1-x)*(0.5-y)*(1-y)-4.0*p1*(1-x)*(0.5-y)*(1-y) -4.0*p2*(0.5-x)*(0.5-y)*(1-y)-4.0*p1*(0.5-x)*(0.5-y)*(1-y);
		dndx = 2*p3*y*(y+x-3/2.0)-2*p4*y*(y-x-1/2.0)+4*p6*(1-y)*y-4*p8*(1-y)*y+2*p3*x*y-4*p7*x*y+4*p7*(1-x)*y-2*p4*(1-x)*y+2*p2*(1-y)*(-y+x-1/2.0)-2*p1*(1-y)*(-y-x+1/2.0)+2*p2*x*(1-y)-4*p5*x*(1-y) +4*p5*(1-x)*(1-y)-2*p1*(1-x)*(1-y);

		// dndy = 8.0*p3*(1-x)*x*y-16.0*p6*(1-x)*x*y-4.0*p3*(0.5-x)*x*y+8.0*p4*(0.5-x)*x*y+4.0*p7*(0.5-x)*(1-x)*y-8.0*p8*(0.5-x)*(1-x)*y+16.0*p6*(1-x)*x*(1-y)-8.0*p5*(1-x)*x*(1-y)-8.0*p4*(0.5-x)*x*(1-y) +4.0*p2*(0.5-x)*x*(1-y)+8.0*p8*(0.5-x)*(1-x)*(1-y)-4.0*p1*(0.5-x)*(1-x)*(1-y)-8.0*p3*(1-x)*x*(0.5-y)-8.0*p5*(1-x)*x*(0.5-y)+4.0*p3*(0.5-x)*x*(0.5-y)+4.0*p2*(0.5-x)*x*(0.5-y) -4.0*p7*(0.5-x)*(1-x)*(0.5-y)-4.0*p1*(0.5-x)*(1-x)*(0.5-y);
		dndy = 2*p3*x*(y+x-3/2.0)+2*p4*(1-x)*(y-x-1/2.0)+2*p3*x*y-4*p6*x*y+2*p4*(1-x)*y-4*p8*(1-x)*y-2*p2*x*(-y+x-1/2.0)-2*p1*(1-x)*(-y-x+1/2.0)+4*p6*x*(1-y)-2*p2*x*(1-y)+4*p8*(1-x)*(1-y) - 2*p1*(1-x)*(1-y)+4*p7*(1-x)*x-4*p5*(1-x)*x;

		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	// the rest of the loop
	for (int j = 1; j <= partitions; j++)  
	{ 
		y = (double)j/partitions;
		// and now let's render
		glBegin(GL_TRIANGLE_STRIP);  
		for (int i = 0; i <= partitions; i++)  
		{ 
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = 2*p3*x*y*(y+x-3/2.0) + 2*p4*(1-x)*y*(y-x-1/2.0) + 4*p6*x*(1-y)*y + 4*p8*(1-x)*(1-y)*y + 4*p7*(1-x)*x*y + 2*p2*x*(1-y)*(-y+x-1/2.0) + 2*p1*(1-x)*(1-y)*(-y-x+1/2.0) + 4*p5*(1-x)*x*(1-y);

			// and now set the normal vector for the upper row
			dndx = 2*p3*y*(y+x-3/2.0)-2*p4*y*(y-x-1/2.0)+4*p6*(1-y)*y-4*p8*(1-y)*y+2*p3*x*y-4*p7*x*y+4*p7*(1-x)*y-2*p4*(1-x)*y+2*p2*(1-y)*(-y+x-1/2.0)-2*p1*(1-y)*(-y-x+1/2.0)+2*p2*x*(1-y)-4*p5*x*(1-y) +4*p5*(1-x)*(1-y)-2*p1*(1-x)*(1-y);
			dndy = 2*p3*x*(y+x-3/2.0)+2*p4*(1-x)*(y-x-1/2.0)+2*p3*x*y-4*p6*x*y+2*p4*(1-x)*y-4*p8*(1-x)*y-2*p2*x*(-y+x-1/2.0)-2*p1*(1-x)*(-y-x+1/2.0)+4*p6*x*(1-y)-2*p2*x*(1-y)+4*p8*(1-x)*(1-y) - 2*p1*(1-x)*(1-y)+4*p7*(1-x)*x-4*p5*(1-x)*x;

			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glVertex3dv(pu[i].data);
			glNormal3dv(nl[i].data);
			glVertex3dv(pl[i].data);
		} 
		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;
		glEnd(); 
	} 
}


inline void VPStateModel::renderQuad9(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, const fem::point &p9, int partitions)
{
/*
	^ y
	|
	4 -- 7 -- 3
	|         |
	8    9    6
	|         |
	1 -- 5 -- 2 --> x
*/
	// defining temporary structures for points and normal vectors
	fem::point p_upper_row[partitions+1];
	fem::point *pu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;
	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = 16.0*p9*(1-x)*x*(1-y)*y - 8.0*p6*(0.5-x)*x*(1-y)*y + 8.0*p8*(0.5-x)*(1-x)*(1-y)*y - 8.0*p7*(1-x)*x*(0.5-y)*y + 4.0*p3*(0.5-x)*x*(0.5-y)*y - 4.0*p4*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*p5*(1-x)*x*(0.5-y)*(1-y) - 4.0*p2*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*p1*(0.5-x)*(1-x)*(0.5-y)*(1-y);

		// and now set the normal vector
		dndx = 8.0*p6*x*(1-y)*y-16.0*p9*x*(1-y)*y+16.0*p9*(1-x)*(1-y)*y-8.0*p8*(1-x)*(1-y)*y-8.0*p6*(0.5-x)*(1-y)*y-8.0*p8*(0.5-x)*(1-y)*y-4.0*p3*x*(0.5-y)*y+8.0*p7*x*(0.5-y)*y-8.0*p7*(1-x)*(0.5-y)*y +4.0*p4*(1-x)*(0.5-y)*y+4.0*p3*(0.5-x)*(0.5-y)*y+4.0*p4*(0.5-x)*(0.5-y)*y+4.0*p2*x*(0.5-y)*(1-y)-8.0*p5*x*(0.5-y)*(1-y)+8.0*p5*(1-x)*(0.5-y)*(1-y)-4.0*p1*(1-x)*(0.5-y)*(1-y) -4.0*p2*(0.5-x)*(0.5-y)*(1-y)-4.0*p1*(0.5-x)*(0.5-y)*(1-y);
		dndy = 8.0*p7*(1-x)*x*y-16.0*p9*(1-x)*x*y-4.0*p3*(0.5-x)*x*y+8.0*p6*(0.5-x)*x*y+4.0*p4*(0.5-x)*(1-x)*y-8.0*p8*(0.5-x)*(1-x)*y+16.0*p9*(1-x)*x*(1-y)-8.0*p5*(1-x)*x*(1-y)-8.0*p6*(0.5-x)*x*(1-y) +4.0*p2*(0.5-x)*x*(1-y)+8.0*p8*(0.5-x)*(1-x)*(1-y)-4.0*p1*(0.5-x)*(1-x)*(1-y)-8.0*p7*(1-x)*x*(0.5-y)-8.0*p5*(1-x)*x*(0.5-y)+4.0*p3*(0.5-x)*x*(0.5-y)+4.0*p2*(0.5-x)*x*(0.5-y) -4.0*p4*(0.5-x)*(1-x)*(0.5-y)-4.0*p1*(0.5-x)*(1-x)*(0.5-y);
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	// the rest of the loop
	for (int j = 1; j <= partitions; j++)  
	{ 
		y = (double)j/partitions;
		// and now let's render
		glBegin(GL_TRIANGLE_STRIP);  
		for (int i = 0; i <= partitions; i++)  
		{ 
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = 16.0*p9*(1-x)*x*(1-y)*y - 8.0*p6*(0.5-x)*x*(1-y)*y + 8.0*p8*(0.5-x)*(1-x)*(1-y)*y - 8.0*p7*(1-x)*x*(0.5-y)*y + 4.0*p3*(0.5-x)*x*(0.5-y)*y - 4.0*p4*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*p5*(1-x)*x*(0.5-y)*(1-y) - 4.0*p2*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*p1*(0.5-x)*(1-x)*(0.5-y)*(1-y);

			// and now set the normal vector for the upper row
			dndx = 8.0*p6*x*(1-y)*y-16.0*p9*x*(1-y)*y+16.0*p9*(1-x)*(1-y)*y-8.0*p8*(1-x)*(1-y)*y-8.0*p6*(0.5-x)*(1-y)*y-8.0*p8*(0.5-x)*(1-y)*y-4.0*p3*x*(0.5-y)*y+8.0*p7*x*(0.5-y)*y-8.0*p7*(1-x)*(0.5-y)*y +4.0*p4*(1-x)*(0.5-y)*y+4.0*p3*(0.5-x)*(0.5-y)*y+4.0*p4*(0.5-x)*(0.5-y)*y+4.0*p2*x*(0.5-y)*(1-y)-8.0*p5*x*(0.5-y)*(1-y)+8.0*p5*(1-x)*(0.5-y)*(1-y)-4.0*p1*(1-x)*(0.5-y)*(1-y) -4.0*p2*(0.5-x)*(0.5-y)*(1-y)-4.0*p1*(0.5-x)*(0.5-y)*(1-y);
			dndy = 8.0*p7*(1-x)*x*y-16.0*p9*(1-x)*x*y-4.0*p3*(0.5-x)*x*y+8.0*p6*(0.5-x)*x*y+4.0*p4*(0.5-x)*(1-x)*y-8.0*p8*(0.5-x)*(1-x)*y+16.0*p9*(1-x)*x*(1-y)-8.0*p5*(1-x)*x*(1-y)-8.0*p6*(0.5-x)*x*(1-y) +4.0*p2*(0.5-x)*x*(1-y)+8.0*p8*(0.5-x)*(1-x)*(1-y)-4.0*p1*(0.5-x)*(1-x)*(1-y)-8.0*p7*(1-x)*x*(0.5-y)-8.0*p5*(1-x)*x*(0.5-y)+4.0*p3*(0.5-x)*x*(0.5-y)+4.0*p2*(0.5-x)*x*(0.5-y) -4.0*p4*(0.5-x)*(1-x)*(0.5-y)-4.0*p1*(0.5-x)*(1-x)*(0.5-y);
			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glVertex3dv(pu[i].data);
			glNormal3dv(nl[i].data);
			glVertex3dv(pl[i].data);
		} 
		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;
		glEnd(); 
	} 
}


inline void VPStateModel::renderTriangle3(const fem::point &p1, const fem::point &p2, const fem::point &p3, int partitions)
{
	partitions = 1;	// just to shut up the warning
	fem::point temp;
	temp = getNormalVector(p1,p2,p3);
	glBegin(GL_TRIANGLES);
	glNormal3dv(temp.data);
	glVertex3dv(p1.data);
	glVertex3dv(p2.data);
	glVertex3dv(p3.data);
	glEnd();
}


inline void VPStateModel::renderTriangle6(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, const fem::point &p5, const fem::point &p6, int partitions)
{
/*
     v
     ^          
     |           
     2            
     |`, 
     |  `.          
     5    `4         
     |      `.        
     |        `.       
     0-----3----1 --> u 

*/
	// defining temporary structures for points and normal vectors
	fem::point p_upper_row[partitions+1];
	fem::point *pu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;
	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = p2*y*(2*y-1)+4*p6*(-y-x+1)*y+4*p5*x*y+p1*(2*(-y-x+1)-1)*(-y-x+1)+4*p4*x*(-y-x+1)+p3*x*(2*x-1);

		// and now set the normal vector
		dndx = -4*p6*y+4*p5*y+4*p4*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+p3*(2*x-1)-4*p4*x+2*p3*x;
		dndy = p2*(2*y-1)-4*p6*y+2*p2*y+4*p6*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+4*p5*x-4*p4*x;
		
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	// the rest of the loop
	for (int j = 1, i; j <= partitions; j++)  
	{ 
		y = (double)j/partitions;
		// and now let's render
		glBegin(GL_TRIANGLE_STRIP);  
		for (i = 0; i <= (partitions-j); i++)  
		{ 
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = p2*y*(2*y-1)+4*p6*(-y-x+1)*y+4*p5*x*y+p1*(2*(-y-x+1)-1)*(-y-x+1)+4*p4*x*(-y-x+1)+p3*x*(2*x-1);

			// and now set the normal vector for the upper row
			dndx = -4*p6*y+4*p5*y+4*p4*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+p3*(2*x-1)-4*p4*x+2*p3*x;
			dndy = p2*(2*y-1)-4*p6*y+2*p2*y+4*p6*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+4*p5*x-4*p4*x;
			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glVertex3dv(pu[i].data);
			glNormal3dv(nl[i].data);
			glVertex3dv(pl[i].data);
		} 
		glNormal3dv(nl[i].data);
		glVertex3dv(pl[i].data);
		glEnd(); 

		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;
	} 
}


void VPStateModel::paintNode( ViewportData &data, GLfloat color[4], const fem::point pos)
{
	glPushMatrix();
	glTranslated(pos.data[0],pos.data[1],pos.data[2]);
	
	glScalef(data.node_scale/(data.aspect_ratio*pow(2,data.zoom)), data.node_scale/(data.aspect_ratio*pow(2,data.zoom)), data.node_scale/(data.aspect_ratio*pow(2,data.zoom)));

	//TODO find a better rendering for the nodes
	glBegin(GL_LINES);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3i(0,0,0);
		glVertex3i(2,0,0);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3i(0,0,0);
		glVertex3i(0,2,0);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3i(0,0,0);
		glVertex3i(0,0,2);
	glEnd();

	//TODO paint selected node in a different color
	// paint the nodal sphere
	/*
	if(document->model_selection.isNodeSelected(label))
		glColor3f(1.0f,0,0);
	else
	*/
	glColor3fv(color);

	GLUquadric *p;
	p = gluNewQuadric();
	gluSphere(p,1,8,8);

	/*
	// paint restrictions, if there are any
	if(model->node_restrictions_list.find(label) != model->node_restrictions_list.end())
	{
		if(model->node_restrictions_list[label].dx())
		{
			glBegin(GL_TRIANGLES);
			glNormal3f(1.4142f, 0, 1.4142f);
			glVertex3i(0,0,0);
			glVertex3i(-2,2,2);
			glVertex3i(-2,-2,2);

			glNormal3f(1.4142f,-1.4142f, 0);
			glVertex3i(0,0,0);
			glVertex3i(-2,-2, 2);
			glVertex3i(-2,-2,-2);

			glNormal3f(1.4142f, 0, -1.4142f);
			glVertex3i(0,0,0);
			glVertex3i(-2,-2,-2);
			glVertex3i(-2, 2,-2);

			glNormal3f(1.4142f, 1.4142f, 0);
			glVertex3i(0,0,0);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2, 2, 2);

			// backface
			glNormal3f(-1,0,0);
			glVertex3i(-2, 2, 2);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i(-2,-2, 2);
			glVertex3i(-2, 2, 2);
			glEnd();
		}
		if(model->node_restrictions_list[label].dy())
		{
			// render the pyramid
			glBegin(GL_TRIANGLES);
			glNormal3i( 2, 0, 2);
			glVertex3i( 0, 0, 0);
			glVertex3i( 2,-2,-2);
			glVertex3i( 2, 2,-2);

			glNormal3i( 0,-2, 2);
			glVertex3i(0,0,0);
			glVertex3i(-2,-2,-2);
			glVertex3i( 2,-2,-2);

			glNormal3i(-2, 0, 2);
			glVertex3i(0,0,0);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2,-2,-2);

			glNormal3i( 0, 2, 2);
			glVertex3i(0,0,0);
			glVertex3i( 2, 2,-2);
			glVertex3i(-2, 2,-2);

			// backface
			glNormal3f( 0,0,-1);
			glVertex3i( 2, 2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i( 2, 2,-2);
			glVertex3i( 2,-2,-2);
			glEnd();
		}
		if(model->node_restrictions_list[label].dz())
		{
			glRotatef(-90,1,0,0);
			// render the pyramid
			glBegin(GL_TRIANGLES);
			glNormal3i( 2, 0, 2);
			glVertex3i( 0, 0, 0);
			glVertex3i( 2,-2,-2);
			glVertex3i( 2, 2,-2);

			glNormal3i( 0,-2, 2);
			glVertex3i(0,0,0);
			glVertex3i(-2,-2,-2);
			glVertex3i( 2,-2,-2);

			glNormal3i(-2, 0, 2);
			glVertex3i(0,0,0);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2,-2,-2);

			glNormal3i( 0, 2, 2);
			glVertex3i(0,0,0);
			glVertex3i( 2, 2,-2);
			glVertex3i(-2, 2,-2);

			// backface
			glNormal3f( 0,0,-1);
			glVertex3i( 2, 2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i( 2, 2,-2);
			glVertex3i( 2,-2,-2);
			glEnd();
		}
	}
	*/

	// end 
	glPopMatrix();
}


void VPStateModel::selectModelObjects(const fem::point &near,const fem::point &far)
{
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
}
