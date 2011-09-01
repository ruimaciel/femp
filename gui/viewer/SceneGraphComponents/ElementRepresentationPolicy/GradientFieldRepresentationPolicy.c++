#include "GradientFieldRepresentationPolicy.h++"

#include <GL/gl.h>

// Constructors/Destructors
//  

GradientFieldRepresentationPolicy::GradientFieldRepresentationPolicy ( ) 
{
	m_temp_p.reserve(27);	// to accomodate the maximum number of points
	m_gradient = NULL;
}


GradientFieldRepresentationPolicy::~GradientFieldRepresentationPolicy ( ) 
{ 
}


// Other methods
//  
void
GradientFieldRepresentationPolicy::tri3(p_index_t p1, p_index_t p2, p_index_t p3, ViewportColors &colors)
{
	glEnable(GL_BLEND);

	//int partitions = 4;	//TODO implement a better code

	fem::point temp;
	fem::point ptemp;
	temp = fem::getNormalVector(m_temp_p[p1],m_temp_p[p2],m_temp_p[p3]);
	
	glBegin(GL_TRIANGLES);
	glNormal3dv(temp.data);
	ptemp.set(0,0);  
	glColor3fv( m_gradient->tri3(p1, p2, p3, ptemp, colors) );
	glVertex3dv(m_temp_p[p1].data);

	ptemp.set(1,0);  
	glColor3fv( m_gradient->tri3(p1, p2, p3, ptemp, colors) );
	glVertex3dv(m_temp_p[p2].data);

	ptemp.set(0,1);  
	glColor3fv( m_gradient->tri3(p1, p2, p3, ptemp, colors) );
	glVertex3dv(m_temp_p[p3].data);

	glEnd();
	glDisable(GL_BLEND);
}


