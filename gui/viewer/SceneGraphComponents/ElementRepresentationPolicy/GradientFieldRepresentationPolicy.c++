#include "GradientFieldRepresentationPolicy.h++"

#include <assert.h>
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
GradientFieldRepresentationPolicy::tri3(fem::element_ref_t const &ref,p_index_t p1, p_index_t p2, p_index_t p3, ViewportColors &colors)
{
	assert(m_gradient != NULL);

	glEnable(GL_BLEND);

	//int partitions = 4;	//TODO implement a better code

	fem::point temp;
	fem::point ptemp;
	temp = fem::getNormalVector(m_temp_p[p1],m_temp_p[p2],m_temp_p[p3]);
	
	glBegin(GL_TRIANGLES);
	glNormal3dv(temp.data);
	ptemp.set(0,0);  
	glColor3fv( m_gradient->tri3(ref, p1, p2, p3, ptemp, colors) );
	glVertex3dv(m_temp_p[p1].data);

	ptemp.set(1,0);  
	glColor3fv( m_gradient->tri3(ref, p1, p2, p3, ptemp, colors) );
	glVertex3dv(m_temp_p[p2].data);

	ptemp.set(0,1);  
	glColor3fv( m_gradient->tri3(ref, p1, p2, p3, ptemp, colors) );
	glVertex3dv(m_temp_p[p3].data);

	glEnd();
	glDisable(GL_BLEND);
}


void
GradientFieldRepresentationPolicy::tri6(fem::element_ref_t const &ref,p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4,p_index_t p5, p_index_t p6, ViewportColors &colors)
{
	assert(m_gradient != NULL);

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
	fem::point p_local_upper_row[partitions+1];
	fem::point *plu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;

	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point p_local_lower_row[partitions+1];
	fem::point *pll;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	plu = p_local_upper_row;
	pll = p_local_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = m_temp_p[p3]*y*(2*y-1)+4*m_temp_p[p6]*(-y-x+1)*y+4*m_temp_p[p5]*x*y+m_temp_p[p1]*(2*(-y-x+1)-1)*(-y-x+1)+4*m_temp_p[p4]*x*(-y-x+1)+m_temp_p[p2]*x*(2*x-1);
		p_local_lower_row[i] = fem::point(x,y);

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
		for (i = 0; i <= (partitions-j); i++)  
		{ 
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = m_temp_p[p3]*y*(2*y-1)+4*m_temp_p[p6]*(-y-x+1)*y+4*m_temp_p[p5]*x*y+m_temp_p[p1]*(2*(-y-x+1)-1)*(-y-x+1)+4*m_temp_p[p4]*x*(-y-x+1)+m_temp_p[p2]*x*(2*x-1);
			plu[i] = fem::point(x,y);

			// and now set the normal vector for the upper row
			dndx = -4*m_temp_p[p6]*y+4*m_temp_p[p5]*y+4*m_temp_p[p4]*(-y-x+1)-2*m_temp_p[p1]*(-y-x+1)-m_temp_p[p1]*(2*(-y-x+1)-1)+m_temp_p[p2]*(2*x-1)-4*m_temp_p[p4]*x+2*m_temp_p[p2]*x;
			dndy = m_temp_p[p3]*(2*y-1)-4*m_temp_p[p6]*y+2*m_temp_p[p3]*y+4*m_temp_p[p6]*(-y-x+1)-2*m_temp_p[p1]*(-y-x+1)-m_temp_p[p1]*(2*(-y-x+1)-1)+4*m_temp_p[p5]*x-4*m_temp_p[p4]*x;
			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glColor3fv( m_gradient->tri6(ref, p1, p2, p3, p4, p5, p6, plu[i], colors) );
			glVertex3dv(pu[i].data);
			glNormal3dv(nl[i].data);
			glColor3fv( m_gradient->tri6(ref, p1, p2, p3, p4, p5, p6, pll[i], colors) );
			glVertex3dv(pl[i].data);
		} 
		glNormal3dv(nl[i].data);
		glColor3fv( m_gradient->tri6(ref, p1, p2, p3, p4, p5, p6, pll[i], colors) );
		glVertex3dv(pl[i].data);
		glEnd(); 

		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		pll = plu;
		plu = (plu == p_local_upper_row)?p_local_lower_row:p_local_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;
	} 
	glDisable(GL_BLEND);
}


