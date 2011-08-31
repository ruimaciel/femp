#include "OpaqueRepresentationPolicy.h++"

#include <GL/gl.h>

// Constructors/Destructors
//  

OpaqueRepresentationPolicy::OpaqueRepresentationPolicy ( ) 
{
	m_temp_p.reserve(27);	// to accomodate the maximum number of points
}

OpaqueRepresentationPolicy::~OpaqueRepresentationPolicy ( ) { }

//  
// Methods
//  



// Other methods
//  
void
OpaqueRepresentationPolicy::tri3(fem::point &p1, fem::point &p2, fem::point &p3, ViewportColor &color)
{
	glEnable(GL_BLEND);

	//int partitions = 4;	//TODO implement a better code

	fem::point temp;
	temp = fem::getNormalVector(p1,p2,p3);
	
	glBegin(GL_TRIANGLES);
	glColor4f(color.surface);
	glNormal3dv(temp.data);
	glVertex3dv(p1.data);
	glVertex3dv(p2.data);
	glVertex3dv(p3.data);
	glEnd();
	glDisable(GL_BLEND);
}


void
OpaqueRepresentationPolicy::tri6(fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4,fem::point &p5, fem::point &p6, ViewportColor &color)
{
	glEnable(GL_BLEND);
	//int partitions = 6;	//TODO implement a better code

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
		p_lower_row[i] = p3*y*(2*y-1)+4*p6*(-y-x+1)*y+4*p5*x*y+p1*(2*(-y-x+1)-1)*(-y-x+1)+4*p4*x*(-y-x+1)+p2*x*(2*x-1);

		// and now set the normal vector
		dndx = -4*p6*y+4*p5*y+4*p4*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+p2*(2*x-1)-4*p4*x+2*p2*x;
		dndy = p3*(2*y-1)-4*p6*y+2*p3*y+4*p6*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+4*p5*x-4*p4*x;
		
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	// the rest of the loop
	for (int j = 1, i; j <= partitions; j++)  
	{ 
		y = (double)j/partitions;
		// and now let's render
		glBegin(GL_TRIANGLE_STRIP);  
		glColor4f(color.surface);
		for (i = 0; i <= (partitions-j); i++)  
		{ 
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = p3*y*(2*y-1)+4*p6*(-y-x+1)*y+4*p5*x*y+p1*(2*(-y-x+1)-1)*(-y-x+1)+4*p4*x*(-y-x+1)+p2*x*(2*x-1);

			// and now set the normal vector for the upper row
			dndx = -4*p6*y+4*p5*y+4*p4*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+p2*(2*x-1)-4*p4*x+2*p2*x;
			dndy = p3*(2*y-1)-4*p6*y+2*p3*y+4*p6*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+4*p5*x-4*p4*x;
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
OpaqueRepresentationPolicy::quad4(fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4, ViewportColor &color)
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
		p_lower_row[i] = p3*x*y+p4*(1-x)*y+p2*x*(1-y)+p1*(1-x)*(1-y);

		// and now set the normal vector
		dndx = p3*y-p4*y+p2*(1-y)-p1*(1-y);
		dndy = p3*x-p2*x+p4*(1-x)-p1*(1-x);
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	glColor4f(color.surface);

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
	glDisable(GL_BLEND);
}


void
OpaqueRepresentationPolicy::quad8(fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4, fem::point &p5, fem::point &p6, fem::point &p7, fem::point &p8, ViewportColor &color)
{
	glEnable(GL_BLEND);
	// int partitions = 6;	//TODO implement a better code

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

	glColor4f(color.surface);

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = 2.0*p3*x*y*(y+x-3/2.0) + 2.0*p4*(1-x)*y*(y-x-1/2.0) + 4.0*p6*x*(1-y)*y + 4.0*p8*(1-x)*(1-y)*y + 4.0*p7*(1-x)*x*y + 2.0*p2*x*(1-y)*(-y+x-1/2.0) + 2.0*p1*(1-x)*(1-y)*(-y-x+1/2.0) + 4.0*p5*(1-x)*x*(1-y);

		// and now set the normal vector
		dndx = 2*p3*y*(y+x-3/2.0)-2*p4*y*(y-x-1/2.0)+4*p6*(1-y)*y-4*p8*(1-y)*y+2*p3*x*y-4*p7*x*y+4*p7*(1-x)*y-2*p4*(1-x)*y+2*p2*(1-y)*(-y+x-1/2.0)-2*p1*(1-y)*(-y-x+1/2.0)+2*p2*x*(1-y)-4*p5*x*(1-y) +4*p5*(1-x)*(1-y)-2*p1*(1-x)*(1-y);

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
	glDisable(GL_BLEND);
}


void
OpaqueRepresentationPolicy::quad9(fem::point &p1, fem::point &p2, fem::point &p3, fem::point &p4, fem::point &p5, fem::point &p6, fem::point &p7, fem::point &p8, fem::point &p9, ViewportColor &color)
{
	glEnable(GL_BLEND);
	// int partitions = 6;	//TODO implement a better code

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

	glColor4f(color.surface);

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
	glDisable(GL_BLEND);
}


/**
 */
void
OpaqueRepresentationPolicy::tetra4 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_TETRAHEDRON4);
	assert(element.nodes.size() == 4);

	// generate a temporary list of all nodes
	m_temp_p.resize(4);
	for(int i = 0; i < 4; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	// render each surface
	tri3( m_temp_p[0], m_temp_p[3], m_temp_p[2]);
	tri3( m_temp_p[1], m_temp_p[0], m_temp_p[2]);
	tri3( m_temp_p[3], m_temp_p[1], m_temp_p[2]);
	tri3( m_temp_p[0], m_temp_p[1], m_temp_p[3]);
}


/**
 */
void
OpaqueRepresentationPolicy::tetra10 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_TETRAHEDRON10);
	assert(element.nodes.size() == 10);

	// generate a temporary list of all nodes
	m_temp_p.resize(10);
	for(int i = 0; i < 10; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	// render each surface
	tri6( m_temp_p[0], m_temp_p[3], m_temp_p[2], m_temp_p[7], m_temp_p[8], m_temp_p[6] );
	tri6( m_temp_p[1], m_temp_p[0], m_temp_p[2], m_temp_p[4], m_temp_p[6], m_temp_p[5] );
	tri6( m_temp_p[3], m_temp_p[1], m_temp_p[2], m_temp_p[9], m_temp_p[5], m_temp_p[8]);
	tri6( m_temp_p[0], m_temp_p[1], m_temp_p[3], m_temp_p[4], m_temp_p[9], m_temp_p[7]);
}
 