void
GradientFieldRepresentationPolicy::tri6(p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4,p_index_t p5, p_index_t p6, ViewportColors &color)
{
	glEnable(GL_BLEND);
	int partitions = 6;	//TODO implement a better code

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
		p_lower_row[i] = m_temp_p[p3]*y*(2*y-1)+4*m_temp_p[p6]*(-y-x+1)*y+4*m_temp_p[p5]*x*y+m_temp_p[p1]*(2*(-y-x+1)-1)*(-y-x+1)+4*m_temp_p[p4]*x*(-y-x+1)+m_temp_p[p2]*x*(2*x-1);

		// and now set the normal vector
		dndx = -4*m_temp_p[p6]*y+4*m_temp_p[p5]*y+4*m_temp_p[p4]*(-y-x+1)-2*m_temp_p[p1]*(-y-x+1)-m_temp_p[p1]*(2*(-y-x+1)-1)+m_temp_p[p2]*(2*x-1)-4*m_temp_p[p4]*x+2*m_temp_p[p2]*x;
		dndy = m_temp_p[p3]*(2*y-1)-4*m_temp_p[p6]*y+2*m_temp_p[p3]*y+4*m_temp_p[p6]*(-y-x+1)-2*m_temp_p[p1]*(-y-x+1)-m_temp_p[p1]*(2*(-y-x+1)-1)+4*m_temp_p[p5]*x-4*m_temp_p[p4]*x;
		
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	// the rest of the loop
	for (int j = 1, i; j <= partitions; j++)  
	{ 
		y = (double)j/partitions;
		// and now let's render
		glBegin(GL_TRIANGLE_STRIP);  
		glColor4fv(color.surface);
		for (i = 0; i <= (partitions-j); i++)  
		{ 
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = m_temp_p[p3]*y*(2*y-1)+4*m_temp_p[p6]*(-y-x+1)*y+4*m_temp_p[p5]*x*y+m_temp_p[p1]*(2*(-y-x+1)-1)*(-y-x+1)+4*m_temp_p[p4]*x*(-y-x+1)+m_temp_p[p2]*x*(2*x-1);

			// and now set the normal vector for the upper row
			dndx = -4*m_temp_p[p6]*y+4*m_temp_p[p5]*y+4*m_temp_p[p4]*(-y-x+1)-2*m_temp_p[p1]*(-y-x+1)-m_temp_p[p1]*(2*(-y-x+1)-1)+m_temp_p[p2]*(2*x-1)-4*m_temp_p[p4]*x+2*m_temp_p[p2]*x;
			dndy = m_temp_p[p3]*(2*y-1)-4*m_temp_p[p6]*y+2*m_temp_p[p3]*y+4*m_temp_p[p6]*(-y-x+1)-2*m_temp_p[p1]*(-y-x+1)-m_temp_p[p1]*(2*(-y-x+1)-1)+4*m_temp_p[p5]*x-4*m_temp_p[p4]*x;
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
	glDisable(GL_BLEND);
}


void
GradientFieldRepresentationPolicy::quad4(p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, ViewportColors &color)
{
	glEnable(GL_BLEND);
	int partitions = 3;	//TODO implement a better code

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
		p_lower_row[i] = m_temp_p[p3]*x*y+m_temp_p[p4]*(1-x)*y+m_temp_p[p2]*x*(1-y)+m_temp_p[p1]*(1-x)*(1-y);

		// and now set the normal vector
		dndx = m_temp_p[p3]*y-m_temp_p[p4]*y+m_temp_p[p2]*(1-y)-m_temp_p[p1]*(1-y);
		dndy = m_temp_p[p3]*x-m_temp_p[p2]*x+m_temp_p[p4]*(1-x)-m_temp_p[p1]*(1-x);
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	glColor4fv(color.surface);

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
			pu[i] = m_temp_p[p3]*x*y+m_temp_p[p4]*(1-x)*y+m_temp_p[p2]*x*(1-y)+m_temp_p[p1]*(1-x)*(1-y);

			// and now set the normal vector
			dndx = m_temp_p[p3]*y-m_temp_p[p4]*y+m_temp_p[p2]*(1-y)-m_temp_p[p1]*(1-y);
			dndy = m_temp_p[p3]*x-m_temp_p[p2]*x+m_temp_p[p4]*(1-x)-m_temp_p[p1]*(1-x);

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
	glDisable(GL_BLEND);
}


void
GradientFieldRepresentationPolicy::quad8(p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, p_index_t p5, p_index_t p6, p_index_t p7, p_index_t p8, ViewportColors &color)
{
	glEnable(GL_BLEND);
	int partitions = 6;	//TODO implement a better code

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

	glColor4fv(color.surface);

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = 2.0*m_temp_p[p3]*x*y*(y+x-3/2.0) + 2.0*m_temp_p[p4]*(1-x)*y*(y-x-1/2.0) + 4.0*m_temp_p[p6]*x*(1-y)*y + 4.0*m_temp_p[p8]*(1-x)*(1-y)*y + 4.0*m_temp_p[p7]*(1-x)*x*y + 2.0*m_temp_p[p2]*x*(1-y)*(-y+x-1/2.0) + 2.0*m_temp_p[p1]*(1-x)*(1-y)*(-y-x+1/2.0) + 4.0*m_temp_p[p5]*(1-x)*x*(1-y);

		// and now set the normal vector
		dndx = 2*m_temp_p[p3]*y*(y+x-3/2.0)-2*m_temp_p[p4]*y*(y-x-1/2.0)+4*m_temp_p[p6]*(1-y)*y-4*m_temp_p[p8]*(1-y)*y+2*m_temp_p[p3]*x*y-4*m_temp_p[p7]*x*y+4*m_temp_p[p7]*(1-x)*y-2*m_temp_p[p4]*(1-x)*y+2*m_temp_p[p2]*(1-y)*(-y+x-1/2.0)-2*m_temp_p[p1]*(1-y)*(-y-x+1/2.0)+2*m_temp_p[p2]*x*(1-y)-4*m_temp_p[p5]*x*(1-y) +4*m_temp_p[p5]*(1-x)*(1-y)-2*m_temp_p[p1]*(1-x)*(1-y);

		dndy = 2*m_temp_p[p3]*x*(y+x-3/2.0)+2*m_temp_p[p4]*(1-x)*(y-x-1/2.0)+2*m_temp_p[p3]*x*y-4*m_temp_p[p6]*x*y+2*m_temp_p[p4]*(1-x)*y-4*m_temp_p[p8]*(1-x)*y-2*m_temp_p[p2]*x*(-y+x-1/2.0)-2*m_temp_p[p1]*(1-x)*(-y-x+1/2.0)+4*m_temp_p[p6]*x*(1-y)-2*m_temp_p[p2]*x*(1-y)+4*m_temp_p[p8]*(1-x)*(1-y) - 2*m_temp_p[p1]*(1-x)*(1-y)+4*m_temp_p[p7]*(1-x)*x-4*m_temp_p[p5]*(1-x)*x;

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
			pu[i] = 2*m_temp_p[p3]*x*y*(y+x-3/2.0) + 2*m_temp_p[p4]*(1-x)*y*(y-x-1/2.0) + 4*m_temp_p[p6]*x*(1-y)*y + 4*m_temp_p[p8]*(1-x)*(1-y)*y + 4*m_temp_p[p7]*(1-x)*x*y + 2*m_temp_p[p2]*x*(1-y)*(-y+x-1/2.0) + 2*m_temp_p[p1]*(1-x)*(1-y)*(-y-x+1/2.0) + 4*m_temp_p[p5]*(1-x)*x*(1-y);

			// and now set the normal vector for the upper row
			dndx = 2*m_temp_p[p3]*y*(y+x-3/2.0)-2*m_temp_p[p4]*y*(y-x-1/2.0)+4*m_temp_p[p6]*(1-y)*y-4*m_temp_p[p8]*(1-y)*y+2*m_temp_p[p3]*x*y-4*m_temp_p[p7]*x*y+4*m_temp_p[p7]*(1-x)*y-2*m_temp_p[p4]*(1-x)*y+2*m_temp_p[p2]*(1-y)*(-y+x-1/2.0)-2*m_temp_p[p1]*(1-y)*(-y-x+1/2.0)+2*m_temp_p[p2]*x*(1-y)-4*m_temp_p[p5]*x*(1-y) +4*m_temp_p[p5]*(1-x)*(1-y)-2*m_temp_p[p1]*(1-x)*(1-y);
			dndy = 2*m_temp_p[p3]*x*(y+x-3/2.0)+2*m_temp_p[p4]*(1-x)*(y-x-1/2.0)+2*m_temp_p[p3]*x*y-4*m_temp_p[p6]*x*y+2*m_temp_p[p4]*(1-x)*y-4*m_temp_p[p8]*(1-x)*y-2*m_temp_p[p2]*x*(-y+x-1/2.0)-2*m_temp_p[p1]*(1-x)*(-y-x+1/2.0)+4*m_temp_p[p6]*x*(1-y)-2*m_temp_p[p2]*x*(1-y)+4*m_temp_p[p8]*(1-x)*(1-y) - 2*m_temp_p[p1]*(1-x)*(1-y)+4*m_temp_p[p7]*(1-x)*x-4*m_temp_p[p5]*(1-x)*x;

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
	glDisable(GL_BLEND);
}


void
GradientFieldRepresentationPolicy::quad9(p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, p_index_t p5, p_index_t p6, p_index_t p7, p_index_t p8, p_index_t p9, ViewportColors &color)
{
	glEnable(GL_BLEND);
	int partitions = 6;	//TODO implement a better code

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
		p_lower_row[i] = 16.0*m_temp_p[p9]*(1-x)*x*(1-y)*y - 8.0*m_temp_p[p6]*(0.5-x)*x*(1-y)*y + 8.0*m_temp_p[p8]*(0.5-x)*(1-x)*(1-y)*y - 8.0*m_temp_p[p7]*(1-x)*x*(0.5-y)*y + 4.0*m_temp_p[p3]*(0.5-x)*x*(0.5-y)*y - 4.0*m_temp_p[p4]*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*m_temp_p[p5]*(1-x)*x*(0.5-y)*(1-y) - 4.0*m_temp_p[p2]*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(0.5-y)*(1-y);

		// and now set the normal vector
		dndx = 8.0*m_temp_p[p6]*x*(1-y)*y-16.0*m_temp_p[p9]*x*(1-y)*y+16.0*m_temp_p[p9]*(1-x)*(1-y)*y-8.0*m_temp_p[p8]*(1-x)*(1-y)*y-8.0*m_temp_p[p6]*(0.5-x)*(1-y)*y-8.0*m_temp_p[p8]*(0.5-x)*(1-y)*y-4.0*m_temp_p[p3]*x*(0.5-y)*y+8.0*m_temp_p[p7]*x*(0.5-y)*y-8.0*m_temp_p[p7]*(1-x)*(0.5-y)*y +4.0*m_temp_p[p4]*(1-x)*(0.5-y)*y+4.0*m_temp_p[p3]*(0.5-x)*(0.5-y)*y+4.0*m_temp_p[p4]*(0.5-x)*(0.5-y)*y+4.0*m_temp_p[p2]*x*(0.5-y)*(1-y)-8.0*m_temp_p[p5]*x*(0.5-y)*(1-y)+8.0*m_temp_p[p5]*(1-x)*(0.5-y)*(1-y)-4.0*m_temp_p[p1]*(1-x)*(0.5-y)*(1-y) -4.0*m_temp_p[p2]*(0.5-x)*(0.5-y)*(1-y)-4.0*m_temp_p[p1]*(0.5-x)*(0.5-y)*(1-y);
		dndy = 8.0*m_temp_p[p7]*(1-x)*x*y-16.0*m_temp_p[p9]*(1-x)*x*y-4.0*m_temp_p[p3]*(0.5-x)*x*y+8.0*m_temp_p[p6]*(0.5-x)*x*y+4.0*m_temp_p[p4]*(0.5-x)*(1-x)*y-8.0*m_temp_p[p8]*(0.5-x)*(1-x)*y+16.0*m_temp_p[p9]*(1-x)*x*(1-y)-8.0*m_temp_p[p5]*(1-x)*x*(1-y)-8.0*m_temp_p[p6]*(0.5-x)*x*(1-y) +4.0*m_temp_p[p2]*(0.5-x)*x*(1-y)+8.0*m_temp_p[p8]*(0.5-x)*(1-x)*(1-y)-4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(1-y)-8.0*m_temp_p[p7]*(1-x)*x*(0.5-y)-8.0*m_temp_p[p5]*(1-x)*x*(0.5-y)+4.0*m_temp_p[p3]*(0.5-x)*x*(0.5-y)+4.0*m_temp_p[p2]*(0.5-x)*x*(0.5-y) -4.0*m_temp_p[p4]*(0.5-x)*(1-x)*(0.5-y)-4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(0.5-y);
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	glColor4fv(color.surface);

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
			pu[i] = 16.0*m_temp_p[p9]*(1-x)*x*(1-y)*y - 8.0*m_temp_p[p6]*(0.5-x)*x*(1-y)*y + 8.0*m_temp_p[p8]*(0.5-x)*(1-x)*(1-y)*y - 8.0*m_temp_p[p7]*(1-x)*x*(0.5-y)*y + 4.0*m_temp_p[p3]*(0.5-x)*x*(0.5-y)*y - 4.0*m_temp_p[p4]*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*m_temp_p[p5]*(1-x)*x*(0.5-y)*(1-y) - 4.0*m_temp_p[p2]*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(0.5-y)*(1-y);

			// and now set the normal vector for the upper row
			dndx = 8.0*m_temp_p[p6]*x*(1-y)*y-16.0*m_temp_p[p9]*x*(1-y)*y+16.0*m_temp_p[p9]*(1-x)*(1-y)*y-8.0*m_temp_p[p8]*(1-x)*(1-y)*y-8.0*m_temp_p[p6]*(0.5-x)*(1-y)*y-8.0*m_temp_p[p8]*(0.5-x)*(1-y)*y-4.0*m_temp_p[p3]*x*(0.5-y)*y+8.0*m_temp_p[p7]*x*(0.5-y)*y-8.0*m_temp_p[p7]*(1-x)*(0.5-y)*y +4.0*m_temp_p[p4]*(1-x)*(0.5-y)*y+4.0*m_temp_p[p3]*(0.5-x)*(0.5-y)*y+4.0*m_temp_p[p4]*(0.5-x)*(0.5-y)*y+4.0*m_temp_p[p2]*x*(0.5-y)*(1-y)-8.0*m_temp_p[p5]*x*(0.5-y)*(1-y)+8.0*m_temp_p[p5]*(1-x)*(0.5-y)*(1-y)-4.0*m_temp_p[p1]*(1-x)*(0.5-y)*(1-y) -4.0*m_temp_p[p2]*(0.5-x)*(0.5-y)*(1-y)-4.0*m_temp_p[p1]*(0.5-x)*(0.5-y)*(1-y);
			dndy = 8.0*m_temp_p[p7]*(1-x)*x*y-16.0*m_temp_p[p9]*(1-x)*x*y-4.0*m_temp_p[p3]*(0.5-x)*x*y+8.0*m_temp_p[p6]*(0.5-x)*x*y+4.0*m_temp_p[p4]*(0.5-x)*(1-x)*y-8.0*m_temp_p[p8]*(0.5-x)*(1-x)*y+16.0*m_temp_p[p9]*(1-x)*x*(1-y)-8.0*m_temp_p[p5]*(1-x)*x*(1-y)-8.0*m_temp_p[p6]*(0.5-x)*x*(1-y) +4.0*m_temp_p[p2]*(0.5-x)*x*(1-y)+8.0*m_temp_p[p8]*(0.5-x)*(1-x)*(1-y)-4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(1-y)-8.0*m_temp_p[p7]*(1-x)*x*(0.5-y)-8.0*m_temp_p[p5]*(1-x)*x*(0.5-y)+4.0*m_temp_p[p3]*(0.5-x)*x*(0.5-y)+4.0*m_temp_p[p2]*(0.5-x)*x*(0.5-y) -4.0*m_temp_p[p4]*(0.5-x)*(1-x)*(0.5-y)-4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(0.5-y);
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
	glDisable(GL_BLEND);
}


/**
 */
void
GradientFieldRepresentationPolicy::tetra4 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_TETRAHEDRON4);
	assert(element.nodes.size() == 4);
	assert(m_gradient != NULL);

	m_gradient->calculateGradientValues(element);

	// generate a temporary list of all nodes
	m_temp_p.resize(4);
	for(int i = 0; i < 4; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	// render each surface
	tri3( 0, 3, 2, color);
	tri3( 1, 0, 2, color);
	tri3( 3, 1, 2, color);
	tri3( 0, 1, 3, color);
}


/**
 */
void
GradientFieldRepresentationPolicy::tetra10 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_TETRAHEDRON10);
	assert(element.nodes.size() == 10);
	assert(m_gradient != NULL);

	m_gradient->calculateGradientValues(element);


	// generate a temporary list of all nodes
	m_temp_p.resize(10);
	for(int i = 0; i < 10; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	// render each surface
	tri6( 0, 3, 2, 7, 8, 6, color);
	tri6( 1, 0, 2, 4, 6, 5, color);
	tri6( 3, 1, 2, 9, 5, 8, color);
	tri6( 0, 1, 3, 4, 9, 7, color);
}
 