void
GradientFieldRepresentationPolicy::quad4(fem::element_ref_t const &ref,p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, ViewportColors &colors)
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
	fem::point p_local_upper_row[partitions+1];
	fem::point *plu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;

	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point p_local_lower_row[partitions+1];
	fem::point *pll;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	plu = p_local_upper_row;
	pll = p_local_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = m_temp_p[p3]*x*y+m_temp_p[p4]*(1-x)*y+m_temp_p[p2]*x*(1-y)+m_temp_p[p1]*(1-x)*(1-y);
		p_local_lower_row[i] = fem::point(x-0.5,y-0.5);

		// and now set the normal vector
		dndx = m_temp_p[p3]*y-m_temp_p[p4]*y+m_temp_p[p2]*(1-y)-m_temp_p[p1]*(1-y);
		dndy = m_temp_p[p3]*x-m_temp_p[p2]*x+m_temp_p[p4]*(1-x)-m_temp_p[p1]*(1-x);
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
			pu[i] = m_temp_p[p3]*x*y+m_temp_p[p4]*(1-x)*y+m_temp_p[p2]*x*(1-y)+m_temp_p[p1]*(1-x)*(1-y);
			plu[i] = fem::point(x-0.5,y-0.5);

			// and now set the normal vector
			dndx = m_temp_p[p3]*y-m_temp_p[p4]*y+m_temp_p[p2]*(1-y)-m_temp_p[p1]*(1-y);
			dndy = m_temp_p[p3]*x-m_temp_p[p2]*x+m_temp_p[p4]*(1-x)-m_temp_p[p1]*(1-x);

			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glColor3fv( m_gradient->quad4(ref, p1, p2, p3, p4, plu[i], colors) );
			glVertex3dv(pu[i].data);

			glNormal3dv(nl[i].data);
			glColor3fv( m_gradient->quad4(ref, p1, p2, p3, p4, pll[i], colors) );
			glVertex3dv(pl[i].data);
		} 
		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		pll = plu;
		plu = (plu == p_local_upper_row)?p_local_lower_row:p_local_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;

		glEnd(); 
	} 
	glDisable(GL_BLEND);
}


void
GradientFieldRepresentationPolicy::quad8(fem::element_ref_t const &ref,p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, p_index_t p5, p_index_t p6, p_index_t p7, p_index_t p8, ViewportColors &colors)
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
	fem::point p_local_upper_row[partitions+1];
	fem::point *plu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;

	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point p_local_lower_row[partitions+1];
	fem::point *pll;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	plu = p_local_upper_row;
	pll = p_local_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = 2.0*m_temp_p[p3]*x*y*(y+x-3/2.0) + 2.0*m_temp_p[p4]*(1-x)*y*(y-x-1/2.0) + 4.0*m_temp_p[p6]*x*(1-y)*y + 4.0*m_temp_p[p8]*(1-x)*(1-y)*y + 4.0*m_temp_p[p7]*(1-x)*x*y + 2.0*m_temp_p[p2]*x*(1-y)*(-y+x-1/2.0) + 2.0*m_temp_p[p1]*(1-x)*(1-y)*(-y-x+1/2.0) + 4.0*m_temp_p[p5]*(1-x)*x*(1-y);
		p_local_lower_row[i] = fem::point(x-0.5,y-0.5);

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
			plu[i] = fem::point(x-0.5,y-0.5);

			// and now set the normal vector for the upper row
			dndx = 2*m_temp_p[p3]*y*(y+x-3/2.0)-2*m_temp_p[p4]*y*(y-x-1/2.0)+4*m_temp_p[p6]*(1-y)*y-4*m_temp_p[p8]*(1-y)*y+2*m_temp_p[p3]*x*y-4*m_temp_p[p7]*x*y+4*m_temp_p[p7]*(1-x)*y-2*m_temp_p[p4]*(1-x)*y+2*m_temp_p[p2]*(1-y)*(-y+x-1/2.0)-2*m_temp_p[p1]*(1-y)*(-y-x+1/2.0)+2*m_temp_p[p2]*x*(1-y)-4*m_temp_p[p5]*x*(1-y) +4*m_temp_p[p5]*(1-x)*(1-y)-2*m_temp_p[p1]*(1-x)*(1-y);
			dndy = 2*m_temp_p[p3]*x*(y+x-3/2.0)+2*m_temp_p[p4]*(1-x)*(y-x-1/2.0)+2*m_temp_p[p3]*x*y-4*m_temp_p[p6]*x*y+2*m_temp_p[p4]*(1-x)*y-4*m_temp_p[p8]*(1-x)*y-2*m_temp_p[p2]*x*(-y+x-1/2.0)-2*m_temp_p[p1]*(1-x)*(-y-x+1/2.0)+4*m_temp_p[p6]*x*(1-y)-2*m_temp_p[p2]*x*(1-y)+4*m_temp_p[p8]*(1-x)*(1-y) - 2*m_temp_p[p1]*(1-x)*(1-y)+4*m_temp_p[p7]*(1-x)*x-4*m_temp_p[p5]*(1-x)*x;

			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glColor3fv( m_gradient->quad8(ref, p1, p2, p3, p4, p5, p6, p7, p8, plu[i], colors) );
			glVertex3dv(pu[i].data);
			glNormal3dv(nl[i].data);
			glColor3fv( m_gradient->quad8(ref, p1, p2, p3, p4, p5, p6, p7, p8, pll[i], colors) );
			glVertex3dv(pl[i].data);
		} 
		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		pll = plu;
		plu = (plu == p_local_upper_row)?p_local_lower_row:p_local_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;
		glEnd(); 
	} 
	glDisable(GL_BLEND);
}


