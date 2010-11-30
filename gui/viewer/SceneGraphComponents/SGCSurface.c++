#include "SGCSurface.h++"

#include <GL/gl.h>

#include "../Logs.h++"	// declare the global message loggers


SGCSurface::SGCSurface(fem::Surface &reference_surface)
	: SceneGraphComponent()
{
	this->setReferenceSurface(reference_surface);
}


SGCSurface::~SGCSurface()
{
}


void SGCSurface::setReferenceSurface(fem::Surface &reference_surface)
{
	this->surface = &reference_surface;

	/*
	mylog.setPrefix("SGCSurface::setReferenceSurface()");
	mylog.message("yet to be implemented");
	*/

	//TODO adjust boundary to this surface
}


void SGCSurface::paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors)
{
	assert(model != NULL);
	using namespace fem;


	switch(surface->type)
	{
		case Element::FE_TRIANGLE3:
			glColor3fv(colors.tetrahedron4);
			renderTriangle3(model->node_list[surface->nodes[0]], model->node_list[surface->nodes[1]], model->node_list[surface->nodes[2]]);
			break;

		case Element::FE_TRIANGLE6:
			glColor3fv(colors.tetrahedron4);
			renderTriangle6(model->node_list[surface->nodes[0]], model->node_list[surface->nodes[1]], model->node_list[surface->nodes[2]], model->node_list[surface->nodes[3]], model->node_list[surface->nodes[4]], model->node_list[surface->nodes[5]]);
			break;

		case Element::FE_QUADRANGLE4:
			glColor3fv(colors.tetrahedron4);
			renderQuad4(model->node_list[surface->nodes[0]], model->node_list[surface->nodes[1]], model->node_list[surface->nodes[2]], model->node_list[surface->nodes[3]]);
			break;

		case Element::FE_QUADRANGLE8:
			glColor3fv(colors.tetrahedron4);
			renderQuad8(model->node_list[surface->nodes[0]], model->node_list[surface->nodes[1]], model->node_list[surface->nodes[2]], model->node_list[surface->nodes[3]], model->node_list[surface->nodes[4]],  model->node_list[surface->nodes[5]],model->node_list[surface->nodes[6]],  model->node_list[surface->nodes[7]]);
			break;

		case Element::FE_QUADRANGLE9:
			glColor3fv(colors.tetrahedron4);
			renderQuad9(model->node_list[surface->nodes[0]], model->node_list[surface->nodes[1]], model->node_list[surface->nodes[2]], model->node_list[surface->nodes[3]], model->node_list[surface->nodes[4]], model->node_list[surface->nodes[5]],model->node_list[surface->nodes[6]],  model->node_list[surface->nodes[7]], model->node_list[surface->nodes[8]] );
			break;

		default:
			mylog.setPrefix("SGCSurface::paintGL()");
			mylog.message("unknown surface");
			break;
	}
}


inline void SGCSurface::renderLine3(const fem::point &p1, const fem::point &p2, const fem::point &p3, int partitions)
{
	glBegin(GL_LINE_STRIP); 
	for(int i = 0; i <= partitions; i++) 
	{ 
		float x = i/(float)partitions; 
		glVertex3dv( (2.0*p3*(x-0.5)*x-4.0*p2*(x-1)*x+2.0*p1*(x-1)*(x-0.5)).data); 
	} 
	glEnd();
}


inline void SGCSurface::renderQuad4(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, int partitions)
{
/*
	^ y
	|
	4 ------ 3
	|        |
	|        |
	|        |
	1 ------ 2 --> x
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

inline void SGCSurface::renderQuad8(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, int partitions)
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


inline void SGCSurface::renderQuad9(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, const fem::point &p9, int partitions)
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


inline void SGCSurface::renderTriangle3(const fem::point &p1, const fem::point &p2, const fem::point &p3, int partitions)
{
/*
     v
     ^          
     |           
     2            
     |`, 
     |  `.          
     |    `.         
     |      `.        
     |        `.       
     0----------1 --> u 

*/
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


inline void SGCSurface::renderTriangle6(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, const fem::point &p5, const fem::point &p6, int partitions)
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


void SGCSurface::accept(OperationsVisitor &v)
{
	v.visit(*this);
}