/**
 */
void
GradientFieldRepresentationPolicy::hexa8 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_HEXAHEDRON8);
	assert(element.nodes.size() == 8);
	assert(m_gradient != NULL);

	m_gradient->calculateGradientValues(element);


	// generate a temporary list of all nodes
	m_temp_p.resize(8);
	for(int i = 0; i < 8; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	// render each surface
	quad4( 0, 4, 7, 3, color);
	quad4( 4, 5, 6, 7, color);
	quad4( 5, 1, 2, 6, color);
	quad4( 1, 0, 3, 2, color);
	quad4( 2, 3, 7, 6, color);
	quad4( 0, 1, 5, 4, color);
}


/**
 */
void
GradientFieldRepresentationPolicy::hexa20 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_HEXAHEDRON20);
	assert(element.nodes.size() == 20);
	assert(m_gradient != NULL);

	m_gradient->calculateGradientValues(element);


	// generate a temporary list of all nodes
	m_temp_p.resize(20);
	for(int i = 0; i < 20; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	quad8( 0, 4, 7, 3, 10, 17, 15, 9, color);
	quad8( 4, 5, 6, 7, 16, 18, 19, 17, color);
	quad8( 5, 1, 2, 6, 12, 11, 14, 18, color);
	quad8( 1, 0, 3, 2, 8, 9, 13, 11, color);
	quad8( 2, 3, 7, 6, 13, 15, 19, 14, color);
	quad8( 0, 1, 5, 4, 8, 12, 16, 10, color);
}