void
GradientFieldRepresentationPolicy::quad9(fem::element_ref_t const &ref,p_index_t p1, p_index_t p2, p_index_t p3, p_index_t p4, p_index_t p5, p_index_t p6, p_index_t p7, p_index_t p8, p_index_t p9, ViewportColors &colors)
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
	fem::point p_local_upper_row[partitions+1];
	fem::point *plu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;

	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point p_local_lower_row[partitions+1];
	fem::point *pll;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	plu = p_local_upper_row;
	pll = p_local_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = 16.0*m_temp_p[p9]*(1-x)*x*(1-y)*y - 8.0*m_temp_p[p6]*(0.5-x)*x*(1-y)*y + 8.0*m_temp_p[p8]*(0.5-x)*(1-x)*(1-y)*y - 8.0*m_temp_p[p7]*(1-x)*x*(0.5-y)*y + 4.0*m_temp_p[p3]*(0.5-x)*x*(0.5-y)*y - 4.0*m_temp_p[p4]*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*m_temp_p[p5]*(1-x)*x*(0.5-y)*(1-y) - 4.0*m_temp_p[p2]*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(0.5-y)*(1-y);
		p_local_lower_row[i] = fem::point(x-0.5,y-0.5);

		// and now set the normal vector
		dndx = 8.0*m_temp_p[p6]*x*(1-y)*y-16.0*m_temp_p[p9]*x*(1-y)*y+16.0*m_temp_p[p9]*(1-x)*(1-y)*y-8.0*m_temp_p[p8]*(1-x)*(1-y)*y-8.0*m_temp_p[p6]*(0.5-x)*(1-y)*y-8.0*m_temp_p[p8]*(0.5-x)*(1-y)*y-4.0*m_temp_p[p3]*x*(0.5-y)*y+8.0*m_temp_p[p7]*x*(0.5-y)*y-8.0*m_temp_p[p7]*(1-x)*(0.5-y)*y +4.0*m_temp_p[p4]*(1-x)*(0.5-y)*y+4.0*m_temp_p[p3]*(0.5-x)*(0.5-y)*y+4.0*m_temp_p[p4]*(0.5-x)*(0.5-y)*y+4.0*m_temp_p[p2]*x*(0.5-y)*(1-y)-8.0*m_temp_p[p5]*x*(0.5-y)*(1-y)+8.0*m_temp_p[p5]*(1-x)*(0.5-y)*(1-y)-4.0*m_temp_p[p1]*(1-x)*(0.5-y)*(1-y) -4.0*m_temp_p[p2]*(0.5-x)*(0.5-y)*(1-y)-4.0*m_temp_p[p1]*(0.5-x)*(0.5-y)*(1-y);

		dndy = 8.0*m_temp_p[p7]*(1-x)*x*y-16.0*m_temp_p[p9]*(1-x)*x*y-4.0*m_temp_p[p3]*(0.5-x)*x*y+8.0*m_temp_p[p6]*(0.5-x)*x*y+4.0*m_temp_p[p4]*(0.5-x)*(1-x)*y-8.0*m_temp_p[p8]*(0.5-x)*(1-x)*y+16.0*m_temp_p[p9]*(1-x)*x*(1-y)-8.0*m_temp_p[p5]*(1-x)*x*(1-y)-8.0*m_temp_p[p6]*(0.5-x)*x*(1-y) +4.0*m_temp_p[p2]*(0.5-x)*x*(1-y)+8.0*m_temp_p[p8]*(0.5-x)*(1-x)*(1-y)-4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(1-y)-8.0*m_temp_p[p7]*(1-x)*x*(0.5-y)-8.0*m_temp_p[p5]*(1-x)*x*(0.5-y)+4.0*m_temp_p[p3]*(0.5-x)*x*(0.5-y)+4.0*m_temp_p[p2]*(0.5-x)*x*(0.5-y) -4.0*m_temp_p[p4]*(0.5-x)*(1-x)*(0.5-y)-4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(0.5-y);
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
			pu[i] = 16.0*m_temp_p[p9]*(1-x)*x*(1-y)*y - 8.0*m_temp_p[p6]*(0.5-x)*x*(1-y)*y + 8.0*m_temp_p[p8]*(0.5-x)*(1-x)*(1-y)*y - 8.0*m_temp_p[p7]*(1-x)*x*(0.5-y)*y + 4.0*m_temp_p[p3]*(0.5-x)*x*(0.5-y)*y - 4.0*m_temp_p[p4]*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*m_temp_p[p5]*(1-x)*x*(0.5-y)*(1-y) - 4.0*m_temp_p[p2]*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(0.5-y)*(1-y);
			plu[i] = fem::point(x-0.5,y-0.5);

			// and now set the normal vector for the upper row
			dndx = 8.0*m_temp_p[p6]*x*(1-y)*y-16.0*m_temp_p[p9]*x*(1-y)*y+16.0*m_temp_p[p9]*(1-x)*(1-y)*y-8.0*m_temp_p[p8]*(1-x)*(1-y)*y-8.0*m_temp_p[p6]*(0.5-x)*(1-y)*y-8.0*m_temp_p[p8]*(0.5-x)*(1-y)*y-4.0*m_temp_p[p3]*x*(0.5-y)*y+8.0*m_temp_p[p7]*x*(0.5-y)*y-8.0*m_temp_p[p7]*(1-x)*(0.5-y)*y +4.0*m_temp_p[p4]*(1-x)*(0.5-y)*y+4.0*m_temp_p[p3]*(0.5-x)*(0.5-y)*y+4.0*m_temp_p[p4]*(0.5-x)*(0.5-y)*y+4.0*m_temp_p[p2]*x*(0.5-y)*(1-y)-8.0*m_temp_p[p5]*x*(0.5-y)*(1-y)+8.0*m_temp_p[p5]*(1-x)*(0.5-y)*(1-y)-4.0*m_temp_p[p1]*(1-x)*(0.5-y)*(1-y) -4.0*m_temp_p[p2]*(0.5-x)*(0.5-y)*(1-y)-4.0*m_temp_p[p1]*(0.5-x)*(0.5-y)*(1-y);
			dndy = 8.0*m_temp_p[p7]*(1-x)*x*y-16.0*m_temp_p[p9]*(1-x)*x*y-4.0*m_temp_p[p3]*(0.5-x)*x*y+8.0*m_temp_p[p6]*(0.5-x)*x*y+4.0*m_temp_p[p4]*(0.5-x)*(1-x)*y-8.0*m_temp_p[p8]*(0.5-x)*(1-x)*y+16.0*m_temp_p[p9]*(1-x)*x*(1-y)-8.0*m_temp_p[p5]*(1-x)*x*(1-y)-8.0*m_temp_p[p6]*(0.5-x)*x*(1-y) +4.0*m_temp_p[p2]*(0.5-x)*x*(1-y)+8.0*m_temp_p[p8]*(0.5-x)*(1-x)*(1-y)-4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(1-y)-8.0*m_temp_p[p7]*(1-x)*x*(0.5-y)-8.0*m_temp_p[p5]*(1-x)*x*(0.5-y)+4.0*m_temp_p[p3]*(0.5-x)*x*(0.5-y)+4.0*m_temp_p[p2]*(0.5-x)*x*(0.5-y) -4.0*m_temp_p[p4]*(0.5-x)*(1-x)*(0.5-y)-4.0*m_temp_p[p1]*(0.5-x)*(1-x)*(0.5-y);

			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glColor3fv( m_gradient->quad9(ref, p1, p2, p3, p4, p5, p6, p7, p8, p9, plu[i], colors) );
			glVertex3dv(pu[i].data);

			glNormal3dv(nl[i].data);
			glColor3fv( m_gradient->quad9(ref, p1, p2, p3, p4, p5, p6, p7, p8, p9, pll[i], colors) );
			glVertex3dv(pl[i].data);
		} 
		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		pll = plu;
		plu = (plu == p_local_upper_row)?p_local_lower_row:p_local_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;
		glEnd(); 
	} 
	glDisable(GL_BLEND);
}