/**
 */
void
OpaqueRepresentationPolicy::hexa8 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_HEXAHEDRON8);
	assert(element.nodes.size() == 8);

	// generate a temporary list of all nodes
	m_temp_p.resize(8);
	for(int i = 0; i < 8; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	// render each surface
	quad4( m_temp_p[0], m_temp_p[4], m_temp_p[7], m_temp_p[3]);
	quad4( m_temp_p[4], m_temp_p[5], m_temp_p[6], m_temp_p[7]);
	quad4( m_temp_p[5], m_temp_p[1], m_temp_p[2], m_temp_p[6]);
	quad4( m_temp_p[1], m_temp_p[0], m_temp_p[3], m_temp_p[2]);
	quad4( m_temp_p[2], m_temp_p[3], m_temp_p[7], m_temp_p[6]);
	quad4( m_temp_p[0], m_temp_p[1], m_temp_p[5], m_temp_p[4]);
}


/**
 */
void
OpaqueRepresentationPolicy::hexa20 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_HEXAHEDRON20);
	assert(element.nodes.size() == 20);

	// generate a temporary list of all nodes
	m_temp_p.resize(20);
	for(int i = 0; i < 20; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	quad4( m_temp_p[0], m_temp_p[4], m_temp_p[7], m_temp_p[3], m_temp_p[10], m_temp_p[17], m_temp_p[15], m_temp_p[9]);
	quad4( m_temp_p[4], m_temp_p[5], m_temp_p[6], m_temp_p[7], m_temp_p[16], m_temp_p[18], m_temp_p[19], m_temp_p[17]);
	quad4( m_temp_p[5], m_temp_p[1], m_temp_p[2], m_temp_p[6], m_temp_p[12], m_temp_p[11], m_temp_p[14], m_temp_p[18]);
	quad4( m_temp_p[1], m_temp_p[0], m_temp_p[3], m_temp_p[2], m_temp_p[8], m_temp_p[9], m_temp_p[13], m_temp_p[11]);
	quad4( m_temp_p[2], m_temp_p[3], m_temp_p[7], m_temp_p[6], m_temp_p[13], m_temp_p[15], m_temp_p[19], m_temp_p[14]);
	quad4( m_temp_p[0], m_temp_p[1], m_temp_p[5], m_temp_p[4], m_temp_p[8], m_temp_p[12], m_temp_p[16], m_temp_p[10]);
}


/**
 */
void
OpaqueRepresentationPolicy::hexa27 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_HEXAHEDRON27);
	assert(element.nodes.size() == 27);

	// generate a temporary list of all nodes
	m_temp_p.resize(27);
	for(int i = 0; i < 27; i++)
	{
		m_temp_p[i] = (*displacement)[element.nodes[i]];
	}

	quad4( m_temp_p[0], m_temp_p[4], m_temp_p[7], m_temp_p[3], m_temp_p[10], m_temp_p[17], m_temp_p[15], m_temp_p[9], m_temp_p[22]);
	quad4( m_temp_p[4], m_temp_p[5], m_temp_p[6], m_temp_p[7], m_temp_p[16], m_temp_p[18], m_temp_p[19], m_temp_p[17], m_temp_p[25]);
	quad4( m_temp_p[5], m_temp_p[1], m_temp_p[2], m_temp_p[6], m_temp_p[12], m_temp_p[11], m_temp_p[14], m_temp_p[18], m_temp_p[23]);
	quad4( m_temp_p[1], m_temp_p[0], m_temp_p[3], m_temp_p[2], m_temp_p[8], m_temp_p[9], m_temp_p[13], m_temp_p[11], m_temp_p[20]);
	quad4( m_temp_p[2], m_temp_p[3], m_temp_p[7], m_temp_p[6], m_temp_p[13], m_temp_p[15], m_temp_p[19], m_temp_p[14], m_temp_p[24]);
	quad4( m_temp_p[0], m_temp_p[1], m_temp_p[5], m_temp_p[4], m_temp_p[8], m_temp_p[12], m_temp_p[16], m_temp_p[10], m_temp_p[21]);
}


/**
 */
void
OpaqueRepresentationPolicy::prism6 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_PRISM6);
}


/**
 */
void
OpaqueRepresentationPolicy::prism15 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_PRISM15);
}


/**
 */
void
OpaqueRepresentationPolicy::prism18 (fem::Element &element, ViewportColor &color, DisplacementsRepresentationPolicy *displacement)
{
	assert(element.type == fem::Element::FE_PRISM18);
}