/**
 */
void
GradientFieldRepresentationPolicy::hexa27 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_HEXAHEDRON27);
	assert(element.nodes.size() == 27);
	assert(m_gradient != NULL);

	m_gradient->calculateGradientValues(element);


	// generate a temporary list of all nodes
	m_temp_p.resize(27);
	for(int i = 0; i < 27; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	quad9( 0, 4, 7, 3, 10, 17, 15, 9, 22, color);
	quad9( 4, 5, 6, 7, 16, 18, 19, 17, 25, color);
	quad9( 5, 1, 2, 6, 12, 11, 14, 18, 23, color);
	quad9( 1, 0, 3, 2, 8, 9, 13, 11, 20, color);
	quad9( 2, 3, 7, 6, 13, 15, 19, 14, 24, color);
	quad9( 0, 1, 5, 4, 8, 12, 16, 10, 21, color);
}


/**
 */
void
GradientFieldRepresentationPolicy::prism6 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_PRISM6);
	assert(element.nodes.size() == 6);

	// generate a temporary list of all nodes
	m_temp_p.resize(6);
	for(int i = 0; i < 6; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	tri3( 0, 2, 1, color);
	tri3( 3, 4, 5, color);

	quad4( 3, 0, 1, 4, color);
	quad4( 4, 1, 2, 5, color);
	quad4( 0, 3, 5, 2, color);
}