/**
 */
void
GradientFieldRepresentationPolicy::tetra4 (fem::element_ref_t const &element_reference, fem::Element &element, ViewportColors &colors, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_TETRAHEDRON4);
	assert(element.nodes.size() == 4);
	assert(m_gradient != NULL);

	// generate a temporary list of all nodes
	m_temp_p.resize(4);
	for(int i = 0; i < 4; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	glDisable(GL_LIGHTING);
	// render each surface
	tri3( element_reference, 0, 3, 2, colors);
	tri3( element_reference, 1, 0, 2, colors);
	tri3( element_reference, 3, 1, 2, colors);
	tri3( element_reference, 0, 1, 3, colors);
	glEnable(GL_LIGHTING);
}


/**
 */
void
GradientFieldRepresentationPolicy::tetra10 (fem::element_ref_t const &element_reference, fem::Element &element, ViewportColors &colors, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_TETRAHEDRON10);
	assert(element.nodes.size() == 10);
	assert(m_gradient != NULL);


	// generate a temporary list of all nodes
	m_temp_p.resize(10);
	for(int i = 0; i < 10; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	glDisable(GL_LIGHTING);
	// render each surface
	tri6( element_reference, 0, 3, 2, 7, 8, 6, colors);
	tri6( element_reference, 1, 0, 2, 4, 6, 5, colors);
	tri6( element_reference, 3, 1, 2, 9, 5, 8, colors);
	tri6( element_reference, 0, 1, 3, 4, 9, 7, colors);
	glEnable(GL_LIGHTING);
}
 