/**
 */
void
GradientFieldRepresentationPolicy::prism15 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_PRISM15);
	assert(element.nodes.size() == 15);

	// generate a temporary list of all nodes
	m_temp_p.resize(15);
	for(int i = 0; i < 15; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	tri6( 0, 2, 1, 7, 9, 6, color);
	tri6( 3, 4, 5, 12, 14, 13, color);

	quad8( 3, 0, 1, 4, 8, 6, 10, 12, color);
	quad8( 4, 1, 2, 5, 10, 9, 11, 14, color);
	quad8( 0, 3, 5, 2, 8, 13, 11, 7, color);
}


/**
 */
void
GradientFieldRepresentationPolicy::prism18 (fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_PRISM18);
	assert(element.nodes.size() == 18);
	assert(m_gradient != NULL);

	m_gradient->calculateGradientValues(element);


	// generate a temporary list of all nodes
	m_temp_p.resize(18);
	for(int i = 0; i < 18; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	tri6( 0, 2, 1, 7, 9, 6, color);
	tri6( 3, 4, 5, 12, 14, 13, color);

	quad9( 3, 0, 1, 4, 8, 6, 10, 12, 15, color);
	quad9( 4, 1, 2, 5, 10, 9, 11, 14, 17, color);
	quad9( 0, 3, 5, 2, 8, 13, 11, 7, 16, color);
}