/**
 */
void
GradientFieldRepresentationPolicy::hexa8 (fem::element_ref_t const &element_reference, fem::Element &element, ViewportColors &colors, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_HEXAHEDRON8);
	assert(element.nodes.size() == 8);
	assert(m_gradient != NULL);

	// generate a temporary list of all nodes
	m_temp_p.resize(8);
	for(int i = 0; i < 8; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	glDisable(GL_LIGHTING);
	// render each surface
	quad4( element_reference, 0, 4, 7, 3, colors);
	quad4( element_reference, 4, 5, 6, 7, colors);
	quad4( element_reference,  5, 1, 2, 6, colors);
	quad4( element_reference, 1, 0, 3, 2, colors);
	quad4( element_reference, 2, 3, 7, 6, colors);
	quad4( element_reference, 0, 1, 5, 4, colors);
	glEnable(GL_LIGHTING);
}


/**
 */
void
GradientFieldRepresentationPolicy::hexa20 (fem::element_ref_t const &element_reference, fem::Element &element, ViewportColors &colors, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_HEXAHEDRON20);
	assert(element.nodes.size() == 20);
	assert(m_gradient != NULL);

	// generate a temporary list of all nodes
	m_temp_p.resize(20);
	for(int i = 0; i < 20; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	glDisable(GL_LIGHTING);
	quad8( element_reference,  0, 4, 7, 3, 10, 17, 15, 9, colors);
	quad8( element_reference,  4, 5, 6, 7, 16, 18, 19, 17, colors);
	quad8( element_reference,  5, 1, 2, 6, 12, 11, 14, 18, colors);
	quad8( element_reference,  1, 0, 3, 2, 8, 9, 13, 11, colors);
	quad8( element_reference,  2, 3, 7, 6, 13, 15, 19, 14, colors);
	quad8( element_reference,  0, 1, 5, 4, 8, 12, 16, 10, colors);
	glEnable(GL_LIGHTING);
}


/**
 */
void
GradientFieldRepresentationPolicy::hexa27 (fem::element_ref_t const &element_reference, fem::Element &element, ViewportColors &colors, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_HEXAHEDRON27);
	assert(element.nodes.size() == 27);
	assert(m_gradient != NULL);

	// generate a temporary list of all nodes
	m_temp_p.resize(27);
	for(int i = 0; i < 27; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	glDisable(GL_LIGHTING);
	quad9( element_reference,  0, 4, 7, 3, 10, 17, 15, 9, 22, colors);
	quad9( element_reference,  4, 5, 6, 7, 16, 18, 19, 17, 25, colors);
	quad9( element_reference,  5, 1, 2, 6, 12, 11, 14, 18, 23, colors);
	quad9( element_reference,  1, 0, 3, 2, 8, 9, 13, 11, 20, colors);
	quad9( element_reference,  2, 3, 7, 6, 13, 15, 19, 14, 24, colors);
	quad9( element_reference,  0, 1, 5, 4, 8, 12, 16, 10, 21, colors);
	glEnable(GL_LIGHTING);
}


/**
 */
void
GradientFieldRepresentationPolicy::prism6 (fem::element_ref_t const &element_reference, fem::Element &element, ViewportColors &colors, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_PRISM6);
	assert(element.nodes.size() == 6);
	assert(m_gradient != NULL);

	// generate a temporary list of all nodes
	m_temp_p.resize(6);
	for(int i = 0; i < 6; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	glDisable(GL_LIGHTING);
	tri3( element_reference, 0, 2, 1, colors);
	tri3( element_reference, 3, 4, 5, colors);

	quad4(element_reference,  3, 0, 1, 4, colors);
	quad4(element_reference,  4, 1, 2, 5, colors);
	quad4(element_reference,  0, 3, 5, 2, colors);
	glEnable(GL_LIGHTING);
}


/**
 */
void
GradientFieldRepresentationPolicy::prism15 (fem::element_ref_t const &element_reference, fem::Element &element, ViewportColors &colors, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_PRISM15);
	assert(element.nodes.size() == 15);
	assert(m_gradient != NULL);

	// generate a temporary list of all nodes
	m_temp_p.resize(15);
	for(int i = 0; i < 15; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	glDisable(GL_LIGHTING);
	tri6(element_reference,  0, 2, 1, 7, 9, 6, colors);
	tri6(element_reference,  3, 4, 5, 12, 14, 13, colors);

	quad8(element_reference,  3, 0, 1, 4, 8, 6, 10, 12, colors);
	quad8(element_reference,  4, 1, 2, 5, 10, 9, 11, 14, colors);
	quad8(element_reference,  0, 3, 5, 2, 8, 13, 11, 7, colors);
	glEnable(GL_LIGHTING);
}


/**
 */
void
GradientFieldRepresentationPolicy::prism18 (fem::element_ref_t const &element_reference, fem::Element &element, ViewportColors &colors, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_PRISM18);
	assert(element.nodes.size() == 18);
	assert(m_gradient != NULL);

	// generate a temporary list of all nodes
	m_temp_p.resize(18);
	for(int i = 0; i < 18; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	glDisable(GL_LIGHTING);
	tri6(element_reference, 0, 2, 1, 7, 9, 6, colors);
	tri6(element_reference, 3, 4, 5, 12, 14, 13, colors);

	quad9(element_reference, 3, 0, 1, 4, 8, 6, 10, 12, 15, colors);
	quad9(element_reference, 4, 1, 2, 5, 10, 9, 11, 14, 17, colors);
	quad9(element_reference, 0, 3, 5, 2, 8, 13, 11, 7, 16, colors);
	glEnable(GL_LIGHTING);
}


void 
GradientFieldRepresentationPolicy::renderNeutral()
{
	m_gradient = m_gradient_flyweight_factory.neutral();
}


void 
GradientFieldRepresentationPolicy::renderConstant(float value)
{
	m_gradient = m_gradient_flyweight_factory.constant(value);
}


void 
GradientFieldRepresentationPolicy::renderStrains11()
{
	m_gradient = m_gradient_flyweight_factory.strains11();
}


void 
GradientFieldRepresentationPolicy::renderStrains22()
{
	m_gradient = m_gradient_flyweight_factory.strains22();
}


void 
GradientFieldRepresentationPolicy::renderStrains33()
{
	m_gradient = m_gradient_flyweight_factory.strains33();
}


void 
GradientFieldRepresentationPolicy::renderStrains12()
{
	m_gradient = m_gradient_flyweight_factory.strains12();
}


void 
GradientFieldRepresentationPolicy::renderStrains23()
{
	m_gradient = m_gradient_flyweight_factory.strains23();
}


void 
GradientFieldRepresentationPolicy::renderStrains13()
{
	m_gradient = m_gradient_flyweight_factory.strains13();
}


void 
GradientFieldRepresentationPolicy::renderVonMises()
{
	m_gradient = m_gradient_flyweight_factory.vonMises();
}


void 
GradientFieldRepresentationPolicy::setModel(fem::Model &model)
{
	m_gradient_flyweight_factory.setModel(model);
}


void 
GradientFieldRepresentationPolicy::setAnalysisResult(fem::AnalysisResult<double> &result)
{
	m_gradient_flyweight_factory.setAnalysisResult(result);
}

